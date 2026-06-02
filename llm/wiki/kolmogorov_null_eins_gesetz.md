---
key: kolmogorov_null_eins_gesetz
title: Kolmogorovsches Null-Eins-Gesetz
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit, null_eins_gesetz
refs: [terminale_sigma_algebra_definition, unabhaengigkeit_blocklemma]
---
Sei $\{\mathcal{E}_n\}_{n \in \mathbb{N}}$ eine unabhängige Folge von schnittstabilen Ereignissystemen und $\mathcal{E}_\infty$ die zugehörige terminale $\sigma$-Algebra.

Dann gilt für jedes terminale Ereignis $A \in \mathcal{E}_\infty$:
$$P[A] \in \{0, 1\}$$

Allgemeiner gilt: Falls $A, B \in \mathcal{E}_\infty$, dann sind $A$ und $B$ unabhängig, d.h. $P[A \cap B] = P[A] P[B]$.

--proof--
Sei $\mathcal{C}_m := \sigma(\bigcup_{n=1}^m \mathcal{E}_n)$ und $\mathcal{D}_m := \sigma(\bigcup_{n=m+1}^\infty \mathcal{E}_n)$. Nach dem Blocklemma sind $\mathcal{C}_m$ und $\mathcal{D}_m$ unabhängig. Da $\mathcal{E}_\infty \subseteq \mathcal{D}_m$ für alle $m$, ist $\mathcal{E}_\infty$ von $\mathcal{C}_m$ unabhängig. Da dies für alle $m$ gilt, ist $\mathcal{E}_\infty$ unabhängig von der $\sigma$-Algebra $\mathcal{C} := \sigma(\bigcup_{m=1}^\infty \mathcal{C}_m)$.
Wegen $\mathcal{E}_\infty \subseteq \mathcal{C}$ ist $\mathcal{E}_\infty$ von sich selbst unabhängig. Für $A \in \mathcal{E}_\infty$ gilt also $P[A \cap A] = P[A] P[A]$, also $P[A] = P[A]^2$, was nur für $P[A] \in \{0, 1\}$ möglich ist.
