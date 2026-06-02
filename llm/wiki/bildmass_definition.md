---
key: bildmass_definition
title: Bildmaß (induziertes Maß)
type: def
tags: [masstheorie]
refs: [messbarer_raum_definition, sigma_additivitaet_mass_definition]
---
Seien $(\Omega, \mathcal{F}, \mu)$ ein Maßraum und $(\Omega', \mathcal{F}')$ ein messbarer Raum. Sei $f: \Omega \to \Omega'$ eine [[messbarer_raum_definition|messbare Abbildung]].

Das **Bildmaß** von $\mu$ unter $f$, bezeichnet mit $\mu f$ oder $f_*\mu$, ist die Mengenfunktion $\mu f: \mathcal{F}' \to [0, \infty]$, definiert durch:
$$(\mu f)(A') := \mu(f^{-1}(A')) \quad \text{für alle } A' \in \mathcal{F}'$$

--proof--
Es ist zu zeigen, dass $\mu f$ ein Maß auf $(\Omega', \mathcal{F}')$ ist:
\begin{enumerate}[label=(\arabic*)]
    \item **Nullstelle**: $(\mu f)(\emptyset) = \mu(f^{-1}(\emptyset)) = \mu(\emptyset) = 0$.
    \item **$\sigma$-Additivität**: Sei $\{A'_n\}_{n \in \mathbb{N}} \subseteq \mathcal{F}'$ eine Folge paarweise disjunkter Mengen. Da $f^{-1}(\bigcup A'_n) = \bigcup f^{-1}(A'_n)$ und die Urbilder $f^{-1}(A'_n)$ aufgrund der Disjunktheit der $A'_n$ ebenfalls paarweise disjunkt sind, folgt aus der $\sigma$-Additivität von $\mu$:
\end{enumerate}
$$(\mu f)\left(\bigcup_{n=1}^\infty A'_n\right) = \mu\left(\bigcup_{n=1}^\infty f^{-1}(A'_n)\right) = \sum_{n=1}^\infty \mu(f^{-1}(A'_n)) = \sum_{n=1}^\infty (\mu f)(A'_n)$$
--proof--
