---
key: sigma_additivitaet_mass_definition
title: Definition eines Maßes
type: def
tags: [masstheorie, grundlagen]
refs: [inhalt_definition]
---
Eine Mengenfunktion $\mu: \mathcal{C} \to [0, \infty]$ heißt:

- **$\sigma$-additiv**, wenn für jede disjunkte Folge $\{A_k\}_{k \in \mathbb{N}} \subseteq \mathcal{C}$ mit $\sum_{k=1}^\infty A_k \in \mathcal{C}$ gilt:
  $$\mu\left[\sum_{k=1}^\infty A_k\right] = \sum_{k=1}^\infty \mu[A_k]$$

- **Maß**, wenn $\mu[\emptyset] = 0$ gilt und $\mu$ $\sigma$-additiv ist.

--proof--
Ein Maß ist ein $\sigma$-additiver Inhalt. Die $\sigma$-Additivität ist die zentrale Eigenschaft, die den Übergang von endlichen Summen zu unendlichen Reihen erlaubt und damit die Grundlage für die Integrationstheorie (Lebesgue-Integral) bildet.
