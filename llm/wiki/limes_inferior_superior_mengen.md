---
key: limes_inferior_superior_mengen
title: Limes inferior und Limes superior von Mengenfolgen
type: def
tags: [mengenlehre, mengenfolgen]
refs: []
---
Für eine Folge $\{A_n\}_{n \in \mathbb{N}} \subseteq 2^\Omega$ heißt die Menge
$$\liminf_{n \to \infty} A_n := \bigcup_{n=1}^\infty \bigcap_{k=n}^\infty A_k$$
der Limes inferior der Folge $\{A_n\}_{n \in \mathbb{N}}$ und die Menge
$$\limsup_{n \to \infty} A_n := \bigcap_{n=1}^\infty \bigcup_{k=n}^\infty A_k$$
heißt der Limes superior der Folge $\{A_n\}_{n \in \mathbb{N}}$.

--examples--
Es gilt:
$$\liminf_{n \to \infty} A_n = \{\omega \in \Omega \mid \omega \in A_n \text{ für alle außer endlich viele } n \in \mathbb{N}\}$$
und
$$\limsup_{n \to \infty} A_n = \{\omega \in \Omega \mid \omega \in A_n \text{ für unendlich viele } n \in \mathbb{N}\}$$
Damit folgt unmittelbar $\liminf_{n \to \infty} A_n \subseteq \limsup_{n \to \infty} A_n$.
