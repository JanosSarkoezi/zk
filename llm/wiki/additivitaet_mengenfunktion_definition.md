---
key: additivitaet_mengenfunktion_definition
title: Additivität von Mengenfunktionen
type: def
tags: [masstheorie, grundlagen]
refs: [mengenfunktion_definition]
---
Eine [[mengenfunktion_definition|Mengenfunktion]] $\mu: \mathcal{C} \to [0, \infty]$ heißt:

- **additiv**, wenn für je zwei Mengen $A, B \in \mathcal{C}$ mit $A \cap B = \emptyset$ und $A + B \in \mathcal{C}$ gilt:
  $$\mu[A + B] = \mu[A] + \mu[B]$$

- **endlich additiv**, wenn für jede endliche disjunkte Familie $\{A_i\}_{i \in I} \subseteq \mathcal{C}$ mit $\sum_{i \in I} A_i \in \mathcal{C}$ gilt:
  $$\mu\left[\sum_{i \in I} A_i\right] = \sum_{i \in I} \mu[A_i]$$

--proof--
Jede endlich additive [[mengenfunktion_definition|Mengenfunktion]] ist offensichtlich auch additiv (wähle $|I|=2$). Die Umkehrung gilt im Allgemeinen nur, wenn das Mengensystem $\mathcal{C}$ stabil unter endlichen Vereinigungen ist (z. B. ein Ring).
