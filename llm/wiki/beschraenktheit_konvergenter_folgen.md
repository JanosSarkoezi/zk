---
key: beschraenktheit_konvergenter_folgen
title: Beschränktheit konvergenter Folgen
type: satz
tags: [analysis, folgen, beschraenktheit]
refs: [grenzwert_definition]
---
Jede konvergente Folge $(a_n)$ ist beschränkt.

--proof--
Sei $a = \lim_{n \to \infty} a_n$. Zu $\epsilon = 1$ gibt es ein $N \in \mathbb{N}$, so dass für alle $n > N$ gilt:
$|a_n - a| < 1$, also $|a_n| < |a| + 1$.
Setze $M = \max \{ |a_1|, |a_2|, \dots, |a_N|, |a| + 1 \}$.
Dann gilt für alle $n \in \mathbb{N}$: $|a_n| \le M$. 
Die Folge ist somit beschränkt.
