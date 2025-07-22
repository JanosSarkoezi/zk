# Java's FlatMap: Functional Bind Analogy

## Frage

Was ist das alalogon von bind in Java 21 Funktional Programmierung?

## Antwort

Um Ihre Frage zu beantworten, gibt es in der funktionalen Programmierung (und
damit auch in Java 21) keine direkte, *eingebaute* Funktion, die "zwei
Ausgänge" im herkömmlichen Sinne hat, wie man es vielleicht aus anderen
Paradigmen (z.B. C mit `out`-Parametern oder Rückgabe von mehreren Werten per
Referenz) kennt.

**Warum "zwei Ausgänge" in Java funktional schwierig sind:**

Funktionen in der funktionalen Programmierung sind typischerweise so
konzipiert, dass sie **genau einen Rückgabewert** haben. Dies ist ein
Grundprinzip, das die Vorhersagbarkeit und Testbarkeit von Funktionen erhöht.
Eine Funktion, die basierend auf einer Eingabe *entweder* den einen *oder* den
anderen Wert zurückgibt, aber nicht beide gleichzeitig, ist der Normalfall.
Wenn sie *beide* Werte gleichzeitig zurückgeben müsste, bräuchte man eine
Struktur, die beide Werte enthält.

**Wie man das in Java 21 funktional umsetzen kann (Analoga):**

Sie beschreiben eine Situation, in der Sie eine Eingabe haben und basierend
darauf entweder einen "positiven" oder einen "negativen" Fall unterscheiden
möchten. Dies lässt sich in Java 21 auf verschiedene funktionale Weisen elegant
lösen:

1.  **Rückgabe eines `Pair` (oder einer ähnlichen Tupel-Struktur):** Wenn Sie
    *tatsächlich beide* Ergebnisse (positiv und negativ) gleichzeitig haben
    möchten, dann ist der Rückgabewert eine Datenstruktur, die beide Ergebnisse
    enthält. Java hat keine eingebaute `Pair`-Klasse im Core JDK, aber viele
    Bibliotheken bieten diese an (z.B. `org.apache.commons.lang3.tuple.Pair` oder
    Spring Data `Pair`). Sie könnten auch eine einfache eigene Klasse erstellen.

      * **Vorteil:** Klarer, dass beide Ergebnisse berechnet werden und
        verfügbar sind.
      * **Nachteil:** Muss nicht immer der Fall sein, dass beide gleichzeitig
        gebraucht werden.

```java
import java.util.Objects;
import java.util.function.Function;

// Eigene Pair-Klasse (oder aus einer Bibliothek)
class ResultPair<P, N> {
    private final P positiveResult;
    private final N negativeResult;

    public ResultPair(P positiveResult, N negativeResult) {
        this.positiveResult = positiveResult;
        this.negativeResult = negativeResult;
    }

    public P getPositiveResult() { return positiveResult; }
    public N getNegativeResult() { return negativeResult; }

    @Override
    public String toString() {
        return "ResultPair{" +
               "positiveResult=" + positiveResult +
               ", negativeResult=" + negativeResult +
               '}';
    }
}

public class TwoOutputFunction {

    // Funktion, die eine Zahl nimmt und ein ResultPair zurückgibt
    public static Function<Integer, ResultPair<String, String>> processNumber() {
        return number -> {
            String positiveCase = "Positive Result: " + (number * 2);
            String negativeCase = "Negative Result: " + (number - 10);
            return new ResultPair<>(positiveCase, negativeCase);
        };
    }

    public static void main(String[] args) {
        Function<Integer, ResultPair<String, String>> processor = processNumber();

        ResultPair<String, String> result1 = processor.apply(5);
        System.out.println(result1.getPositiveResult()); // Positive Result: 10
        System.out.println(result1.getNegativeResult()); // Negative Result: -5

        ResultPair<String, String> result2 = processor.apply(-3);
        System.out.println(result2.getPositiveResult()); // Positive Result: -6
        System.out.println(result2.getNegativeResult()); // Negative Result: -13
    }
}
```

