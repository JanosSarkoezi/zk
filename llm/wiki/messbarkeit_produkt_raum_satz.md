---
key: messbarkeit_produkt_raum_satz
title: Messbare Abbildungen in ein messbares Produkt
type: satz
tags: [masstheorie]
refs: [produkt_sigma_algebra_definition, messbarer_raum_definition]
---
Sei $(\Omega_0, \mathcal{F}_0)$ ein messbarer Raum und sei $f: \Omega_0 \to \prod_{i \in I} \Omega_i$ eine [[messbarer_raum_definition|Abbildung]]. Dann sind folgende Aussagen äquivalent:
(a) $f$ ist messbar bezüglich der Produkt-$\sigma$-Algebra auf $\prod_{i \in I} \Omega_i$.
(b) Für alle $i \in I$ ist die Koordinatenabbildung $f_i := \pi_i \circ f$ messbar.

--proof--
Der Beweis verläuft vollkommen analog zum topologischen Fall (Satz 3.2.2), wobei Topologien durch $\sigma$-Algebren und Stetigkeit durch Messbarkeit ersetzt werden. Die Stabilität der $\sigma$-Algebra unter abzählbaren Vereinigungen stellt sicher, dass das Argument auch für unendliche (abzählbare) Indexmengen tragfähig bleibt.
