---
key: ring_definition
title: Definition eines Rings
type: def
tags: [masstheorie, mengensysteme]
refs: []
---
Ein Mengensystem $\mathcal{R} \subseteq 2^\Omega$ heißt Ring auf $\Omega$, wenn es die folgenden Eigenschaften besitzt:
\begin{enumerate}[label=(\roman*)]
  \item Es gilt $\emptyset \in \mathcal{R}$.
  \item Für alle $A, B \in \mathcal{R}$ gilt $A \setminus B \in \mathcal{R}$.
  \item Für alle $A, B \in \mathcal{R}$ gilt $A \cup B \in \mathcal{R}$.
\end{enumerate}

--examples--
Jeder Ring ist ein Halbring. Ein Ring ist zudem stabil unter endlichen Durchschnitten, da $A \cap B = A \setminus (A \setminus B)$ gilt.
Ein Ring, der auch die Grundmenge $\Omega$ enthält, heißt Algebra.
