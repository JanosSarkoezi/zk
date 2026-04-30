---
key: produkt_sigma_algebra_definition
title: Produkt-sigma-Algebra (Kolmogorovsche sigma-Algebra)
type: def
tags: [masstheorie]
refs: [sigma_algebra_erzeugte_definition, produkt_mengen_projektion_definition]
---
Sei $\{(\Omega_i, \mathcal{F}_i)\}_{i \in I}$ eine Familie von messbaren Räumen. Die Produkt-$\sigma$-Algebra $\bigotimes_{i \in I} \mathcal{F}_i$ auf $\prod_{i \in I} \Omega_i$ ist die kleinste $\sigma$-Algebra, für die alle [[produkt_mengen_projektion_definition|Projektionen]] $\pi_j$ messbar sind. Es gilt:
$$\bigotimes_{i \in I} \mathcal{F}_i = \sigma\left( \bigcup_{i \in I} \pi_i^{-1}(\mathcal{F}_i) \right)$$
Diese $\sigma$-Algebra wird auch als Kolmogorovsche $\sigma$-Algebra bezeichnet.

--examples--
Analog zur Produkttopologie ist die Produkt-$\sigma$-Algebra die von den Urbildern der messbaren Mengen der Komponenten erzeugte $\sigma$-Algebra.
Wichtige Eigenschaften:
\begin{enumerate}[label=(\arabic*)]
  \item Eine Abbildung $f: \Omega \to \prod_{i \in I} \Omega_i$ ist genau dann messbar, wenn jede Koordinatenabbildung $f_i := \pi_i \circ f$ messbar ist (Satz 3.3.2).
  \item Für eine abzählbare Indexmenge $I$ und Borel-$\sigma$-Algebren gilt oft $\bigotimes_{i \in I} \mathcal{B}(\Omega_i) = \mathcal{B}(\prod_{i \in I} \Omega_i)$, sofern die Räume "gutartig" sind (z.B. zweites Abzählbarkeitsaxiom erfüllen).
  \item Im Fall $\mathbb{R}^n$ gilt $\mathcal{B}(\mathbb{R}^n) = \bigotimes_{i=1}^n \mathcal{B}(\mathbb{R})$.
\end{enumerate}
