# Funktionales Visitor Pattern in Java

## Frage

Wie sehe das Visitor Design Pattern in Java aus, wenn man funktional
programmieren moechte?

## Antwort

Visitor Design Pattern in Java lässt sich funktional mithilfe von **Java 8
Lambdas und der `Function` Schnittstelle** umsetzen. Anstatt für jeden
Besuchertyp eine eigene Klasse zu erstellen, können die spezifischen Aktionen
direkt als Funktionen definiert und in einem Map gespeichert werden.

### Traditioneller Visitor im Vergleich zur funktionalen Umsetzung

#### Traditioneller Ansatz 🏛️

Im traditionellen Visitor Pattern implementiert man das `Visitor` Interface für
jeden Besuchertyp. Jede konkrete Klasse (z.B. `ElementA`, `ElementB`) hat eine
`accept()` Methode, die den entsprechenden `visit()` Aufruf des Besuchers
entgegennimmt.

  - **Vorteile:** Klare Trennung von Algorithmus und Objektstruktur. Einfache
    Erweiterung um neue Operationen.
  - **Nachteile:** Um eine neue Operation hinzuzufügen, müssen alle
    Visitor-Implementierungen geändert werden. Neue Elemente erfordern Änderungen
    in allen Visitor-Klassen.

### Funktionaler Ansatz 👩‍💻

Der funktionale Ansatz nutzt die Stärken von Java 8, um den Boilerplate-Code zu reduzieren und das Muster flexibler zu gestalten.

#### 1. Die `Element` Schnittstelle

Zuerst definieren wir die `Element` Schnittstelle. Anstatt eine `accept()` Methode zu haben, die eine `Visitor` Instanz annimmt, definieren wir eine Methode, die eine Funktion entgegennimmt.

```java
// Der funktionale 'Visitor'
@FunctionalInterface
interface Function<T, R> {
    R apply(T t);
}

// Das 'Element' Interface
public interface Element {
    <R> R accept(Function<Element, R> visitor);
}
```

#### 2. Konkrete `Element` Klassen

Die konkreten `Element` Klassen implementieren die `accept()` Methode, die einfach die übergebene Funktion auf sich selbst anwendet.

```java
public class ElementA implements Element {
    public <R> R accept(Function<Element, R> visitor) {
        return visitor.apply(this);
    }
}

public class ElementB implements Element {
    public <R> R accept(Function<Element, R> visitor) {
        return visitor.apply(this);
    }
}
```

#### 3. Erstellen der "Besucher"-Logik

Die Logik für die verschiedenen Elemente wird nicht in Klassen, sondern als **Lambdas** definiert. Wir können eine `Map` verwenden, um die verschiedenen Funktionen basierend auf dem Typ des Elements zu speichern.

```java
import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;

public class FunctionalVisitor {
    private final Map<Class<?>, Function<Object, ?>> visitors = new HashMap<>();

    public <T, R> void register(Class<T> type, Function<T, R> visitor) {
        visitors.put(type, (Function<Object, ?>) visitor);
    }

    public <R> R visit(Element element) {
        Function<Object, ?> visitor = visitors.get(element.getClass());
        if (visitor != null) {
            return (R) visitor.apply(element);
        }
        throw new IllegalArgumentException("No visitor registered for type: " + element.getClass());
    }
}
```

#### 4. Anwendung 🚀

Die Anwendung ist viel schlanker. Wir erstellen eine Instanz des `FunctionalVisitor`, registrieren die Lambdas und rufen die `visit()` Methode auf.

