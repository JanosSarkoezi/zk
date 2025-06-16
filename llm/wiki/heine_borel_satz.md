---
key: heine_borel_satz
title: Satz von Heine-Borel
type: satz
tags: [analysis, topologie, kompaktheit]
refs: [kompaktheit_folgen_definition]
---
In $\mathbb{R}^n$ (hier speziell $\mathbb{R}$) ist eine Teilmenge $K$ genau dann kompakt, wenn sie abgeschlossen und beschränkt ist.

--proof--
Heuser (Satz 36.2): 
\begin{enumerate}[label=\arabic*.]
    \item ($\implies$): Ist $K$ kompakt, so muss $K$ beschränkt sein (sonst gäbe es eine Folge $x_n$ mit $|x_n| \to \infty$ ohne konvergente Teilfolge). Zudem muss $K$ abgeschlossen sein (da jeder Häufungspunkt Grenzwert einer Folge in $K$ ist und somit nach Definition in $K$ liegen muss).
    \item ($\impliedby$): Ist $K$ beschränkt, besitzt jede Folge nach Bolzano-Weierstraß eine konvergente Teilfolge. Da $K$ abgeschlossen ist, liegt der Grenzwert dieser Teilfolge in $K$.
\end{enumerate}
