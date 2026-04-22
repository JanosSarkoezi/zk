---
key: konvergenz_funktionen_definition
title: Punktweise und Gleichmäßige Konvergenz
type: def
tags: [analysis, konvergenz, funktionenfolge]
refs: [grenzwert_definition]
---
Eine Folge von Funktionen $(f_n)$ auf einer Menge $X$ heißt:
\begin{enumerate}
    \item \textbf{punktweise konvergent} gegen $f$, wenn für jedes $x \in X$ die Zahlenfolge $(f_n(x))$ gegen $f(x)$ konvergiert.
    \item \textbf{gleichmäßig konvergent} gegen $f$, wenn es zu jedem $\epsilon > 0$ ein $n_0(\epsilon)$ gibt (das nicht von $x$ abhängt), so dass für alle $n > n_0$ und alle $x \in X$ gilt:
    $$|f_n(x) - f(x)| < \epsilon$$
\end{enumerate}

--proof--
Die gleichmäßige Konvergenz ist eine stärkere Bedingung als die punktweise Konvergenz. Sie besagt anschaulich, dass die Funktionen $f_n$ ab einem gewissen $n$ komplett innerhalb eines "$\epsilon$-Schlauchs" um die Grenzfunktion $f$ liegen. Formal lässt sich dies über die Supremumsnorm ausdrücken: $f_n \to f$ gleichmäßig genau dann, wenn $\|f_n - f\|_\infty \to 0$.
