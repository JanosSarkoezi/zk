---
key: produkt_sigma_algebra_abzaehlbar_satz
title: Produkt-sigma-Algebra bei abzählbarer Indexmenge
type: satz
tags: [masstheorie]
refs: [produkt_sigma_algebra_definition]
---
Sei die Indexmenge $I$ abzählbar. Dann ist die Produkt-$\sigma$-Algebra identisch mit der von dem Produkt der $\sigma$-Algebren erzeugten $\sigma$-Algebra:
$$\bigotimes_{i \in I} \mathcal{F}_i = \sigma\left( \prod_{i \in I} \mathcal{F}_i \right)$$

--proof--
Analog zu Satz 3.2.4 für Topologien. Der entscheidende Unterschied ist, dass  [[sigma_algebra_definition|$\sigma$-Algebren]] unter *abzählbaren* Durchschnitten stabil sind. Daher gilt für eine abzählbare Indexmenge $I$:
$$\prod_{i \in I} A_i = \bigcap_{i \in I} \pi_i^{-1}(A_i) \in \bigotimes_{i \in I} \mathcal{F}_i$$
Dies zeigt $\prod \mathcal{F}_i \subseteq \bigotimes \mathcal{F}_i$. Die andere Inklusion folgt daraus, dass die Projektionen bezüglich $\sigma(\prod \mathcal{F}_i)$ messbar sind.
