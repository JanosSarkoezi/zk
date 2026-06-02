---
key: reihe_unabhaengiger_zufallsvariablen_null_eins_gesetz
title: Null-Eins-Gesetz für Reihen unabhängiger Zufallsvariablen
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit, null_eins_gesetz, reihe
refs: [kolmogorov_null_eins_gesetz, unabhaengigkeit_zufallsgroessen_definition]
---
Sei $\{X_n\}_{n \in \mathbb{N}}$ eine unabhängige Folge von reellen Zufallsvariablen. Sei $A$ das Ereignis, dass die Reihe $\sum_{n=1}^\infty X_n$ konvergiert.

Dann gilt:
$$P[A] \in \{0, 1\}$$

Allgemeiner gilt dies für jedes Ereignis, das nur vom Konvergenzverhalten der Reihe abhängt (z.B. Divergenz gegen $+\infty$).

--proof--
Das Ereignis $A$ lässt sich als terminales Ereignis der Folge von $\sigma$-Algebren $\mathcal{E}_n = \sigma(X_n)$ darstellen. Da für jedes $m \in \mathbb{N}$ gilt:
$$\sum_{n=1}^\infty X_n \text{ konvergiert} \iff \sum_{n=m}^\infty X_n \text{ konvergiert}$$
ist $A$ in der $\sigma$-Algebra $\sigma(X_m, X_{m+1}, \dots)$ enthalten. Da dies für alle $m$ gilt, liegt $A$ in der terminalen $\sigma$-Algebra $\mathcal{E}_\infty$. Nach dem [[kolmogorov_null_eins_gesetz|Kolmogorovsches Null-Eins-Gesetz]] folgt $P[A] \in \{0, 1\}$.
