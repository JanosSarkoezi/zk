---
key: riemann_integrabilitaet_kriterium
title: Riemannsches Integrabilitätskriterium
type: satz
tags: [analysis, integration]
refs: [darboux_integrale_definition]
---
Eine beschränkte Funktion $f$ ist auf $[a, b]$ genau dann Riemann-[[darboux_integrale_definition|integrierbar]], wenn zu jedem $\epsilon > 0$ eine Zerlegung $Z$ von $[a, b]$ existiert, so dass die Differenz zwischen Obersumme und Untersumme kleiner als $\epsilon$ ist:
$$O(f, Z) - U(f, Z) < \epsilon$$

--proof--
Das Kriterium folgt direkt aus der Definition der Darboux-[[darboux_integrale_definition|Integrale]] als Supremum bzw. Infimum. Es ist das praktische Hauptwerkzeug, um die Integrierbarkeit von Funktionenklassen (wie stetigen oder monotonen Funktionen) nachzuweisen.
