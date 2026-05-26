---
key: mass_mit_dichte_eindeutigkeit_satz
title: Eindeutigkeit der Dichte
type: satz
tags: [masstheorie, integration]
refs: [mass_mit_dichte_definition, sigma_algebra_erzeugte_definition]
---
Sei $\nu$ ein Maß mit $\mu$-Dichte. Ist $\mu$ oder $\nu$ $\sigma$-endlich, so ist die $\mu$-Dichte $f$ von $\nu$ $\mu$-fast überall eindeutig bestimmt.

--proof--
Seien $f, g$ zwei $\mu$-Dichten von $\nu$. Dann gilt $\int_A f \, d\mu = \int_A g \, d\mu$ für alle $A \in \mathcal{F}$.
Im $\sigma$-endlichen Fall folgt daraus mittels Standardargumenten (Betrachten der Mengen $\{f > g\}$ und $\{g > f\}$), dass $\mu(\{f \neq g\}) = 0$ gelten muss. Ohne $\sigma$-Endlichkeit ist dies im Allgemeinen falsch (siehe Gegenbeispiele mit dem Zählmaß auf überabzählbaren Mengen).
