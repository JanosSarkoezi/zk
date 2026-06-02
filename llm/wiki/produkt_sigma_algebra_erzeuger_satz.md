---
key: produkt_sigma_algebra_erzeuger_satz
title: Produkt-sigma-Algebra und Erzeugersysteme
type: satz
tags: [masstheorie]
refs: [produkt_sigma_algebra_definition, sigma_algebra_erzeugte_definition]
---
Für alle $i \in I$ sei $\mathcal{E}_i$ ein Mengensystem mit $\sigma(\mathcal{E}_i) = \mathcal{F}_i$. Dann wird die Produkt-$\sigma$-Algebra durch die Urbilder dieser Erzeuger erzeugt:
$$\bigotimes_{i \in I} \mathcal{F}_i = \sigma\left( \bigcup_{i \in I} \pi_i^{-1}(\mathcal{E}_i) \right)$$

--proof--
Der Beweis verläuft analog zum topologischen Fall ([[produkttopologie_erzeuger_satz|Satz 3.2.3]]). Die Messbarkeit der Projektionen $\pi_j$ bezüglich der von den Erzeuger-Urbildern erzeugten $\sigma$-Algebra zeigt, dass die Produkt-$\sigma$-Algebra (als kleinste solche $\sigma$-Algebra) in dieser enthalten sein muss. Die umgekehrte Inklusion ist trivial.
