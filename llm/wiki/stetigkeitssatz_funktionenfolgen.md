---
key: stetigkeitssatz_funktionenfolgen
title: Stetigkeitssatz für Funktionenfolgen
type: satz
tags: [analysis, stetigkeit, konvergenz]
refs: [konvergenz_funktionen_definition, stetigkeit_epsilon_delta_definition]
---
Konvergiert eine Folge stetiger Funktionen $(f_n)$ auf $X$ gleichmäßig gegen $f$, so ist auch die Grenzfunktion $f$ auf $X$ stetig.

--proof--
Sei $\xi \in X$. Wir nutzen die "$\epsilon/3$-Abschätzung":
$$|f(x) - f(\xi)| \le |f(x) - f_n(x)| + |f_n(x) - f_n(\xi)| + |f_n(\xi) - f(\xi)|$$
Wegen gleichmäßiger Konvergenz können wir $n$ so groß wählen, dass der erste und dritte Term kleiner als $\epsilon/3$ sind (unabhängig von $x$). Wegen der Stetigkeit von $f_n$ gibt es eine Umgebung von $\xi$, in der der mittlere Term kleiner als $\epsilon/3$ ist. Insgesamt folgt $|f(x) - f(\xi)| < \epsilon$.
