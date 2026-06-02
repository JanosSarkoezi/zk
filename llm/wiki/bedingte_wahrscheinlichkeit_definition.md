---
key: bedingte_wahrscheinlichkeit_definition
title: Bedingte Wahrscheinlichkeit
type: def
tags: wahrscheinlichkeit, bedingte_wahrscheinlichkeit
refs: [wahrscheinlichkeitsraum_definition]
---
Sei $(\Omega, \mathcal{F}, P)$ ein Wahrscheinlichkeitsraum und $C \in \mathcal{F}$ ein Ereignis mit $P[C] > 0$.

Das Wahrscheinlichkeitsmaß $P[ \cdot | C]: \mathcal{F} \to [0,1]$, definiert durch
$$P[A | C] := \frac{P[A \cap C]}{P[C]}$$
für alle $A \in \mathcal{F}$, heißt **bedingtes Wahrscheinlichkeitsmaß** unter $C$.

Für ein Ereignis $A \in \mathcal{F}$ heißt der Wert $P[A | C]$ die **bedingte Wahrscheinlichkeit** von $A$ unter $C$.

--proof--
Dass $P[ \cdot | C]$ tatsächlich ein Wahrscheinlichkeitsmaß auf $(\Omega, \mathcal{F})$ ist, folgt aus der $\sigma$-Additivität von $P$:
\begin{enumerate}[label=(\arabic*)]
    \item $P[\Omega | C] = \frac{P[\Omega \cap C]}{P[C]} = \frac{P[C]}{P[C]} = 1$.
    \item Für eine Folge paarweise disjunkter Ereignisse $\{A_n\}_{n \in \mathbb{N}} \subseteq \mathcal{F}$ gilt:
$$P\left[ \bigcup_{n=1}^\infty A_n \middle| C \right] = \frac{P\left( \left( \bigcup_{n=1}^\infty A_n \right) \cap C \right)}{P[C]} = \frac{P\left( \bigcup_{n=1}^\infty (A_n \cap C) \right)}{P[C]} = \frac{\sum_{n=1}^\infty P[A_n \cap C]}{P[C]} = \sum_{n=1}^\infty P[A_n | C]$$
wobei die dritte Gleichheit aus der Disjunktheit der Mengen $A_n \cap C$ folgt.
\end{enumerate}
