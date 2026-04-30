---
key: topologie_definition
title: Definition einer Topologie
type: def
tags: [topologie, mengensysteme]
refs: []
---
Ein Mengensystem $\mathcal{T} \subseteq 2^\Omega$ heißt Topologie auf $\Omega$, wenn es die folgenden Eigenschaften besitzt:
\begin{enumerate}[label=(\roman*)]
    \item Es gilt $\Omega \in \mathcal{T}$ und $\emptyset \in \mathcal{T}$.
    \item Für jede Familie $\{Q_i\}_{i \in I} \subseteq \mathcal{T}$ gilt $\bigcup_{i \in I} Q_i \in \mathcal{T}$.
    \item Für jede endliche Familie $\{Q_i\}_{i \in I} \subseteq \mathcal{T}$ gilt $\bigcap_{i \in I} Q_i \in \mathcal{T}$.
\end{enumerate}

--examples--
Eine Menge $A \in 2^\Omega$ heißt offen bezüglich $\mathcal{T}$, wenn $A \in \mathcal{T}$ gilt. Eine Menge $A \in 2^\Omega$ heißt abgeschlossen bezüglich $\mathcal{T}$, wenn $A^c \in \mathcal{T}$ gilt (d.h. das Komplement ist offen).
Beispiele:
\begin{enumerate}[label=(\arabic*)]
    \item Die Potenzmenge $2^\Omega$ ist eine Topologie auf $\Omega$.
    \item Das Mengensystem $\{\emptyset, \Omega\}$ ist eine Topologie auf $\Omega$.
\end{enumerate}
