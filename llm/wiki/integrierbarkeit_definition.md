---
key: integrierbarkeit_definition
title: Integrierbare Funktionen
type: def
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [lebesgue_integral_positiv_definition, numerische_funktion_definition]
---
Sei $(\Omega, \mathcal{F}, \mu)$ ein Maßraum. Eine messbare Funktion $f: \Omega \to \bar{\mathbb{R}}$ heißt:

\begin{enumerate}[label=(\arabic*)]
    \item **Quasiintegrierbar**, wenn $\min \left( \int_\Omega f^+ \, d\mu, \int_\Omega f^- \, d\mu \right) < \infty$. In diesem Fall ist das Integral definiert als $\int_\Omega f \, d\mu := \int_\Omega f^+ \, d\mu - \int_\Omega f^- \, d\mu$.
    \item **Integrierbar**, wenn $\int_\Omega |f| \, d\mu < \infty$. Dies ist äquivalent dazu, dass sowohl $\int_\Omega f^+ \, d\mu < \infty$ als auch $\int_\Omega f^- \, d\mu < \infty$ gilt.
\end{enumerate}

Dabei sind $f^+ := \max(f, 0)$ und $f^- := \max(-f, 0)$ der Positiv- bzw. Negativteil von $f$.

--proof--
Da $|f| = f^+ + f^-$, folgt aus der Linearität des Integrals für positive Funktionen, dass $\int |f| \, d\mu = \int f^+ \, d\mu + \int f^- \, d\mu$. Die Endlichkeit von $\int |f| \, d\mu$ ist also gleichbedeutend mit der Endlichkeit beider Teilintegrale. Integrierbare Funktionen sind nach Lemma 8.3.1 fast überall endlich.
