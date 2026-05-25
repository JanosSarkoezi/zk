---
key: l_unendlich_raum_definition
title: Der Raum L-unendlich (Beschränkte Funktionen)
type: def
tags: [maßtheorie, funktionalanalysis]
refs: [l0_raum_definition, fast_ueberall_definition]
---
Für einen Maßraum $(\Omega, \mathcal{F}, \mu)$ ist der Raum $L^\infty(\mathcal{F}, \mu)$ definiert als die Menge der (Äquivalenzklassen von) messbaren reellen Funktionen, die **wesentlich beschränkt** sind.

Eine Funktion $f$ heißt wesentlich beschränkt, wenn es eine Konstante $C \ge 0$ gibt, so dass $|f| \le C$ $\mu$-fast überall gilt. Die **wesentliche Supremumsnorm** ist definiert als:
$$\|f\|_\infty := \inf \{ C \ge 0 \mid |f| \le C \text{ f.ü.} \}$$

--proof--
$(L^\infty(\mathcal{F}, \mu), \|\cdot\|_\infty)$ ist ein Banach-Raum (vollständiger normierter Raum). Dies folgt aus der Tatsache, dass eine Cauchy-Folge in der $\|\cdot\|_\infty$-Norm eine punktweise Cauchy-Folge außerhalb einer abzählbaren Vereinigung von Nullmengen (also wieder einer Nullmenge) induziert.
--proof--
