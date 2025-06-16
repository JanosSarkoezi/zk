# Partialbrucherlegung 

## Frage

Bei der Partialbrucherlegung wir bei doppleter Nullstelle ein bestimmter Ansatz
gemache, warum muss das so gemacht werden?

## Antwort

Der spezifische Ansatz bei einer **doppelten Nullstelle** (oder allgemeiner
einer $k$-fachen Nullstelle) in der Partialbruchzerlegung ist notwendig, um die
**Vollständigkeit** des Zerlegungsansatzes zu gewährleisten und
sicherzustellen, dass jede rationale Funktion zerlegt werden kann.

### Der Ansatz bei mehrfachen Nullstellen

Wenn der Nenner der rationalen Funktion einen Faktor der Form $(x - x_0)^k$
hat, wobei $k \ge 2$ die Vielfachheit der Nullstelle $x_0$ ist (doppelte
Nullstelle: $k=2$), muss der Partialbruchansatz **alle Potenzen** dieses
Faktors von 1 bis $k$ als Nenner berücksichtigen.

Für eine $k$-fache Nullstelle $x_0$ lautet der Ansatz:

$$\frac{P(x)}{(x-x_0)^k \cdot R(x)} = \frac{A_1}{x-x_0} + \frac{A_2}{(x-x_0)^2} + \dots + \frac{A_k}{(x-x_0)^k} + \text{Partialbrüche für } R(x)$$

Wobei $A_1, A_2, \dots, A_k$ Konstanten sind und $R(x)$ die restlichen Faktoren
des Nenners darstellt.

---

### Warum dieser Ansatz erforderlich ist

Der Grund, warum die Terme mit den **niedrigeren Potenzen** (wie
$\frac{A_1}{x-x_0}$ und $\frac{A_2}{(x-x_0)^2}$ bei einer dreifachen
Nullstelle) benötigt werden, liegt darin, dass beim **Zusammenfassen** der
Brüche jede dieser Potenzen zu dem komplexen Ursprungsbruch beitragen kann.

Betrachten wir als Beispiel eine doppelte Nullstelle ($k=2$) im Nenner, also
den Faktor $(x-a)^2$.

Angenommen, Sie hätten nur den Term mit der höchsten Potenz im Ansatz:
$$\frac{P(x)}{(x-a)^2} \stackrel{?}{=} \frac{B}{(x-a)^2}$$
Wenn Sie beispielsweise den einfachen Bruch $\frac{x+1}{(x-2)^2}$ zerlegen müssten, würde dieser Ansatz fehlschlagen, da Sie nur eine Konstante $B$ im Zähler haben, aber $x+1$ ein Polynom vom Grad 1 ist.

Der **korrekte** Ansatz ist:
$$\frac{P(x)}{(x-a)^2} = \frac{A}{x-a} + \frac{B}{(x-a)^2}$$

Wenn Sie diese beiden Brüche wieder addieren, erhalten Sie:
$$\frac{A}{x-a} + \frac{B}{(x-a)^2} = \frac{A \cdot (x-a)}{(x-a)^2} + \frac{B}{(x-a)^2} = \frac{A(x-a) + B}{(x-a)^2} = \frac{Ax + (B-Aa)}{(x-a)^2}$$

Der resultierende Zähler $Ax + (B-Aa)$ ist ein **allgemeines Polynom vom Grad
1** (oder Grad 0, falls $A=0$). Da der Zähler des ursprünglichen Bruches
maximal den Grad 1 haben kann (da der Nenner Grad 2 hat), **muss** die
Zerlegung diese allgemeine Form des Zählers im Ergebnis abdecken können. Ohne
den Term $\frac{A}{x-a}$ könnte die Zerlegung nur Brüche erzeugen, deren Zähler
eine Konstante (Grad 0) ist, und somit würde die Methode für Brüche mit einem
linearen Zähler fehlschlagen.

Die zusätzlichen Terme mit den niedrigeren Potenzen sind also notwendig, um
**alle möglichen Polynome** im Zähler des ursprünglichen rationalen Ausdrucks
abzudecken, deren Grad kleiner ist als die Vielfachheit der Nullstelle.

Der Link unten zeigt eine Erklärung zur Partialbruchzerlegung mit doppelten Nullstellen.

[Partialbruchzerlegung: Doppelte Polstellen](https://www.youtube.com/watch?v=FVnJMx4of78)
http://googleusercontent.com/youtube_content/0



