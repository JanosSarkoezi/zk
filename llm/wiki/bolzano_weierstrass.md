---
key: bolzano_weierstrass
title: Satz von Bolzano-Weierstraß
type: satz
tags: [analysis, folgen, teilfolgen]
refs: [monotoniekriterium, beschraenktheit_konvergenter_folgen]
---
Jede beschränkte Folge $(a_n)$ reeller Zahlen besitzt mindestens eine konvergente Teilfolge.

--proof--
Wir zeigen zunächst, dass jede Folge eine monotone Teilfolge besitzt. 
Nenne $n$ einen "Spitzenwert", falls $a_n \ge a_m$ für alle $m > n$.
Fall 1: Es gibt unendlich viele Spitzenwerte $n_1 < n_2 < n_3 < \dots$. Dann ist die Teilfolge $(a_{n_k})$ monoton fallend ($a_{n_k} \ge a_{n_{k+1}}$).
Fall 2: Es gibt nur endlich viele Spitzenwerte. Sei $N$ der letzte Spitzenwert (oder $N=0$, falls keine existieren). Für jedes $n > N$ ist $n$ kein Spitzenwert, d.h. es gibt ein $m > n$ mit $a_m > a_n$. 
Wir können so eine streng monoton wachsende Teilfolge $n_1 < n_2 < \dots$ mit $a_{n_1} < a_{n_2} < \dots$ konstruieren.
Da die ursprüngliche Folge beschränkt ist, ist auch die monotone Teilfolge beschränkt und konvergiert somit nach dem Monotoniekriterium.
