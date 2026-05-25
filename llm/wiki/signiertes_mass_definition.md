---
key: signiertes_mass_definition
title: Definition eines signierten Maßes
type: def
tags: [masstheorie, grundlagen]
refs: [sigma_additivitaet_mass_definition]
---
Sei $\mathcal{C}$ ein Mengensystem mit $\emptyset \in \mathcal{C}$. Eine Mengenfunktion $\nu: \mathcal{C} \to \bar{\mathbb{R}}$ heißt **signiertes Maß**, wenn sie die folgenden Eigenschaften besitzt:

\begin{enumerate}[label=(\arabic*)]
    \item $\nu$ nimmt höchstens einen der Werte $-\infty$ und $+\infty$ an.
    \item $\nu[\emptyset] = 0$.
    \item $\nu$ ist $\sigma$-additiv, d. h. für jede disjunkte Folge $\{A_k\}_{k \in \mathbb{N}} \subseteq \mathcal{C}$ mit $\sum_{k=1}^\infty A_k \in \mathcal{C}$ gilt:
          $$\nu\left[\sum_{k=1}^\infty A_k\right] = \sum_{k=1}^\infty \nu[A_k]$$
          Dabei muss die Reihe in $\bar{\mathbb{R}}$ unbedingt konvergent sein.
\end{enumerate}

--proof--
Ein signiertes Maß verallgemeinert den Maßbegriff, indem es auch negative Werte zulässt. Die Bedingung (1) verhindert undefinierte Ausdrücke wie $\infty - \infty$ bei der Summation. Jedes Maß ist ein signiertes Maß.
