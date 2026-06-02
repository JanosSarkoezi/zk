---
key: unabhaengigkeit_ereignissysteme_definition
title: Unabhängigkeit von Ereignissystemen
type: def
tags: wahrscheinlichkeit, unabhaengigkeit
refs: [unabhaengigkeit_ereignisse_familie_definition]
---
Eine Familie $\{\mathcal{E}_i\}_{i \in I}$ von Ereignissystemen $\mathcal{E}_i \subseteq \mathcal{F}$ heißt **unabhängig**, wenn jede Familie von Ereignissen $\{A_i\}_{i \in I}$ mit $A_i \in \mathcal{E}_i$ für alle $i \in I$ unabhängig ist.

Präzise bedeutet dies, dass für jede endliche, nichtleere Teilmenge $J \subseteq I$ und jede Wahl von Ereignissen $A_i \in \mathcal{E}_i$ ($i \in J$) gilt:
$$P\left[ \bigcap_{i \in J} A_i \right] = \prod_{i \in J} P[A_i]$$

--proof--
Diese Definition verallgemeinert die Unabhängigkeit von Ereignissen auf ganze Systeme (wie Algebren oder $\sigma$-Algebren). Ein wichtiges Resultat ist, dass die Unabhängigkeit von Erzeugern unter gewissen Bedingungen die Unabhängigkeit der erzeugten $\sigma$-Algebren impliziert.
