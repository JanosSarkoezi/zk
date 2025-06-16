# Java Stream Beispiele

## Frage

Hast du paar gute Anwendungen mit Streams in Java 21? Sozusagen Beispiele von
denen man lernen kann. :)

## Antwort


Na klar! Java Streams (seit Java 8, aber in Java 21 mit vielen Optimierungen)
sind ein mächtiges Tool zur Verarbeitung von Daten in einer funktionalen Art.
Hier sind einige **lehrreiche und praxisnahe Beispiele**, die verschiedene
Konzepte abdecken – von den Grundlagen bis zu etwas fortgeschritteneren
Anwendungen.

## 1. **Grundlegende Filter- und Map-Operationen**

### Beispiel: Namen in Großbuchstaben, die mit "A" beginnen

```java
List<String> names = List.of("Anna", "Bob", "Alex", "Charlie", "Albert");

List<String> result = names.stream()
    .filter(name -> name.startsWith("A"))
    .map(String::toUpperCase)
    .collect(Collectors.toList());

System.out.println(result); // [ANNA, ALEX, ALBERT]
```

## 2. **Gruppieren mit `Collectors.groupingBy`**

### Beispiel: Wörter nach ihrer Länge gruppieren

```java
List<String> words = List.of("apple", "banana", "cherry", "dog", "egg");

Map<Integer, List<String>> grouped = words.stream()
    .collect(Collectors.groupingBy(String::length));

System.out.println(grouped);
// z.B. {3=[dog, egg], 5=[apple], 6=[banana, cherry]}
```

## 3. **Summieren und Statistiken mit `Collectors.summarizingInt`**

### Beispiel: Durchschnittsalter berechnen

```java
record Person(String name, int age) {}

List<Person> people = List.of(
    new Person("Alice", 30),
    new Person("Bob", 25),
    new Person("Charlie", 35)
);

Double averageAge = people.stream()
    .collect(Collectors.averagingInt(Person::age));

System.out.println("Durchschnittsalter: " + averageAge);
```

## 4. **`flatMap` – z.B. für Listen von Listen**

### Beispiel: Alle Elemente aus verschachtelten Listen sammeln

```java
List<List<String>> nested = List.of(
    List.of("a", "b"),
    List.of("c", "d", "e"),
    List.of("f")
);

List<String> flattened = nested.stream()
    .flatMap(List::stream)
    .collect(Collectors.toList());

System.out.println(flattened); // [a, b, c, d, e, f]
```

## 5. **Advanced: Custom Collector für Zeichenhäufigkeit**

### Beispiel: Wie oft kommt jeder Buchstabe vor?

```java
String input = "hello world";

Map<Character, Long> frequency = input.chars()
    .filter(Character::isLetter)
    .mapToObj(c -> (char) c)
    .collect(Collectors.groupingBy(
        c -> c,
        Collectors.counting()
    ));

System.out.println(frequency); // z.B. {d=1, e=1, h=1, l=3, o=2, r=1, w=1}
```

## 6. **Performance-Tipp in Java 21: `toList()` statt `collect(Collectors.toList())`**

```java
List<String> uppercase = List.of("one", "two", "three").stream()
    .map(String::toUpperCase)
    .toList(); // seit Java 16+, empfohlen in Java 21

System.out.println(uppercase); // [ONE, TWO, THREE]
```

## 7. **Textanalyse aus Datei (Files.lines + Streams)**

### Beispiel: Die 10 häufigsten Wörter in einer Datei

```java
Path path = Path.of("example.txt");

Map<String, Long> wordFreq = Files.lines(path)
    .flatMap(line -> Arrays.stream(line.toLowerCase().split("\\W+")))
    .filter(word -> !word.isBlank())
    .collect(Collectors.groupingBy(
        Function.identity(), Collectors.counting()
    ));

wordFreq.entrySet().stream()
    .sorted(Map.Entry.<String, Long>comparingByValue().reversed())
    .limit(10)
    .forEach(entry -> 
        System.out.println(entry.getKey() + ": " + entry.getValue())
    );
```

## 8. **Mehrere Bedingungen + Optional**

### Beispiel: Erste Person über 30 finden

```java
Optional<Person> result = people.stream()
    .filter(p -> p.age() > 30)
    .findFirst();

result.ifPresent(System.out::println);
```

## Frage

Koenntest ud paar komplexere Beispile auch geben?

## Antwort


Sehr gerne! Hier sind **komplexere und realistischere Beispiele**, bei denen
Java Streams elegant eingesetzt werden, inklusive **verschachtelter Objekte**,
**Mehrfach-Gruppierung**, **Custom Collector** und ein bisschen
**Business-Logik**. Diese Beispiele eignen sich super zum Lernen, wie man
Streams auch in echten Projekten einsetzt.

## 1. **Mehrstufige Gruppierung: Personen nach Land und Alter**

### Szenario:

Du hast eine Liste von Personen, die nach **Land** und **Altersgruppe** gruppiert werden sollen.

