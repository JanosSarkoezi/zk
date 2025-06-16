---
key: potenzreihe_identitaetssatz
title: Identitätssatz für Potenzreihen
type: satz
tags: [analysis, potenzreihe]
refs: [potenzreihe_definition_konvergenz]
---
Stimmen zwei Potenzreihen $f(x) = \sum a_n(x-x_0)^n$ und $g(x) = \sum b_n(x-x_0)^n$ in einer Umgebung von $x_0$ (oder in einer Menge mit Häufungspunkt $x_0$) überein, so sind sie identisch, d.h. es gilt
$$a_n = b_n \quad \text{für alle } n \in \mathbb{N}_0.$$

--proof--
Wegen $f(x_0) = a_0$ und $g(x_0) = b_0$ folgt sofort $a_0 = b_0$. Durch sukzessives Differenzieren und Auswerten an der Stelle $x_0$ erhält man $a_n = \frac{f^{(n)}(x_0)}{n!}$ und $b_n = \frac{g^{(n)}(x_0)}{n!}$, woraus die Behauptung folgt.
