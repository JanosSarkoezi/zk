---
key: arzela_ascoli_satz
title: Satz von Arzelà-Ascoli
type: satz
tags: [analysis, konvergenz, kompaktheit, gleichstetigkeit]
refs: [stetigkeit_folgen_definition, kompaktheit_folgen_definition]
---
Eine Folge $(f_n)$ stetiger Funktionen auf einer kompakten Menge $X \subset \mathbb{R}$ besitzt genau dann eine gleichmäßig konvergente Teilfolge, wenn sie:
\begin{enumerate}
    \item \textbf{gleichmäßig beschränkt} ist (es gibt ein $M$ mit $|f_n(x)| \le M$ für alle $n, x$), und
    \item \textbf{gleichstetig} ist (zu jedem $\epsilon > 0$ gibt es ein $\delta > 0$, so dass für alle $n$ und alle $x, y$ mit $|x-y| < \delta$ gilt: $|f_n(x) - f_n(y)| < \epsilon$).
\end{enumerate}

--proof--
Die Notwendigkeit der Bedingungen ist leicht zu zeigen. Für die Hinlänglichkeit nutzt man ein Diagonalverfahren auf einer abzählbaren dichten Teilmenge von $X$ (z.B. die rationalen Zahlen), um eine punktweise konvergente Teilfolge zu erhalten. Die Gleichstetigkeit erlaubt es dann, diese punktweise Konvergenz auf ganz $X$ zur gleichmäßigen Konvergenz zu erweitern.
