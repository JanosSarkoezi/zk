---
key: mass_mit_dichte_definition
title: Maß mit Dichte
type: def
tags: [masstheorie, integration]
refs: [integral_induziertes_mass_satz]
---
Ein Maß $\nu$ auf $(\Omega, \mathcal{F})$ heißt ein **Maß mit $\mu$-Dichte** (oder kurz Maß mit Dichte), wenn eine positive messbare Funktion $f: \Omega \to [0, \infty]$ existiert, so dass
$$
\nu(A) = \int_A f \, d\mu \quad \text{für alle } A \in \mathcal{F}
$$
Die Funktion $f$ heißt eine $\mu$-Dichte von $\nu$. Man schreibt auch $d\nu = f \, d\mu$ oder $\nu = f \mu$.

--proof--
Jedes Maß mit Dichte ist nach dem Satz über integralinduzierte Maße tatsächlich ein Maß. Es ist zudem absolutstetig bezüglich $\mu$.
