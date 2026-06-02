---
key: unabhaengigkeit_zufallsgroessen_transformation_satz
title: Unabhängigkeit unter messbaren Transformationen
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit
refs: [unabhaengigkeit_zufallsgroessen_definition]
---
Sei $\{X_i\}_{i \in I}$ eine unabhängige Familie von Zufallsgrößen $X_i : \Omega \to \Omega'_i$. Seien $T_i : \Omega'_i \to \Omega''_i$ messbare Abbildungen.

Dann ist auch die Familie der transformierten Zufallsgrößen $\{T_i \circ X_i\}_{i \in I}$ unabhängig.

--proof--
Die von $T_i \circ X_i$ erzeugte $\sigma$-Algebra ist $\sigma(T_i \circ X_i) = (T_i \circ X_i)^{-1}(\mathcal{F}''_i) = X_i^{-1}(T_i^{-1}(\mathcal{F}''_i))$. Da $T_i$ messbar ist, gilt $T_i^{-1}(\mathcal{F}''_i) \subseteq \mathcal{F}'_i$ und somit $\sigma(T_i \circ X_i) \subseteq \sigma(X_i)$.
Da die Familie $\{\sigma(X_i)\}_{i \in I}$ unabhängig ist, ist nach der Definition der Unabhängigkeit von Ereignissystemen auch jede Familie von Unter-Systemen unabhängig. Somit ist $\{\sigma(T_i \circ X_i)\}_{i \in I}$ unabhängig.
