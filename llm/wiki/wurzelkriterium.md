---
key: wurzelkriterium
title: Wurzelkriterium für Reihen
type: satz
tags: [analysis, reihen, konvergenz]
refs: [absolute_konvergenz, reihe_definition]
---
Sei $\sum a_n$ eine unendliche Reihe.
\begin{enumerate}[label=\arabic*.]
    \item Existiert ein $q < 1$, so dass $\sqrt[n]{|a_n|} \le q$ für fast alle $n$, so konvergiert die Reihe absolut.
    \item Gilt $\sqrt[n]{|a_n|} \ge 1$ für unendlich viele $n$, so divergiert die Reihe.
\end{enumerate}

--proof--
\begin{enumerate}[label=\arabic*.]
    \item Aus $\sqrt[n]{|a_n|} \le q$ folgt $|a_n| \le q^n$. Da $q < 1$, ist die geometrische Reihe $\sum q^n$ eine konvergente Majorante. Nach dem Majorantenkriterium konvergiert $\sum a_n$ absolut.
    \item Aus $\sqrt[n]{|a_n|} \ge 1$ folgt $|a_n| \ge 1$. Die Glieder der Reihe bilden somit keine Nullfolge, woraus die Divergenz folgt.
\end{enumerate}
