---
key: andersen_jessen_satz
title: Satz von Andersen-Jessen
type: satz
tags: [wahrscheinlichkeitstheorie, masstheorie]
refs: [projektive_familie_wahrscheinlichkeitsmasse_definition, produkt_mass_definition]
---
Sei $\{(\Omega_i, \mathcal{F}_i, P_i)\}_{i \in I}$ eine beliebige Familie von Wahrscheinlichkeitsräumen. Dann existiert genau ein Wahrscheinlichkeitsmaß $P$ auf dem Produktraum $(\Omega, \mathcal{F}) = \bigotimes_{i \in I} (\Omega_i, \mathcal{F}_i)$, so dass für jede endliche Teilmenge $J \subseteq I$ gilt:
$$
P \circ \pi_J^{-1} = \bigotimes_{i \in J} P_i
$$
Das globale Maß $P$ wird als das Produktmaß der Familie $\{P_i\}_{i \in I}$ bezeichnet.

--proof--
Der Beweis nutzt die Projektivität der endlichen Produktmaße. Die Schwierigkeit liegt in der $\sigma$-Additivität des auf der Zylinderalgebra definierten Inhalts. Andersen und Jessen bewiesen dies für beliebige Wahrscheinlichkeitsräume, indem sie die $\emptyset$-Stetigkeit mittels Schnitt-Argumenten und der Fubini-Eigenschaft der endlichen Produkte zeigten.
