---
key: produkt_mass_definition
title: Produktmaß
type: def
tags: [masstheorie]
refs: [produkt_sigma_algebra_definition, halbring_definition]
---
Seien $(M, \mathcal{M}, \mu)$ und $(N, \mathcal{N}, \nu)$ zwei Maßräume. Ein Maß $\rho$ auf der Produkt-$\sigma$-Algebra $\mathcal{M} \otimes \mathcal{N}$ heißt **Produktmaß** von $\mu$ und $\nu$, wenn für alle messbaren Rechtecke $A \times B \in \mathcal{M} \times \mathcal{N}$ gilt:
$$
\rho(A \times B) = \mu(A) \cdot \nu(B)
$$
Sind $\mu$ und $\nu$ $\sigma$-endlich, so existiert genau ein solches Maß, bezeichnet mit $\mu \otimes \nu$.

--proof--
Die Existenz folgt aus dem Fortsetzungssatz von Carathéodory, da die Abbildung $\rho(A \times B) = \mu(A)\nu(B)$ ein prämaß-ähnliches Verhalten auf dem Halbring der Rechtecke zeigt. Die Eindeutigkeit folgt im $\sigma$-endlichen Fall aus dem Eindeutigkeitssatz für Maße.
