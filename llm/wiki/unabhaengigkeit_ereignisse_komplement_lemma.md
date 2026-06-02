---
key: unabhaengigkeit_ereignisse_komplement_lemma
title: Unabhängigkeit und Komplementbildung
type: lemma
tags: wahrscheinlichkeit, unabhaengigkeit
refs: [unabhaengigkeit_ereignisse_definition]
---
Seien $A, B \in \mathcal{F}$ unabhängige Ereignisse. Dann sind auch die Ereignisse $A$ und $\bar{B}$ unabhängig.

Durch wiederholte Anwendung folgt, dass auch $\{\bar{A}, B\}$ und $\{\bar{A}, \bar{B}\}$ unabhängige Familien sind.

--proof--
Es gilt:
$$P[A \cap \bar{B}] + P[A \cap B] = P[A]$$
Da $A$ und $B$ unabhängig sind, ist $P[A \cap B] = P[A] P[B]$. Einsetzen liefert:
$$P[A \cap \bar{B}] = P[A] - P[A] P[B] = P[A] (1 - P[B]) = P[A] P[\bar{B}]$$
Dies zeigt die Unabhängigkeit von $A$ und $\bar{B}$.
