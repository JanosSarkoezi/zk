---
key: sigma_algebra_durchschnitt_satz
title: Durchschnitt von sigma-Algebren
type: satz
tags: [masstheorie, mengensysteme]
refs: [sigma_algebra_definition]
---
Sei $H$ eine nichtleere Indexmenge und sei $\{\mathcal{F}_h\}_{h \in H}$ eine Familie von $\sigma$-Algebren auf $\Omega$. Dann ist das Mengensystem
$$\mathcal{F} := \bigcap_{h \in H} \mathcal{F}_h$$
eine [[sigma_algebra_definition|$\sigma$-Algebra]] auf $\Omega$.

--proof--
Der Beweis verläuft analog zum Beweis für den Durchschnitt von Topologien durch Nachprüfen der Axiome:
\begin{enumerate}[label=(\roman*)]
  \item Da $\Omega \in \mathcal{F}_h$ für alle $h \in H$, gilt $\Omega \in \mathcal{F}$.
  \item Ist $A \in \mathcal{F}$, so gilt $A \in \mathcal{F}_h$ für alle $h \in H$. Da jedes $\mathcal{F}_h$ eine [[sigma_algebra_definition|$\sigma$-Algebra]] ist, folgt $A^c \in \mathcal{F}_h$ für alle $h \in H$. Also $A^c \in \mathcal{F}$.
  \item Ist $\{A_n\}_{n \in \mathbb{N}} \subseteq \mathcal{F}$, so gilt $\{A_n\}_{n \in \mathbb{N}} \subseteq \mathcal{F}_h$ für alle $h \in H$. Da jedes $\mathcal{F}_h$ eine [[sigma_algebra_definition|$\sigma$-Algebra]] ist, folgt $\bigcup_{n=1}^\infty A_n \in \mathcal{F}_h$ für alle $h \in H$. Also $\bigcup_{n=1}^\infty A_n \in \mathcal{F}$.
\end{enumerate}
