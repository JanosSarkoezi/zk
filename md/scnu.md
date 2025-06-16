# Untitled

## Frage

Wenn ich die Klasse 
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

habe und moechte die Klasse 

```java
public class ValidatingBuilder<T> {
    private final T instance;
    private final List<Validator<T>> validators = new ArrayList<>();

    public ValidatingBuilder(Supplier<T> supplier) {
        this.instance = supplier.get();
    }

    public <V> ValidatingBuilder<T> with(BiConsumer<T, V> setter, V value) {
        setter.accept(instance, value);
        return this;
    }

    public ValidatingBuilder<T> withValidator(Validator<T> validator) {
        validators.add(validator);
        return this;
    }

    public List<String> validate() {
        List<String> errors = new ArrayList<>();
        for (Validator<T> validator : validators) {
            validator.validate(instance).ifPresent(errors::add);
        }
        return errors;
    }

    public ValidationResult<T> buildResult() {
        List<String> errors = validate();
        return new ValidationResult<>(instance, errors);
    }

    public T build() {
        List<String> errors = validate();
        if (!errors.isEmpty()) {
            throw new ValidationException(errors);
        }
        return instance;
    }
}
```
als Unterklasse von Builder haben, wie sehe das aus?

## Antwort

Die Klasse `ValidatingBuilder<T>` kann nicht direkt eine Unterklasse von
`Builder<T, B>` sein, ohne **die Generik** von Builder **entsprechend
anzupassen**, denn:

- `Builder<T, B>` verwendet ein rekursives Generik-Muster (auch bekannt als
  Curiously Recurring Template Pattern, CRTP), was bedeutet, dass Unterklassen
  den zweiten Typparameter (B) korrekt spezifizieren müssen, um Typ-Sicherheit
  bei Methoden wie `with(...)` und `self()` zu gewährleisten.
- Außerdem hat `ValidatingBuilder` zusätzliche Funktionalität (`Validator<T>`,
  `validate()`, etc.), die nicht in `Builder` vorgesehen ist.

## Ziel: `ValidatingBuilder` als Unterklasse von `Builder`

Du möchtest etwas wie:

```java
public class ValidatingBuilder<T> extends Builder<T, ValidatingBuilder<T>> {
    ...
}
```

Das ist **möglich**, aber du musst die Vererbung korrekt umsetzen. Außerdem
musst du `with(...)`, `self()` und den Konstruktor eventuell überschreiben oder
erweitern.

## Lösung: ValidatingBuilder erweitert Builder

```java
public class ValidatingBuilder<T> extends Builder<T, ValidatingBuilder<T>> {
    private final List<Validator<T>> validators = new ArrayList<>();

    public ValidatingBuilder(Supplier<T> supplier) {
        super(supplier);
    }

    public ValidatingBuilder<T> withValidator(Validator<T> validator) {
        validators.add(validator);
        return this;
    }

    public List<String> validate() {
        List<String> errors = new ArrayList<>();
        for (Validator<T> validator : validators) {
            validator.validate(instance).ifPresent(errors::add);
        }
        return errors;
    }

    public ValidationResult<T> buildResult() {
        List<String> errors = validate();
        return new ValidationResult<>(instance, errors);
    }

    @Override
    public T build() {
        List<String> errors = validate();
        if (!errors.isEmpty()) {
            throw new ValidationException(errors);
        }
        return super.build();
    }

    @Override
    protected ValidatingBuilder<T> self() {
        return this;
    }
}
```

## Beispielnutzung

```java
Person person = new ValidatingBuilder<>(Person::new)
    .with(Person::setName, "Alice")
    .with(Person::setAge, 25)
    .withValidator(p -> p.getAge() < 0 ? Optional.of("Age must be non-negative") : Optional.empty())
    .build(); // validiert automatisch
```

## Wichtiges zur Typstruktur

- `ValidatingBuilder<T>` erweitert `Builder<T, ValidatingBuilder<T>>` → das ist
  nötig, damit `with(...)` weiterhin korrekt `ValidatingBuilder<T>` zurückliefert
  (Fluent Interface).
- Die Methode `self()` muss überschrieben werden, um den korrekten Typ zu liefern.
- Wenn du zusätzliche Methoden in ValidatingBuilder einführst, brauchst du
  `with(...)` nicht neu zu definieren – du erbst sie.

## Frage

> muss die methode `self()` der Klasse ValidatorBuilder kein Cast vornehmen,
> damit das Fluent-Pattern funktioniert?

## Antowrt

Gute Frage! Bei der Methode `self()` in der `ValidatingBuilder`-Klasse, die von
`Builder<T, B>` erbt und `self()` überschreibt, ist kein Cast nötig, wenn sie
so definiert ist:

```java
@Override
protected ValidatingBuilder<T> self() {
    return this;
}
```

### Warum?

- In der Basisklasse `Builder<T, B>` ist `self()` so definiert:
  ```java
  protected B self() {
      return (B) this;  // hier ist ein Cast nötig, weil `this` noch vom Typ Builder ist
  }
  ```
- In der Unterklasse `ValidatingBuilder<T>` erweitern wir `Builder<T,
  ValidatingBuilder<T>>`, also ist der Typ `B = ValidatingBuilder<T>`. Innerhalb
  von `ValidatingBuilder` ist this schon vom Typ `ValidatingBuilder<T>`, daher
  ist:
  ```java
  protected ValidatingBuilder<T> self() {
      return this;
  }
  ```
  **einfach korrekt**, da keine Typkonvertierung nötig ist.

### Zusammenfassung:

- **In der Basisklasse**: Ein Cast (B) this ist nötig, weil Builder nicht weiß,
  welcher konkrete Subtyp B ist.
- **In der Subklasse**: Kein Cast, weil this bereits den richtigen Typ hat.

Falls du `self()` **nicht** überschreibst, wird der Basisklassen-Cast
verwendet, der aber normalerweise funktioniert — allerdings ist das
Überschreiben sauberer und vermeidet mögliche `ClassCastException`, wenn das
Pattern richtig eingesetzt wird.
