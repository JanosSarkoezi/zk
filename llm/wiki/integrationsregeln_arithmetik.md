---
key: integrationsregeln_arithmetik
title: Arithmetische Regeln für Integrale
type: satz
tags: [analysis, integration]
refs: [riemann_integral_definition]
---
Sind $f$ und $g$ auf $[a, b]$ R-integrierbar, so gilt:
\begin{enumerate}[label=\arabic*.]
    \item **Linearität**: $\int_a^b (\alpha f + \beta g) \, dx = \alpha \int_a^b f \, dx + \beta \int_a^b g \, dx$ für $\alpha, \beta \in \mathbb{R}$.
    \item **Monotonie**: Ist $f(x) \le g(x)$ für alle $x \in [a, b]$, so ist $\int_a^b f \, dx \le \int_a^b g \, dx$.
    \item **Intervalladditivität**: $\int_a^b f \, dx = \int_a^c f \, dx + \int_c^b f \, dx$ für $c \in (a, b)$.
\end{enumerate}

--proof--
Diese Eigenschaften folgen unmittelbar aus den entsprechenden Eigenschaften der endlichen Riemannschen Summen durch Grenzübergang.
