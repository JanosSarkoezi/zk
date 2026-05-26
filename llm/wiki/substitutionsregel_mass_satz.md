---
key: substitutionsregel_mass_satz
title: Substitutionsregel (Transformationssatz) für Maße
type: satz
tags: [integration, masstheorie]
refs: [bildmass_definition, lebesgue_integral_positiv_definition]
---
Seien $(\Omega, \mathcal{F}, \mu)$ und $(\Omega', \mathcal{F}')$ Messräume und $T: \Omega \to \Omega'$ eine messbare Abbildung. Sei $\mu_T$ das Bildmaß von $\mu$ unter $T$. Für jede messbare Funktion $h: \Omega' \to \bar{\mathbb{R}}$ gilt:

\begin{enumerate}[label=(\arabic*)]
    \item Ist $h \ge 0$, so gilt $\int_{\Omega'} h \, d\mu_T = \int_\Omega (h \circ T) \, d\mu$.
    \item $h$ ist genau dann $\mu_T$-integrierbar, wenn $h \circ T$ $\mu$-integrierbar ist. In diesem Fall gilt die obige Gleichung ebenfalls.
\end{enumerate}

--proof--
Beweis durch algebraische Induktion über $h$:
\begin{enumerate}[label=(\arabic*)]
    \item Für $h = \chi_{A'}$ gilt $\int \chi_{A'} \, d\mu_T = \mu_T(A') = \mu(T^{-1}(A')) = \int \chi_{T^{-1}(A')} \, d\mu = \int (\chi_{A'} \circ T) \, d\mu$.
    \item Erweiterung auf einfache Funktionen (Linearität) und positive messbare Funktionen (Monotone Konvergenz).
    \item Erweiterung auf integrierbare Funktionen durch Zerlegung in Positiv- und Negativteil.
\end{enumerate}
