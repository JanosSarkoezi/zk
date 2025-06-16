---
key: jensen_ungleichung
title: Jensensche Ungleichung
type: satz
tags: [analysis, ungleichung, konvexität]
refs: []
---
Ist $f$ eine konvexe Funktion auf einem Intervall $I$, so gilt für alle $x_1, \dots, x_n \in I$ und Gewichte $\lambda_1, \dots, \lambda_n \ge 0$ mit $\sum \lambda_i = 1$:
$$f\left( \sum_{i=1}^n \lambda_i x_i \right) \le \sum_{i=1}^n \lambda_i f(x_i)$$

--proof--
Heuser (Nr. 59, Aufgabe 6): Der Beweis erfolgt durch vollständige Induktion über $n$. Der Induktionsanfang $n=2$ entspricht genau der Definition der Konvexität. Der Induktionsschritt nutzt die Definition erneut für eine geschickte Aufteilung der Summe. Geometrisch besagt die Ungleichung, dass der Funktionswert am Schwerpunkt der Stellen kleiner oder gleich dem Schwerpunkt der Funktionswerte ist (der Graph liegt unterhalb der Verbindungsstrecken).
