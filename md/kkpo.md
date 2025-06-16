# Factory Methode in Interface

## Frage

> Wenn ich sowas sehe, wie

```java
@FunctionalInterface
public interface Validator<T> {

    Optional<String> validate(T t);

    static <T> Validator<T> of(Predicate<T> predicate, String errorMessage) {
        return t -> predicate.test(t) ? Optional.empty() : Optional.of(errorMessage);
    }
}
```
> ist die Methode of ein ersatz fuer den Konstruktor mit zwei Parametern?

## Antwort

Ja, genau — die Methode `of(...)` in deinem Beispiel dient als
**Factory-Methode** und ist in der Praxis ein **Ersatz für einen Konstruktor
mit zwei Parametern**.

### Warum so gemacht?

Da `Validator<T>` ein **Interface** ist (und kein konkreter Typ), kann es
**keinen Konstruktor** haben. Ein Interface kann jedoch **statische Methoden**
enthalten (seit Java 8), und diese werden häufig verwendet, um sogenannte
**Factory-Methoden** bereitzustellen – genau wie `of(...)` hier.

### Was passiert in `of(...)` genau?

```java
static <T> Validator<T> of(Predicate<T> predicate, String errorMessage) {
    return t -> predicate.test(t) ? Optional.empty() : Optional.of(errorMessage);
}
```

Diese Methode:
- nimmt ein Prädikat (Predicate<T>) und eine Fehlermeldung entgegen,
- erzeugt eine Instanz eines `Validator<T>` durch einen Lambda-Ausdruck (also
  eine Implementierung der `validate(...)`-Methode),
- und gibt diese Instanz zurück.

Das ist konzeptuell so, als würdest du folgendes machen, wenn `Validator` eine
Klasse wäre:

```java
new Validator<>(predicate, errorMessage);
```

Aber da `Validator` ein Interface mit nur einer abstrakten Methode ist (also
ein sogenanntes **Functional Interface**), kannst du mit einem Lambda arbeiten.

### Fazit

Ja, `of(...)` ist ein Factory-Methoden-Ersatz für einen Konstruktor. Es erzeugt
eine konkrete **Lambda-Implementierung** der `Validator<T>`-Schnittstelle mit
den angegebenen Parametern.
