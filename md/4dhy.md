# Either und Collections

Basierend auf dem bereitgestellten Code und den gängigen Mustern der funktionalen Programmierung, könnten `collectAll` und eine erweiterte `filter` Methode für die `Either` Klasse wie folgt aussehen:

### `collectAll` Methode

Die Methode `collectAll` würde einen `Collector` für Java Streams implementieren, um eine Liste von `Either`-Instanzen zu verarbeiten. Anstatt nur den ersten Fehler zurückzugeben, würde dieser Collector alle Fehler sammeln.

```java
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collector;

public interface Either<L, R> {
    // ... bestehende Methoden ...

    /**
     * Sammelt eine Liste von Either-Instanzen in einem einzigen Either-Objekt.
     * Wenn alle Elemente Right sind, wird ein Right mit der Liste der Werte zurückgegeben.
     * Wenn mindestens ein Left vorhanden ist, wird ein Left zurückgegeben, das eine Liste aller Fehler enthält.
     *
     * @param <L> Der Typ des linken (Fehler-) Wertes.
     * @param <R> Der Typ des rechten (Erfolgs-) Wertes.
     * @return Ein Collector, der die Transformation durchführt.
     */
    static <L, R> Collector<Either<L, R>, ?, Either<List<L>, List<R>>> collectAll() {
        return Collector.of(
            EitherCollectorState::new,
            EitherCollectorState::add,
            EitherCollectorState::combine,
            EitherCollectorState::finish
        );
    }

    class EitherCollectorState<L, R> {
        private final List<L> errors = new ArrayList<>();
        private final List<R> values = new ArrayList<>();

        public void add(Either<L, R> either) {
            either.match(errors::add, values::add);
        }

        public EitherCollectorState<L, R> combine(EitherCollectorState<L, R> other) {
            this.errors.addAll(other.errors);
            this.values.addAll(other.values);
            return this;
        }

        public Either<List<L>, List<R>> finish() {
            if (errors.isEmpty()) {
                return Either.right(values);
            } else {
                return Either.left(errors);
            }
        }
    }
}
```

**Verwendung:**
Diese `collectAll`-Methode wäre ideal für die Validierung mehrerer Eingaben in einem Stream, da sie alle Fehler anzeigt, anstatt nur den ersten.

```java
List<String> rawData = List.of("10", "20", "-5", "abc");
Either<List<String>, List<Integer>> result = rawData.stream()
    .map(s -> {
        try {
            int num = Integer.parseInt(s);
            return num < 0 ? Either.left("Zahl ist negativ: " + num) : Either.right(num);
        } catch (NumberFormatException e) {
            return Either.left("Keine gültige Zahl: " + s);
        }
    })
    .collect(Either.collectAll());

result.match(
    errors -> System.out.println("Es sind folgende Fehler aufgetreten: " + errors),
    numbers -> System.out.println("Alle Werte sind gültig: " + numbers)
);
// Ausgabe: Es sind folgende Fehler aufgetreten: [Zahl ist negativ: -5, Keine gültige Zahl: abc]
```
