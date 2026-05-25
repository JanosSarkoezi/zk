---
key: lebesgue_mass_definition
title: Lebesgue-Maß auf den Borelmengen
type: def
tags: [masstheorie, analysis]
refs: [borelsche_sigma_algebra_definition, caratheodory_fortsetzungssatz]
---
Das **Lebesgue-Maß** $\lambda^n$ auf $(\mathbb{R}^n, \mathcal{B}(\mathbb{R}^n))$ ist die eindeutige Fortsetzung des Elementarvolumens (Inhalts) von $n$-dimensionalen Intervallen (Quadern) auf die Borelsche $\sigma$-Algebra.

Für einen Quader $I = \prod_{i=1}^n [a_i, b_i]$ gilt:
$$\lambda^n(I) = \prod_{i=1}^n (b_i - a_i)$$

--proof--
Da das System der halboffenen Intervalle einen Halbring bildet und das darauf definierte Volumen ein $\sigma$-endliches Maß ist, garantiert der [[caratheodory_fortsetzungssatz|Satz von Carathéodory]] die Existenz und Eindeutigkeit einer Fortsetzung auf die von den Intervallen erzeugte $\sigma$-Algebra, welche genau die Borelsche $\sigma$-Algebra $\mathcal{B}(\mathbb{R}^n)$ ist.
