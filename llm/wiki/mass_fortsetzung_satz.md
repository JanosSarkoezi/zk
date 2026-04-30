---
key: mass_fortsetzung_satz
title: Fortsetzungssatz für Maße
type: satz
tags: [masstheorie, halbring, ring]
refs: [halbring_definition, inhalt_fortsetzung_satz, sigma_additivitaet_mass_definition]
---
Sei $\mathcal{C}$ ein Halbring. Dann besitzt jedes Maß $\mu: \mathcal{C} \to [0, \infty]$ eine eindeutige Fortsetzung zu einem Maß $\bar{\mu}: \rho(\mathcal{C}) \to [0, \infty]$.

--proof--
Da $\mu$ ein Maß ist, ist es insbesondere ein Inhalt. Nach dem [[inhalt_fortsetzung_satz|Fortsetzungssatz für Inhalte]] existiert eine eindeutige Fortsetzung $\bar{\mu}$ auf den erzeugten Ring $\rho(\mathcal{C})$, die dort ein Inhalt ist. Es bleibt zu zeigen, dass $\bar{\mu}$ $\sigma$-additiv ist.

Sei $A \in \rho(\mathcal{C})$ und $\{A_k\}_{k \in \mathbb{N}} \subseteq \rho(\mathcal{C})$ eine disjunkte Folge mit $A = \sum_{k=1}^\infty A_k$.
Da $A \in \rho(\mathcal{C})$, existiert eine endliche disjunkte Familie $\{B_i\}_{i \in I} \subseteq \mathcal{C}$ mit $A = \sum_{i \in I} B_i$.
Analog existieren für jedes $k \in \mathbb{N}$ endliche disjunkte Familien $\{B_{k,j}\}_{j \in J(k)} \subseteq \mathcal{C}$ mit $A_k = \sum_{j \in J(k)} B_{k,j}$.

Durch geschicktes Ausnutzen der $\sigma$-Additivität von $\mu$ auf dem Halbring $\mathcal{C}$ (unter Verwendung von Schnitten $B_i \cap B_{k,j}$) zeigt man, dass $\bar{\mu}[A] = \sum_{k=1}^\infty \bar{\mu}[A_k]$.
--proof--
