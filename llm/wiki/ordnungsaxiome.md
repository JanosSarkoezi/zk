---
key: ordnungsaxiome
title: Die Ordnungsaxiome für die reellen Zahlen
type: axiom
tags: [analysis, reals, order]
refs: [koerperaxiome]
---
Die Ordnungsaxiome definieren die „Kleiner-Beziehung“ $a < b$ in $\mathbb{R}$:

\begin{enumerate}[label=(A \arabic*)]
    \item Trichotomiegesetz: Für zwei reelle Zahlen $a, b$ gilt stets genau eine der Beziehungen $a < b$, $a = b$ oder $a > b$.
    \item Transitivitätsgesetz: $a < b$ und $b < c \Rightarrow a < c$.
    \item Monotoniegesetze:
    \begin{enumerate}[leftmargin=0.5cm]
        \item $a < b \Rightarrow a+c < b+c$ für jedes $c$.
        \item $a < b \Rightarrow ac < bc$ für jedes $c > 0$.
    \end{enumerate}
\end{enumerate}

--proof--
H. Heuser, Lehrbuch der Analysis Teil 1, S. 36. Diese Axiome erweitern den Körper $\mathbb{R}$ zu einem angeordneten Körper.
