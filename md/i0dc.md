# Either und Validators Integration

Ich hatte mit dir bei einer Diskussion ueber anwendung von flatMap bei der Either Klasse ein Beispiel bekommen die mir gut gefallen hat. Hier sind die Daten dazu:

```java
import java.io.FileWriter;
import java.io.IOException;

// Beispiel-Hilfsklassen für die Demonstration
class Either<L, R> {
    // ... Implementierung der Either-Klasse ...
}

// Simulations-Klasse für die Geschäftslogik
class BusinessService {

    // 1. Validieren der Eingabe
    public Either<String, String> validateInput(String input) {
        if (input == null || input.isEmpty()) {
            return Either.left("Eingabe darf nicht leer sein.");
        }
        return Either.right(input.trim());
    }

    // 2. Datenbankzugriff simulieren
    public Either<String, Integer> fetchFromDatabase(String username) {
        if ("admin".equals(username)) {
            return Either.right(12345); // Beispiel-ID
        }
        return Either.left("Benutzer '" + username + "' nicht gefunden.");
    }

    // 3. Daten verarbeiten
    public Either<String, String> processData(int dataId) {
        if (dataId % 2 != 0) {
            return Either.left("Datenverarbeitung fehlgeschlagen: Ungerade ID.");
        }
        return Either.right("Verarbeitete Daten für ID " + dataId);
    }

    // 4. In eine Datei schreiben (hier mit echtem Nebeneffekt)
    public Either<String, Void> writeToFile(String data) {
        try (FileWriter writer = new FileWriter("output.txt")) {
            writer.write(data);
            return Either.right(null); // 'Void' signalisiert den Erfolg ohne Wert
        } catch (IOException e) {
            return Either.left("Fehler beim Schreiben in die Datei: " + e.getMessage());
        }
    }
}

public class FlatMapSequenceExample {

    public static void main(String[] args) {
        BusinessService service = new BusinessService();
        String username = "admin";

        // Elegante Verkettung der Operationen
        Either<String, Void> result = service.validateInput(username)
            .flatMap(service::fetchFromDatabase)
            .flatMap(service::processData)
            .flatMap(service::writeToFile);

        // Prüfung des Endergebnisses
        result.match(
            error -> System.out.println("Prozess fehlgeschlagen: " + error),
            success -> System.out.println("Prozess erfolgreich abgeschlossen.")
        );
    }
}
```
und
```java
import java.util.List;
import java.util.stream.Collectors;

// Hier muss die Either-Klasse und der BusinessService von oben vorhanden sein

public class EitherStreamProcessing {

    private final BusinessService service = new BusinessService();

    // Kapseln der sequenziellen Verarbeitung in eine einzige Funktion
    public Either<String, Void> processUser(String username) {
        return service.validateInput(username)
            .flatMap(service::fetchFromDatabase)
            .flatMap(service::processData)
            .flatMap(service::writeToFile);
    }

    public static void main(String[] args) {
        EitherStreamProcessing processor = new EitherStreamProcessing();
        List<String> usernames = List.of("admin", "guest", "user123");

        // Anwenden der Funktion auf den Stream
        List<Either<String, Void>> results = usernames.stream()
            .map(processor::processUser)
            .collect(Collectors.toList());

        // Auswertung der Ergebnisse
        System.out.println("--- Ergebnisse der Verarbeitung ---");
        results.forEach(either -> either.match(
            error -> System.out.println("❌ Fehler: " + error),
            success -> System.out.println("✅ Erfolg: Verarbeitung abgeschlossen.")
        ));
    }
}
```

Koennte man nicht bei der Validierung mit der Metode validateInput die Validators Klasse nutzen und dann bei der Auswertung des ValidationResults mit Either weiter arbeiten?

Sie möchten wissen, ob es möglich ist, die `Validators`-Klasse mit der `Either`-Klasse zu kombinieren, um die Eingangsvalidierung in Ihrer `BusinessService`-Klasse zu verbessern und die `flatMap`-Kette fortzusetzen.

