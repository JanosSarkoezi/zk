---
key: peano_axiome
title: Die Peanoschen Axiome
type: axiom
tags: [analysis, naturals, foundation]
refs: []
---
Die Peanoschen Axiome bilden die Grundlage für die Konstruktion der natürlichen Zahlen $\mathbb{N}$. Sie wurden von Giuseppe Peano (1858-1932) eingeführt und lauten:

\begin{enumerate}[label=\arabic*.]
    \item 1 ist eine natürliche Zahl.
    \item Jeder natürlichen Zahl $n$ ist genau eine Nachfolgerzahl $n'$ zugeordnet.
    \item 1 ist kein Nachfolger einer natürlichen Zahl.
    \item Verschiedene natürliche Zahlen haben verschiedene Nachfolger: $n \neq m \Rightarrow n' \neq m'$.
    \item Induktionsaxiom: Enthält eine Menge $M$ die Zahl 1 und mit jedem $n \in M$ auch dessen Nachfolger $n'$, so besteht $M$ aus allen natürlichen Zahlen ($M = \mathbb{N}$).
\end{enumerate}

--proof--
H. Heuser, Lehrbuch der Analysis Teil 1, S. 34. Diese Axiome dienen als Fundament, um darauf das Rechnen in $\mathbb{N}$ (Addition, Multiplikation) rekursiv aufzubauen.
