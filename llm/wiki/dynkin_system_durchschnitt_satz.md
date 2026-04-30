---
key: dynkin_system_durchschnitt_satz
title: Durchschnitt von Dynkin-Systemen
type: satz
tags: [masstheorie, mengensysteme]
refs: [dynkin_system_definition]
---
Sei $H$ eine nichtleere Indexmenge und sei $\{\mathcal{D}_h\}_{h \in H}$ eine Familie von Dynkin-Systemen auf $\Omega$. Dann ist das Mengensystem
$$\mathcal{D} := \bigcap_{h \in H} \mathcal{D}_h$$
eine [[dynkin_system_definition|Dynkin-System]] auf $\Omega$.

--proof--
Der Beweis erfolgt durch Nachprüfen der Axiome:
\begin{enumerate}[label=(\roman*)]
  \item $\Omega \in \mathcal{D}_h$ für alle $h \in H \implies \Omega \in \mathcal{D}$.
  \item $A \in \mathcal{D} \implies A \in \mathcal{D}_h$ für alle $h \in H \implies A^c \in \mathcal{D}_h$ für alle $h \in H \implies A^c \in \mathcal{D}$.
  \item Ist $\{A_n\}_{n \in \mathbb{N}} \subseteq \mathcal{D}$ eine Folge paarweise disjunkter Mengen, so gilt $\{A_n\} \subseteq \mathcal{D}_h$ für alle $h \in H$. Also $\bigcup_{n=1}^\infty A_n \in \mathcal{D}_h$ für alle $h \in H$, woraus $\bigcup_{n=1}^\infty A_n \in \mathcal{D}$ folgt.
\end{enumerate}
