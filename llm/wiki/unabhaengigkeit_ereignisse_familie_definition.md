---
key: unabhaengigkeit_ereignisse_familie_definition
title: Unabhängigkeit einer Familie von Ereignissen
type: def
tags: wahrscheinlichkeit, unabhaengigkeit
refs: [unabhaengigkeit_ereignisse_definition]
---
Eine Familie $\{A_i\}_{i \in I}$ von Ereignissen $A_i \in \mathcal{F}$ eines Wahrscheinlichkeitsraums $(\Omega, \mathcal{F}, P)$ heißt **unabhängig**, wenn für jede endliche, nichtleere Teilmenge $J \subseteq I$ gilt:
$$P\left[ \bigcap_{i \in J} A_i \right] = \prod_{i \in J} P[A_i]$$

--proof--
Die Definition fordert, dass die Produktformel für alle endlichen Teilfamilien gilt. Insbesondere folgt daraus die paarweise Unabhängigkeit (für $|J|=2$), aber die Umkehrung gilt im Allgemeinen nicht (siehe Beispiel von Bernstein).
Eine Familie heißt **paarweise unabhängig**, wenn $P[A_i \cap A_j] = P[A_i] P[A_j]$ für alle $i, j \in I$ mit $i \neq j$ gilt. Unabhängigkeit ist eine deutlich stärkere Forderung als paarweise Unabhängigkeit.
