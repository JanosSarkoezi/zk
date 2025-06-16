---
key: stetigkeit_folgen_definition
title: Stetigkeit (Folgendefinition)
type: def
tags: [analysis, stetigkeit, folgen]
refs: [grenzwert_definition]
---
Eine Funktion $f$ heißt an einer Stelle $\xi$ ihres Definitionsbereichs $X$ **stetig**, wenn für jede Folge $(x_n)$ aus $X$, die gegen $\xi$ strebt, auch die Folge der Funktionswerte gegen $f(\xi)$ konvergiert:
$$x_n \to \xi \implies f(x_n) \to f(\xi)$$
$f$ heißt stetig auf $X$, wenn $f$ in jedem Punkt $\xi \in X$ stetig ist.

--proof--
Diese Definition basiert auf dem Grenzwertbegriff für Folgen. Eine Funktion ist also stetig, wenn der Grenzwertbildungsprozess mit der Funktionsauswertung vertauschbar ist: $\lim_{n \to \infty} f(x_n) = f(\lim_{n \to \infty} x_n)$. Heuser (Nr. 34) betont, dass isolierte Punkte von $X$ per definitionem Stetigkeitspunkte sind, da dort nur die stationäre Folge $x_n = \xi$ gegen $\xi$ konvergiert.
