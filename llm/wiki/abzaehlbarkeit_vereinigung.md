---
key: abzaehlbarkeit_vereinigung
title: Vereinigung höchstens abzählbarer Mengen
type: satz
tags: [analysis, mengen, abzaehlbarkeit]
refs: [abzaehlbarkeit_q]
---
Die Vereinigung von höchstens abzählbar vielen Mengen, von denen jede höchstens abzählbar ist, ist selbst wieder höchstens abzählbar.

--proof--
Seien $M_1, M_2, \dots$ die abzählbar vielen Mengen. Wir können die Elemente in einem Schema anordnen:
$m_{11}, m_{12}, m_{13}, \dots$
$m_{21}, m_{22}, m_{23}, \dots$
...
Durch das Cantorsche Diagonalverfahren (erstes Diagonalverfahren) können wir alle Elemente in einer Folge anordnen, indem wir die Diagonalen $m_{ij}$ mit $i+j=k$ sukzessive durchlaufen. Doppelt vorkommende Elemente werden übersprungen. Dies liefert eine Abbildung von $\mathbb{N}$ auf die Vereinigungsmenge.
