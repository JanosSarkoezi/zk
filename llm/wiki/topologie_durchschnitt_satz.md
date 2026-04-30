---
key: topologie_durchschnitt_satz
title: Durchschnitt von Topologien
type: satz
tags: [topologie, mengensysteme]
refs: [topologie_definition]
---
Sei $H$ eine nichtleere Indexmenge und sei $\{\mathcal{T}_h\}_{h \in H}$ eine Familie von Topologien auf $\Omega$. Dann ist das Mengensystem
$$\mathcal{T} := \bigcap_{h \in H} \mathcal{T}_h$$
eine [[topologie_definition|Topologie]] auf $\Omega$.

--proof--
Wir zeigen, dass $\mathcal{T}$ die Axiome einer [[topologie_definition|Topologie]] erfüllt:
\begin{enumerate}[label=(\roman*)]
  \item Für alle $h \in H$ gilt $\Omega, \emptyset \in \mathcal{T}_h$. Daher gilt $\Omega, \emptyset \in \bigcap_{h \in H} \mathcal{T}_h = \mathcal{T}$.
  \item Sei $\{Q_i\}_{i \in I}$ eine beliebige Familie von Mengen in $\mathcal{T}$. Dann gilt für alle $i \in I$ und alle $h \in H$: $Q_i \in \mathcal{T}_h$. Da jedes $\mathcal{T}_h$ eine [[topologie_definition|Topologie]] ist, folgt $\bigcup_{i \in I} Q_i \in \mathcal{T}_h$ für alle $h \in H$. Daher gilt $\bigcup_{i \in I} Q_i \in \mathcal{T}$.
  \item Sei $\{Q_i\}_{i \in I}$ eine endliche Familie von Mengen in $\mathcal{T}$. Dann gilt für alle $i \in I$ und alle $h \in H$: $Q_i \in \mathcal{T}_h$. Da jedes $\mathcal{T}_h$ eine [[topologie_definition|Topologie]] ist, folgt $\bigcap_{i \in I} Q_i \in \mathcal{T}_h$ für alle $h \in H$. Daher gilt $\bigcap_{i \in I} Q_i \in \mathcal{T}$.
\end{enumerate}
Daher ist $\mathcal{T}$ eine [[topologie_definition|Topologie]] auf $\Omega$.
