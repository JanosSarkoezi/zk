---
key: konvexitaet_definition
title: Definition der Konvexität
type: def
tags: [analysis, funktion, konvexitaet]
refs: [mittelwertsatz_differentialrechnung, jensen_ungleichung]
---
Eine reelle Funktion $f$ heißt auf einem Intervall $I$ **konvex**, wenn für je zwei verschiedene Punkte $x_1, x_2 \in I$ und für alle $\lambda \in (0,1)$ stets die Ungleichung
$$f((1-\lambda)x_1 + \lambda x_2) \le (1-\lambda)f(x_1) + \lambda f(x_2)$$
erfüllt ist. Gilt in dieser Ungleichung stets das Kleiner-Zeichen $<$, so heißt $f$ **streng konvex**.

--proof--
Geometrisch bedeutet die Konvexität, dass jeder Punkt der Verbindungsstrecke (Sekante) zwischen zwei Punkten $(x_1, f(x_1))$ und $(x_2, f(x_2))$ des Graphen von $f$ oberhalb oder auf dem Graphen liegt. 
Ist die umgekehrte Ungleichung erfüllt, heißt die Funktion **konkav** (bzw. **streng konkav**).
