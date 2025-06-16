---
key: abelscher_grenzwertsatz
title: Abelscher Grenzwertsatz
type: satz
tags: [analysis, potenzreihe, konvergenz]
refs: [potenzreihe_definition_konvergenz]
---
Konvergiert die Potenzreihe $f(x) = \sum_{n=0}^\infty a_n (x-x_0)^n$ an einem der Randpunkte ihres Konvergenzintervalls, etwa für $x = x_0 + r$, so ist die Funktion $f$ in diesem Punkt (linksseitig) stetig, d.h. es gilt:
$$\lim_{x \to (x_0+r)^-} f(x) = \sum_{n=0}^\infty a_n r^n$$

--proof--
Der Beweis nutzt die Abelsche Partielle Summation, um die Konvergenz der Reihe am Randpunkt auf eine gleichmäßige Konvergenz im Intervall $[x_0, x_0+r]$ zurückzuführen.