Ja, das ist möglich. Die `ValidationResult` kann elegant in eine `Either`-Instanz umgewandelt werden, da beide Schnittstellen ähnliche Erfolg-/Fehler-Muster verwenden. Ein **erfolgreiches `ValidationResult`** wird in einen **`Either.Right`** umgewandelt und ein **fehlgeschlagenes `ValidationResult`** mit seinen Fehlern in einen **`Either.Left`**.

### Integration von `Validators` und `Either`

Um die beiden Konzepte zu verknüpfen, können Sie Ihre `validateInput`-Methode im `BusinessService` anpassen. Anstatt die Validierungslogik manuell zu implementieren, verwenden Sie einen `Validator` aus der `Validators`-Klasse. Hier ist ein Beispiel, wie die Methode aussehen könnte:

```java
import java.util.stream.Collectors;

// Die Either-Klasse und die Klassen aus dem Validator-Paket
// müssen hier verfügbar sein.

public class BusinessService {

    // 1. Validieren der Eingabe mit Validators-Klasse
    public Either<String, String> validateInput(String input) {
        // Erstellen Sie einen Validator für die Eingabe.
        // `notBlank` ist eine gute Wahl, da es sowohl null als auch leere Strings abfängt.
        var inputValidator = Validators.notBlank(s -> s, "Eingabe darf nicht leer sein.");

        // Führen Sie die Validierung aus.
        ValidationResult<String> validationResult = inputValidator.validate(input);

        // Transformieren Sie das ValidationResult in ein Either.
        // Bei Erfolg (`Success`) verwenden wir den Wert, 
        // bei Misserfolg (`Failure`) die gesammelten Fehlermeldungen.
        return validationResult.fold(
            errors -> Either.left(errors.stream().collect(Collectors.joining(", "))),
            value -> Either.right(value.trim())
        );
    }

    // 2. Datenbankzugriff simulieren
    public Either<String, Integer> fetchFromDatabase(String username) {
        if ("admin".equals(username)) {
            return Either.right(12345); // Beispiel-ID
        }
        return Either.left("Benutzer '" + username + "' nicht gefunden.");
    }

    // 3. Daten verarbeiten
    public Either<String, String> processData(int dataId) {
        if (dataId % 2 != 0) {
            return Either.left("Datenverarbeitung fehlgeschlagen: Ungerade ID.");
        }
        return Either.right("Verarbeitete Daten für ID " + dataId);
    }

    // 4. In eine Datei schreiben (hier mit echtem Nebeneffekt)
    public Either<String, Void> writeToFile(String data) {
        // ... Implementierung wie in Ihrem Beispiel ...
        return Either.right(null);
    }
}
```

-----

### Erläuterung der Umsetzung

Die Methode `validateInput` wurde umgestaltet, um die bereitgestellten Utility-Klassen zu nutzen:

1.  **Validator-Erstellung:** Sie verwenden `Validators.notBlank()`, einen statischen Hilfs-Validator, der prüft, ob eine Zeichenfolge nicht `null` oder leer ist.
2.  **Validierung:** Der erstellte `inputValidator` wird mit der Eingabe aufgerufen. Er gibt ein `ValidationResult<String>` zurück.
3.  **Transformation:** Die entscheidende Stelle ist die `fold`-Methode auf dem `ValidationResult`. Mit ihr können Sie das Ergebnis je nach Zustand (Erfolg oder Misserfolg) in einen anderen Typ umwandeln.
      * `validationResult.fold(...)`
      * **Fehlerfall (`errors`):** Wenn das `ValidationResult` ein `Failure` ist, enthält es eine Liste von Fehlermeldungen. Diese Liste wird zu einem einzigen String zusammengefügt, der dann in einen `Either.left` gekapselt wird.
      * **Erfolgsfall (`value`):** Wenn das `ValidationResult` ein `Success` ist, wird der enthaltene Wert zurückgegeben, der dann in einem `Either.right` gekapselt wird.

Durch diese Anpassung können Sie die mächtigen Werkzeuge der `Validators`-Klasse für die anfängliche Validierungslogik nutzen und nahtlos zur eleganten, sequenziellen Verarbeitung mit `flatMap` in der `Either`-Klasse übergehen.


