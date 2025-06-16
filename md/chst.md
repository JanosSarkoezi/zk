# Schöne Optional Anwendungen

## Frage

> Kannst du mit in Java 21 paar schoene Anwendungen von Optional zeigen?

## Antwort


Klar! In Java 21 ist Optional nach wie vor ein sehr nützliches Werkzeug, um mit
potenziell null-Werten sauber und funktional umzugehen. Ich zeige dir ein paar
praktische und "schöne" Anwendungen, die idiomatisch und elegant sind.

## 1. Optional mit map und flatMap zum sicheren Zugriff

```java
public class User {
    private String name;
    private Address address;

    // Konstruktor, Getter...
}

public class Address {
    private String city;

    // Konstruktor, Getter...
}

// Zugriff auf Stadtname, ohne NullPointerException:
Optional<User> optionalUser = Optional.ofNullable(getUser());

String city = optionalUser
    .map(User::getAddress)
    .map(Address::getCity)
    .orElse("Unbekannt");
```

✅ Vorteil: Kein explizites Null-Checking nötig, kurze und lesbare Kette.

## 2. Optional mit filter für Validierung

```java
Optional<String> maybeEmail = Optional.of("test@example.com");

maybeEmail
    .filter(email -> email.contains("@"))
    .ifPresentOrElse(
        System.out::println,
        () -> System.out.println("Ungültige E-Mail")
    );
```

✅ Vorteil: Funktionaler Stil für Validierungen, ohne if-Blöcke.

## 3. Optional als Rückgabewert in Repository-Pattern

```java
public interface UserRepository {
    Optional<User> findById(String id);
}

// Nutzung:
userRepository.findById("abc123")
    .ifPresentOrElse(
        user -> System.out.println("Name: " + user.getName()),
        () -> System.out.println("Benutzer nicht gefunden")
    );
```

✅ Vorteil: Zwingt den Aufrufer dazu, sich mit der Möglichkeit von Abwesenheit auseinanderzusetzen.

## 4. Optional mit or und orElseGet für Fallbacks

```java
Optional<String> maybeUsername = Optional.empty();

String username = maybeUsername
    .or(() -> Optional.of("StandardUser"))
    .get();

System.out.println(username); // "StandardUser"
```

Oder Lazy-Alternative mit orElseGet:

```java
String user = maybeUsername.orElseGet(() -> fetchDefaultUsername());
```

✅ Vorteil: Fallback-Werte klar deklarativ definieren, lazy wenn nötig.

## 5. Optional mit Streams kombinieren (ab Java 9)

```java
List<Optional<String>> optionalNames = List.of(
    Optional.of("Alice"),
    Optional.empty(),
    Optional.of("Bob")
);

List<String> names = optionalNames.stream()
    .flatMap(Optional::stream)
    .toList();

System.out.println(names); // ["Alice", "Bob"]
```

### Was macht Optional::stream?

Seit Java 9 hat Optional<T> eine Methode:

```java
public Stream<T> stream()
```

Diese Methode:
- Gibt einen Stream mit **0 oder 1 Element** zurück:
  - Wenn Optional leer ist → Stream.empty()
  - Wenn ein Wert da ist → Stream.of(value)

### Wie wirkt `flatMap(Optional::stream)`?

Wenn du so etwas hast:
```java
Stream<Optional<T>> → flatMap(Optional::stream) → Stream<T>
```
… dann bedeutet das:
- **Alle leeren Optionals** werden **herausgefiltert**, weil
  `Optional.empty().stream()` nichts liefert.
- **Alle vorhandenen Werte** werden **"ausgepackt"**, also zu einem normalen
  Stream zusammengefügt.

### Warum nicht einfach map?

Wenn du map(Optional::get) machen würdest:
```java
optionalNames.stream()
    .map(Optional::get)
    .toList();
```

Dann würdest du bei leeren Optionals eine `NoSuchElementException` bekommen.
Deshalb ist `flatMap(Optional::stream)` der sichere, funktionale Weg, um **nur
die vorhandenen Werte** zu extrahieren.

### Optional mit Konvertirung von String zu Boolean 

```java
Optional.ofNullable(attributeValue)
            .map(Boolean::parseBoolean)
            .map(isTrue -> isTrue ? handleTrueCase() : handleFalseCase())
            .orElseGet(this::handleNullCase);
```
