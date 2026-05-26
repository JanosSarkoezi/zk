---
key: radon_nikodym_satz
title: Satz von Radon-Nikodym
type: satz
tags: [masstheorie, integration]
refs: [absolutstetigkeit_mass_definition, mass_mit_dichte_definition]
---
Sei $\mu$ ein $\sigma$-endliches Maß auf $(\Omega, \mathcal{F})$. Ein Maß $\nu$ auf $(\Omega, \mathcal{F})$ ist genau dann absolutstetig bezüglich $\mu$ ($\nu \ll \mu$), wenn $\nu$ ein Maß mit $\mu$-Dichte ist. Das heißt, es existiert eine positive messbare Funktion $f: \Omega \to [0, \infty]$, so dass $\nu = f \mu$.
Die Dichte $f$ ist $\mu$-fast überall eindeutig bestimmt.

--proof--
Die Notwendigkeit der Dichte-Existenz unter der Bedingung $\nu \ll \mu$ ist der Kern des Satzes. Der Beweis nutzt oft die Hilbert-Raum-Struktur von $L^2$ oder die Hahn-Zerlegung (wie in Schmidt ausgeführt). Die Eindeutigkeit folgt aus der $\sigma$-Endlichkeit von $\mu$.
