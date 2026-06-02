---
key: borel_null_eins_gesetz
title: Borelsches Null-Eins-Gesetz
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit, null_eins_gesetz
refs: [borel_cantelli_lemma_1, borel_cantelli_lemma_2]
---
Sei $\{A_n\}_{n \in \mathbb{N}}$ eine unabhängige Folge von Ereignissen. Dann gilt für die Wahrscheinlichkeit des Limes superior:
$$P\left[ \limsup_{n \to \infty} A_n \right] \in \{0, 1\}$$
Genauer gilt:
$$P\left[ \limsup_{n \to \infty} A_n \right] = \begin{cases} 0 & \text{falls } \sum_{n=1}^\infty P[A_n] < \infty \\ 1 & \text{falls } \sum_{n=1}^\infty P[A_n] = \infty \end{cases}$$

--proof--
Die Aussage folgt direkt aus der Kombination des [[borel_cantelli_lemma_1|ersten]] und [[borel_cantelli_lemma_2|zweiten]] Lemmas von Borel-Cantelli. Das erste Lemma benötigt keine Unabhängigkeit, während das zweite Lemma die Unabhängigkeit zwingend voraussetzt.
