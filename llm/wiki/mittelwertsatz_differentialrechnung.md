---
key: mittelwertsatz_differentialrechnung
title: Mittelwertsatz der Differentialrechnung
type: satz
tags: [analysis, ableitung]
refs: [ableitung_definition, extremalsatz_weierstrass]
---
Sei $f: [a, b] \to \mathbb{R}$ stetig auf $[a, b]$ und differenzierbar in $(a, b)$. Dann gibt es mindestens ein $\xi \in (a, b)$ mit:
$$f'(\xi) = \frac{f(b) - f(a)}{b - a}$$

--proof--
Heuser (Satz 49.1): Ein Spezialfall ist der **Satz von Rolle**: Gilt $f(a) = f(b)$, so existiert ein $\xi$ mit $f'(\xi) = 0$. Den allgemeinen Fall führt man durch die Hilfsfunktion
$$g(x) = f(x) - \frac{f(b) - f(a)}{b - a}(x - a)$$
auf den Satz von Rolle zurück. Geometrisch besagt der Satz, dass es eine Stelle gibt, an der die Tangentensteigung gleich der Sekantensteigung durch die Endpunkte des Intervalls ist.
