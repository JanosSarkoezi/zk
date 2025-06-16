---
key: mittelwertsatz_hoehere_differenzen
title: Mittelwertsatz für höhere Differenzen
type: satz
tags: [analysis, ableitung, differenzenquotient]
refs: [mittelwertsatz_differentialrechnung]
---
Es sei $n \in \mathbb{N}$ und $h \neq 0$. Die Funktion $f$ sei auf einem Intervall erklärt, das die Punkte $x_0, x_0+h, \dots, x_0+nh$ enthält. Ist $f^{(n-1)}$ auf dem Intervall $[a, b]$ (dem kleinsten Intervall, das diese Punkte enthält) vorhanden und stetig und im Innern differenzierbar, so gibt es eine Stelle $\xi \in (a, b)$ mit
$$f^{(n)}(\xi) = \frac{\Delta^n f(x_0)}{h^n}$$
wobei $\Delta^n f(x_0)$ die $n$-te Differenz von $f$ an der Stelle $x_0$ bezeichnet.

--proof--
Der Beweis erfolgt per Induktion über $n$. Für $n=1$ entspricht die Aussage dem gewöhnlichen Mittelwertsatz der Differentialrechnung. Für den Induktionsschritt betrachtet man die Hilfsfunktion $g(x) = f(x+h) - f(x)$ und wendet die Induktionsvoraussetzung an.
