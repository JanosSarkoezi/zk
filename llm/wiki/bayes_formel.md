---
key: bayes_formel
title: Formel von Bayes
type: satz
tags: wahrscheinlichkeit, bedingte_wahrscheinlichkeit
refs: [formel_totale_wahrscheinlichkeit]
---
Sei $\{C_i\}_{i \in I}$ eine höchstens abzählbare Partition von $\Omega$ mit $P[C_i] > 0$. Dann gilt für jedes Ereignis $A \in \mathcal{F}$ mit $P[A] > 0$ und jedes $j \in I$:
$$P[C_j | A] = \frac{P[A | C_j] P[C_j]}{\sum_{i \in I} P[A | C_i] P[C_i]}$$

--proof--
Nach Definition der bedingten Wahrscheinlichkeit gilt:
$$P[C_j | A] = \frac{P[C_j \cap A]}{P[A]}$$
Der Zähler lässt sich als $P[A | C_j] P[C_j]$ schreiben. Der Nenner lässt sich mittels der [[formel_totale_wahrscheinlichkeit|Formel von der totalen Wahrscheinlichkeit]] durch die Partition $\{C_i\}$ ausdrücken. Einsetzen liefert die Formel.
