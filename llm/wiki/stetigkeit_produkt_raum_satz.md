---
key: stetigkeit_produkt_raum_satz
title: Stetige Abbildungen in ein topologisches Produkt
type: satz
tags: [topologie]
refs: [produkttopologie_definition, topologischer_raum_definition]
---
Sei $(\Omega_0, \mathcal{T}_0)$ ein topologischer Raum und sei $f: \Omega_0 \to \prod_{i \in I} \Omega_i$ eine [[topologischer_raum_definition|Abbildung]]. Dann sind folgende Aussagen äquivalent:
(a) $f$ ist stetig bezüglich der [[produkttopologie_definition|Produkttopologie]] auf $\prod_{i \in I} \Omega_i$.
(b) Für alle $i \in I$ ist die Koordinatenabbildung $f_i := \pi_i \circ f$ stetig.

--proof--
(a) $\implies$ (b): Da alle Projektionen $\pi_i$ bezüglich der [[produkttopologie_definition|Produkttopologie]] stetig sind (nach Definition), ist die Komposition $\pi_i \circ f$ zweier stetiger Abbildungen stetig.
(b) $\implies$ (a): Sei $f_i = \pi_i \circ f$ stetig für alle $i \in I$. Es gilt:
$$f^{-1}\left( \bigcup_{i \in I} \pi_i^{-1}(\mathcal{T}_i) \right) = \bigcup_{i \in I} f^{-1}(\pi_i^{-1}(\mathcal{T}_i)) = \bigcup_{i \in I} (\pi_i \circ f)^{-1}(\mathcal{T}_i) \subseteq \mathcal{T}_0$$
Da $\mathcal{T}_0$ eine Topologie ist, folgt $f^{-1}\left( \tau\left( \bigcup \pi_i^{-1}(\mathcal{T}_i) \right) \right) \subseteq \mathcal{T}_0$. Dies ist genau die Stetigkeit von $f$ bezüglich der [[produkttopologie_definition|Produkttopologie]].
