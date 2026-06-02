---
key: unabhaengigkeit_zufallsgroessen_produktmass_satz
title: Charakterisierung der Unabhängigkeit durch das Produktmaß
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit, produkt_mass
refs: [unabhaengigkeit_zufallsgroessen_definition, produkt_mass_definition]
---
Sei $\{X_i\}_{i \in I}$ eine Familie von Zufallsgrößen $X_i : \Omega \to \Omega'_i$ und sei $X = (X_i)_{i \in I} : \Omega \to \prod_{i \in I} \Omega'_i$ die gemeinsame Zufallsgröße.

Die Familie $\{X_i\}_{i \in I}$ ist genau dann unabhängig, wenn das Bildmaß $P^X$ (die gemeinsame Verteilung) gleich dem Produktmaß der Randverteilungen $P^{X_i}$ ist:
$$P^X = \bigotimes_{i \in I} P^{X_i}$$

--proof--
Nach dem Eindeutigkeitssatz für Maße ist die Gleichheit zweier Maße auf einem Produktraum äquivalent zur Gleichheit auf den Rechteckmengen (Zylindermengen). Ein Zylinder mit endlicher Basis $J$ hat das Maß $P^X(\prod_{i \in J} B_i \times \prod_{i \notin J} \Omega'_i) = P[\bigcap_{i \in J} \{X_i \in B_i\}]$. Das Produktmaß ordnet dieser Menge den Wert $\prod_{i \in J} P^{X_i}(B_i)$ zu. Die Gleichheit dieser Werte für alle endlichen $J$ und alle messbaren $B_i$ ist gerade die Definition der Unabhängigkeit der Familie $\{X_i\}$.
