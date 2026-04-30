---
key: sigma_algebra_eigenschaften_lemma
title: Eigenschaften von sigma-Algebren
type: lemma
tags: [masstheorie, mengensysteme]
refs: [sigma_algebra_definition]
---
Sei $\mathcal{F}$ eine $\sigma$-Algebra auf $\Omega$. Dann gilt:
\begin{enumerate}[label=(\arabic*)]
  \item $\emptyset \in \mathcal{F}$.
  \item Für jede Folge $\{A_n\}_{n \in \mathbb{N}} \subseteq \mathcal{F}$ gilt $\bigcap_{n=1}^\infty A_n \in \mathcal{F}$.
  \item Für jede endliche Familie $\{A_i\}_{i \in I} \subseteq \mathcal{F}$ gilt $\bigcup_{i \in I} A_i \in \mathcal{F}$ und $\bigcap_{i \in I} A_i \in \mathcal{F}$.
\end{enumerate}

--proof--
\begin{enumerate}[label=(\arabic*)]
  \item Da $\Omega \in \mathcal{F}$ gilt, folgt aus Axiom (ii), dass $\emptyset = \Omega^c \in \mathcal{F}$ gilt.
  \item Sei $\{A_n\}_{n \in \mathbb{N}} \subseteq \mathcal{F}$. Dann gilt $A_n^c \in \mathcal{F}$ für alle $n \in \mathbb{N}$ (Axiom (ii)). Aus Axiom (iii) folgt $\bigcup_{n=1}^\infty A_n^c \in \mathcal{F}$. Erneute Anwendung von Axiom (ii) und den de Morganschen Regeln liefert:
$$\bigcap_{n=1}^\infty A_n = \left(\bigcup_{n=1}^\infty A_n^c\right)^c \in \mathcal{F}$$
  \item Folgt aus (1), (2) und Axiom (iii), indem man die endliche Familie durch Hinzufügen von $\emptyset$ (für Vereinigungen) oder $\Omega$ (für Durchschnitte) zu einer unendlichen Folge ergänzt.
\end{enumerate}
