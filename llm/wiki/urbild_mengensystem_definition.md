---
key: urbild_mengensystem_definition
title: Urbild eines Mengensystems
type: def
tags: [mengenlehre, mengensysteme]
refs: [urbild_eigenschaften_lemma]
---
Seien $\Omega$ und $\Omega'$ nichtleere Mengen und sei $f: \Omega \to \Omega'$ eine Abbildung. Für ein Mengensystem $\mathcal{E}' \subseteq 2^{\Omega'}$ heißt das Mengensystem
$$f^{-1}(\mathcal{E}') := \{ A \in 2^\Omega \mid A = f^{-1}(A') \text{ mit } A' \in \mathcal{E}' \}$$
das Urbild von $\mathcal{E}'$ unter $f$.

--examples--
Das Urbild einer Abbildung $f^{-1}: 2^{\Omega'} \to 2^\Omega$ kommutiert mit den grundlegenden Operationen der Mengenlehre. Insbesondere gilt nach Lemma 2.1.1:
\begin{enumerate}[label=(\arabic*)]
  \item $f^{-1}(\Omega') = \Omega$ und $f^{-1}(\emptyset) = \emptyset$.
  \item $f^{-1}((A')^c) = (f^{-1}(A'))^c$.
  \item $f^{-1}(\bigcup_{i \in I} A'_i) = \bigcup_{i \in I} f^{-1}(A'_i)$ und $f^{-1}(\bigcap_{i \in I} A'_i) = \bigcap_{i \in I} f^{-1}(A'_i)$.
\end{enumerate}
Daraus folgt unmittelbar (Folgerung 2.1.2):
- Das Urbild einer Topologie ist eine Topologie.
- Das Urbild einer [[sigma_algebra_definition|$\sigma$-Algebra]] ist eine $\sigma$-Algebra.
