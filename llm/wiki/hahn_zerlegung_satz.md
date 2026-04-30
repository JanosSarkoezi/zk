---
key: hahn_zerlegung_satz
title: Satz von der Hahn-Zerlegung
type: satz
tags: [masstheorie, signiertes_mass]
refs: [jordan_zerlegung_satz]
---
Sei $\mathcal{C}$ eine $\sigma$-Algebra und $\nu: \mathcal{C} \to \bar{\mathbb{R}}$ ein signiertes Maß. Dann existiert eine Partition der Grundmenge $\Omega$ in zwei disjunkte Mengen $\Omega^+$ und $\Omega^-$ ($\Omega = \Omega^+ + \Omega^-$) aus $\mathcal{C}$, sodass für alle $A \in \mathcal{C}$ gilt:
$$\nu^+[A] = \nu[A \cap \Omega^+] \quad \text{und} \quad \nu^-[A] = -\nu[A \cap \Omega^-]$$

Insbesondere ist $\nu$ auf Teilmengen von $\Omega^+$ nicht-negativ und auf Teilmengen von $\Omega^-$ nicht-positiv.

--proof--
Der Beweis nutzt eine Folge von Mengen $\{A_n\}$, die das Supremum $\nu^+(\Omega)$ approximieren. Durch Bildung von Limes-Mengen (Limes superior/inferior von Mengenfolgen) konstruiert man $\Omega^+$ und zeigt, dass $\nu^-(\Omega^+) = 0$ sowie $\nu^+(\Omega^-) = 0$ gilt. Daraus folgen die Identitäten für die Jordan-Anteile.
--proof--
