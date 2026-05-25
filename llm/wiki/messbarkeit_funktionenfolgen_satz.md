---
key: messbarkeit_funktionenfolgen_satz
title: Messbarkeit von Limites von Funktionenfolgen
type: satz
tags: [maßtheorie]
refs: [messbarkeit_numerische_funktion_charakterisierung_satz]
---
Sei $\{f_n\}_{n \in \mathbb{N}}$ eine Folge messbarer numerischer Funktionen auf $(\Omega, \mathcal{F})$. Dann sind auch folgende Funktionen messbar:

\begin{enumerate}[label=(\arabic*)]
    \item $\sup_{n \in \mathbb{N}} f_n$
    \item $\inf_{n \in \mathbb{N}} f_n$
    \item $\limsup_{n \to \infty} f_n$
    \item $\liminf_{n \to \infty} f_n$
\end{enumerate}

--proof--
Für das Supremum gilt: $\{\sup f_n > a\} = \bigcup_{n \in \mathbb{N}} \{f_n > a\}$. Da jedes $\{f_n > a\} \in \mathcal{F}$, ist auch deren abzählbare Vereinigung in $\mathcal{F}$. Analog folgt die Messbarkeit des Infimums über $\{\inf f_n < a\} = \bigcup \{f_n < a\}$.
Die Limites superior und inferior ergeben sich durch Kombination:
$\limsup f_n = \inf_{k \in \mathbb{N}} (\sup_{n \ge k} f_n)$ und $\liminf f_n = \sup_{k \in \mathbb{N}} (\inf_{n \ge k} f_n)$.
Da Suprema und Infima messbar sind, sind es auch diese Ausdrücke.
--proof--
