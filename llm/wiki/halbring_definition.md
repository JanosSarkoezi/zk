---
key: halbring_definition
title: Definition eines Halbrings
type: def
tags: [masstheorie, mengensysteme]
refs: []
---
Ein Mengensystem $\mathcal{H} \subseteq 2^\Omega$ heißt Halbring auf $\Omega$, wenn es die folgenden Eigenschaften besitzt:
\begin{enumerate}[label=(\roman*)]
  \item Es gilt $\emptyset \in \mathcal{H}$.
  \item Für alle $A, B \in \mathcal{H}$ gilt $A \cap B \in \mathcal{H}$ ($\cap$-Stabilität).
  \item Für alle $A, B \in \mathcal{H}$ gibt es eine endliche disjunkte Familie $\{C_j\}_{j \in J} \subseteq \mathcal{H}$ mit $A \setminus B = \sum_{j \in J} C_j$.
\end{enumerate}

--examples--
Das wichtigste Beispiel für einen Halbring ist das System $\mathcal{J}(\mathbb{R}^n)$ der halboffenen Intervalle $(a, b]$ in $\mathbb{R}^n$. Halbringe dienen als Ausgangspunkt für die Konstruktion von Maßen (z.B. dem Lebesgue-Maß), da sich das Maß auf dem Halbring oft leicht definieren lässt und dann auf den erzeugten Ring bzw. die [[sigma_algebra_definition|$\sigma$-Algebra]] fortgesetzt werden kann.
