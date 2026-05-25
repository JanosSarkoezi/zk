---
key: aeusseres_mass_definition
title: Äußeres Maß
type: def
tags: [masstheorie]
refs: [sigma_additivitaet_mass_definition]
---
Sei $\Omega$ eine Menge. Eine Abbildung $\mu^*: 2^\Omega \to [0, \infty]$ heißt **äußeres Maß**, wenn sie folgende Eigenschaften besitzt:

\begin{enumerate}[label=(\arabic*)]
    \item **Nullstelle**: $\mu^*(\emptyset) = 0$.
    \item **Monotonie**: Aus $A \subseteq B \subseteq \Omega$ folgt $\mu^*(A) \le \mu^*(B)$.
    \item **$\sigma$-Subadditivität**: Für jede Folge $\{A_n\}_{n \in \mathbb{N}}$ von Teilmengen von $\Omega$ gilt:
          $$\mu^*\left(\bigcup_{n=1}^\infty A_n\right) \le \sum_{n=1}^\infty \mu^*(A_n)$$
\end{enumerate}

--proof--
Ein äußeres Maß ist im Allgemeinen kein Maß, da es nicht notwendigerweise additiv auf disjunkten Mengen ist. Es dient als Konstruktionswerkzeug, um mittels des Carathéodory-Kriteriums eine $\sigma$-Algebra und ein darauf definiertes Maß zu erhalten.
