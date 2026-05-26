---
key: absolutstetigkeit_mass_definition
title: Absolutstetigkeit von Maßen
type: def
tags: [masstheorie]
refs: [fast_ueberall_definition]
---
Ein Maß $\nu$ auf $(\Omega, \mathcal{F})$ heißt **absolutstetig** bezüglich eines Maßes $\mu$ (geschrieben $\nu \ll \mu$), wenn jede $\mu$-Nullmenge auch eine $\nu$-Nullmenge ist. Das heißt:
$$
\forall A \in \mathcal{F}: \mu(A) = 0 \implies \nu(A) = 0
$$

--proof--
Jedes Maß mit $\mu$-Dichte ist absolutstetig bezüglich $\mu$. Der Satz von Radon-Nikodym liefert unter $\sigma$-Endlichkeitsvoraussetzungen die Umkehrung.
