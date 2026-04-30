---
key: wurzelkriterium
title: Wurzelkriterium für Reihen
type: satz
tags: [analysis, reihen, konvergenz]
refs: [absolute_konvergenz, reihe_definition]
---
Sei $\sum a_n$ eine unendliche [[reihe_definition|Reihe]].
\begin{enumerate}
    \item Existiert ein $q < 1$, so dass $\sqrt[n]{|a_n|} \le q$ für fast alle $n$, so [[absolute_konvergenz|konvergiert]] die [[reihe_definition|Reihe]] absolut.
    \item Gilt $\sqrt[n]{|a_n|} \ge 1$ für unendlich viele $n$, so divergiert die [[reihe_definition|Reihe]].
\end{enumerate}

--proof--
\begin{enumerate}
    \item Aus $\sqrt[n]{|a_n|} \le q$ folgt $|a_n| \le q^n$. Da $q < 1$, ist die geometrische [[reihe_definition|Reihe]] $\sum q^n$ eine [[absolute_konvergenz|konvergente]] Majorante. Nach dem Majorantenkriterium [[absolute_konvergenz|konvergiert]] $\sum a_n$ absolut.
    \item Aus $\sqrt[n]{|a_n|} \ge 1$ folgt $|a_n| \ge 1$. Die Glieder der [[reihe_definition|Reihe]] bilden somit keine Nullfolge, woraus die Divergenz folgt.
\end{enumerate}
