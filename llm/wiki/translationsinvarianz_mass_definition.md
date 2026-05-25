---
key: translationsinvarianz_mass_definition
title: Translationsinvarianz von Maßen
type: def
tags: [masstheorie, analysis]
refs: [lebesgue_mass_definition, bildmass_definition]
---
Ein Maß $\mu$ auf der Borelschen $\sigma$-Algebra $\mathcal{B}(\mathbb{R}^n)$ heißt **translationsinvariant**, wenn für alle Vektoren $c \in \mathbb{R}^n$ und alle Borelmengen $A \in \mathcal{B}(\mathbb{R}^n)$ gilt:
$$\mu(A + c) = \mu(A)$$
wobei $A + c := \{x + c \mid x \in A\}$.

Äquivalent dazu ist, dass das Bildmaß von $\mu$ unter der Translation $\tau_c: x \mapsto x + c$ wieder $\mu$ ergibt ($\mu \tau_c = \mu$).

--proof--
Die Äquivalenz folgt direkt aus der Definition des Bildmaßes: $(\mu \tau_c)(A) = \mu(\tau_c^{-1}(A)) = \mu(A - c)$. Setzt man $A' = A - c$, so ist $\mu(A' + c) = \mu(A')$, was der Definition der Translationsinvarianz entspricht.
