---
key: produkttopologie_endlich_satz
title: Produkttopologie bei endlicher Indexmenge
type: satz
tags: [topologie]
refs: [produkttopologie_definition]
---
Sei die Indexmenge $I$ endlich. Dann ist die [[produkttopologie_definition|Produkttopologie]] identisch mit der von dem Produkt der Topologien erzeugten Topologie:
$$\bigotimes_{i \in I} \mathcal{T}_i = \tau\left( \prod_{i \in I} \mathcal{T}_i \right)$$

--proof--
Für alle $j \in I$ gilt $\pi_j^{-1}(\mathcal{T}_j) \subseteq \prod_{i \in I} \mathcal{T}_i \subseteq \tau(\prod \mathcal{T}_i)$, da $\Omega_i \in \mathcal{T}_i$. Damit sind alle Projektionen bezüglich $\tau(\prod \mathcal{T}_i)$ stetig, woraus $\bigotimes \mathcal{T}_i \subseteq \tau(\prod \mathcal{T}_i)$ folgt.
Sei nun $\{A_i\}_{i \in I}$ mit $A_i \in \mathcal{T}_i$. Dann gilt $\prod A_i = \bigcap_{i \in I} \pi_i^{-1}(A_i)$. Da $I$ endlich ist und die Urbilder in der [[produkttopologie_definition|Produkttopologie]] liegen, liegt auch deren endlicher Durchschnitt in der [[produkttopologie_definition|Produkttopologie]]. Also $\prod \mathcal{T}_i \subseteq \bigotimes \mathcal{T}_i$, woraus die Gleichheit folgt.
