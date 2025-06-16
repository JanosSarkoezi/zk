---
key: hoelder_ungleichung
title: Höldersche Ungleichung (für Summen)
type: satz
tags: [analysis, ungleichung]
refs: []
---
Seien $p, q > 1$ mit $1/p + 1/q = 1$. Dann gilt für alle komplexen (oder reellen) Zahlen $a_1, \dots, a_n$ und $b_1, \dots, b_n$:
$$\sum_{k=1}^n |a_k b_k| \le \left( \sum_{k=1}^n |a_k|^p \right)^{1/p} \left( \sum_{k=1}^n |b_k|^q \right)^{1/q}$$

--proof--
Heuser (Satz 59.2): Der Beweis nutzt die Konkavität des Logarithmus bzw. die Youngsche Ungleichung $ab \le \frac{a^p}{p} + \frac{b^q}{q}$ für nichtnegative $a, b$. Durch geeignete Normierung der Folgen $a$ und $b$ und anschließende Summation folgt die Behauptung. Für $p=q=2$ ergibt sich die Cauchy-Schwarzsche Ungleichung als Spezialfall.
