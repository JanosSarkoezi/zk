---
key: mittelwertsatz_integralrechnung
title: Erster Mittelwertsatz der Integralrechnung
type: satz
tags: [analysis, integration]
refs: [stetigkeit_impliziert_integrabilitaet, zwischenwertsatz]
---
Ist $f$ auf $[a, b]$ stetig, so gibt es mindestens eine Stelle $\xi \in [a, b]$, so dass gilt:
$$\int_a^b f(x) \, dx = f(\xi) \cdot (b - a)$$

--proof--
Da $f$ auf dem kompakten Intervall $[a, b]$ stetig ist, nimmt sie nach dem Satz von Weierstraß ein Minimum $m$ und ein Maximum $M$ an. Es gilt $m(b-a) \le \int f \, dx \le M(b-a)$. Aus dem Zwischenwertsatz folgt dann die Existenz von $\xi$.
