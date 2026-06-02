---
key: existenz_unabhaengiger_zufallsgroessen_satz
title: Existenz unabhängiger Zufallsgrößen
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit, produkt_mass
refs: [produkt_mass_definition, unabhaengigkeit_zufallsgroessen_definition]
---
Zu jeder Familie von Wahrscheinlichkeitsräumen $\{(\Omega_i, \mathcal{F}_i, Q_i)\}_{i \in I}$ existiert ein Wahrscheinlichkeitsraum $(\Omega, \mathcal{F}, P)$ und eine unabhängige Familie von Zufallsgrößen $\{X_i\}_{i \in I}$ mit $X_i : \Omega \to \Omega_i$ derart, dass die Verteilung von $X_i$ gerade $Q_i$ ist (d.h. $P^{X_i} = Q_i$).

--proof--
Man wähle als Wahrscheinlichkeitsraum den Produktraum $(\Omega, \mathcal{F}, P) = \bigotimes_{i \in I} (\Omega_i, \mathcal{F}_i, Q_i)$ und als Zufallsgrößen die Projektionen $X_i := \pi_i$.
Nach dem Satz über die Unabhängigkeit der Projektionen in Produkträumen ([[unabhaengigkeit_projektionen_produktraum_satz|Unabhängigkeit der Projektionen im Produktraum]]) ist diese Familie unabhängig. Die Randverteilung der $i$-ten Projektion ist nach Definition des Produktmaßes gerade $Q_i$.
