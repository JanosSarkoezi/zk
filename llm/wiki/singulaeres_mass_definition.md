---
key: singulaeres_mass_definition
title: Singuläre Maße
type: def
tags: [masstheorie]
refs: [sigma_algebra_definition]
---
Zwei Maße $\mu$ und $\nu$ auf $(\Omega, \mathcal{F})$ heißen **zueinander singulär** (geschrieben $\nu \perp \mu$), wenn es eine Menge $N \in \mathcal{F}$ gibt, so dass:
$$
\nu(\Omega \setminus N) = 0 \quad \text{und} \quad \mu(N) = 0
$$
Das heißt, $\nu$ und $\mu$ "leben" auf disjunkten Teilmengen von $\Omega$.

--proof--
Die Relation ist symmetrisch. Ein typisches Beispiel ist das Dirac-Maß $\delta_x$ und das Lebesgue-Maß $\lambda$ auf $\mathbb{R}$, falls $\{x\}$ eine $\lambda$-Nullmenge ist.
