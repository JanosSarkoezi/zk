---
key: wahrscheinlichkeitsraum_definition
title: Wahrscheinlichkeitsraum und Zufallsvariable
type: def
tags: [wahrscheinlichkeitstheorie]
refs: [mass_mit_dichte_definition, messbarer_raum_definition]
---
Ein **Wahrscheinlichkeitsraum** ist ein Maßraum $(\Omega, \mathcal{F}, P)$, bei dem das Maß $P$ die Eigenschaft $P(\Omega) = 1$ besitzt. In diesem Kontext wird:

- $\Omega$ als Ergebnismenge,

- $\mathcal{F}$ als Ereignisalgebra (oder $\sigma$-Algebra der Ereignisse),

- $P$ als Wahrscheinlichkeitsmaß bezeichnet.

Eine [[messbarer_raum_definition|messbare Abbildung]] $X: \Omega \to \Omega'$ in einen weiteren Messraum $(\Omega', \mathcal{F}')$ heißt **Zufallsvariable** (oder allgemeiner Zufallsgröße). Das Bildmaß $P_X = P \circ X^{-1}$ auf $\Omega'$ heißt die **Verteilung** von $X$.

--proof--
Da $P$ ein Maß mit $P(\Omega)=1$ ist, ist $P_X$ ebenfalls ein Maß auf $\Omega'$ mit $P_X(\Omega') = P(X^{-1}(\Omega')) = P(\Omega) = 1$. Somit ist auch $P_X$ ein Wahrscheinlichkeitsmaß.
