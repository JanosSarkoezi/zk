---
key: quotientenkriterium
title: Quotientenkriterium für Reihen
type: satz
tags: [analysis, reihen, konvergenz]
refs: [absolute_konvergenz, reihe_definition]
---
Sei $\sum a_n$ eine [[reihe_definition|Reihe]] mit $a_n \neq 0$ für fast alle $n$.
\begin{enumerate}
    \item Existiert ein $q < 1$, so dass $|\frac{a_{n+1}}{a_n}| \le q$ für fast alle $n$, so [[absolute_konvergenz|konvergiert]] die [[reihe_definition|Reihe]] absolut.
    \item Gilt $|\frac{a_{n+1}}{a_n}| \ge 1$ für fast alle $n$, so divergiert die [[reihe_definition|Reihe]].
\end{enumerate}

--proof--
\begin{enumerate}
    \item Sei $|\frac{a_{n+1}}{a_n}| \le q$ für $n \ge N$. Dann gilt $|a_{N+k}| \le q^k |a_N|$. 
    Die [[reihe_definition|Reihe]] $\sum_{k=0}^\infty |a_{N+k}|$ hat somit die [[absolute_konvergenz|konvergente]] geometrische [[reihe_definition|Reihe]] $\sum q^k |a_N|$ als Majorante (da $q < 1$) und [[absolute_konvergenz|konvergiert]] nach dem Majorantenkriterium.
    \item Falls $|\frac{a_{n+1}}{a_n}| \ge 1$, so ist $|a_{n+1}| \ge |a_n|$. Die Glieder bilden also keine Nullfolge, was nach dem Nullfolgenkriterium die Divergenz impliziert.
\end{enumerate}
