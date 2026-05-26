---
key: lebesgue_integral_positiv_definition
title: Lebesgue-Integral für positive messbare Funktionen
type: def
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [lebesgue_integral_einfach_definition, messbarkeit_numerische_funktion_charakterisierung_satz]
---
Sei $(\Omega, \mathcal{F}, \mu)$ ein Maßraum und $f: \Omega \to [0, \infty]$ eine positive messbare Funktion. Das Lebesgue-Integral von $f$ bezüglich $\mu$ ist definiert als
$$
\int_\Omega f \, d\mu := \sup \left\{ \int_\Omega h \, d\mu \mid h \text{ ist einfach mit } 0 \le h \le f \right\}
$$
Dieses Integral nimmt Werte in $[0, \infty]$ an.

--proof--
Diese Definition erweitert das Integral für einfache Funktionen, da für eine einfache Funktion $f$ das Supremum gerade bei $h=f$ angenommen wird. Die Wohldefiniertheit folgt aus der Monotonie des Integrals für einfache Funktionen.
