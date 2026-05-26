---
key: lebesgue_integral_einfach_definition
title: Lebesgue-Integral für positive einfache Funktionen
type: def
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [einfache_funktion_definition, sigma_additivitaet_mass_definition]
---
Sei $(\Omega, \mathcal{F}, \mu)$ ein Maßraum. Für eine positive einfache Funktion $f: \Omega \to [0, \infty)$ mit der Standarddarstellung $f = \sum_{a \in f(\Omega)} a \chi_{\{f=a\}}$ definieren wir das Lebesgue-Integral bezüglich $\mu$ durch
$$
\int_\Omega f \, d\mu := \sum_{a \in f(\Omega)} a \mu(\{f=a\})
$$
Dabei gilt die Konvention $0 \cdot \infty = 0$.

--proof--
Die Definition ist wohldefiniert, da $f(\Omega)$ für eine einfache Funktion endlich ist und für jede messbare Menge $A \in \mathcal{F}$ der Wert $\mu(A) \in [0, \infty]$ definiert ist. Die Verträglichkeit mit anderen Darstellungen von $f$ wird durch Lemma 8.1.1 sichergestellt.
