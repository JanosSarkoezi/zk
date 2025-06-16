---
key: erweiterter_mittelwertsatz_integralrechnung
title: Erweiterter Mittelwertsatz der Integralrechnung
type: satz
tags: [analysis, integration]
refs: [mittelwertsatz_integralrechnung]
---
Es seien $f, g$ auf $[a, b]$ R-integrierbar, $f$ stetig und $g$ ohne Vorzeichenwechsel (d.h. $g(x) \ge 0$ oder $g(x) \le 0$ für alle $x$). Dann gibt es eine Stelle $\xi \in [a, b]$ mit:
$$\int_a^b f(x)g(x) \, dx = f(\xi) \int_a^b g(x) \, dx$$

--proof--
Der Beweis verläuft analog zum ersten Mittelwertsatz unter Ausnutzung der Monotonie des Integrals, wobei die Funktion $g$ als "Gewichtsfunktion" fungiert.
