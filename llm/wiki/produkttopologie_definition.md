---
key: produkttopologie_definition
title: Produkttopologie
type: def
tags: [topologie]
refs: [topologie_erzeugte_definition, produkt_mengen_projektion_definition]
---
Sei $\{(\Omega_i, \mathcal{T}_i)\}_{i \in I}$ eine Familie von topologischen Räumen. Die Produkttopologie $\bigotimes_{i \in I} \mathcal{T}_i$ auf $\prod_{i \in I} \Omega_i$ ist die kleinste [[topologie_erzeugte_definition|Topologie]], für die alle [[produkt_mengen_projektion_definition|Projektionen]] $\pi_j$ stetig sind. Es gilt:
$$\bigotimes_{i \in I} \mathcal{T}_i = \tau\left( \bigcup_{i \in I} \pi_i^{-1}(\mathcal{T}_i) \right)$$

--examples--
Die Forderung der Stetigkeit aller $\pi_j$ bedeutet nach Definition $f^{-1}(\mathcal{T}_j) \subseteq \mathcal{T}$ für alle $j \in I$. Die Produkttopologie ist somit die von der Vereinigung aller Urbilder der offenen Mengen [[topologie_erzeugte_definition|erzeugte Topologie]].
Beispiel: Die natürliche [[topologie_erzeugte_definition|Topologie]] auf $\mathbb{R}^n$ ist die Produkttopologie der natürlichen Topologien der Faktoren $\mathbb{R}$.
Ein wichtiges Resultat ([[stetigkeit_produkt_raum_satz|Satz 3.2.2]]) ist: Eine Abbildung $f: \Omega \to \prod_{i \in I} \Omega_i$ ist genau dann stetig, wenn jede Koordinatenabbildung $f_i := \pi_i \circ f$ stetig ist.
