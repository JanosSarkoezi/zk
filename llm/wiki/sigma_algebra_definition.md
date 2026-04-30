---
key: sigma_algebra_definition
title: Definition einer sigma-Algebra
type: def
tags: [masstheorie, mengensysteme]
refs: []
---
Ein Mengensystem $\mathcal{F} \subseteq 2^\Omega$ heißt $\sigma$-Algebra auf $\Omega$, wenn es die folgenden Eigenschaften besitzt:

\begin{enumerate}[label=(\roman*)]
    \item Es gilt $\Omega \in \mathcal{F}$.
    \item Für jede Menge $A \in \mathcal{F}$ gilt $A^c \in \mathcal{F}$.
    \item Für jede Folge $\{A_n\}_{n \in \mathbb{N}} \subseteq \mathcal{F}$ gilt $\bigcup_{n=1}^\infty A_n \in \mathcal{F}$.
\end{enumerate}

--examples--
Ist $\mathcal{F}$ eine [[sigma_algebra_definition|$\sigma$-Algebra]] auf $\Omega$, so heißt eine Menge $A \in \mathcal{F}$ messbar bezüglich $\mathcal{F}$.
Beispiele:
\begin{enumerate}[label=(\arabic*)]
    \item Die Potenzmenge $2^\Omega$ ist eine $\sigma$-Algebra auf $\Omega$.
    \item Das Mengensystem $\{\emptyset, \Omega\}$ ist eine $\sigma$-Algebra auf $\Omega$.
\end{enumerate}
