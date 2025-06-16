---
key: ableitung_umkehrfunktion
title: Ableitung der Umkehrfunktion
type: satz
tags: [analysis, ableitung]
refs: [ableitung_definition, stetigkeit_folgen_definition]
---
Sei $f$ auf einem Intervall streng monoton und stetig. Ist $f$ an der Stelle $\xi$ differenzierbar mit $f'(\xi) \neq 0$, so ist die Umkehrfunktion $f^{-1}$ an der Stelle $\eta = f(\xi)$ differenzierbar mit:
$$(f^{-1})'(\eta) = \frac{1}{f'(f^{-1}(\eta))} = \frac{1}{f'(\xi)}$$

--proof--
Heuser (Satz 47.3): Der Beweis folgt aus dem Identitätsübergang $y \to \eta \implies x \to \xi$:
$$\frac{f^{-1}(y) - f^{-1}(\eta)}{y - \eta} = \frac{x - \xi}{f(x) - f(\xi)} = \frac{1}{\frac{f(x) - f(\xi)}{x - \xi}}$$
Da $f'$ an der Stelle $\xi$ existiert und ungleich $0$ ist, liefert der Grenzübergang genau den Kehrwert der Ableitung.
