---
key: newton_verfahren_satz
title: Konvergenz des Newton-Verfahrens
type: satz
tags: [analysis, numerik, iteration]
refs: [ableitung_definition, mittelwertsatz_differentialrechnung]
---
Die Funktion $f: [a,b] \to \mathbb{R}$ erfülle die Voraussetzungen:
a) $f''$ ist vorhanden, stetig und $f''(x) \ge 0$ (oder $\le 0$) auf $[a,b]$.
b) $f'$ hat keine Nullstellen in $[a,b]$.
c) $f(a)f(b) < 0$.
Dann besitzt $f(x)=0$ in $[a,b]$ genau eine Lösung $\xi$. Die durch die Iterationsvorschrift
$$x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$$
definierte **Newton-Folge** konvergiert gegen $\xi$, wenn der Startpunkt $x_0$ so gewählt wird, dass $f(x_0)f''(x_0) \ge 0$ gilt. Unter der zusätzlichen Voraussetzung $f''' \in C[a,b]$ ist die Konvergenz **quadratisch**.

--proof--
Der Beweis nutzt die Taylor-Formel zweiter Ordnung, um zu zeigen, dass der Fehler $|x_{n+1}-\xi|$ durch $K|x_n-\xi|^2$ abgeschätzt werden kann. Die Monotonie der Folge ergibt sich aus der Konvexität bzw. Konkavität von $f$.
