---
key: unabhaengigkeit_ereignisse_null_eins_lemma
title: Unabhängigkeit von Null-Eins-Ereignissen
type: lemma
tags: wahrscheinlichkeit, unabhaengigkeit
refs: [unabhaengigkeit_ereignisse_definition]
---
Sei $A \in \mathcal{F}$ ein beliebiges Ereignis und sei $B \in \mathcal{F}$ ein Ereignis mit $P[B] \in \{0, 1\}$. Dann ist $\{A, B\}$ unabhängig.

Insbesondere sind das sichere Ereignis $\Omega$ und das unmögliche Ereignis $\emptyset$ von jedem Ereignis unabhängig.

--proof--
1. Fall $P[B] = 0$:
Da $A \cap B \subseteq B$ gilt, folgt aus der Monotonie des Maßes $0 \le P[A \cap B] \le P[B] = 0$, also $P[A \cap B] = 0$.
Damit ist $P[A \cap B] = 0 = P[A] \cdot 0 = P[A] P[B]$.

2. Fall $P[B] = 1$:
Es gilt $P[A \cup B] = 1$. Aus der Siebformel (oder Subadditivität) folgt:
$P[A \cap B] = P[A] + P[B] - P[A \cup B] = P[A] + 1 - 1 = P[A]$.
Damit ist $P[A \cap B] = P[A] = P[A] \cdot 1 = P[A] P[B]$.
