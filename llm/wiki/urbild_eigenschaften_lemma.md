---
key: urbild_eigenschaften_lemma
title: Eigenschaften des Urbilds
type: lemma
tags: [mengenlehre]
refs: []
---
Sei $f: \Omega \to \Omega'$ eine Abbildung. Das Urbild einer Abbildung kommutiert mit den grundlegenden operationen der Mengenlehre:
\begin{enumerate}[label=(\arabic*)]
  \item $f^{-1}(\Omega') = \Omega$ und $f^{-1}(\emptyset) = \emptyset$.
  \item Für alle $A' \in 2^{\Omega'}$ gilt $f^{-1}((A')^c) = (f^{-1}(A'))^c$.
  \item Für jede Familie $\{A'_i\}_{i \in I} \subseteq 2^{\Omega'}$ gilt
$$f^{-1}\left(\bigcup_{i \in I} A'_i\right) = \bigcup_{i \in I} f^{-1}(A'_i)$$
und
$$f^{-1}\left(\bigcap_{i \in I} A'_i\right) = \bigcap_{i \in I} f^{-1}(A'_i)$$
\end{enumerate}

--proof--
Diese Eigenschaften folgen direkt aus der Definition des Urbilds $f^{-1}(A') = \{ \omega \in \Omega \mid f(\omega) \in A' \}$:
Zu (2): $\omega \in f^{-1}((A')^c) \iff f(\omega) \in (A')^c \iff f(\omega) \notin A' \iff \omega \notin f^{-1}(A') \iff \omega \in (f^{-1}(A'))^c$.
Zu (3) für Vereinigungen: $\omega \in f^{-1}(\bigcup A'_i) \iff f(\omega) \in \bigcup A'_i \iff \exists i \in I: f(\omega) \in A'_i \iff \exists i \in I: \omega \in f^{-1}(A'_i) \iff \omega \in \bigcup f^{-1}(A'_i)$.
Die Durchschnitte folgen analog oder über die de Morganschen Regeln aus (2) und (3).
Insbesondere folgt aus (3), dass Urbilder disjunkter Mengen wieder disjunkt sind.
