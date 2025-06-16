# Funktionales Dekorator Pattern

## Frage

Wie sehe das Dekorator Design Pattern in Java aus, wenn man funktional
programmieren moechte?

## Antwort

Okay, lass uns das **Decorator Pattern** einmal funktional in Java denken.

In der objektorientierten Variante ist der Dekorator meistens eine eigene
Klasse, die dasselbe Interface implementiert wie das „dekorierte“ Objekt und es
intern hält. In der **funktionalen Programmierung** wollen wir stattdessen
**Funktionen** als Bausteine verwenden, die sich leicht kombinieren lassen —
oft mit **Lambda-Ausdrücken** und **Function**-Interfaces.

## 1. Klassisches OO-Dekorator-Pattern (nur zur Erinnerung)

```java
interface TextProcessor {
    String process(String input);
}

class BaseProcessor implements TextProcessor {
    public String process(String input) {
        return input;
    }
}

class UppercaseDecorator implements TextProcessor {
    private final TextProcessor inner;

    public UppercaseDecorator(TextProcessor inner) {
        this.inner = inner;
    }

    public String process(String input) {
        return inner.process(input).toUpperCase();
    }
}
```

Das ist sehr Boilerplate-lastig.

## 2. Funktionale Variante mit `Function<T, R>`

Hier nutzen wir **höhere Ordnungsfunktionen** zum Dekorieren.

```java
import java.util.function.Function;

public class FunctionalDecorator {
    public static void main(String[] args) {
        // Basisfunktion
        Function<String, String> baseProcessor = text -> text;

        // Dekoratoren als Funktionen
        Function<String, String> toUpperCase = s -> s.toUpperCase();
        Function<String, String> addExclamation = s -> s + "!";
        Function<String, String> trimSpaces = String::trim;

        // Dekorieren durch Function#andThen oder compose
        Function<String, String> decorated =
                baseProcessor
                    .andThen(trimSpaces)
                    .andThen(toUpperCase)
                    .andThen(addExclamation);

        System.out.println(decorated.apply("   hallo welt   "));
        // Ausgabe: HALLO WELT!
    }
}
```

Mermaid-Sequence-Diagramm

```sh
sequenceDiagram
    participant main as main
    participant base as baseProcessor
    participant trim as trimSpaces
    participant upper as toUpperCase
    participant exclam as addExclamation
    
    main->>base: andThen(trim)
    base-->>main: returns new function (func1)
    main->>func1: andThen(upper)
    func1-->>main: returns new function (func2)
    main->>func2: andThen(exclam)
    func2-->>main: returns final function (decorated)
    
    Note right of main: Jetzt wird der String verarbeitet
    
    main->>decorated: apply("   hello   ")
    decorated->>base: apply("   hello   ")
    base-->>decorated: returns "   hello   "
    decorated->>trim: apply("   hello   ")
    trim-->>decorated: returns "hello"
    decorated->>upper: apply("hello")
    upper-->>decorated: returns "HELLO"
    decorated->>exclam: apply("HELLO")
    exclam-->>decorated: returns "HELLO!"

    main->>System.out.println: print("HELLO!")
```

**Warum ist das funktional?**

* Wir haben keine zusätzlichen Klassen für jeden Dekorator.
* Dekoration ist nur eine **Funktionskomposition**.
* Das Dekorieren ist **dynamisch** (zur Laufzeit einfach durch `.andThen()` oder `.compose()` zusammensteckbar).

## 3. Mit generischen Higher-Order-Decorator-Funktionen

Man kann auch Dekoratoren als **Funktion-von-Funktionen** definieren:

```java
import java.util.function.Function;

public class HigherOrderDecorator {
    public static void main(String[] args) {
        // Higher-order Decorator
        Function<Function<String, String>, Function<String, String>> upperCaseDecorator =
                (func) -> (input) -> func.apply(input).toUpperCase();

        Function<Function<String, String>, Function<String, String>> trimDecorator =
                (func) -> (input) -> func.apply(input).trim();

        // Basis
        Function<String, String> base = s -> s;

        // Verkettung
        Function<String, String> decorated = 
                upperCaseDecorator
                    .andThen(trimDecorator)
                    .apply(base);

        System.out.println(decorated.apply("   hallo funktional   "));
        // Ausgabe: HALLO FUNKTIONAL
    }
}
```

Mermaid-Sequence-Diagramm

```sh
sequenceDiagram
    participant main as main
    participant UCD as upperCaseDecorator
    participant TD as trimDecorator
    participant base as base function

    main->>UCD: apply(base)
    UCD-->>main: returns new function (func1)
    main->>TD: apply(func1)
    TD-->>main: returns new function (decorated)
    main->>decorated: apply("   hallo funktional   ")
    decorated->>TD: called with "   hallo funktional   "
    TD->>UCD: apply("   hallo funktional   ")
    UCD->>base: apply("   hallo funktional   ")
    base-->>UCD: returns "   hallo funktional   "
    UCD->>UCD: toUpperCase()
    UCD-->>TD: returns "   HALLO FUNKTIONAL   "
    TD->>TD: trim()
    TD-->>main: returns "HALLO FUNKTIONAL"
    main->>System.out.println: print("HALLO FUNKTIONAL")
```

Das sieht schon sehr nach der **funktionalen Entsprechung des OO-Decorators**
aus:

* Jeder "Decorator" ist eine Funktion, die eine Funktion nimmt und eine neue
  Funktion zurückgibt.
* Wir behalten die Flexibilität des OO-Patterns, aber mit deutlich weniger
  Code.

**Kurz gesagt:**
In funktionalem Java wird das Decorator-Pattern meist als
**Funktionskomposition** oder **Higher-Order Function** umgesetzt, statt durch
Vererbung und Wrapper-Objekte.
