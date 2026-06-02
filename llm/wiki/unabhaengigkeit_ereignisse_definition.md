---
key: unabhaengigkeit_ereignisse_definition
title: Unabhängigkeit von Ereignissen
type: def
tags: wahrscheinlichkeit, unabhaengigkeit
refs: [bedingte_wahrscheinlichkeit_definition]
---
Zwei Ereignisse $A, B \in \mathcal{F}$ eines Wahrscheinlichkeitsraums $(\Omega, \mathcal{F}, P)$ heißen **unabhängig** (voneinander), wenn gilt:
$$P[A \cap B] = P[A] P[B]$$

In diesem Fall sagt man auch, dass $A$ unabhängig von $B$ ist (und umgekehrt).

--proof--
Die Definition ist motiviert durch die bedingte Wahrscheinlichkeit. Falls $P[B] \in (0,1)$ ist, so ist $A$ genau dann unabhängig von $B$, wenn die bedingte Wahrscheinlichkeit von $A$ unter $B$ gleich der unbedingten Wahrscheinlichkeit von $A$ ist:
$$P[A | B] = \frac{P[A \cap B]}{P[B]} = P[A] \iff P[A \cap B] = P[A] P[B]$$
Ebenso gilt dann $P[A|B] = P[A|\bar{B}]$, was bedeutet, dass das Eintreten oder Nicht-Eintreten von $B$ keinen Einfluss auf die Wahrscheinlichkeit von $A$ hat.
