# Lambda-Ausdrücke in Java: Verschachtelung & Übergabe

## Frage

Lass uns etwas rumspielen mit Lambda Ausdruecken (LA) in Java 21. 
- Kann ich einem LA ein anderes LA uebergeben?
- Kann ein LA ein anderes LA enthalten?

## Antwort

Hallo! Das sind sehr gute Fragen, die den Kern von funktionaler Programmierung
in Java treffen. Die Antwort ist in beiden Fällen ein klares **Ja**.

### Lambda-Ausdrücke als Parameter

Du kannst einem Lambda-Ausdruck einen anderen Lambda-Ausdruck übergeben, weil
Lambda-Ausdrücke in Java letztlich als Instanzen von **funktionalen
Interfaces** behandelt werden. Ein funktionales Interface ist ein Interface mit
genau einer abstrakten Methode.

Wenn du einen Lambda-Ausdruck übergeben möchtest, definierst du einfach einen
Parameter in deinem funktionalen Interface, dessen Typ ebenfalls ein
funktionales Interface ist.

Hier ist ein einfaches Beispiel:

Stellen wir uns vor, wir haben ein Interface `Operation`, das eine Ganzzahl mit
einer anderen Ganzzahl verarbeitet:

```java
@FunctionalInterface
interface Operation {
    int apply(int a, int b);
}
```

Jetzt erstellen wir ein weiteres Interface `ComplexOperation`, dessen Methode
eine Zahl und eine `Operation` als Parameter akzeptiert:

```java
@FunctionalInterface
interface ComplexOperation {
    int perform(int value, Operation op);
}
```

Mit diesen beiden Interfaces können wir jetzt einen Lambda-Ausdruck schreiben,
der einen anderen Lambda-Ausdruck als Argument nimmt:

```java
public class Main {
    public static void main(String[] args) {
        // Ein Lambda-Ausdruck, der zwei Zahlen addiert
        Operation add = (x, y) -> x + y;

        // Ein Lambda-Ausdruck, der eine Zahl mit einer Operation verarbeitet
        ComplexOperation processor = (val, op) -> op.apply(val, 10);

        // Wir übergeben den "add"-Lambda-Ausdruck an den "processor"-Lambda-Ausdruck
        int result = processor.perform(5, add);
        System.out.println("Resultat: " + result); // Output: Resultat: 15
    }
}
```

In diesem Beispiel wird der `processor`-Lambda-Ausdruck mit `(5, add)`
aufgerufen. Hier ist `add` ein Lambda-Ausdruck, der dem funktionalen Interface
`Operation` entspricht.

### Ein Lambda-Ausdruck, der einen anderen Lambda-Ausdruck enthält

Ein Lambda-Ausdruck kann auch einen anderen Lambda-Ausdruck im Body enthalten.
Das ist im Grunde genommen eine ganz normale Sache. Der "innere"
Lambda-Ausdruck wird dann als lokale Variable definiert und kann innerhalb des
"äußeren" Lambda-Ausdrucks verwendet werden.

Hier ist ein Beispiel, das auf den obigen Interfaces aufbaut:

```java
public class Main {
    public static void main(String[] args) {
        // Ein Lambda-Ausdruck, der die Addition durchführt und 
        // dann das Ergebnis mit einem anderen internen Lambda-Ausdruck multipliziert
        Operation calculator = (x, y) -> {
            // Interner Lambda-Ausdruck
            Operation multiply = (a, b) -> a * b;

            // Verwendung des internen Lambdas
            int sum = x + y;
            return multiply.apply(sum, 2);
        };

        int finalResult = calculator.apply(10, 5);
        System.out.println("Finales Resultat: " + finalResult); // Output: Finales Resultat: 30
    }
}
```

In diesem Code-Schnipsel siehst du, wie der äußere Lambda-Ausdruck
(`calculator`) einen internen Lambda-Ausdruck (`multiply`) definiert und diesen
dann im Body verwendet. Das zeigt sehr schön, wie Lambda-Ausdrücke flexibel und
ineinander verschachtelt verwendet werden können, was die funktionale
Programmierung in Java so mächtig macht.
