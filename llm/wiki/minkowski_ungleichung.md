---
key: minkowski_ungleichung
title: Minkowski-Ungleichung (für Summen)
type: satz
tags: [analysis, ungleichung]
refs: [hoelder_ungleichung]
---
Sei $p \ge 1$. Dann gilt für alle komplexen (oder reellen) Zahlen $a_1, \dots, a_n$ und $b_1, \dots, b_n$:
$$\left( \sum_{k=1}^n |a_k + b_k|^p \right)^{1/p} \le \left( \sum_{k=1}^n |a_k|^p \right)^{1/p} + \left( \sum_{k=1}^n |b_k|^p \right)^{1/p}$$

--proof--
Heuser (Satz 59.3): Die Minkowski-Ungleichung ist die Dreiecksungleichung für die $l^p$-Norm. Der Beweis für $p > 1$ nutzt die Höldersche Ungleichung. Man schreibt $|a_k+b_k|^p = |a_k+b_k| \cdot |a_k+b_k|^{p-1} \le (|a_k| + |b_k|) |a_k+b_k|^{p-1}$, summiert über $k$ und wendet auf die beiden resultierenden Summen die Höldersche Ungleichung mit dem Exponenten $q = p/(p-1)$ an.
