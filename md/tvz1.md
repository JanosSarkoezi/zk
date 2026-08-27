### Schritt 3: Das State-Pattern (Verbindung zum Editor-Zustand)

Jetzt erstellen wir ein Interface für deine Editor-Zustände (`EditorState`). Jeder Zustand liefert seine individuelle `InteractionMap` oder verarbeitet die Events direkt darüber:

```java
package de.fmc.editor.state;

public interface EditorState {

    // Jeder Zustand definiert seine eigenen Bindings
    InteractionMap getInteractionMap();

    default boolean handleInteraction(InteractionEventData event) {
        return getInteractionMap().handle(event);
    }

    // Lifecycle-Methoden für Zustände
    default void onEnter() {}
    default void onExit() {}
}
```

---

## 3. Anwendungsbeispiel: Verschiedene Zustände

Jetzt zeigt sich die Stärke der Architektur. Du kannst Zustände wie **SelectState** (Auswahlmodus) und **CreateNodeState** (Element-Erstellmodus) definieren:

### Zustand A: `SelectState` (Normale Interaktion)
```java
public class SelectState implements EditorState {

    private final InteractionMap bindings;
    private final EditorContext context;

    public SelectState(EditorContext context) {
        this.context = context;

        this.bindings = new InteractionMap()
            // Tastatur-Shortcuts
            .on(EventMatcher.shortcut(KeyCode.Z), context::undo)
            .on(EventMatcher.keyPressed(KeyCode.DELETE), context::deleteSelected)

            // Reiner Mausklick -> Element auswählen
            .on(EventMatcher.primaryClick(), event -> {
                context.selectAt(event.worldX(), event.worldY());
            })

            // Shift + Klick -> Zur Auswahl hinzufügen
            .on(EventMatcher.shiftClick(), event -> {
                context.toggleSelectionAt(event.worldX(), event.worldY());
            })

            // Doppelklick -> In den Erstellmodus oder Editormodus wechseln
            .on(EventMatcher.primaryDoubleClick(), event -> {
                context.switchState(new CreateNodeState(context));
            });
    }

    @Override
    public InteractionMap getInteractionMap() {
        return bindings;
    }
}
```

### Zustand B: `CreateNodeState` (Neues Element platzieren)
Derselbe Primärklick tut im `CreateNodeState` etwas völlig anderes:

```java
public class CreateNodeState implements EditorState {

    private final InteractionMap bindings;

    public CreateNodeState(EditorContext context) {
        this.bindings = new InteractionMap()
            // Primärklick erzeugt hier ein neues Element!
            .on(EventMatcher.primaryClick(), event -> {
                context.spawnNodeAt(event.worldX(), event.worldY());
                // Danach zurück zum SelectState wechseln
                context.switchState(new SelectState(context));
            })

            // ESC bricht das Erstellen ab
            .on(EventMatcher.keyPressed(KeyCode.ESCAPE), () -> {
                context.switchState(new SelectState(context));
            });
    }

    @Override
    public InteractionMap getInteractionMap() {
        return bindings;
    }
}
```

---

## Vor- und Nachteile dieses Ansatzes

### Vorteile:
1. **Extrem hohe Lesbarkeit:** Du siehst im Konstruktor eines Zustands auf einen Blick, welche Tasten/Mausaktionen in diesem Zustand was tun.
2. **Kein riesiges `if/else` oder `switch`:** Weder im Event-Handler noch im Zustand gibt es lange Abfragen.
3. **Sehr leicht erweiterbar:** Neue Kombinationen (z. B. `Alt + Rechtsklick`) erfordern nur eine neue Statik-Methode in `EventMatcher`.
4. **Zustandstrennung:** Die selbe Taste/Aktion (`ENTER`, `Klick`) ruft automatisch die richtige Logik für den aktuellen Zustand auf.

<ElicitationsGroup message="Wie möchtest du das Thema vertiefen?">
  <Elicitation label="Zeige mir die EditorContext-Klasse (State Machine Management)" query="Zeige mir, wie die EditorContext-Klasse aufgebaut ist, die den aktuellen Zustand (EditorState) verwaltet und Events an ihn weiterleitet."/>
  <Elicitation label="Wie handhabt man Drag & Drop (Mausbewegung) in diesem System?" query="Wie erweitert man dieses Event-System um Continuous-Events wie Mouse-Dragging (z. B. Selektionsrahmen ziehen oder Elemente verschieben)?"/>
