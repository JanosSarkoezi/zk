---
key: integralkriterium_konvergenz
title: Integralkriterium für unendliche Reihen
type: satz
tags: [analysis, reihen, integralrechnung]
refs: [reihe_definition, uneigentliches_integral_unbeschraenkt_definition]
---
Das Integralkriterium stellt einen Zusammenhang zwischen der Konvergenz einer unendlichen Reihe und einem uneigentlichen Integral her.

Die Funktion $f$ sei auf $[m, \infty)$ (mit $m \in \mathbb{N}$) positiv und monoton fallend. Dann haben die Reihe $\sum_{k=m}^{\infty} f(k)$ und das uneigentliche Integral $\int_{m}^{\infty} f(x) \, dx$ dasselbe Konvergenzverhalten.

Es gilt insbesondere:
$$\sum_{k=m+1}^{\infty} f(k) \le \int_{m}^{\infty} f(x) \, dx \le \sum_{k=m}^{\infty} f(k)$$

--proof--
Da $f$ fallend ist, gilt für $x \in [k, k+1]$ die Abschätzung:
$$f(k+1) \le f(x) \le f(k)$$
Integration über $[k, k+1]$ liefert:
$$f(k+1) \le \int_{k}^{k+1} f(x) \, dx \le f(k)$$
Summation über $k = m, \dots, n-1$ ergibt:
$$\sum_{k=m+1}^{n} f(k) \le \int_{m}^{n} f(x) \, dx \le \sum_{k=m}^{n-1} f(k)$$
Durch den Grenzübergang $n \to \infty$ folgt die Behauptung, da beide Seiten monoton wachsen und somit genau dann konvergieren, wenn sie beschränkt sind.
