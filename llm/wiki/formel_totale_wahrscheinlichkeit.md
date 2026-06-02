---
key: formel_totale_wahrscheinlichkeit
title: Formel von der totalen Wahrscheinlichkeit
type: satz
tags: wahrscheinlichkeit, bedingte_wahrscheinlichkeit
refs: [bedingte_wahrscheinlichkeit_definition]
---
Sei $(\Omega, \mathcal{F}, P)$ ein Wahrscheinlichkeitsraum und $\{C_i\}_{i \in I}$ eine höchstens abzählbare Partition von $\Omega$ (d.h. $\Omega = \bigcup_{i \in I} C_i$ disjunkt) mit $P[C_i] > 0$ für alle $i \in I$.

Dann gilt für jedes Ereignis $A \in \mathcal{F}$:
$$P[A] = \sum_{i \in I} P[A | C_i] P[C_i]$$

Im einfachsten Fall einer Zerlegung in $C$ und $\bar{C}$ ($P[C] \in (0,1)$) gilt:
$$P[A] = P[A | C] P[C] + P[A | \bar{C}] P[\bar{C}]$$

--proof--
Es gilt $A = A \cap \Omega = A \cap \bigcup_{i \in I} C_i = \bigcup_{i \in I} (A \cap C_i)$. Da die $C_i$ paarweise disjunkt sind, sind auch die $A \cap C_i$ paarweise disjunkt. Aus der $\sigma$-Additivität folgt:
$$P[A] = \sum_{i \in I} P[A \cap C_i]$$
Nach Definition der bedingten Wahrscheinlichkeit ist $P[A \cap C_i] = P[A | C_i] P[C_i]$, woraus die Behauptung folgt.
