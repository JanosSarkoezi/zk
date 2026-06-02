---
key: unabhaengigkeit_dynkin_system_satz
title: Dynkin-System der unabhängigen Ereignisse
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit, dynkin_system
refs: [unabhaengigkeit_ereignisse_null_eins_lemma, unabhaengigkeit_ereignisse_komplement_lemma, unabhaengigkeit_ereignisse_stetigkeit_lemma, dynkin_system_definition]
---
Sei $(\Omega, \mathcal{F}, P)$ ein Wahrscheinlichkeitsraum und $A \in \mathcal{F}$ ein Ereignis. Dann ist die Menge
$$\mathcal{D}_A := \{ B \in \mathcal{F} \mid \{A, B\} \text{ ist unabhängig} \}$$
ein Dynkin-System über $\Omega$.

--proof--
Wir prüfen die Eigenschaften [[dynkin_system_definition|eines Dynkin-Systems]]:

\begin{enumerate}[label=(\arabic*)]
    \item $\Omega \in \mathcal{D}_A$: Dies folgt aus $P[A \cap \Omega] = P[A] = P[A] \cdot 1 = P[A] P[\Omega]$.
    \item $B \in \mathcal{D}_A \implies \bar{B} \in \mathcal{D}_A$: Dies ist genau die Aussage von [[unabhaengigkeit_ereignisse_komplement_lemma|Unabhängigkeit und Komplementbildung]].
    \item Ist $\{B_n\}_{n \in \mathbb{N}} \subseteq \mathcal{D}_A$ eine Folge paarweise disjunkter Mengen, so ist $\bigcup_{n=1}^\infty B_n \in \mathcal{D}_A$: Dies ist Teil (1) von [[unabhaengigkeit_ereignisse_stetigkeit_lemma|Unabhängigkeit und Stetigkeit des Maßes]].
\end{enumerate}
Somit ist $\mathcal{D}_A$ ein Dynkin-System.
