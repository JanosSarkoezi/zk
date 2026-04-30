---
key: produkttopologie_erzeuger_satz
title: Produkttopologie und Erzeugersysteme
type: satz
tags: [topologie]
refs: [produkttopologie_definition, topologie_erzeugte_definition]
---
Für alle $i \in I$ sei $\mathcal{E}_i$ ein Mengensystem mit $\tau(\mathcal{E}_i) = \mathcal{T}_i$. Dann wird die [[produkttopologie_definition|Produkttopologie]] durch die Urbilder dieser Erzeuger erzeugt:
$$\bigotimes_{i \in I} \mathcal{T}_i = \tau\left( \bigcup_{i \in I} \pi_i^{-1}(\mathcal{E}_i) \right)$$

--proof--
Für alle $j \in I$ gilt $\pi_j^{-1}(\mathcal{T}_j) = \pi_j^{-1}(\tau(\mathcal{E}_j)) = \tau(\pi_j^{-1}(\mathcal{E}_j)) \subseteq \tau(\bigcup_{i \in I} \pi_i^{-1}(\mathcal{E}_i))$. Daraus folgt, dass alle Projektionen bezüglich der [[topologie_erzeugte_definition|Topologie]] $\tau(\bigcup \pi_i^{-1}(\mathcal{E}_i))$ stetig sind. Nach Definition der [[produkttopologie_definition|Produkttopologie]] als kleinste solche [[topologie_erzeugte_definition|Topologie]] folgt die Inklusion "$\subseteq$". Die umgekehrte Inklusion ist klar, da $\mathcal{E}_i \subseteq \mathcal{T}_i$ gilt.
