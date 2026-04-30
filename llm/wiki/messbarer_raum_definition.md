---
key: messbarer_raum_definition
title: Messbarer Raum und messbare Abbildung
type: def
tags: [masstheorie]
refs: [sigma_algebra_definition, urbild_mengensystem_definition]
---
Ist $\Omega$ eine nichtleere Menge und $\mathcal{F}$ eine [[sigma_algebra_definition|$\sigma$-Algebra]] auf $\Omega$, so wird das Paar $(\Omega, \mathcal{F})$ als messbarer Raum (oder Messraum) bezeichnet.
Sind $(\Omega, \mathcal{F})$ und $(\Omega', \mathcal{F}')$ messbare Räume, so heißt eine Abbildung $f: \Omega \to \Omega'$ messbar (genauer $\mathcal{F}$-$\mathcal{F}'$-messbar), wenn
$$f^{-1}(\mathcal{F}') \subseteq \mathcal{F}$$
gilt.

--examples--
Die Definition der Messbarkeit ist formal analog zur Definition der Stetigkeit topologischer Räume, wobei Topologien durch $\sigma$-Algebren ersetzt werden.
Sind $(\Omega, \mathcal{F})$, $(\Omega', \mathcal{F}')$ und $(\Omega'', \mathcal{F}'')$ messbare Räume und sind $f: \Omega \to \Omega'$ und $g: \Omega' \to \Omega''$ messbar, so ist auch die Komposition $g \circ f: \Omega \to \Omega''$ messbar.
