---
key: markov_ungleichung_satz
title: Markov-Ungleichung
type: satz
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [lebesgue_integral_positiv_definition]
---
Sei $(\Omega, \mathcal{F}, \mu)$ ein Maßraum und $f: \Omega \to [0, \infty]$ eine positive messbare Funktion. Dann gilt für jedes $c \in (0, \infty)$:
$$
\mu(\{f \ge c\}) \le \frac{1}{c} \int_\Omega f \, d\mu
$$

--proof--
Es gilt die Abschätzung $f \ge c \chi_{\{f \ge c\}}$. Aus der Monotonie und Linearität des Integrals folgt:
$$
\int_\Omega f \, d\mu \ge \int_\Omega c \chi_{\{f \ge c\}} \, d\mu = c \int_\Omega \chi_{\{f \ge c\}} \, d\mu = c \mu(\{f \ge c\})
$$
Division durch $c$ liefert die Behauptung.
