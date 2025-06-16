# Monade in Java

Eine Monade besteht aus:
- Einem Endofunktor T : C → C
- Einer natürlichen Transformation η : Id → T (Einheit)
- Einer natürlichen Transformation μ : T∘T → T (Multiplikation oder "join")

Und die Gesetze sehen so aus:
- Assoziativität: μ ∘ Tμ = μ ∘ μT
- Einheitsgesetze: μ ∘ Tη = μ ∘ ηT = id_T

```java
import java.util.function.Function;

class Value<U> {
    private final U value;

    public Value(U value) {
        this.value = value;
    }

    public U get() {
        return value;
    }

    // Functor map: U -> V wird zu Value<U> -> Value<V>
    public <V> Value<V> map(Function<? super U, ? extends V> f) {
        return new Value<>(f.apply(value));
    }

    // flatMap: bind, kombiniert map + join
    public <V> Value<V> flatMap(Function<? super U, Value<V>> f) {
        return f.apply(value);
    }

    // static unit (η): verpackt U in Value<U>
    public static <U> Value<U> of(U value) {
        return new Value<>(value);
    }

    // μ (join): verflacht Value<Value<U>> zu Value<U>
    public static <U> Value<U> join(Value<Value<U>> mmv) {
        return mmv.flatMap(x -> x);
    }

    @Override
    public String toString() {
        return "Value(" + value + ")";
    }
}
```

### Was passiert hier?
- `Value.of(...)` ist deine **unit** (η), verpackt einen Wert in `Value`.
- `map` transformiert den Wert im Container, ohne den Container zu verändern.
- `flatMap` bindet eine Funktion, die selbst `Value` zurückgibt, also mappt und
  verflacht in einem Schritt.
- join (μ) verflacht einen verschachtelten `Value<Value<U>>` Container.

## Frage

ok danke ... was habe ich gelernt:
- `map` braucht man um `Value<U>` als einen Funktor ansehen zu koennen
- `of` ist die Einheit der Monade
- `flatMap` ist eine Zusammenfassung von join und map: flatMap = join ∘ map
  richtig?

### Was du gelernt hast:
1. `map`
→ macht aus `Value<U>` einen **Functor**, weil du Funktionen U → V auf den
Inhalt anwenden kannst:
```java
<V> Value<V> map(Function<? super U, ? extends V>)
```
2. `of` (unit / η)
→ ist die Einheits-Transformation der Monade:
```java
static <U> Value<U> of(U value)
```
3. flatMap = join ∘ map
→ flatMap(f) kann man als:
```java
flatMap(f) = join(map(f))
```
lesen, d. h.:
- wende f: U → Value<V> an (ergibt Value<Value<V>>)
- dann verflache (join) → ergibt Value<V>

### Definition von `join`
join verflacht eine verschachtelte Struktur:
```
join: Value<Value<U>> → Value<U>
```

Du kannst es definieren einfach mit `flatMap` und `x -> x`, aber nur wenn
`flatMap` schon vorhanden ist. Da wir jetzt `flatMap` über `join` definieren
wollen, brauchen wir `join` als primitives Bauteil.

#### Implementierung von join in deiner Value<U>-Monade
```java
public static <U> Value<U> join(Value<Value<U>> mmv) {
    return mmv.get();  // gibt das innere Value<U> zurück
}
```

#### Danach kannst du flatMap wie geplant definieren:
```java
public <V> Value<V> flatMap(Function<? super U, Value<V>> f) {
    return join(this.map(f));
}
```

### Die drei Monadengesetze

1. Links-Identität
`of(x).flatMap(f) == f(x)`
```java
Value.of("x").flatMap(f) → f("x")  ✅
```
Das erfüllt deine Implementierung sofort, weil flatMap direkt f.apply(value) ist.

2. Rechts-Identität
`m.flatMap(of) == m`
```java
Value.of("x").flatMap(Value::of) // → Value.of("x")  ✅
```
Auch das erfüllt deine flatMap, da Value::of einfach den Wert neu einpackt – flatMap ändert nichts.

