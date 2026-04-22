---
key: dgl_getrennte_veraenderliche
title: DGL mit getrennten Veränderlichen
type: satz
tags: [analysis, differentialgleichung]
refs: [stammfunktion_definition, hauptsatz_differential_integralrechnung]
---
Eine Differentialgleichung der Form $y' = f(x)g(y)$ heißt DGL mit getrennten Veränderlichen. Sind $f$ und $g$ stetig und $g(y) \neq 0$ im betrachteten Bereich, so lassen sich die Lösungen durch Integration gewinnen:
$$\int \frac{dy}{g(y)} = \int f(x) \, dx + C$$

--proof--
Durch Division durch $g(y)$ erhält man $\frac{y'}{g(y)} = f(x)$. Nach der Kettenregel ist die linke Seite die Ableitung von $H(y(x))$, wobei $H$ eine Stammfunktion von $1/g$ ist. Integration beider Seiten nach $x$ liefert $H(y(x)) = \int f(x) \, dx + C$. Da $g$ keine Nullstellen hat, ist $H$ streng monoton und somit invertierbar: $y(x) = H^{-1}(\int f(x) \, dx + C)$.
