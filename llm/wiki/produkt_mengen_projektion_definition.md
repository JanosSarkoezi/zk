---
key: produkt_mengen_projektion_definition
title: Produkt von Mengen und Projektionen
type: def
tags: [mengenlehre]
refs: []
---
Sei $\{\Omega_i\}_{i \in I}$ eine Familie von nichtleeren Mengen. Die Menge aller Abbildungen $\omega: I \to \bigcup_{i \in I} \Omega_i$ mit $\omega(i) \in \Omega_i$ für alle $i \in I$ heißt das Produkt der Familie $\{\Omega_i\}_{i \in I}$ und wird mit $\prod_{i \in I} \Omega_i$ bezeichnet.
Für jedes $j \in I$ heißt die Abbildung $\pi_j: \prod_{i \in I} \Omega_i \to \Omega_j$ mit $\pi_j(\omega) := \omega(j)$ die Projektion auf die $j$-te Koordinate.

--examples--
Für ein $A_j \in 2^{\Omega_j}$ hat das Urbild unter der Projektion $\pi_j$ die Darstellung:
$$\pi_j^{-1}(A_j) = \prod_{i \in I} B_i \quad \text{mit} \quad B_i := \begin{cases} A_j & \text{falls } i = j \\ \Omega_i & \text{sonst} \end{cases}$$
Solche Mengen werden oft als (einfache) Zylindermengen bezeichnet.
Das Produkt von Mengensystemen $\mathcal{E}_i \subseteq 2^{\Omega_i}$ ist definiert als:
$$\prod_{i \in I} \mathcal{E}_i := \left\{ \prod_{i \in I} A_i \mid A_i \in \mathcal{E}_i \text{ für alle } i \in I \right\}$$
Es gilt $\pi_j^{-1}(\mathcal{E}_j) \subseteq \prod_{i \in I} \mathcal{E}_i$, sofern $\Omega_i \in \mathcal{E}_i$ für alle $i \in I$.
