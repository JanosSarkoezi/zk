---
key: unabhaengigkeit_zufallsgroessen_definition
title: Unabhängigkeit von Zufallsgrößen
type: def
tags: wahrscheinlichkeit, unabhaengigkeit, zufallsvariable
refs: [messbarer_raum_definition, unabhaengigkeit_ereignissysteme_definition]
---
Eine Familie $\{X_i\}_{i \in I}$ von Zufallsgrößen $X_i : \Omega \to \Omega_i$ auf einem Wahrscheinlichkeitsraum $(\Omega, \mathcal{F}, P)$ heißt **unabhängig**, wenn die Familie der von ihnen erzeugten $\sigma$-Algebren $\{\sigma(X_i)\}_{i \in I}$ unabhängig ist.

Dabei ist $\sigma(X_i) := X_i^{-1}(\mathcal{F}_i)$ das Urbild-System der messbaren Mengen im Zielraum.

--proof--
Zufallsgrößen sind genau dann unabhängig, wenn Informationen über die Werte einer Teilmenge von ihnen keine Rückschlüsse auf die Werte der anderen zulassen. Für reellwertige Zufallsvariablen lässt sich die Unabhängigkeit äquivalent über die Verteilungsfunktionen charakterisieren (Produkt der Verteilungsfunktionen).
