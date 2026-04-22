---
key: euler_summenformel
title: Die Eulersche Summenformel
type: satz
tags: [analysis, integral, reihe, bernoulli]
refs: [riemann_integral_definition, bernoulli_zahlen_definition]
---
Die Eulersche Summenformel verknüpft die Summe von Funktionswerten mit dem Integral der Funktion. Für eine $(2p+1)$-mal stetig differenzierbare Funktion $f$ auf $[0, n]$ gilt:
$$\sum_{k=1}^n f(k) = \int_0^n f(x) \, dx + \frac{f(n)-f(0)}{2} + \sum_{\mu=1}^p \frac{B_{2\mu}}{(2\mu)!} [f^{(2\mu-1)}(n) - f^{(2\mu-1)}(0)] + R_{2p}$$
wobei $B_{2\mu}$ die Bernoulli-Zahlen und $R_{2p}$ das Restglied sind.

--proof--
Die Herleitung erfolgt über die Integration der Bernoulli-Polynome $\beta_k(x)$. Durch wiederholte partielle Integration von $\int_0^1 f(x+k) \beta'_1(x) \, dx$ gewinnt man Ausdrücke für die Differenz zwischen Summe und Integral, wobei die Eigenschaften der Bernoulli-Polynome ($\beta'_k = \beta_{k-1}$ und $\beta_k(0) = \beta_k(1) = \frac{B_k}{k!}$ für $k \ge 2$) genutzt werden.
