---
key: topologischer_raum_definition
title: Topologischer Raum und stetige Abbildung
type: def
tags: [topologie]
refs: [topologie_definition, urbild_mengensystem_definition]
---
Ist $\Omega$ eine nichtleere Menge und $\mathcal{T}$ eine [[topologie_definition|Topologie]] auf $\Omega$, so wird das Paar $(\Omega, \mathcal{T})$ als topologischer Raum bezeichnet.
Sind $(\Omega, \mathcal{T})$ und $(\Omega', \mathcal{T}')$ topologische Räume, so heißt eine Abbildung $f: \Omega \to \Omega'$ stetig (genauer $\mathcal{T}$-$\mathcal{T}'$-stetig), wenn
$$f^{-1}(\mathcal{T}') \subseteq \mathcal{T}$$
gilt.

--examples--
Die Bedingung $f^{-1}(\mathcal{T}') \subseteq \mathcal{T}$ bedeutet, dass das Urbild jeder offenen Menge in $\Omega'$ offen in $\Omega$ ist.
Sind $(\Omega, \mathcal{T})$, $(\Omega', \mathcal{T}')$ und $(\Omega'', \mathcal{T}'')$ topologische Räume und sind $f: \Omega \to \Omega'$ und $g: \Omega' \to \Omega''$ stetig, so ist auch die Komposition $g \circ f: \Omega \to \Omega''$ stetig. Dies folgt aus $(g \circ f)^{-1}(\mathcal{T}'') = f^{-1}(g^{-1}(\mathcal{T}'')) \subseteq f^{-1}(\mathcal{T}') \subseteq \mathcal{T}$.