```java
public class Main {
    public static void main(String[] args) {
        FunctionalVisitor visitor = new FunctionalVisitor();

        // Registrieren der Logik als Lambdas
        visitor.register(ElementA.class, (ElementA a) -> {
            System.out.println("Visiting ElementA");
            return "Result from ElementA";
        });

        visitor.register(ElementB.class, (ElementB b) -> {
            System.out.println("Visiting ElementB");
            return "Result from ElementB";
        });

        Element elementA = new ElementA();
        Element elementB = new ElementB();

        String resultA = visitor.visit(elementA); // Output: Visiting ElementA
        String resultB = visitor.visit(elementB); // Output: Visiting ElementB

        System.out.println(resultA); // Output: Result from ElementA
        System.out.println(resultB); // Output: Result from ElementB
    }
}
```

**Vorteile des funktionalen Ansatzes:**

  - **Weniger Boilerplate-Code:** Es müssen keine separaten Visitor-Klassen
    mehr erstellt werden.
  - **Höhere Flexibilität:** Die Logik kann zur Laufzeit dynamisch hinzugefügt
    oder entfernt werden.
  - **Einfachere Erweiterung:** Neue "Besucher"-Logik lässt sich durch das
    Hinzufügen einer Lambda-Funktion registrieren, ohne bestehende Klassen ändern
    zu müssen.

## Frage

Diese Methode wuerde auch bei einem Compositum funktionieren? Wenn also das
Compositum eine Liste von Kindern hat?

## Antwort

Ja, der funktionale Ansatz funktioniert auch sehr gut mit dem Composite Design
Pattern. Sie können die Methode `accept` des Composite-Objekts so
implementieren, dass es die übergebene Funktion rekursiv auf alle seine
Kind-Elemente anwendet.

### Implementierung im Composite

Um dies zu verdeutlichen, nehmen wir an, dass `Composite` eine Liste von `Element`-Objekten enthält. Die `accept`-Methode im `Composite` würde dann folgendermaßen aussehen:

```java
import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

// Das 'Composite' Element
public class Composite implements Element {
    private List<Element> children = new ArrayList<>();

    public void add(Element element) {
        children.add(element);
    }

    @Override
    public <R> R accept(Function<Element, R> visitor) {
        for (Element child : children) {
            child.accept(visitor);
        }
        // Das Composite-Objekt selbst kann auch verarbeitet werden,
        // oder Sie geben null, einen leeren Wert oder das Ergebnis einer Aggregation zurück.
        return null;
    }
}
```

In diesem Beispiel durchläuft die `accept`-Methode des `Composite` jedes
Kind-Element und ruft dessen eigene `accept`-Methode auf, der wiederum der
gleiche funktionale "Visitor" übergeben wird. Die Verarbeitung der einzelnen
Blätter (z.B. `ElementA`, `ElementB`) und der Composite-Knoten erfolgt dann wie
zuvor über die registrierten Lambdas im `FunctionalVisitor`.

### Anwendung im Composite-Kontext

Wenn Sie das `Composite`-Objekt mit diesem funktionalen Visitor verwenden, sähe der Code wie folgt aus:

```java
// ... (bestehende FunctionalVisitor und Element Klassen)

public class Main {
    public static void main(String[] args) {
        FunctionalVisitor visitor = new FunctionalVisitor();

        visitor.register(ElementA.class, (ElementA a) -> {
            System.out.println("Visiting Leaf ElementA");
            return null;
        });

        visitor.register(ElementB.class, (ElementB b) -> {
            System.out.println("Visiting Leaf ElementB");
            return null;
        });

        // Erstellen der Baumstruktur
        Composite composite1 = new Composite();
        composite1.add(new ElementA());
        composite1.add(new ElementB());

        Composite composite2 = new Composite();
        composite2.add(new ElementA());
        composite2.add(composite1);

        // Besucher auf den obersten Knoten anwenden
        composite2.accept(visitor::visit);
    }
}
```

Die `visitor::visit` Methode ist eine Methodenreferenz, die als Lambda-Funktion
an die `accept`-Methode übergeben wird. Wenn Sie das Programm ausführen, wird
die Besucherlogik für jedes Blatt-Element im Baum ausgeführt, obwohl Sie nur
den obersten `Composite`-Knoten besucht haben.
