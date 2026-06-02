---
key: unabhaengigkeit_blocklemma
title: Blocklemma für unabhängige Ereignissysteme
type: lemma
tags: wahrscheinlichkeit, unabhaengigkeit
refs: [unabhaengigkeit_erzeugte_sigma_algebren_satz]
---
Sei $\{\mathcal{E}_i\}_{i \in I}$ eine unabhängige Familie von schnittstabilen Ereignissystemen. Seien $M_1, \dots, M_n \subseteq I$ paarweise disjunkte Teilmengen der Indexmenge. Dann ist die Familie der $\sigma$-Algebren
$$\mathcal{G}_k := \sigma\left( \bigcup_{i \in M_k} \mathcal{E}_i \right), \quad k=1, \dots, n$$
ebenfalls unabhängig.

--proof--
Definiere für jede Teilmenge $L \subseteq I$ das System $\mathcal{C}_L$ aller endlichen Schnitte von Ereignissen aus $\bigcup_{i \in L} \mathcal{E}_i$. Da die $\mathcal{E}_i$ einzeln schnittstabil sind und die $M_k$ disjunkt sind, lässt sich zeigen, dass die Systeme $\mathcal{C}_{M_k}$ unabhängig und schnittstabil sind. Nach dem Satz über die [[unabhaengigkeit_erzeugte_sigma_algebren_satz|Unabhängigkeit erzeugter sigma-Algebren]] folgt dann die Unabhängigkeit der erzeugten $\sigma$-Algebren $\sigma(\mathcal{C}_{M_k}) = \sigma(\bigcup_{i \in M_k} \mathcal{E}_i)$.
