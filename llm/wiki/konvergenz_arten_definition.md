---
key: konvergenz_arten_definition
title: Konvergenzarten für Funktionenfolgen
type: def
tags: [maßtheorie]
refs: [fast_ueberall_definition]
---
Sei $\{f_n\}_{n \in \mathbb{N}}$ eine Folge messbarer reeller Funktionen auf $(\Omega, \mathcal{F}, \mu)$ und $f$ eine messbare Funktion.

\begin{enumerate}[label=(\arabic*)]
    \item **Punktweise Konvergenz**: $f_n(\omega) \to f(\omega)$ für alle $\omega \in \Omega$.
    \item **Punktweise Konvergenz fast überall**: $f_n \to f$ $\mu$-fast überall.
    \item **Gleichmäßige Konvergenz**: $\|f_n - f\| \to 0$ in der Supremumsnorm.
    \item **Gleichmäßige Konvergenz fast überall** (Konvergenz in $L^\infty$): $\|f_n - f\|_\infty \to 0$.
\end{enumerate}

--proof--
Gleichmäßige Konvergenz impliziert punktweise Konvergenz. Die "fast überall"-Varianten erlauben Ausnahmen auf Nullmengen, was in der Maßtheorie die natürliche Betrachtungsweise ist.
--proof--
