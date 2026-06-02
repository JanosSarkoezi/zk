---
key: borel_cantelli_lemma_2
title: Zweites Lemma von Borel-Cantelli
type: lemma
tags: wahrscheinlichkeit, konvergenz, unabhaengigkeit, borel_cantelli
refs: [borel_cantelli_lemma_1, unabhaengigkeit_ereignisse_familie_definition]
---
Sei $\{A_n\}_{n \in \mathbb{N}}$ eine **unabhängige** Folge von Ereignissen. Falls die Summe der Wahrscheinlichkeiten divergiert, d.h.
$$\sum_{n=1}^\infty P[A_n] = \infty$$
dann ist die Wahrscheinlichkeit für das Eintreten unendlich vieler dieser Ereignisse gleich Eins:
$$P\left[ \limsup_{n \to \infty} A_n \right] = 1$$

--proof--
Wir zeigen $P[(\limsup A_n)^c] = 0$. Es gilt:
$$(\limsup_{n \to \infty} A_n)^c = \left( \bigcap_{n=1}^\infty \bigcup_{k=n}^\infty A_k \right)^c = \bigcup_{n=1}^\infty \bigcap_{k=n}^\infty A_k^c$$
Wegen der Unabhängigkeit und der Stetigkeit von oben gilt für festes $n$:
$$P\left[ \bigcap_{k=n}^\infty A_k^c \right] = \lim_{m \to \infty} P\left[ \bigcap_{k=n}^m A_k^c \right] = \lim_{m \to \infty} \prod_{k=n}^m (1 - P[A_k])$$
Mit der Ungleichung $1-x \le e^{-x}$ folgt:
$$\prod_{k=n}^m (1 - P[A_k]) \le \prod_{k=n}^m e^{-P[A_k]} = \exp\left( -\sum_{k=n}^m P[A_k] \right)$$
Da $\sum P[A_k] = \infty$, geht der Exponent gegen $-\infty$ und das Produkt gegen 0. Da dies für jedes $n$ gilt, ist auch die Wahrscheinlichkeit der Vereinigung über $n$ gleich 0.
