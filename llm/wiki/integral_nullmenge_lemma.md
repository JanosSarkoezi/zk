---
key: integral_nullmenge_lemma
title: Integration über Nullmengen und fast überall verschwindende Funktionen
type: lemma
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [lebesgue_integral_positiv_definition, fast_ueberall_definition]
---
Sei $(\Omega, \mathcal{F}, \mu)$ ein Maßraum und $f$ eine messbare Funktion.

\begin{enumerate}[label=(\arabic*)]
    \item Ist $f \ge 0$ und $\int_\Omega f \, d\mu = 0$, so gilt $f = 0$ fast überall.
    \item Gilt $f = 0$ fast überall, so ist $\int_\Omega |f| \, d\mu = 0$.
    \item Unterscheiden sich zwei positive messbare Funktionen $f$ und $g$ nur auf einer Nullmenge ($f = g$ f.ü.), so gilt $\int_\Omega f \, d\mu = \int_\Omega g \, d\mu$.
\end{enumerate}

--proof--
\begin{enumerate}[label=(\arabic*)]
    \item Für jedes $n \in \mathbb{N}$ gilt $\{f \ge 1/n\} \subseteq \{f > 0\}$. Nach der Markov-Ungleichung ist $\mu(\{f \ge 1/n\}) \le n \int f \, d\mu = 0$. Mit der Stetigkeit des Maßes von unten folgt $\mu(\{f > 0\}) = \lim \mu(\{f \ge 1/n\}) = 0$.
    \item Folgt aus der Definition des Integrals für einfache Funktionen (da $\chi_A$ für eine Nullmenge $A$ das Integral $\mu(A) = 0$ hat) und dem Approximationssatz.
    \item Folgt aus der Zerlegung $f = f \chi_{\{f=g\}} + f \chi_{\{f \neq g\}}$, wobei das zweite Integral wegen (2) verschwindet.
\end{enumerate}
