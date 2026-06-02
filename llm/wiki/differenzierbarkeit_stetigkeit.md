---
key: differenzierbarkeit_stetigkeit
title: Zusammenhang Differenzierbarkeit und Stetigkeit
type: satz
tags: [analysis, ableitung, stetigkeit]
refs: [ableitung_definition, stetigkeit_folgen_definition]
---
Ist eine Funktion $f$ an einer Stelle $\xi$ [[ableitung_definition|differenzierbar]], so ist sie dort auch [[stetigkeit_folgen_definition|stetig]]. Die Umkehrung gilt im Allgemeinen nicht.

--proof--
Heuser ([[differenzierbarkeit_stetigkeit|Satz 46.1]]): Sei $f$ [[ableitung_definition|differenzierbar]] in $\xi$. Für $x \neq \xi$ gilt:
$$f(x) - f(\xi) = \frac{f(x) - f(\xi)}{x - \xi} \cdot (x - \xi)$$
Da der erste Faktor für $x \to \xi$ gegen $f'(\xi)$ konvergiert und der zweite gegen $0$, folgt:
$$\lim_{x \to \xi} (f(x) - f(\xi)) = f'(\xi) \cdot 0 = 0$$
Also $\lim_{x \to \xi} f(x) = f(\xi)$, was genau die Definition der [[stetigkeit_folgen_definition|Stetigkeit]] ist. Das Gegenbeispiel der Betragsfunktion $f(x) = |x|$ zeigt, dass [[stetigkeit_folgen_definition|Stetigkeit]] keine Differenzierbarkeit impliziert (Knick an der Stelle 0).
