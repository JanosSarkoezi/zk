---
key: zwischenwertsatz
title: Zwischenwertsatz für stetige Funktionen
type: satz
tags: [analysis, stetigkeit]
refs: [nullstellensatz_bolzano]
---
Sei $f: [a, b] \to \mathbb{R}$ eine stetige Funktion. Dann nimmt $f$ jeden Wert zwischen $f(a)$ und $f(b)$ mindestens einmal an.

--proof--
Sei $y$ ein Wert zwischen $f(a)$ und $f(b)$. Betrachte die Hilfsfunktion $g(x) = f(x) - y$. $g$ ist als Differenz stetiger Funktionen stetig. Da $y$ zwischen $f(a)$ und $f(b)$ liegt, haben $g(a)$ und $g(b)$ unterschiedliche Vorzeichen. Nach dem Nullstellensatz von Bolzano gibt es ein $\xi \in (a, b)$ mit $g(\xi) = 0$, also $f(\xi) = y$.
