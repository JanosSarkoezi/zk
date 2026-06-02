---
key: borel_cantelli_lemma_1
title: Erstes Lemma von Borel-Cantelli
type: lemma
tags: wahrscheinlichkeit, konvergenz, borel_cantelli
refs: [wahrscheinlichkeitsraum_definition, limes_superior_inferior_definition]
---
Sei $\{A_n\}_{n \in \mathbb{N}}$ eine Folge von Ereignissen in einem Wahrscheinlichkeitsraum $(\Omega, \mathcal{F}, P)$. Falls die Summe der Wahrscheinlichkeiten konvergiert, d.h.
$$\sum_{n=1}^\infty P[A_n] < \infty$$
dann ist die Wahrscheinlichkeit für das Eintreten unendlich vieler dieser Ereignisse gleich Null:
$$P\left[ \limsup_{n \to \infty} A_n \right] = 0$$

--proof--
Es gilt nach Definition des Limes superior von Mengen:
$$\limsup_{n \to \infty} A_n = \bigcap_{n=1}^\infty \bigcup_{k=n}^\infty A_k$$
Wegen der Monotonie des Maßes gilt für jedes $m \in \mathbb{N}$:
$$P\left[ \bigcap_{n=1}^\infty \bigcup_{k=n}^\infty A_k \right] \le P\left[ \bigcup_{k=m}^\infty A_k \right]$$
Nach der $\sigma$-Subadditivität gilt:
$$P\left[ \bigcup_{k=m}^\infty A_k \right] \le \sum_{k=m}^\infty P[A_k]$$
Da die Reihe $\sum P[A_n]$ konvergiert, geht der Rest $\sum_{k=m}^\infty P[A_k]$ für $m \to \infty$ gegen Null. Somit muss die Wahrscheinlichkeit des Schnitts Null sein.
