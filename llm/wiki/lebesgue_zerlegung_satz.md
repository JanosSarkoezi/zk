---
key: lebesgue_zerlegung_satz
title: Lebesguescher Zerlegungssatz
type: satz
tags: [masstheorie]
refs: [absolutstetigkeit_mass_definition, singulaeres_mass_definition]
---
Sei $\mu$ ein $\sigma$-endliches Maß auf $(\Omega, \mathcal{F})$. Jedes $\sigma$-endliche Maß $\nu$ auf $(\Omega, \mathcal{F})$ besitzt eine eindeutige Zerlegung
$$
\nu = \phi + \psi
$$
wobei $\phi \ll \mu$ (absolutstetiger Teil) und $\psi \perp \mu$ (singulärer Teil).

--proof--
Die Existenz folgt durch Anwendung des Satzes von Radon-Nikodym auf das Maß $\nu$ bezüglich $\tau = \mu + \nu$. Die Eindeutigkeit ergibt sich aus den Definitionen von Absolutstetigkeit und Singularität.
