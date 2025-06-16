---
key: kompaktheit_folgen_definition
title: Kompaktheit (Folgendefinition)
type: def
tags: [analysis, topologie, kompaktheit]
refs: [bolzano_weierstrass]
---
Eine Teilmenge $K \subseteq \mathbb{R}$ heißt **kompakt**, wenn jede Folge $(x_n)$ aus $K$ eine Teilfolge besitzt, die gegen einen Grenzwert $\xi$ konvergiert, der selbst wieder in $K$ liegt ($\xi \in K$).

--proof--
Diese Definition entspricht der "Folgenkompaktheit". In $\mathbb{R}$ ist dies nach dem Satz von Heine-Borel (Heuser, Satz 36.2) äquivalent dazu, dass $K$ beschränkt und abgeschlossen ist. Der Beweis nutzt den Satz von Bolzano-Weierstraß, wonach jede beschränkte Folge eine konvergente Teilfolge besitzt; die Abgeschlossenheit garantiert, dass der Grenzwert in der Menge bleibt.
