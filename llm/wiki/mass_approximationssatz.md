---
key: mass_approximationssatz
title: Approximationssatz für Maße
type: satz
tags: [masstheorie]
refs: [sigma_algebra_definition, ring_definition, caratheodory_fortsetzungssatz]
---
Sei $\mathcal{F} = \sigma(\mathcal{A})$ die von einer Algebra $\mathcal{A}$ erzeugte $\sigma$-Algebra. Ist $\mu: \mathcal{F} \to [0, \infty]$ ein endliches Maß, so gibt es für jede Menge $A \in \mathcal{F}$ und jedes $\epsilon > 0$ eine Menge $C \in \mathcal{A}$ mit:
$$\mu(A \Delta C) < \epsilon$$
Dabei bezeichnet $A \Delta C = (A \setminus C) \cup (C \setminus A)$ die symmetrische Differenz.

--proof--
Nach dem Satz von Carathéodory lässt sich das Maß $\mu$ als Einschränkung des äußeren Maßes $\mu^*$ darstellen, das durch $\mu^*$ auf $\mathcal{A}$ konstruiert wurde.
Für $A \in \mathcal{F}$ gibt es nach Definition des äußeren Maßes eine Folge $\{E_n\} \subseteq \mathcal{A}$ mit $A \subseteq \bigcup E_n$ und $\sum \mu(E_n) \le \mu(A) + \epsilon/2$.
Da $\mu$ endlich ist, konvergiert die Reihe, und man kann ein $N$ so groß wählen, dass für $C := \bigcup_{n=1}^N E_n \in \mathcal{A}$ (da $\mathcal{A}$ eine Algebra ist) die Differenz $\mu(A \Delta C)$ beliebig klein wird.
