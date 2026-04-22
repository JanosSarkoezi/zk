---
key: weierstrass_majorantenkriterium
title: Weierstraßsches Majorantenkriterium
type: satz
tags: [analysis, reihe, konvergenz]
refs: [konvergenz_funktionen_definition, absolute_konvergenz]
---
Eine Funktionenreihe $\sum_{k=1}^\infty f_k(x)$ konvergiert auf $X$ gleichmäßig, wenn es eine konvergente Reihe $\sum_{k=1}^\infty c_k$ mit reellen Gliedern $c_k \ge 0$ gibt, so dass für alle $x \in X$ und alle $k \in \mathbb{N}$ gilt:
$$|f_k(x)| \le c_k$$

--proof--
Wegen $|f_k(x)| \le c_k$ und der Konvergenz von $\sum c_k$ konvergiert die Reihe nach dem Majorantenkriterium für jedes $x$ absolut. Sei $s_n(x)$ die Teilsumme und $s(x)$ der Grenzwert. Dann gilt:
$$|s(x) - s_n(x)| = |\sum_{k=n+1}^\infty f_k(x)| \le \sum_{k=n+1}^\infty |f_k(x)| \le \sum_{k=n+1}^\infty c_k$$
Da das Restglied der konvergenten Reihe $\sum c_k$ gegen 0 strebt und unabhängig von $x$ ist, folgt die gleichmäßige Konvergenz.
