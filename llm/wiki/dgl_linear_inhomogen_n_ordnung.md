---
key: dgl_linear_inhomogen_n_ordnung
title: Inhomogene lineare Differentialgleichungen n-ter Ordnung
type: satz
tags: [analysis, dgl]
refs: [dgl_linear_homogen_n_ordnung]
---
Die allgemeine Lösung einer inhomogenen linearen Differentialgleichung
$$L[x] = x^{(n)} + a_{n-1}x^{(n-1)} + \dots + a_0 x = s(t)$$
ist von der Form $x(t) = x_h(t) + x_p(t)$, wobei $x_h$ die allgemeine Lösung der zugehörigen homogenen Gleichung und $x_p$ eine beliebige **partikuläre Lösung** der inhomogenen Gleichung ist.

--proof--
Die Linearität des Operators $L$ impliziert $L[x_1 - x_2] = L[x_1] - L[x_2]$. Sind $x_1, x_2$ Lösungen der inhomogenen Gleichung, so ist ihre Differenz eine Lösung der homogenen Gleichung. Eine partikuläre Lösung kann oft durch den Ansatz vom Typ der rechten Seite oder durch Variation der Konstanten gefunden werden.