</ElicitationsGroup>

---

# you asked

message time: 2026-08-02 23:54:53

Wie erweitert man dieses Event-System um Continuous-Events wie Mouse-Dragging (z. B. Selektionsrahmen ziehen oder Elemente verschieben)?

---

# gemini response

Um kontinuierliche Aktionen wie **Drag & Drop**, **Selektionsrahmen (Rubberband Selection)** oder **Elemente Verschieben** sauber abzubilden, stößt ein reines Point-in-Time-Event (ein einzelner Klick) an seine Grenzen.

Bei Drags benötigen wir **Stateful Interaction** (Start, Update, End). Dafür erweitert man das System am besten um ein **Gestures / Drag-Handler Pattern**.

---

## 1. Welches Problem müssen wir lösen?

Ein Drag-Vorgang hat einen Lebenszyklus über drei JavaFX-Events hinweg:
1. `MOUSE_PRESSED` $\rightarrow$ **Drag Start** (Startposition merken, z. B. Selektionsrahmen initialisieren)
2. `MOUSE_DRAGGED` $\rightarrow$ **Drag Update** (Aktuelle Position verarbeiten, Differenz $\Delta x, \Delta y$ berechnen)
3. `MOUSE_RELEASED` $\rightarrow$ **Drag End** (Aktion abschließen, Undo/Redo-State speichern)

Damit das Event-System nicht mit Zwischenzuständen überflutet wird, führen wir das Konzept eines **`DragHandler`** ein.

---

## 2. Die Erweiterung: `DragHandler` & `DragMatcher`

### Schritt 1: Das `DragHandler`-Interface

Ein `DragHandler` verwaltet den Zustand *während* des Draggings:

```java
package de.fmc.editor.state;

public interface DragHandler {
    /** Wird einmalig beim Drücken der Maustaste aufgerufen. */
    void onStart(InteractionEventData startEvent);

    /** Wird bei jeder Mausbewegung mit gedrückter Taste aufgerufen. */
    void onDrag(InteractionEventData currentEvent, double deltaX, double deltaY);

    /** Wird beim Loslassen der Maustaste aufgerufen. */
    void onEnd(InteractionEventData endEvent);
}
```

---

### Schritt 2: Erweiterung der `InteractionMap` für Drags

Wir erweitern `InteractionMap`, sodass sie unterscheidet zwischen **Aktionen (Single Events)** und **Drag-Gesten (Continuous Events)**:

```java
package de.fmc.editor.state;

import java.util.ArrayList;
import java.util.List;

public class InteractionMap {

    private final List<Binding> singleBindings = new ArrayList<>();
    private final List<DragBinding> dragBindings = new ArrayList<>();

    // Aktiver Drag-Zustand (null, wenn gerade kein Drag läuft)
    private ActiveDrag activeDrag = null;

    private record Binding(EventMatcher matcher, Consumer<InteractionEventData> action) {}
    private record DragBinding(EventMatcher startMatcher, Supplier<DragHandler> handlerSupplier) {}
    private record ActiveDrag(DragHandler handler, InteractionEventData startEvent) {}

    // --- Standard-Aktionen ---
    public InteractionMap on(EventMatcher matcher, Consumer<InteractionEventData> action) {
        singleBindings.add(new Binding(matcher, action));
        return this;
    }

    // --- Continuous Drag-Aktionen ---
    public InteractionMap onDrag(EventMatcher startMatcher, Supplier<DragHandler> handlerSupplier) {
        dragBindings.add(new DragBinding(startMatcher, handlerSupplier));
        return this;
    }

    // --- Event Handling ---

    /** Aufzurufen bei MOUSE_PRESSED */
    public boolean handlePress(InteractionEventData event) {
        // Prüfen, ob ein Drag gestartet werden soll
        for (DragBinding binding : dragBindings) {
            if (binding.startMatcher().test(event)) {
                DragHandler handler = binding.handlerSupplier().get();
                handler.onStart(event);
                this.activeDrag = new ActiveDrag(handler, event);
                return true;
            }
        }

        // Falls kein Drag-Start matcht, normale Klick-Aktionen prüfen
        return handleSingleEvent(event);
    }

    /** Aufzurufen bei MOUSE_DRAGGED */
    public boolean handleDrag(InteractionEventData event) {
        if (activeDrag != null) {
            double deltaX = event.worldX() - activeDrag.startEvent().worldX();
            double deltaY = event.worldY() - activeDrag.startEvent().worldY();

            activeDrag.handler().onDrag(event, deltaX, deltaY);
            return true;
        }
        return false;
    }

    /** Aufzurufen bei MOUSE_RELEASED */
    public boolean handleRelease(InteractionEventData event) {
        if (activeDrag != null) {
            activeDrag.handler().onEnd(event);
            activeDrag = null; // Drag beendet
            return true;
        }
        return false;
    }

    private boolean handleSingleEvent(InteractionEventData event) {
        for (Binding binding : singleBindings) {
            if (binding.matcher().test(event)) {
                binding.action().accept(event);
                return true;
            }
        }
        return false;
    }
}
```

