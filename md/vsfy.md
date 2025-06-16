# Wahrscheinlichkeit gleicher Karten bei vier Spielern

Angenommen es gibt vier Spieler, die jeweils zehn Karten in der Hand halten.
Alle haben die gleichen Karten. Wie gross ist die Warscheinlichkeit das zwei
Spieler die gleichen Karten ziehen? Sie Ziehen die Karten aus ihren eigenem
Deck.

Das ist ein spannendes Gedankenexperiment zur Kombinatorik! Wenn jeder Spieler
das **exakt gleiche Deck** vor sich liegen hat und jeder daraus eine Karte
zieht, betrachten wir im Grunde vier unabhängige Zufallsexperimente.

Um die Wahrscheinlichkeit zu berechnen, dass **mindestens zwei** Spieler die
gleiche Karte ziehen, ist es am einfachsten, über das **Gegenereignis** zu
gehen: Wie hoch ist die Wahrscheinlichkeit, dass alle vier Spieler
**unterschiedliche** Karten ziehen?

### Die Berechnung Schritt für Schritt

1. **Anzahl der Möglichkeiten insgesamt:**
Jeder der 4 Spieler hat 10 Optionen. Die Gesamtzahl der Kombinationen ist:
$10 \times 10 \times 10 \times 10 = 10^4 = 10.000$

2. **Anzahl der günstigen Fälle (alle ziehen unterschiedlich):**
* Spieler 1 kann jede der **10** Karten ziehen.
* Spieler 2 muss eine andere Karte ziehen (**9** Möglichkeiten).
* Spieler 3 muss wieder eine andere ziehen (**8** Möglichkeiten).
* Spieler 4 zieht eine der verbleibenden (**7** Möglichkeiten).


Rechnung: $10 \times 9 \times 8 \times 7 = 5.040$
3. **Wahrscheinlichkeit für "alle unterschiedlich":**

$$P(\text{alle verschieden}) = \frac{5.040}{10.000} = 0,504 \text{ (oder 50,4 \%)}$$

4. **Wahrscheinlichkeit für "mindestens zwei gleiche":**
Man zieht das Ergebnis von 1 (100 %) ab:

$$P(\text{mindestens zwei gleich}) = 1 - 0,504 = 0,496$$

---

### Das Ergebnis

Die Wahrscheinlichkeit, dass mindestens zwei Spieler die gleiche Karte ziehen,
liegt bei **49,6 %**.

Das ist fast so wahrscheinlich wie ein Münzwurf! Dieses Phänomen ist eng
verwandt mit dem bekannten **Geburtstagsparadoxon**: Schon bei einer kleinen
Gruppe von Personen ist die Chance überraschend hoch, dass zwei denselben
"Wert" (in diesem Fall die Karte) treffen.
