# Validator Klasse mit Builder

## 1. Functional Validator Interface

```java
import java.util.Optional;
import java.util.function.Predicate;

@FunctionalInterface
public interface Validator<T> {

    Optional<String> validate(T t);

    static <T> Validator<T> of(Predicate<T> predicate, String errorMessage) {
        return t -> predicate.test(t) ? Optional.empty() : Optional.of(errorMessage);
    }

    default Validator<T> and(Validator<T> other) {
        return t -> {
            Optional<String> error = this.validate(t);
            return error.isPresent() ? error : other.validate(t);
        };
    }

    default Validator<T> or(Validator<T> other) {
        return t -> {
            Optional<String> error = this.validate(t);
            return error.isEmpty() ? Optional.empty() : other.validate(t);
        };
    }

    default Validator<T> not(String errorMessage) {
        return t -> {
            Optional<String> error = this.validate(t);
            return error.isEmpty() ? Optional.of(errorMessage) : Optional.empty();
        };
    }
}
```

## 2. ValidatingBuilder mit Validator-Liste

### ValidatorBuilder

```java
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.function.BiConsumer;
import java.util.function.Supplier;

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

## 3. ValidationResult & ValidationException

### ValidationException

```java
import java.util.List;

public class ValidationException extends RuntimeException {
    private final List<String> errors;

    public ValidationException(List<String> errors) {
        super("Validation failed: " + String.join("; ", errors));
        this.errors = errors;
    }

    public List<String> getErrors() {
        return errors;
    }
}
```

### ValidationResult

```java
import java.util.List;
import java.util.Optional;

public class ValidationResult<T> {
    private final T result;
    private final List<String> errors;

    public ValidationResult(T result, List<String> errors) {
        this.result = result;
        this.errors = errors;
    }

    public boolean isValid() {
        return errors.isEmpty();
    }

    public T getResult() {
        return result;
    }

    public List<String> getErrors() {
        return errors;
    }
}
```

## 4. Beispiel für die Nutzung

```java
ValidatingBuilder<Person> builder = new ValidatingBuilder<>(Person::new)
    .with(Person::setName, "Alice")
    .with(Person::setAge, 25)
    .withValidator(Validator.of(p -> p.getName() != null && !p.getName().isEmpty(), "Name darf nicht leer sein"))
    .withValidator(Validator.of(p -> p.getAge() != null && p.getAge() >= 18, "Alter muss mindestens 18 sein"));

ValidationResult<Person> result = builder.buildResult();

if (result.isValid()) {
    Person person = result.getResult();
    // Person verwenden
} else {
    result.getErrors().forEach(System.out::println);
}
```

Oder mit Exception:

```java
OptionalParameters params = builder.build();  // wirft ValidationException bei Fehlern
```

## Vorteile dieser Lösung

- **Klare Trennung**: Validatoren kapseln Validierungslogik als funktionale Einheiten.
- **Flexibel**: Validatoren können beliebig komplex sein.
- **Wiederverwendbar**: Validatoren können mehrfach verwendet oder kombiniert werden.
- **Fluent API**: Schöne, lesbare Syntax.