---

## 3. Wie sieht die Benutzung in der Praxis aus?

Nun können wir hochkomplexe Interaktionen wie das Ziehen eines **Selektionsrahmens** oder das **Verschieben von Elementen** extrem sauber als wiederverwendbare Klassen schreiben:

### Beispiel 1: Selektionsrahmen (Rubberband Selection)

```java
public class SelectionBoxDragHandler implements DragHandler {

    private final EditorContext context;
    private SelectionBoxOverlay selectionBox; // Visualisierung im Canvas

    public SelectionBoxDragHandler(EditorContext context) {
        this.context = context;
    }

    @Override
    public void onStart(InteractionEventData startEvent) {
        // Selektionsrahmen an der Klick-Position erzeugen
        selectionBox = context.showSelectionBox(startEvent.worldX(), startEvent.worldY());
    }

    @Override
    public void onDrag(InteractionEventData currentEvent, double deltaX, double deltaY) {
        // Größe des Rechtecks bei jeder Mausbewegung anpassen
        selectionBox.updateBounds(
            currentEvent.worldX(),
            currentEvent.worldY()
        );
    }

    @Override
    public void onEnd(InteractionEventData endEvent) {
        // Alle Elemente innerhalb des finalen Rechtecks auswählen
        context.selectElementsIn(selectionBox.getBounds());

        // Visualisierung entfernen
        selectionBox.remove();
    }
}
```

---

### Beispiel 2: Anbinden an den `SelectState`

Im Zustand `SelectState` verbindest du jetzt einfach deine Matcher mit den `DragHandler`n:

```java
public class SelectState implements EditorState {

    private final InteractionMap bindings;

    public SelectState(EditorContext context) {
        this.bindings = new InteractionMap()
            // 1. Drag mit Primärtaste auf freier Fläche -> Selektionsrahmen
            .onDrag(
                EventMatcher.primaryClick().and(data -> context.isHoveringEmptySpace(data)),
                () -> new SelectionBoxDragHandler(context)
            )

            // 2. Drag auf einem gewählten Element -> Elemente verschieben
            .onDrag(
                EventMatcher.primaryClick().and(data -> context.isHoveringSelectedNode(data)),
                () -> new MoveNodesDragHandler(context)
            )

            // 3. Mittlere Maustaste gedrückt halten + Drag -> Viewport Panning (Kamera verschieben)
            .onDrag(
                data -> data.isMiddleButtonDown(),
                () -> new PanViewportDragHandler(context)
            );
    }

    @Override
    public InteractionMap getInteractionMap() {
        return bindings;
    }
}
```

---

## 4. Wie der JavaFX-Event-Filter/Handler das ansteuert

In deiner JavaFX Canvas/View-Klasse reichst du die Drei-Phasen-Events einfach an den aktuellen State weiter:

```java
// Bei MOUSE_PRESSED
canvas.addEventFilter(MouseEvent.MOUSE_PRESSED, e -> {
    InteractionEventData data = InteractionEventData.from(e, viewport::screenToWorld);
    currentState.getInteractionMap().handlePress(data);
});

// Bei MOUSE_DRAGGED
canvas.addEventFilter(MouseEvent.MOUSE_DRAGGED, e -> {
    InteractionEventData data = InteractionEventData.from(e, viewport::screenToWorld);
    currentState.getInteractionMap().handleDrag(data);
});

// Bei MOUSE_RELEASED
canvas.addEventFilter(MouseEvent.MOUSE_RELEASED, e -> {
    InteractionEventData data = InteractionEventData.from(e, viewport::screenToWorld);
    currentState.getInteractionMap().handleRelease(data);
});
```

