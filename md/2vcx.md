# Java Methodenreferenzen vs. Kategorientheorie-Exponentiale

## Frage

Sind Methoden-Referenzen in Java das Aequivalete zu exponentials in
Kategorietheorie?

## Antwort

Das ist eine interessante und tiefgründige Frage, die Aspekte aus der
Programmierung und der Kategorientheorie miteinander verbindet.

Zunächst eine kurze Antwort: **Nein, Methodenreferenzen in Java sind nicht das
Äquivalent zu Exponentialen in der Kategorientheorie.**

Beide Konzepte haben zwar mit Funktionen und Abbildungen zu tun, aber sie
operieren auf sehr unterschiedlichen Abstraktionsebenen und haben verschiedene
Zwecke.

### Was sind Methodenreferenzen in Java?

Eine **Methodenreferenz** in Java ist syntaktischer Zucker, der die Übergabe
von Lambda-Ausdrücken vereinfacht. Sie bietet eine kompakte Schreibweise, um
auf eine bereits existierende Methode zu verweisen. Der Ausdruck
`Person::getAge` ist zum Beispiel nur eine Kurzform für den Lambda-Ausdruck `p
-> p.getAge()`. Er verweist also auf eine Funktion, die einen `Person`-Objekt
als Eingabe nimmt und dessen Alter zurückgibt.

Ihr Hauptzweck ist die Verbesserung der Lesbarkeit und die Vereinfachung des
Codes. Sie sind eine praktische Funktion, die es uns erlaubt, Methoden als
Argumente an andere Methoden zu übergeben, solange die Signatur der
referenzierten Methode mit dem funktionalen Interface übereinstimmt.

### Was sind Exponentiale in der Kategorientheorie?

In der **Kategorientheorie** sind **Exponentiale** (oder **exponentielle
Objekte**) ein sehr viel abstrakteres Konzept. Sie treten in kartesisch
abgeschlossenen Kategorien (cartesian closed categories, kurz CCC) auf. Eine
Kategorie ist eine CCC, wenn sie endliche Produkte hat und zu je zwei Objekten
$B$ und $C$ ein Objekt $C^B$ existiert. Dieses Objekt $C^B$ repräsentiert die
"Funktionen" von $B$ nach $C$.

Die universelle Eigenschaft von Exponentialen besagt, dass für jedes Objekt $A$
ein Isomorphismus existiert:

$$\text{Hom}(A \times B, C) \cong \text{Hom}(A, C^B)$$

Dieser Isomorphismus wird als **Curry-Hom-Adjunktion** bezeichnet. Er stellt
eine kanonische Beziehung her zwischen Morphismen (Abbildungen) von einem
Produktobjekt $A \times B$ nach $C$ und Morphismen von $A$ nach dem
Exponentialobjekt $C^B$.

### Der entscheidende Unterschied

Der Kernunterschied liegt in der **Abstraktionsebene** und der **fundamentalen
Eigenschaft**:

- **Methodenreferenzen** sind ein **syntaktisches Werkzeug** in einer konkreten
Programmiersprache. Sie sind eine Möglichkeit, über bestehende Funktionen zu
sprechen, aber sie definieren keine neue mathematische Struktur oder
Eigenschaft auf der Ebene des Typsystems. Sie beziehen sich auf die konkrete
Implementierung von Abbildungen.

- **Exponentiale** sind ein **fundamentales, strukturelles Konzept** in der
Kategorientheorie. Sie definieren eine grundlegende Beziehung zwischen Objekten
(Typen) und Morphismen (Funktionen) in einer Kategorie. Sie sagen aus, dass es
eine kanonische Möglichkeit gibt, eine Funktion mit zwei Argumenten (z. B. eine
Funktion von $A \times B$ nach $C$) in eine Funktion mit einem Argument zu
"curryfizieren", die eine Funktion zurückgibt (z. B. eine Funktion von $A$ nach
$C^B$). Die Existenz dieses Exponentialobjekts $C^B$ ist eine *Eigenschaft* der
Kategorie selbst.

In Programmiersprachen, die Funktionen als Objekte erster Klasse behandeln (wie
Haskell, aber auch in Java durch funktionale Interfaces), kann man eine
Analogie zur Curry-Hom-Adjunktion herstellen. Die "Curry-Funktion" würde eine
Funktion `f: (A, B) -> C` in eine Funktion `curried_f: A -> (B -> C)`
umwandeln. In diesem Kontext entspricht `B -> C` dem kategorientheoretischen
Exponentialobjekt $C^B$.

Methodenreferenzen in Java hingegen sind lediglich ein einfacher Verweis auf
eine bereits existierende Methode. Sie sind das syntaktische Werkzeug, das es
uns erlaubt, diese Funktionalität (die Übergabe von Funktionen als Argumente)
zu nutzen. Sie sind nicht das Konzept der "Funktions-zu-Funktions-Typen"
selbst, sondern nur ein Weg, um darauf zu verweisen.

Zusammenfassend lässt sich sagen: Die Kategorientheorie definiert die
mathematische Grundlage, warum Konzepte wie die Curry-Hom-Adjunktion überhaupt
existieren und welche Eigenschaften sie haben. Methodenreferenzen in Java sind
lediglich eine praktische Implementation auf der syntaktischen Ebene, die uns
hilft, diese Konzepte in unserem Code zu verwenden.
