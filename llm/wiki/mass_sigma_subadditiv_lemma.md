---
key: mass_sigma_subadditiv_lemma
title: Monotonie und sigma-Subadditivität von Maßen
type: lemma
tags: [masstheorie, mass]
refs: [sigma_additivitaet_mass_definition, monotonie_subadditivitaet_definition]
---
Sei $\mathcal{C}$ ein Halbring und $\mu: \mathcal{C} \to [0, \infty]$ ein Maß. Dann ist $\mu$ monoton und $\sigma$-subadditiv.

Dabei heißt $\mu$ **$\sigma$-subadditiv**, wenn für jede Folge $\{A_k\}_{k \in \mathbb{N}} \subseteq \mathcal{C}$ mit $\bigcup_{k=1}^\infty A_k \in \mathcal{C}$ gilt:
$$\mu\left[\bigcup_{k=1}^\infty A_k\right] \le \sum_{k=1}^\infty \mu[A_k]$$

--proof--
Da $\mu$ ein Maß ist, ist es insbesondere ein Inhalt, also monoton.
Zum Nachweis der $\sigma$-[[monotonie_subadditivitaet_definition|Subadditivität]] können wir (per Fortsetzungssatz) annehmen, dass $\mathcal{C}$ ein Ring ist. Sei $A := \bigcup A_k \in \mathcal{C}$. Dann ist $B_n := \bigcup_{k=1}^n A_k \in \mathcal{C}$ monoton wachsend mit $B_n \uparrow A$.
Aus der Stetigkeit von unten und der endlichen [[monotonie_subadditivitaet_definition|Subadditivität]] folgt:
$$\mu[A] = \sup_{n \in \mathbb{N}} \mu[B_n] \le \sup_{n \in \mathbb{N}} \sum_{k=1}^n \mu[A_k] = \sum_{k=1}^\infty \mu[A_k]$$
--proof--