---

## Die Vorteile dieser Erweiterung

1. **State-Isolation:** Während ein Drag läuft (`activeDrag != null`), werden keine normalen Klicks versehentlich ausgelöst.
2. **Kapselung von Undo/Redo:** In `onEnd()` des `MoveNodesDragHandler`s kannst du genau **einen** Undo-Schritt aufzeichnen (statt für jedes kleine Pixel-Delta beim Draggen).
3. **Sehr hohe Wiederverwendbarkeit:** Ein `PanViewportDragHandler` (Kamera bewegen) kann problemlos in *allen* Zuständen wiederverwendet werden.

---

# you asked

message time: 2026-08-03 02:19:16

Zeige mir, wie die EditorContext-Klasse aufgebaut ist, die den aktuellen Zustand (EditorState) verwaltet und Events an ihn weiterleitet.

---

# gemini response

Die `EditorContext`-Klasse fungiert als das **Herzstück der State Machine** (Context im klassichen State Pattern) und gleichzeitig als Schnittstelle zwischen der UI (JavaFX) und deinem Anwendungsmodell (Domain Model/Graph/Canvas).

Sie erfüllt im Wesentlichen drei Aufgaben:
1. **Zustandsverwaltung:** Hält den aktuellen `EditorState` und regelt den sauberen Übergang (`switchState`).
2. **Event-Routing:** Reicht JavaFX-Events (Klicks, Drags, Tasten) an den aktiven Zustand weiter.
3. **Services/Modell bereitstellen:** Bietet den konkreten Zuständen und Drag-Handlern Zugriff auf die Kamera/Viewport, das Datenmodell und Auswahllisten (Selection).

---

### Die `EditorContext`-Klasse

```java
package de.fmc.editor.state;

import javafx.geometry.Point2D;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import java.util.Objects;
import java.util.function.BiFunction;

public class EditorContext {

    // Aktueller Zustand des Editors
    private EditorState currentState;

    // Transformation von Screen- zu Welt-Koordinaten (z. B. aus der Kamera/Viewport)
    private final BiFunction<Double, Double, Point2D> sceneToWorldTransformer;

    // Zugrundeliegendes Datenmodell & UI-Layer (Beispiele)
    private final DocumentModel documentModel;
    private final SelectionModel selectionModel;
    private final Viewport viewport;

    public EditorContext(
            EditorState initialState,
            Viewport viewport,
            DocumentModel documentModel,
            SelectionModel selectionModel
    ) {
        this.viewport = Objects.requireNonNull(viewport);
        this.sceneToWorldTransformer = viewport::screenToWorld;
        this.documentModel = Objects.requireNonNull(documentModel);
        this.selectionModel = Objects.requireNonNull(selectionModel);

        // Initialen Zustand setzen
        this.currentState = Objects.requireNonNull(initialState);
        this.currentState.onEnter();
    }

    // =========================================================================
    // 1. State Machine Management (Zustandswechsel)
    // =========================================================================

    /**
     * Wechselt den aktuellen Zustand des Editors.
     * Führt automatisch die Lifecycle-Methoden onExit() und onEnter() aus.
     */
    public synchronized void switchState(EditorState newState) {
        Objects.requireNonNull(newState, "New state cannot be null");

        if (this.currentState.equals(newState)) {
            return; // Kein Wechsel nötig
        }

        // Alter Zustand räumt auf (z.B. Hilfslinien oder Overlays entfernen)
        this.currentState.onExit();

        this.currentState = newState;

        // Neuer Zustand richtet sich ein
        this.currentState.onEnter();
    }

    public EditorState getCurrentState() {
        return currentState;
    }

    // =========================================================================
    // 2. Event Routing (Schnittstelle zu JavaFX)
    // =========================================================================

    /**
     * Reicht ein JavaFX Mouse-Pressed Event an den aktuellen Zustand weiter.
     */
    public boolean handleMousePressed(MouseEvent event) {
        InteractionEventData data = InteractionEventData.from(event, sceneToWorldTransformer);
        return currentState.getInteractionMap().handlePress(data);
    }

    /**
     * Reicht ein JavaFX Mouse-Dragged Event an den aktuellen Zustand weiter.
     */
    public boolean handleMouseDragged(MouseEvent event) {
        InteractionEventData data = InteractionEventData.from(event, sceneToWorldTransformer);
        return currentState.getInteractionMap().handleDrag(data);
    }

    /**
     * Reicht ein JavaFX Mouse-Released Event an den aktuellen Zustand weiter.
     */
    public boolean handleMouseReleased(MouseEvent event) {
        InteractionEventData data = InteractionEventData.from(event, sceneToWorldTransformer);
        return currentState.getInteractionMap().handleRelease(data);
    }

    /**
     * Reicht ein JavaFX Key-Pressed Event an den aktuellen Zustand weiter.
     */
    public boolean handleKeyPressed(KeyEvent event) {
        InteractionEventData data = InteractionEventData.from(event);
        return currentState.getInteractionMap().handlePress(data);
    }

    // =========================================================================
    // 3. Service-Methoden für States & DragHandler (API für Zustände)
    // =========================================================================

    public DocumentModel getDocumentModel() {
        return documentModel;
    }

    public SelectionModel getSelectionModel() {
        return selectionModel;
    }

    public Viewport getViewport() {
        return viewport;
    }

    // Nützliche Abfrage-Methoden für Matcher (z.B. Hovering-Checks)

    public boolean isHoveringEmptySpace(InteractionEventData event) {
        return documentModel.findNodeAt(event.worldX(), event.worldY()).isEmpty();
    }

    public boolean isHoveringSelectedNode(InteractionEventData event) {
        return documentModel.findNodeAt(event.worldX(), event.worldY())
                .map(selectionModel::isSelected)
                .orElse(false);
    }

    // High-Level Editor-Aktionen (Command-Aufrufe)

    public void selectAt(double worldX, double worldY) {
        documentModel.findNodeAt(worldX, worldY)
                .ifPresentOrElse(
                    selectionModel::select,
                    selectionModel::clearSelection
                );
    }

    public void spawnNodeAt(double worldX, double worldY) {
        NodeModel newNode = new NodeModel(worldX, worldY);
        documentModel.addNode(newNode);
        selectionModel.select(newNode);
    }
}
```