```java
record Person(String name, String country, int age) {}

List<Person> people = List.of(
    new Person("Alice", "Germany", 25),
    new Person("Bob", "Germany", 34),
    new Person("Charlie", "Germany", 15),
    new Person("Dave", "USA", 42),
    new Person("Eve", "USA", 16)
);

Map<String, Map<String, List<Person>>> grouped = people.stream()
    .collect(Collectors.groupingBy(
        Person::country,
        Collectors.groupingBy(p -> {
            if (p.age() < 18) return "Minor";
            else if (p.age() < 35) return "Young Adult";
            else return "Adult";
        })
    ));

System.out.println(grouped);
```

## 2. **Benutzerdefinierter Collector: Top N häufigste Elemente**

### Szenario:

Du möchtest aus einer Liste von Wörtern die **Top-N häufigsten** berechnen.

```java
List<String> words = List.of("apple", "banana", "apple", "cherry", "banana", "banana");

Map<String, Long> freq = words.stream()
    .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

List<Map.Entry<String, Long>> top2 = freq.entrySet().stream()
    .sorted(Map.Entry.<String, Long>comparingByValue().reversed())
    .limit(2)
    .toList();

System.out.println(top2); // z.B. [banana=3, apple=2]
```

## 3. **CSV-Datei analysieren: Umsatz nach Kategorie summieren**

### Beispiel für Datenmodell:

```java
record Sale(String product, String category, double price) {}
```

```java
List<Sale> sales = List.of(
    new Sale("Laptop", "Electronics", 999.99),
    new Sale("Headphones", "Electronics", 199.99),
    new Sale("Banana", "Groceries", 0.99),
    new Sale("Apple", "Groceries", 1.29),
    new Sale("Desk", "Furniture", 149.99)
);

Map<String, Double> revenuePerCategory = sales.stream()
    .collect(Collectors.groupingBy(
        Sale::category,
        Collectors.summingDouble(Sale::price)
    ));

System.out.println(revenuePerCategory);
// z.B. {Electronics=1199.98, Groceries=2.28, Furniture=149.99}
```

## 4. **Transaktionen nach Monat gruppieren**

### Du willst alle Käufe nach **Monat** gruppieren – gutes Beispiel für `YearMonth` + Zeitverarbeitung.

```java
record Transaction(String user, double amount, LocalDate date) {}

List<Transaction> transactions = List.of(
    new Transaction("Alice", 200, LocalDate.of(2025, 1, 15)),
    new Transaction("Alice", 150, LocalDate.of(2025, 2, 10)),
    new Transaction("Bob", 100, LocalDate.of(2025, 1, 5))
);

Map<YearMonth, List<Transaction>> byMonth = transactions.stream()
    .collect(Collectors.groupingBy(tx -> YearMonth.from(tx.date())));

System.out.println(byMonth);
```

## 5. **Bedingte Aggregation: Summe von validen Transaktionen**

### Beispiel mit mehreren Filterbedingungen kombiniert

```java
double totalValid = transactions.stream()
    .filter(tx -> tx.amount() > 100)
    .filter(tx -> !tx.user().equals("Bob"))
    .mapToDouble(Transaction::amount)
    .sum();

System.out.println("Total valid amount: " + totalValid);
```

## 6. **Aggregation von verschachtelten Objekten: Firmen und Mitarbeiter**

### Gruppiere die Gehälter pro Firma.

```java
record Employee(String name, double salary) {}
record Company(String name, List<Employee> employees) {}

List<Company> companies = List.of(
    new Company("ACME", List.of(new Employee("Alice", 50000), new Employee("Bob", 60000))),
    new Company("Globex", List.of(new Employee("Charlie", 55000), new Employee("Dave", 65000)))
);

Map<String, Double> salaryPerCompany = companies.stream()
    .collect(Collectors.toMap(
        Company::name,
        c -> c.employees().stream().mapToDouble(Employee::salary).sum()
    ));

System.out.println(salaryPerCompany);
```

## 7. **Daten in ein eigenes DTO transformieren**

### Beispiel: Bestellstatistik in Reporting-Objekt umwandeln

```java
record Order(String product, int quantity, double unitPrice) {}
record ReportLine(String product, int totalQuantity, double totalRevenue) {}

List<Order> orders = List.of(
    new Order("Book", 2, 12.50),
    new Order("Book", 1, 12.50),
    new Order("Pen", 5, 1.20)
);

List<ReportLine> report = orders.stream()
    .collect(Collectors.groupingBy(Order::product))
    .entrySet().stream()
    .map(e -> {
        String product = e.getKey();
        int totalQty = e.getValue().stream().mapToInt(Order::quantity).sum();
        double totalRev = e.getValue().stream().mapToDouble(o -> o.quantity() * o.unitPrice()).sum();
        return new ReportLine(product, totalQty, totalRev);
    })
    .toList();

report.forEach(System.out::println);
```
