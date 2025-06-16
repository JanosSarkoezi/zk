---
key: substitutionsregel
title: Substitutionsregel
type: satz
tags: [analysis, integration]
refs: [hauptsatz_differential_integralrechnung, kettenregel]
---
Es sei $f$ stetig auf dem Intervall $I$ und $g: [a, b] \to I$ eine stetig differenzierbare Funktion. Dann gilt:
$$\int_a^b f(g(t)) \cdot g'(t) \, dt = \int_{g(a)}^{g(b)} f(x) \, dx$$

--proof--
Die Regel ist die Umkehrung der Kettenregel der Differentialrechnung. Ist $F$ eine Stammfunktion von $f$, so ist $F \circ g$ wegen der Kettenregel eine Stammfunktion von $(f \circ g) \cdot g'$. Die Behauptung folgt dann aus dem Hauptsatz.
