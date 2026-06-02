---
key: unabhaengigkeit_ereignisse_komplement_satz
title: Unabhängigkeit und Komplemente bei Familien
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit
refs: [unabhaengigkeit_ereignisse_familie_definition, unabhaengigkeit_ereignisse_komplement_lemma]
---
Sei $\{A_i\}_{i \in I}$ eine unabhängige Familie von Ereignissen. Ersetzt man eine beliebige Teilmenge dieser Ereignisse durch ihre Komplemente, so bleibt die Familie unabhängig.

Präzise: Sei $J \subseteq I$ und definiere $B_i := A_i$ für $i \in I \setminus J$ und $B_i := \bar{A}_i$ für $i \in J$. Dann ist die Familie $\{B_i\}_{i \in I}$ ebenfalls unabhängig.

--proof--
Aufgrund der Definition der Unabhängigkeit über endliche Teilmengen genügt es, den Fall einer endlichen Indexmenge $I = \{1, \dots, n\}$ zu betrachten. Der Beweis erfolgt per Induktion über die Anzahl $k$ der durch Komplemente ersetzten Ereignisse.
Der Induktionsanfang $k=1$ entspricht dem [[unabhaengigkeit_ereignisse_komplement_lemma|Unabhängigkeit und Komplementbildung]]. Der Induktionsschritt nutzt die Tatsache, dass wenn $\{A_1, \dots, A_n\}$ unabhängig ist, auch $\{A_1, \dots, A_{n-1}, \bar{A}_n\}$ unabhängig ist, und wendet dies sukzessive an.
