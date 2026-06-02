---
key: unabhaengigkeit_projektionen_produktraum_satz
title: Unabhängigkeit der Projektionen im Produktraum
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit, produkt_mass
refs: [produkt_mass_definition, unabhaengigkeit_ereignissysteme_definition]
---
Sei $(\Omega, \mathcal{F}, P) = \bigotimes_{i \in I} (\Omega_i, \mathcal{F}_i, Q_i)$ der Produkt-Wahrscheinlichkeitsraum einer Familie von Wahrscheinlichkeitsräumen.

Dann ist die Familie der Koordinaten-$\sigma$-Algebren $\{\pi_i^{-1}(\mathcal{F}_i)\}_{i \in I}$ unabhängig unter dem Produktmaß $P$.

--proof--
Für jede endliche Teilmenge $J \subseteq I$ und jede Wahl von Ereignissen $A_i \in \mathcal{F}_i$ ($i \in J$) gilt nach Definition des Produktmaßes auf Zylindermengen:
$$P\left[ \bigcap_{i \in J} \pi_i^{-1}(A_i) \right] = P\left[ \prod_{i \in J} A_i \times \prod_{i \notin J} \Omega_i \right] = \prod_{i \in J} Q_i(A_i)$$
Da $P[\pi_i^{-1}(A_i)] = Q_i(A_i)$ (Randverteilung), gilt die Produktformel für die Unabhängigkeit.
