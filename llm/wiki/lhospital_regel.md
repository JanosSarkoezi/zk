---
key: lhospital_regel
title: Regel von de l'Hospital
type: satz
tags: [analysis, grenzwert, ableitung]
refs: [ableitung_definition, mittelwertsatz_differentialrechnung]
---
Zur Bestimmung von Grenzwerten des Typs "0/0" oder "$\infty/\infty$": Unter geeigneten Voraussetzungen (Differenzierbarkeit von $f$ und $g$ in der Nähe von $a$, $g'(x) \neq 0$) gilt:
$$\lim_{x \to a} \frac{f(x)}{g(x)} = \lim_{x \to a} \frac{f'(x)}{g'(x)}$$
sofern der Grenzwert auf der rechten Seite existiert.

--proof--
Heuser (Satz 50.1): Der Beweis basiert auf dem verallgemeinerten Mittelwertsatz der Differentialrechnung, der für zwei Funktionen $f, g$ besagt, dass ein $\xi$ existiert mit $(f(b)-f(a))g'(\xi) = (g(b)-g(a))f'(\xi)$. Man wendet dies auf kleine Intervalle nahe $a$ an.
