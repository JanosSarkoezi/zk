---
key: unabhaengigkeit_ereignisse_stetigkeit_lemma
title: Unabhängigkeit und Stetigkeit des Maßes
type: lemma
tags: wahrscheinlichkeit, unabhaengigkeit
refs: [unabhaengigkeit_ereignisse_definition, sigma_additivitaet_stetigkeit_unten_satz]
---
Sei $A \in \mathcal{F}$ ein Ereignis und $\{B_n\}_{n \in \mathbb{N}} \subseteq \mathcal{F}$ eine Folge von Ereignissen derart, dass $\{A, B_n\}$ für alle $n \in \mathbb{N}$ unabhängig ist. Dann gilt:

\begin{enumerate}[label=(\arabic*)]
    \item Ist $\{B_n\}_{n \in \mathbb{N}}$ disjunkt, so ist $\{A, \bigcup_{n=1}^\infty B_n\}$ unabhängig.
    \item Ist $\{B_n\}_{n \in \mathbb{N}}$ monoton wachsend, so ist $\{A, \bigcup_{n \in \mathbb{N}} B_n\}$ unabhängig.
    \item Ist $\{B_n\}_{n \in \mathbb{N}}$ monoton fallend, so ist $\{A, \bigcap_{n \in \mathbb{N}} B_n\}$ unabhängig.
\end{enumerate}

--proof--
Zu (1): Aus der $\sigma$-Additivität von $P$ folgt:
$$P[A \cap \bigcup_{n=1}^\infty B_n] = P[\bigcup_{n=1}^\infty (A \cap B_n)] = \sum_{n=1}^\infty P[A \cap B_n] = \sum_{n=1}^\infty P[A] P[B_n] = P[A] \sum_{n=1}^\infty P[B_n] = P[A] P[\bigcup_{n=1}^\infty B_n]$$
Die Beweise für (2) und (3) folgen analog unter Verwendung der [[sigma_additivitaet_stetigkeit_unten_satz|Stetigkeit]] des Maßes von unten bzw. von oben.
