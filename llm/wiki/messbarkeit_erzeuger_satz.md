---
key: messbarkeit_erzeuger_satz
title: Messbarkeit und Erzeuger der sigma-Algebra
type: satz
tags: [masstheorie]
refs: [messbarer_raum_definition, sigma_algebra_erzeugte_definition]
---
Seien $(\Omega, \mathcal{F})$ und $(\Omega', \mathcal{F}')$ messbare Räume und sei $\mathcal{E}'$ ein Erzeuger von $\mathcal{F}'$ (d.h. $\sigma(\mathcal{E}') = \mathcal{F}'$). Eine [[messbarer_raum_definition|Abbildung]] $f: \Omega \to \Omega'$ ist genau dann messbar, wenn
$$f^{-1}(\mathcal{E}') \subseteq \mathcal{F}$$
gilt.

--proof--
Der Beweis verläuft vollkommen analog zum Beweis für stetige Abbildungen (Satz 2.2.3):
Die Notwendigkeit ($f$ messbar $\implies f^{-1}(\mathcal{E}') \subseteq \mathcal{F}$) ist trivial, da $\mathcal{E}' \subseteq \mathcal{F}'$.
Für die Hinlänglichkeit zeigt man, dass das System $\mathcal{F}'_0 := \{ A' \in \mathcal{F}' \mid f^{-1}(A') \in \mathcal{F} \}$ eine $\sigma$-Algebra auf $\Omega'$ ist. Da $f^{-1}(\mathcal{E}') \subseteq \mathcal{F}$ vorausgesetzt ist, gilt $\mathcal{E}' \subseteq \mathcal{F}'_0$, und da $\mathcal{F}'_0$ eine $\sigma$-Algebra ist, folgt $\mathcal{F}' = \sigma(\mathcal{E}') \subseteq \mathcal{F}'_0$. Damit ist $f^{-1}(\mathcal{F}') \subseteq \mathcal{F}$, also ist $f$ messbar.
