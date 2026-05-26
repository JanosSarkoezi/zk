---
key: integral_induziertes_mass_satz
title: Integralinduzierte Maße (unbestimmtes Integral)
type: satz
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [lebesgue_integral_positiv_definition, integrierbarkeit_definition, sigma_additivitaet_mass_definition, signiertes_mass_definition]
---
Sei $(\Omega, \mathcal{F}, \mu)$ ein Maßraum und $f: \Omega \to \bar{\mathbb{R}}$ eine messbare Funktion. Wir definieren die Mengenfunktion $f \mu: \mathcal{F} \to \bar{\mathbb{R}}$ durch
$$
(f \mu)(A) := \int_A f \, d\mu = \int_\Omega f \chi_A \, d\mu
$$
Dann gilt:
\begin{enumerate}[label=(\arabic*)]
    \item Ist $f$ positiv ($f \ge 0$), so ist $f \mu$ ein Maß auf $\mathcal{F}$.
    \item Ist $f$ $\mu$-integrierbar, so ist $f \mu$ ein endliches signiertes Maß.
\end{enumerate}

--proof--
\begin{enumerate}[label=(\arabic*)]
    \item $f \ge 0 \Rightarrow (f \mu)(\emptyset) = \int_\emptyset f \, d\mu = 0$. Die $\sigma$-Additivität folgt aus dem Satz von der monotonen Konvergenz (angewandt auf $f \sum \chi_{A_n} = \sum f \chi_{A_n}$).
    \item Ist $f$ integrierbar, so sind $f^+$ und $f^-$ integrierbar. Dann sind $(f^+ \mu)$ und $(f^- \mu)$ nach (1) endliche Maße. Da $f \mu = f^+ \mu - f^- \mu$ (Differenz zweier endlicher Maße), ist $f \mu$ ein endliches signiertes Maß.
\end{enumerate}
