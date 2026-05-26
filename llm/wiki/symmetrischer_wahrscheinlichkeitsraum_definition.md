---
key: symmetrischer_wahrscheinlichkeitsraum_definition
title: Symmetrischer Wahrscheinlichkeitsraum (Laplace-Experiment)
type: def
tags: [wahrscheinlichkeitstheorie]
refs: [diskreter_wahrscheinlichkeitsraum_definition]
---
Ein Wahrscheinlichkeitsraum $(\Omega, \mathcal{F}, P)$ heißt **symmetrisch** (oder Laplace-Modell), wenn $\Omega$ endlich ist, $\mathcal{F} = 2^\Omega$ und alle Elementarereignisse die gleiche Wahrscheinlichkeit besitzen:
$$
P(\{\omega\}) = \frac{1}{|\Omega|} \quad \text{für alle } \omega \in \Omega
$$
Für jedes Ereignis $A \in \mathcal{F}$ gilt dann:
$$
P(A) = \frac{|A|}{|\Omega|} = \frac{\text{Anzahl der günstigen Fälle}}{\text{Anzahl der möglichen Fälle}}
$$

--proof--
Dies ist ein Spezialfall des diskreten Wahrscheinlichkeitsraums mit der konstanten Wahrscheinlichkeitsfunktion $p(\omega) = 1/|\Omega|$. Da $\Omega$ endlich ist, ist die Summe wohldefiniert und $P(\Omega) = |\Omega| \cdot (1/|\Omega|) = 1$.
