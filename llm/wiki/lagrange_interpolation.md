---
key: lagrange_interpolation
title: Lagrange-Interpolationspolynom
type: satz
tags: [analysis, numerik, polynome]
refs: [identitaetssatz_polynome]
---
Zu $n+1$ verschiedenen Stützstellen $x_0, x_1, \dots, x_n$ und beliebigen Werten $y_0, y_1, \dots, y_n$ existiert genau ein Polynom $L$ vom Grad $\le n$, so dass gilt:
$L(x_k) = y_k$ für $k = 0, \dots, n$.

--proof--
Die Existenz wird durch die Konstruktion mit Lagrange-Basispolynomen gezeigt:
$L_k(x) = \prod_{j=0, j \neq k}^n \frac{x - x_j}{x_k - x_j}$
Dann ist $L(x) = \sum_{k=0}^n y_k L_k(x)$ das gesuchte Polynom, da $L_k(x_j) = \delta_{kj}$.
Die Eindeutigkeit folgt aus dem Identitätssatz für Polynome: Gäbe es zwei solche Polynome $L$ und $M$, so hätte ihre Differenz $L-M$ an $n+1$ Stellen den Wert 0, obwohl ihr Grad höchstens $n$ ist. Folglich muss $L-M = 0$ sein.
