---
key: unabhaengigkeit_zufallsgroessen_erzeuger_satz
title: Unabhängigkeit von Zufallsgrößen und Erzeugern
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit
refs: [unabhaengigkeit_zufallsgroessen_definition, messbarkeit_erzeuger_satz]
---
Sei $\{X_i\}_{i \in I}$ eine Familie von Zufallsgrößen $X_i : \Omega \to \Omega'_i$. Für jedes $i$ sei $\mathcal{E}'_i$ ein schnittstabiler Erzeuger der Ziel-$\sigma$-Algebra $\mathcal{F}'_i$.

Dann ist die Familie $\{X_i\}_{i \in I}$ genau dann unabhängig, wenn für jede endliche Teilmenge $J \subseteq I$ und jede Wahl von Mengen $B_i \in \mathcal{E}'_i$ ($i \in J$) gilt:
$$P\left[ \bigcap_{i \in J} \{X_i \in B_i\} \right] = \prod_{i \in J} P[X_i \in B_i]$$

--proof--
Die Unabhängigkeit der Zufallsgrößen ist definiert als Unabhängigkeit der Urbild-$\sigma$-Algebren $X_i^{-1}(\mathcal{F}'_i)$. Da $\mathcal{E}'_i$ ein schnittstabiler Erzeuger von $\mathcal{F}'_i$ ist, ist $X_i^{-1}(\mathcal{E}'_i)$ ein schnittstabiler Erzeuger von $X_i^{-1}(\mathcal{F}'_i)$. Die Aussage folgt dann aus dem Satz über die [[unabhaengigkeit_erzeugte_sigma_algebren_satz|Unabhängigkeit erzeugter sigma-Algebren]].
