# Erklärung des Builder Patterns

## Frage

> Ich habe eine krasse Klasse gefunden:
```java
// Abstrakter Builder
public class Builder<T, B extends Builder<T, B>> {
    protected final T instance;

    public Builder(Supplier<T> supplier) {
        instance = supplier.get();
    }

    public <U> B with(BiConsumer<T, U> setter, U value) {
        setter.accept(instance, value);
        return self();
    }

    protected B self() {
        return (B) this;
    }

    public T build() {
        return instance;
    }
}
```
> speziell ist Zeile `public class Builder<T, B extends Builder<T, B>>` schwer
> zu verstehen. Koenntest du mit diese Zeile erklaeren? Danke dir.

## Antwort

Ja, klar! Diese Zeile ist ein klassisches Beispiel für ein **generisches
Fluent-Builder-Pattern mit rekursiver Typbindung**. Das sieht erstmal
kompliziert aus, aber ich erkläre es Schritt für Schritt:

```java
public class Builder<T, B extends Builder<T, B>>
```

Hier passiert Folgendes:

## 1. Generische Typen `T` und `B`

- `T`: Das ist der Typ des Objekts, das am Ende gebaut werden soll (z. B. eine `Person`, `Car`, etc.).
- `B`: Das ist der Typ des konkreten Builders (also eine Subklasse von `Builder<T, B>`).

## 2. `B extends Builder<T, B>` – Rekursive Typbindung


Dieser Teil ist das wirklich Interessante – und Komplizierte:

  `B` ist ein Typ, der **selbst ein** `Builder<T, B>` **ist**.

Das nennt man "Recursive Type Bound" oder auch Curiously Recurring Template
Pattern (CRTP). Es sorgt dafür, dass Methoden im Builder (wie .with(...)) **den
richtigen Rückgabetyp haben**, auch wenn man Unterklassen erstellt.

## Beispiel: Subklasse des Builders

Nehmen wir an, du hast eine Klasse `Person` und einen konkreten
`PersonBuilder`, der von `Builder` erbt:

```java
public class Person {
    private String name;
    private int age;

    public void setName(String name) { this.name = name; }
    public void setAge(int age) { this.age = age; }
}

public class PersonBuilder extends Builder<Person, PersonBuilder> {
    public PersonBuilder() {
        super(Person::new);
    }
}
```

Weil PersonBuilder den Typ B = PersonBuilder angibt, funktioniert das:

```java
Person person = new PersonBuilder()
    .with(Person::setName, "Alice")
    .with(Person::setAge, 30)
    .build();
```

➡️ Ohne diese rekursive Typbindung würden die `.with(...)`-Aufrufe nicht
korrekt typisiert sein (sie würden nur `Builder` zurückgeben, nicht
`PersonBuilder`), was die Fluent API (Kettenaufrufe) kaputt machen würde.

### Warum macht man das so?

Damit jede Unterklasse von `Builder` beim `with(...)`-Aufruf **ihren eigenen
Typ zurückbekommt**, statt einfach nur `Builder` – für **sauberes
Method-Chaining**.

### Kurz gesagt:

```java
public class Builder<T, B extends Builder<T, B>>
```

bedeutet:
„Ich bin ein generischer Builder für `T`, und meine Unterklasse `B` muss mich
**selbst korrekt typisieren**, damit method chaining richtig funktioniert.“

## Frage

> OK. Das ist schon eine sehr beeindrukende Idee. Brauchen wir die self Methode?

## Antwort

Super Frage!
Und ja – die `self()`-Methode ist **essentiell**, damit das Ganze funktioniert.
Lass mich erklären **warum**:

### Was macht `self()`?

```java
protected B self() {
    return (B) this;
}
```

Diese Methode **castet** `this` **auf den konkreten Typ** `B`, also auf die
tatsächliche Unterklasse des Builders.

### Warum brauchen wir das?

In Java gibt dir `this` immer den aktuellen Typ, aber **aus Sicht der
Oberklasse** (also `Builder<T, B>`), ist `this` nur vom Typ `Builder<T, B>`
und Nicht vom Typ `B`.

Aber der Rückgabetyp von `.with(...)` ist `B`, damit method chaining
funktioniert:

```java
return self();  // liefert B zurück
```

Wenn wir einfach return `this`; schreiben würden, dann wäre der Rückgabetyp
`Builder<T, B>` – was nicht ganz das ist, was du brauchst, wenn du
`PersonBuilder` verwendest.

### Was passiert, wenn du self() weglässt?

Wenn du stattdessen in `.with(...)` einfach das hier machst:

```java
return this; // ← Rückgabetyp ist Builder<T, B>
```

…dann **kompiliert es zwar**, aber:

```java
PersonBuilder builder = new PersonBuilder()
    .with(...)  // Rückgabetyp ist nur Builder<Person, PersonBuilder>
    .with(...); // ← Kein Zugriff mehr auf Methoden von PersonBuilder
```

➡️ Du verlierst die Möglichkeit, Builder-Methoden deiner konkreten Subklasse zu
nutzen. Das Fluent-Interface **bricht zusammen**.

### Fazit:

✅ Ja, die `self()`-Methode ist notwendig, damit:
- der Rückgabetyp korrekt auf die Subklasse zeigt (`B`),
- method chaining elegant funktioniert,
- und du Erweiterungen in konkreten Builder-Klassen (wie `PersonBuilder`)
  sinnvoll nutzen kannst.