---

### Anbindung an die JavaFX View (z. B. Canvas Controller)

In deiner JavaFX-Anwendung (z. B. in einer `Controller`-Klasse oder einer benutzerdefinierten `Pane`) musst du den `EditorContext` jetzt nur noch an die Ereignisse deiner View binden:

```java
public class EditorCanvasController {

    private final Canvas canvas;
    private final EditorContext editorContext;

    public EditorCanvasController(Canvas canvas, Viewport viewport, DocumentModel model, SelectionModel selection) {
        this.canvas = canvas;

        // Initialen Zustand festlegen (z.B. SelectState)
        SelectState initialState = new SelectState(null); // Context wird nachfolgend injiziert
        this.editorContext = new EditorContext(initialState, viewport, model, selection);

        // Event Listener auf der JavaFX Pane/Canvas registrieren
        registerEventHandlers();
    }

    private void registerEventHandlers() {
        // Maus-Events
        canvas.addEventFilter(MouseEvent.MOUSE_PRESSED, editorContext::handleMousePressed);
        canvas.addEventFilter(MouseEvent.MOUSE_DRAGGED, editorContext::handleMouseDragged);
        canvas.addEventFilter(MouseEvent.MOUSE_RELEASED, editorContext::handleMouseReleased);

        // Tastatur-Events (auf der Szene oder dem fokussierten Node)
        canvas.setFocusTraversable(true);
        canvas.addEventFilter(KeyEvent.KEY_PRESSED, editorContext::handleKeyPressed);
    }
}
```

---

### Die Vorteile dieser Architektur auf einen Blick

1. **Säuberste Trennung (Decoupling):** Die JavaFX View weiß nichts von den Zuständen (z. B. `SelectState`, `CreateNodeState`). Sie leitet nur Events an den `EditorContext` weiter.
2. **Kapselung von Lifecycle-Logik:** Durch `onEnter()` und `onExit()` beim `switchState` kannst du Overlays (wie z. B. temporäre Platzierungs-Vorschauen) beim Verlassen eines Zustands automatisch aufräumen, ohne dass die View sich darum kümmern muss.
3. **Kein globales Singleton:** Der `EditorContext` wird injiziert. Dadurch sind deine Zustände und Interaktionen hervorragend mit Unit Tests testbar (du kannst z. B. Mock-Objects für den `Viewport` oder das `DocumentModel` übergeben).

---
Powered by [AI Exporter](https://saveai.net)
