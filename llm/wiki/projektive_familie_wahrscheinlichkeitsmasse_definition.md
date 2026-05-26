---
key: projektive_familie_wahrscheinlichkeitsmasse_definition
title: Projektive Familie von Wahrscheinlichkeitsmaßen
type: def
tags: [wahrscheinlichkeitstheorie, masstheorie]
refs: [wahrscheinlichkeitsraum_definition, produkt_sigma_algebra_definition]
---
Sei $I$ eine Indexmenge und $\{(\Omega_i, \mathcal{F}_i)\}_{i \in I}$ eine Familie von Messräumen. Eine Familie $\{P_J\}_{J \in \mathcal{H}(I)}$ von Wahrscheinlichkeitsmaßen auf den endlichen Teilprodukten $(\Omega_J, \mathcal{F}_J)$ heißt **projektiv**, wenn für alle endlichen Teilmengen $K \subseteq J \subseteq I$ gilt:
$$
P_K = P_J \circ \pi_{K,J}^{-1}
$$
wobei $\pi_{K,J}: \Omega_J \to \Omega_K$ die kanonische Projektion ist.

--proof--
Diese Bedingung ist notwendig, damit ein globales Wahrscheinlichkeitsmaß $P$ auf dem Produktraum $(\Omega, \mathcal{F})$ existiert, welches die $P_J$ als Bildmaße unter den Projektionen $\pi_J: \Omega \to \Omega_J$ besitzt.
