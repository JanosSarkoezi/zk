---
key: potenzreihe_definition_konvergenz
title: Konvergenz von Potenzreihen
type: satz
tags: [analysis, reihe, potenzreihe]
refs: [reihe_definition, wurzelkriterium]
---
Eine Reihe der Form $\sum_{n=0}^\infty a_n (x-x_0)^n$ heißt **Potenzreihe** mit dem Mittelpunkt $x_0$ und den Koeffizienten $a_n$.
Der **Konvergenzradius** $r$ der Potenzreihe ist definiert durch die Formel von **Cauchy-Hadamard**:
$$r = \frac{1}{\limsup_{n \to \infty} \sqrt[n]{|a_n|}}$$
(mit $r=0$ falls der Limes superior $\infty$ ist und $r=\infty$ falls er $0$ ist).
Die Reihe konvergiert für alle $x$ mit $|x-x_0| < r$ absolut und divergiert für $|x-x_0| > r$.

--proof--
Die Aussage folgt direkt aus dem Wurzelkriterium für Reihen, angewandt auf die Glieder $b_n = a_n(x-x_0)^n$. Der Konvergenzbereich ist ein Intervall um $x_0$, wobei über das Verhalten an den Rändern $x_0 \pm r$ keine allgemeine Aussage getroffen werden kann.
