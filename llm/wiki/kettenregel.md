---
key: kettenregel
title: Kettenregel
type: satz
tags: [analysis, ableitung]
refs: [ableitung_definition, stetigkeit_folgen_definition]
---
Ist $g$ in $\xi$ [[ableitung_definition|differenzierbar]] und $f$ in $\eta = g(\xi)$ [[ableitung_definition|differenzierbar]], so ist die Komposition $h = f \circ g$ in $\xi$ [[ableitung_definition|differenzierbar]] mit:
$$h'(\xi) = f'(g(\xi)) \cdot g'(\xi)$$

--proof--
Heuser (Satz 47.2): Der naive Beweis durch Erweiterung mit $g(x)-g(\xi)$ scheitert, falls $g(x) = g(\xi)$ in jeder Umgebung von $\xi$ vorkommt. Ein korrekter Beweis nutzt die Charakterisierung der Differenzierbarkeit durch die Hilfsfunktion $F_\eta(y)$, die in $\eta$ [[stetigkeit_folgen_definition|stetig]] ist mit $F_\eta(\eta) = f'(\eta)$. Dann ist $f(y) - f(\eta) = F_\eta(y)(y - \eta)$. Setzt man $y = g(x)$, folgt der Satz durch Grenzübergang.
