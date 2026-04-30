---
key: dynkin_system_definition
title: Definition eines Dynkin-Systems
type: def
tags: [masstheorie, mengensysteme]
refs: []
---
Ein Mengensystem $\mathcal{D} \subseteq 2^\Omega$ heißt Dynkin-System auf $\Omega$, wenn es die folgenden Eigenschaften besitzt:
\begin{enumerate}[label=(\roman*)]
  \item Es gilt $\Omega \in \mathcal{D}$.
  \item Für jede Menge $A \in \mathcal{D}$ gilt $A^c \in \mathcal{D}$.
  \item Für jede Folge paarweise disjunkter Mengen $\{A_n\}_{n \in \mathbb{N}} \subseteq \mathcal{D}$ gilt $\bigcup_{n=1}^\infty A_n \in \mathcal{D}$.
\end{enumerate}

--examples--
Jede [[sigma_algebra_definition|$\sigma$-Algebra]] ist offensichtlich auch ein Dynkin-System. Die Umkehrung gilt im Allgemeinen nicht, da ein Dynkin-System nur unter abzählbaren Vereinigungen **disjunkter** Mengen stabil sein muss.
Eigenschaften:
\begin{enumerate}[label=(\arabic*)]
  \item $\emptyset \in \mathcal{D}$.
  \item Sind $A, B \in \mathcal{D}$ with $B \subseteq A$, so folgt $A \setminus B = (A^c \cup B)^c \in \mathcal{D}$, da $A^c$ und $B$ disjunkt sind und in $\mathcal{D}$ liegen.
\end{enumerate}
