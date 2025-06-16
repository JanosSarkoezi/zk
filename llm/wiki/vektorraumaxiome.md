---
key: vektorraumaxiome
title: Die Vektorraumaxiome
type: axiom
tags: [analysis, linear_algebra, functions]
refs: [koerperaxiome]
---
Ein linearer Raum (Vektorraum) über einem Körper (meist $\mathbb{R}$) ist eine Menge $E$, auf der eine Addition und eine Skalarmultiplikation definiert sind, die folgende Axiome erfüllen:

\begin{enumerate}[label=(V \arabic*)]
    \item $a+(b+c) = (a+b)+c$ (Assoziativgesetz der Addition)
    \item $a+b = b+a$ (Kommutativgesetz der Addition)
    \item Es gibt ein Nullelement $0 \in E$ mit $a+0 = a$.
    \item Zu jedem $a \in E$ gibt es ein $-a \in E$ mit $a+(-a) = 0$.
    \item $\alpha(a+b) = \alpha a + \alpha b$ (Distributivgesetz I)
    \item $(\alpha+\beta)a = \alpha a + \beta a$ (Distributivgesetz II)
    \item $(\alpha\beta)a = \alpha(\beta a)$ (Assoziativgesetz der Skalarmultiplikation)
    \item $1 \cdot a = a$ (Neutralität der Eins)
\end{enumerate}

--proof--
H. Heuser, Lehrbuch der Analysis Teil 1, S. 118. Diese Axiome bilden die Grundlage für die Theorie der Funktionenräume in der Analysis.
