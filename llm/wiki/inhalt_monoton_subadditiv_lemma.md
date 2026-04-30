---
key: inhalt_monoton_subadditiv_lemma
title: Monotonie und Subadditivität von Inhalten
type: lemma
tags: [masstheorie, inhalt]
refs: [inhalt_definition, monotonie_subadditivitaet_definition, inhalt_fortsetzung_satz]
---
Sei $\mathcal{C}$ ein Halbring und $\mu: \mathcal{C} \to [0, \infty]$ ein Inhalt. Dann ist $\mu$ monoton und endlich subadditiv.

--proof--
Aufgrund des Fortsetzungssatzes können wir annehmen, dass $\mathcal{C}$ ein Ring ist.

1. **Monotonie**: Für $A, B \in \mathcal{C}$ mit $B \subseteq A$ gilt $A = B + (A \setminus B)$. Da $B$ und $A \setminus B$ disjunkt sind und beide im Ring liegen, folgt aus der Additivität:
   $$\mu[A] = \mu[B] + \mu[A \setminus B] \ge \mu[B]$$

2. **Endliche [[monotonie_subadditivitaet_definition|Subadditivität]]**: Sei $\{A_k\}_{k=1,\dots,n} \subseteq \mathcal{C}$ eine endliche Familie. Wir definieren die disjunkte Familie:
   $$B_1 := A_1, \quad B_k := A_k \setminus \bigcup_{j=1}^{k-1} A_j$$
   Dann sind $\{B_k\}$ disjunkt, $B_k \in \mathcal{C}$ (da $\mathcal{C}$ ein Ring ist) und $\sum_{k=1}^n B_k = \bigcup_{k=1}^n A_k$.
   Aus der endlichen Additivität und der Monotonie ($B_k \subseteq A_k$) folgt:
   $$\mu\left[\bigcup_{k=1}^n A_k\right] = \mu\left[\sum_{k=1}^n B_k\right] = \sum_{k=1}^n \mu[B_k] \le \sum_{k=1}^n \mu[A_k]$$
--proof--