2.  **Rückgabe eines `Either` (oder einer `Sealed Class` für discriminated
    unions):** Wenn Sie sagen, "der eine Ausgang ist der positive Fall und der
    andere Ausgang der negative Fall", klingt das eher danach, dass nur *einer* der
    beiden Fälle zutrifft. Hierfür ist das `Either`-Muster ideal. Eine `Either<L,
    R>`-Struktur repräsentiert einen Wert, der entweder vom Typ `L` (links) *oder*
    vom Typ `R` (rechts) ist, aber niemals beides. Konventionell steht "Left" oft
    für einen Fehler oder negativen Fall und "Right" für einen Erfolg oder
    positiven Fall. Java hat keine eingebaute `Either`-Klasse, aber viele
    Bibliotheken (z.B. Vavr, Arrow) bieten sie an. Sie können es auch mit Java 17+
    Sealed Classes selbst implementieren.

      * **Vorteil:** Semantisch sehr klar, dass nur einer von zwei Zuständen vorliegt.
      * **Nachteil:** Benötigt eine externe Bibliothek oder eigene Implementierung.

    **Beispiel mit `Either` (konzeptuell, da keine eingebaute Klasse):**

```java
// Repräsentation einer 'Either'-Struktur (konzeptionell)
// In der Realität würde man eine Bibliothek wie Vavr nutzen
sealed interface Either<L, R> {
    record Left<L, R>(L value) implements Either<L, R> {}
    record Right<L, R>(R value) implements Either<L, R> {}

    // Hilfsmethoden für Pattern Matching oder Verarbeitung
    default <T> T fold(Function<L, T> ifLeft, Function<R, T> ifRight) {
        if (this instanceof Left<L, R> left) {
            return ifLeft.apply(left.value());
        } else if (this instanceof Right<L, R> right) {
            return ifRight.apply(right.value());
        }
        throw new IllegalStateException("Unknown Either type");
    }
}

public class OneInputTwoCases {

    // Funktion, die einen Integer nimmt und entweder ein String für den Positivfall
    // oder einen String für den Negativfall zurückgibt.
    public static Function<Integer, Either<String, String>> processBasedOnCondition() {
        return number -> {
            if (number >= 0) {
                return new Either.Right<>("Positive Fall: " + (number * 2));
            } else {
                return new Either.Left<>("Negativer Fall: " + (number - 5));
            }
        };
    }

    public static void main(String[] args) {
        Function<Integer, Either<String, String>> processor = processBasedOnCondition();

        Either<String, String> result1 = processor.apply(5);
        result1.fold(
            left -> { System.out.println(left); return null; },
            right -> { System.out.println(right); return null; }
        ); // Positive Fall: 10

        Either<String, String> result2 = processor.apply(-3);
        result2.fold(
            left -> { System.out.println(left); return null; },
            right -> { System.out.println(right); return null; }
        ); // Negativer Fall: -8
    }
}
```

3.  **Rückgabe einer `Map`:** Obwohl nicht so typisch funktional für diesen
    Anwendungsfall, könnten Sie eine `Map` zurückgeben, die die Ergebnisse für
    "positive" und "negative" Schlüssel enthält. Dies ist flexibel, aber weniger
    typsicher als eine `Pair`-Klasse.

```java
import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;

public class MapOutputFunction {

    public static Function<Integer, Map<String, String>> processNumberToMap() {
        return number -> {
            Map<String, String> results = new HashMap<>();
            results.put("positiveCase", "Positive Result: " + (number * 2));
            results.put("negativeCase", "Negative Result: " + (number - 10));
            return results;
        };
    }

    public static void main(String[] args) {
        Function<Integer, Map<String, String>> processor = processNumberToMap();

        Map<String, String> result = processor.apply(5);
        System.out.println(result.get("positiveCase"));
        System.out.println(result.get("negativeCase"));
    }
}
```

**Die Transformation zu "zwei Ein- und Ausgängen":**

Wenn Sie eine Funktion haben, die intern beide Ergebnisse berechnet (positive
und negative Fälle) und diese in einer `Pair`-Struktur zurückgibt (wie in
Option 1), dann können Sie diese Funktion als die "Funktion mit einem Eingang
und zwei Ausgängen" betrachten.

