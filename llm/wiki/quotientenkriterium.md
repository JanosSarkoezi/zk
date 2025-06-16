---
key: quotientenkriterium
title: Quotientenkriterium für Reihen
type: satz
tags: [analysis, reihen, konvergenz]
refs: [absolute_konvergenz, reihe_definition]
---
Sei $\sum a_n$ eine Reihe mit $a_n \neq 0$ für fast alle $n$.
\begin{enumerate}[label=\arabic*.]
    \item Existiert ein $q < 1$, so dass $|\frac{a_{n+1}}{a_n}| \le q$ für fast alle $n$, so konvergiert die Reihe absolut.
    \item Gilt $|\frac{a_{n+1}}{a_n}| \ge 1$ für fast alle $n$, so divergiert die Reihe.
\end{enumerate}

--proof--
\begin{enumerate}[label=\arabic*.]
    \item Sei $|\frac{a_{n+1}}{a_n}| \le q$ für $n \ge N$. Dann gilt $|a_{N+k}| \le q^k |a_N|$. 
    Die Reihe $\sum_{k=0}^\infty |a_{N+k}|$ hat somit die konvergente geometrische Reihe $\sum q^k |a_N|$ als Majorante (da $q < 1$) und konvergiert nach dem Majorantenkriterium.
    \item Falls $|\frac{a_{n+1}}{a_n}| \ge 1$, so ist $|a_{n+1}| \ge |a_n|$. Die Glieder bilden also keine Nullfolge, was nach dem Nullfolgenkriterium die Divergenz impliziert.
\end{enumerate}