3. Assoziativität
`m.flatMap(f).flatMap(g) == m.flatMap(x -> f(x).flatMap(g))`

Das ist der knifflige Teil, aber auch das erfüllt dein `flatMap`, wenn du es
korrekt über join(map(f)) definierst — oder direkt so wie bisher:
```java
public <V> Value<V> flatMap(Function<? super U, Value<V>> f) {
    return f.apply(value);
}
```
Das funktioniert, weil `flatMap` direkt das nächste monadische Ergebnis übernimmt
und keine zusätzliche Struktur entstehen lässt.


Jawoll! Jetzt tauchst du richtig tief in die **kategorientheoretische Struktur
der Monade** ein — und ja, du hast absolut recht: **$T\mu$** und **$\mu T$**
sind Kompositionen von **einem Funktor** mit **einer natürlichen
Transformation**. 👏

Lass uns das klar und langsam aufbauen:

---

## Grundlegend: Was ist $\mu$?

* $\mu$ ist eine **natürliche Transformation** $\mu : T^2 \Rightarrow T$, also von $T \circ T$ zu $T$
* Konkret: Sie „verflacht“ ein zweifach verschachteltes `T`:

  * z. B. `Value<Value<U>> → Value<U>`

---

## Jetzt kommt die Magie: $T\mu$ und $\mu T$

Beides sind **natürliche Transformationen**, die durch Komposition mit dem Funktor $T$ entstehen:

---

### $T\mu$

* Das bedeutet: **erst `T`, dann `μ`**

* Typ:

  $$
  T\mu : T^3 \Rightarrow T^2
  $$

* In Java-artiger Denkweise:

  ```java
  // Value<Value<Value<U>>> → Value<Value<U>>
  Tμ = value -> value.map(inner -> μ(inner))
       = value.map(inner -> inner.get())
  ```

* Du wendest `μ` auf das **Innere** an, bleibst aber im äußeren `T`.

---

### $\mu T$

* Das bedeutet: **erst `μ`, dann nochmal `T`**

* Typ:

  $$
  \mu T : T^3 \Rightarrow T^2
  $$

* In Java-artiger Form:

  ```java
  // Value<Value<Value<U>>> → Value<Value<U>>
  μT = value -> μ(value.map(x -> x))
       = value.get().map(x -> x)
  ```

* Du „verflachst“ die **äußere Ebene** zuerst, bleibst aber in `T`.

---

## Warum das wichtig ist:

Die **Assoziativität der Monade** sagt:

$$
\mu \circ T\mu = \mu \circ \mu T
$$

Typisch:

$$
T^3 \xrightarrow{T\mu} T^2 \xrightarrow{\mu} T \quad = \quad T^3 \xrightarrow{\mu T} T^2 \xrightarrow{\mu} T
$$

Das heißt:

* Egal, ob du **zuerst innen oder außen verflachst** – am Ende kommst du bei demselben `T` heraus.
* Das ist die **Verallgemeinerung von Klammerassoziativität** in kategorientheoretischem Stil!

---

## Denkhilfe:

In Java:

```java
// Tμ
Value<Value<Value<U>>> triple = ...;
Value<Value<U>> left = triple.map(inner -> inner.get()); // Tμ

// μT
Value<Value<U>> right = triple.get().map(x -> x);        // μT

// μ(Tμ(...)) == μ(μT(...)) → Value<U>
Value<U> result1 = left.get();
Value<U> result2 = right.get();
```

---

## ✅ Zusammenfassung:

| Symbol                             | Typ           | Bedeutung                            |
| ---------------------------------- | ------------- | ------------------------------------ |
| $T\mu$                             | $T^3 \to T^2$ | `map(μ)` — verflache innen           |
| $\mu T$                            | $T^3 \to T^2$ | `μ` nach `map(id)` — verflache außen |
| $\mu \circ T\mu = \mu \circ \mu T$ | $T^3 \to T$   | **Assoziativität**                   |

