---
key: bernoulli_zahlen_definition
title: Bernoulli-Zahlen
type: def
tags: [analysis, reihe, zahlentheorie]
refs: [potenzreihe_definition_konvergenz]
---
Die **Bernoulli-Zahlen** $B_n$ sind die Koeffizienten in der Potenzreihenentwicklung der Funktion
$$\frac{x}{e^x - 1} = \sum_{n=0}^\infty \frac{B_n}{n!} x^n$$
Die ersten Werte sind $B_0 = 1, B_1 = -1/2, B_2 = 1/6, B_4 = -1/30$. Es gilt $B_{2k+1} = 0$ für $k \ge 1$.

--proof--
Die Zahlen können rekursiv durch die Formel $\sum_{k=0}^n \binom{n+1}{k} B_k = 0$ für $n \ge 1$ (mit $B_0=1$) berechnet werden. Sie spielen eine zentrale Rolle in der Summenformel von Euler-Maclaurin und bei der Darstellung der Tangens-Reihe.
