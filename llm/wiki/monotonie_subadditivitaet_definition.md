---
key: monotonie_subadditivitaet_definition
title: Monotonie und Subadditivität
type: def
tags: [masstheorie, grundlagen]
refs: [mengenfunktion_definition]
---
Eine [[mengenfunktion_definition|Mengenfunktion]] $\mu: \mathcal{C} \to [0, \infty]$ heißt:

- **monoton**, wenn für alle $A, B \in \mathcal{C}$ mit $B \subseteq A$ gilt:
  $$\mu[B] \le \mu[A]$$

- **subadditiv**, wenn für alle $A, B \in \mathcal{C}$ mit $A \cup B \in \mathcal{C}$ gilt:
  $$\mu[A \cup B] \le \mu[A] + \mu[B]$$

- **endlich subadditiv**, wenn für jede endliche Familie $\{A_i\}_{i \in I} \subseteq \mathcal{C}$ mit $\bigcup_{i \in I} A_i \in \mathcal{C}$ gilt:
  $$\mu\left[\bigcup_{i \in I} A_i\right] \le \sum_{i \in I} \mu[A_i]$$

--proof--
Jede endlich subadditive [[mengenfunktion_definition|Mengenfunktion]] ist subadditiv. Auf einem Ring ist auch jede subadditive [[mengenfunktion_definition|Mengenfunktion]] endlich subadditiv.
