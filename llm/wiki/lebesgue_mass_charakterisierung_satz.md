---
key: lebesgue_mass_charakterisierung_satz
title: Charakterisierung des Lebesgue-Maßes durch Translationsinvarianz
type: satz
tags: [masstheorie, analysis]
refs: [lebesgue_mass_definition, translationsinvarianz_mass_definition]
---
Ein translationsinvariantes Maß $\mu$ auf $(\mathbb{R}^n, \mathcal{B}(\mathbb{R}^n))$, das auf dem Einheitswürfel $Q = [0, 1)^n$ den Wert $1$ annimmt ($\mu(Q) = 1$), ist identisch mit dem Lebesgue-Maß $\lambda^n$.

Allgemeiner: Jedes translationsinvariante Maß $\mu$ auf $\mathcal{B}(\mathbb{R}^n)$, das auf kompakten Mengen endlich ist, ist ein Vielfaches des Lebesgue-Maßes, d.h. $\mu = c \cdot \lambda^n$ mit $c = \mu([0, 1)^n)$.

--proof--
Da $\mu$ translationsinvariant ist, lässt sich zeigen, dass $\mu$ auf dem Halbring der halboffenen Intervalle proportional zum Volumen ist. Die Eindeutigkeit der Fortsetzung (Satz von Carathéodory) auf die Borelsche $\sigma$-Algebra erzwingt dann $\mu = c \cdot \lambda^n$.
