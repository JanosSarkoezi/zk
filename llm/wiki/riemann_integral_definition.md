---
key: riemann_integral_definition
title: Definition des Riemann-Integrals
type: def
tags: [analysis, integration]
refs: [grenzwert_definition]
---
Eine auf dem kompakten Intervall $[a, b]$ erklärte reelle Funktion $f$ heißt **Riemann-integrierbar** (kurz: R-integrierbar), wenn für jede [[grenzwert_definition|Folge]] von Zerlegungen $(Z_n)$ mit einer Feinheit $|Z_n| \to 0$ die zugehörigen **Riemannschen Summen**
$$S(Z_n, \xi) = \sum_{k=1}^n f(\xi_k) \Delta x_k$$
(unabhängig von der Wahl der Zwischenstellen $\xi_k$) gegen denselben [[grenzwert_definition|Grenzwert]] $J$ konvergieren. Dieser [[grenzwert_definition|Grenzwert]] $J$ heißt das **Riemann-Integral** von $f$ über $[a, b]$ und wird bezeichnet als:
$$\int_a^b f(x) \, dx$$

--examples--
Die Definition stellt sicher, dass das Integral als [[grenzwert_definition|Grenzwert]] eines Netzes von Summen existiert. Eine notwendige Bedingung für die R-Integrierbarkeit ist die Beschränktheit der Funktion $f$ auf $[a, b]$.
