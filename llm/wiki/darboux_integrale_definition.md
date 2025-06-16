---
key: darboux_integrale_definition
title: Darbouxsche Ober- und Unterintegrale
type: def
tags: [analysis, integration]
refs: [supremum_infimum, riemann_integral_definition]
---
Für eine beschränkte Funktion $f$ auf $[a, b]$ und eine Zerlegung $Z$ definiert man die **Untersumme** $U(f, Z)$ und die **Obersumme** $O(f, Z)$ durch die Infima bzw. Suprema der Funktionswerte in den Teilintervallen.
Das **Darbouxsche Unterintegral** ist das Supremum aller Untersummen:
$$\underline{\int_a^b} f(x) \, dx = \sup_{Z} U(f, Z)$$
Das **Darbouxsche Oberintegral** ist das Infimum aller Obersummen:
$$\overline{\int_a^b} f(x) \, dx = \inf_{Z} O(f, Z)$$
Eine Funktion heißt **D-integrierbar**, wenn Ober- und Unterintegral übereinstimmen.

--proof--
Da für jede Zerlegung $U(f, Z) \le O(f, Z)$ gilt, ist stets das Unterintegral kleiner oder gleich dem Oberintegral. Die Übereinstimmung beider Werte ist äquivalent zur Riemann-Integrierbarkeit.
