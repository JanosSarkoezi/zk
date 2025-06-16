---
key: riemann_integral_definition
title: Definition des Riemann-Integrals
type: def
tags: [analysis, integration]
refs: [grenzwert_definition]
---
Eine auf dem kompakten Intervall $[a, b]$ erklärte reelle Funktion $f$ heißt **Riemann-integrierbar** (kurz: R-integrierbar), wenn für jede Folge von Zerlegungen $(Z_n)$ mit einer Feinheit $|Z_n| \to 0$ die zugehörigen **Riemannschen Summen**
$$S(Z_n, \xi) = \sum_{k=1}^n f(\xi_k) \Delta x_k$$
(unabhängig von der Wahl der Zwischenstellen $\xi_k$) gegen denselben Grenzwert $J$ konvergieren. Dieser Grenzwert $J$ heißt das **Riemann-Integral** von $f$ über $[a, b]$ und wird bezeichnet als:
$$\int_a^b f(x) \, dx$$

--proof--
Die Definition stellt sicher, dass das Integral als Grenzwert eines Netzes von Summen existiert. Eine notwendige Bedingung für die R-Integrierbarkeit ist die Beschränktheit der Funktion $f$ auf $[a, b]$.
