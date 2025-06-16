---
key: dgl_linear_homogen_n_ordnung
title: Homogene lineare Differentialgleichungen n-ter Ordnung
type: satz
tags: [analysis, dgl]
refs: [vektorraumaxiome, ableitung_definition]
---
Eine homogene lineare Differentialgleichung $n$-ter Ordnung mit konstanten Koeffizienten hat die Form:
$$x^{(n)} + a_{n-1}x^{(n-1)} + \dots + a_1 x' + a_0 x = 0$$
Die Gesamtheit der (komplexwertigen) Lösungen bildet einen **Vektorraum der Dimension $n$**. Ist $p(\lambda) = \lambda^n + a_{n-1}\lambda^{n-1} + \dots + a_0$ das **charakteristische Polynom** und sind $\lambda_1, \dots, \lambda_m$ dessen Nullstellen mit Vielfachheiten $\nu_1, \dots, \nu_m$, so bilden die Funktionen
$$t^k e^{\lambda_j t} \quad (j=1, \dots, m; \ k=0, \dots, \nu_j - 1)$$
ein Fundamentalsystem von Lösungen.

--proof--
Der Beweis nutzt den Differentiationsoperator $D$ und die Zerlegung des charakteristischen Polynoms in Linearfaktoren. Die lineare Unabhängigkeit der Lösungen folgt aus den Eigenschaften der Exponentialfunktion und der Vandermonde-Determinante.