Wenn Sie nun diese Ergebnisse weiterverarbeiten möchten, um eine "Funktion mit
zwei Ein- und Ausgängen" zu erhalten, bedeutet das, dass Sie eine Funktion
hätten, die:

  * Die positiven und negativen Ergebnisse der ersten Funktion als Eingabe nimmt.
  * Zwei neue Ergebnisse (oder eine neue Paare von Ergebnissen) basierend auf diesen Eingaben erzeugt.

Dies wäre dann einfach eine Funktion, die ein `ResultPair` (von der ersten
Funktion) als Eingabe nimmt und ein *neues* `ResultPair` zurückgibt.

**Beispiel für die Transformation:**

Nehmen wir die `processNumber` Funktion von oben, die ein `ResultPair<String, String>` zurückgibt.

```java
import java.util.Objects;
import java.util.function.Function;

// Eigene Pair-Klasse (wie oben)
class ResultPair<P, N> {
    private final P positiveResult;
    private final N negativeResult;

    public ResultPair(P positiveResult, N negativeResult) {
        this.positiveResult = positiveResult;
        this.negativeResult = negativeResult;
    }

    public P getPositiveResult() { return positiveResult; }
    public N getNegativeResult() { return negativeResult; }

    @Override
    public String toString() {
        return "ResultPair{" +
               "positiveResult=" + positiveResult +
               ", negativeResult=" + negativeResult +
               '}';
    }
}

public class FunctionTransformation {

    // Funktion mit einem Eingang und "zwei Ausgängen" (simuliert durch ResultPair)
    public static Function<Integer, ResultPair<String, String>> initialProcessor() {
        return number -> {
            String positiveCase = "Initial Positive: " + (number * 2);
            String negativeCase = "Initial Negative: " + (number - 10);
            return new ResultPair<>(positiveCase, negativeCase);
        };
    }

    // Funktion, die zwei Eingaben (aus dem ResultPair) nimmt und "zwei Ausgänge" (ein neues ResultPair) erzeugt
    public static Function<ResultPair<String, String>, ResultPair<String, String>> transformProcessor() {
        return initialResults -> {
            String newPositive = "Transformed Positive: " + initialResults.getPositiveResult().toUpperCase();
            String newNegative = "Transformed Negative: " + initialResults.getNegativeResult().toLowerCase();
            return new ResultPair<>(newPositive, newNegative);
        };
    }

    public static void main(String[] args) {
        // Die erste Funktion
        Function<Integer, ResultPair<String, String>> stage1 = initialProcessor();

        // Die zweite Funktion (nimmt das Ergebnis der ersten als Eingabe)
        Function<ResultPair<String, String>, ResultPair<String, String>> stage2 = transformProcessor();

        // Verkettung der Funktionen (compose wäre auch möglich, je nach Reihenfolge)
        // Hier: int -> ResultPair -> ResultPair
        Function<Integer, ResultPair<String, String>> combinedFunction = stage1.andThen(stage2);

        ResultPair<String, String> finalResult = combinedFunction.apply(5);
        System.out.println(finalResult);
        // Output: ResultPair{positiveResult=Transformed Positive: INITIAL POSITIVE: 10, negativeResult=Transformed Negative: initial negative: -5}
    }
}
```

**Zusammenfassend:**

In Java 21 und der funktionalen Programmierung werden "mehrere Ausgänge" einer
Funktion typischerweise durch die Rückgabe einer einzelnen Datenstruktur (wie
`Pair`, `Either` oder ein benutzerdefiniertes Record/Klasse) simuliert, die
alle benötigten Ergebniswerte enthält. Die "Transformation" zu einer Funktion
mit zwei Ein- und Ausgängen würde dann bedeuten, dass die nachfolgende Funktion
diese Ergebnisstruktur als ihre einzelne Eingabe nimmt und wiederum eine
(potenziell neue) Ergebnisstruktur als ihren einzelnen Ausgang zurückgibt.
