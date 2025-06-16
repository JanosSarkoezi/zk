---
key: hauptsatz_differential_integralrechnung
title: Hauptsatz der Differential- und Integralrechnung
type: satz
tags: [analysis, integration, ableitung]
refs: [riemann_integral_definition, stammfunktion_definition]
---
Der Hauptsatz besteht aus zwei komplementären Aussagen:

\begin{enumerate}[label=\arabic*.]
    \item **Teil (Existenz von Stammfunktionen)**: Ist $f: [a, b] \to \mathbb{R}$ stetig, so ist die durch
    $$F(x) = \int_a^x f(t) \, dt$$
    definierte Integralfunktion eine Stammfunktion von $f$ auf $[a, b]$, d.h. $F'(x) = f(x)$.

    \item **Teil (Berechnung von Integralen)**: Ist $F$ eine beliebige Stammfunktion der R-integrierbaren Funktion $f$ auf $[a, b]$, so gilt:
    $$\int_a^b f(x) \, dx = F(b) - F(a) = [F(x)]_a^b$$
\end{enumerate}

--proof--
Der Beweis des ersten Teils nutzt den Mittelwertsatz der Integralrechnung, um zu zeigen, dass der Differenzenquotient von $F$ gegen $f(x)$ strebt. Der zweite Teil folgt daraus, dass sich zwei Stammfunktionen nur um eine Konstante unterscheiden.
