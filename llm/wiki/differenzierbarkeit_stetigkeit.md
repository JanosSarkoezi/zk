---
key: differenzierbarkeit_stetigkeit
title: Zusammenhang Differenzierbarkeit und Stetigkeit
type: satz
tags: [analysis, ableitung, stetigkeit]
refs: [ableitung_definition, stetigkeit_folgen_definition]
---
Ist eine Funktion $f$ an einer Stelle $\xi$ differenzierbar, so ist sie dort auch stetig. Die Umkehrung gilt im Allgemeinen nicht.

--proof--
Heuser (Satz 46.1): Sei $f$ differenzierbar in $\xi$. Für $x \neq \xi$ gilt:
$$f(x) - f(\xi) = \frac{f(x) - f(\xi)}{x - \xi} \cdot (x - \xi)$$
Da der erste Faktor für $x \to \xi$ gegen $f'(\xi)$ konvergiert und der zweite gegen $0$, folgt:
$$\lim_{x \to \xi} (f(x) - f(\xi)) = f'(\xi) \cdot 0 = 0$$
Also $\lim_{x \to \xi} f(x) = f(\xi)$, was genau die Definition der Stetigkeit ist. Das Gegenbeispiel der Betragsfunktion $f(x) = |x|$ zeigt, dass Stetigkeit keine Differenzierbarkeit impliziert (Knick an der Stelle 0).
