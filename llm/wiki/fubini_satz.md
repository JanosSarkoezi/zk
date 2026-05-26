---
key: fubini_satz
title: Satz von Fubini (und Tonelli)
type: satz
tags: [integration, masstheorie]
refs: [produkt_mass_definition, lebesgue_integral_positiv_definition, integrierbarkeit_definition]
---
Seien $(M, \mathcal{M}, \mu)$ und $(N, \mathcal{N}, \nu)$ zwei $\sigma$-endliche Maßräume. Für eine $\mathcal{M} \otimes \mathcal{N}$-messbare Funktion $h: M \times N \to \bar{\mathbb{R}}$ gilt:

\begin{enumerate}[label=(\arabic*)]
    \item **Tonelli (Positiver Fall)**: Ist $h \ge 0$, so sind die Schnitte $y \mapsto h(x, y)$ und $x \mapsto h(x, y)$ messbar, die Integral-Funktionen $x \mapsto \int_N h(x, y) \, d\nu(y)$ und $y \mapsto \int_M h(x, y) \, d\mu(x)$ sind messbar, und es gilt:
   $$
   \int_{M \times N} h \, d(\mu \otimes \nu) = \int_M \left( \int_N h(x, y) \, d\nu(y) \right) d\mu(x) = \int_N \left( \int_M h(x, y) \, d\mu(x) \right) d\nu(y)
   $$
    \item **Fubini (Integrierbarer Fall)**: Ist $h$ $\mu \otimes \nu$-integrierbar, so sind die obigen Integral-Funktionen fast überall definiert, integrierbar, und es gilt dieselbe Identität.
\end{enumerate}

--proof--
Der Beweis nutzt algebraische Induktion. Für Indikatorfunktionen von Rechtecken ist die Behauptung trivial. Die Erweiterung auf die Produkt-$\sigma$-Algebra erfolgt über das Prinzip der guten Mengen (Dynkin-Systeme). Danach folgt die Erweiterung auf einfache, positive und integrierbare Funktionen wie üblich.
