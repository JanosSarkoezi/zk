---
key: l0_raum_definition
title: Der Raum L0 (Messbare Funktionen)
type: def
tags: [maßtheorie, funktionalanalysis]
refs: [messbarkeit_numerische_funktion_charakterisierung_satz]
---
Für einen Messraum $(\Omega, \mathcal{F})$ bezeichnet $\mathcal{L}^0(\mathcal{F})$ die Menge aller messbaren reellen Funktionen $f: \Omega \to \mathbb{R}$.

Auf einem Maßraum $(\Omega, \mathcal{F}, \mu)$ bezeichnet $L^0(\mathcal{F}, \mu)$ den Raum der Äquivalenzklassen von messbaren Funktionen, wobei zwei Funktionen äquivalent sind, wenn sie $\mu$-fast überall übereinstimmen.

--proof--
$\mathcal{L}^0(\mathcal{F})$ ist ein Vektorverband unter punktweiser Addition, skalarer Multiplikation und den Operationen $f \lor g = \max(f, g)$ sowie $f \land g = \min(f, g)$. Der Übergang zu Äquivalenzklassen stellt sicher, dass Funktionen, die sich nur auf Nullmengen unterscheiden, als identisch betrachtet werden.
--proof--
