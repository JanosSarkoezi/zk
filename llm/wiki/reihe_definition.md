---
key: reihe_definition
title: Definition der unendlichen Reihe
type: def
tags: [analysis, folgen, reihen]
refs: [grenzwert_definition]
---
Sei $(a_n)_{n \in \mathbb{N}_0}$ eine Folge reeller Zahlen. Die Folge $(s_n)_{n \in \mathbb{N}_0}$ der **Partialsummen** (Teilsummen) mit
$s_n = \sum_{k=0}^n a_k = a_0 + a_1 + \dots + a_n$
heißt **unendliche Reihe**. Man schreibt dafür symbolisch:
$\sum_{k=0}^\infty a_k$.

Die Reihe heißt **konvergent**, wenn die Folge $(s_n)$ ihrer Partialsummen gegen einen Grenzwert $s \in \mathbb{R}$ konvergiert. In diesem Fall nennt man $s$ die **Summe** der Reihe und schreibt:
$\sum_{k=0}^\infty a_k = s$.
Besitzt die Folge der Partialsummen keinen Grenzwert, so heißt die Reihe **divergent**.

--proof--
(Definition erfordert keinen Beweis.)
Eine unendliche Reihe ist formal nichts anderes als eine spezielle Folge, nämlich die Folge ihrer Teilsummen. Alle Aussagen über die Konvergenz von Reihen lassen sich daher auf die Konvergenz von Folgen zurückführen.
