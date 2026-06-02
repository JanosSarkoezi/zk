---
key: unabhaengigkeit_erzeugte_sigma_algebren_satz
title: Unabhängigkeit erzeugter sigma-Algebren
type: satz
tags: wahrscheinlichkeit, unabhaengigkeit, sigma_algebra
refs: [unabhaengigkeit_ereignissysteme_definition, schnittstabiles_mengensystem_definition, sigma_algebra_dynkin_system_erzeuger_satz]
---
Sei $\{\mathcal{E}_i\}_{i \in I}$ eine Familie von **schnittstabilen** ( $\cap$-stabilen) Ereignissystemen. Dann sind folgende Aussagen äquivalent:

\begin{enumerate}[label=(\arabic*)]
    \item Die Familie $\{\mathcal{E}_i\}_{i \in I}$ ist unabhängig.
    \item Die Familie der erzeugten $\sigma$-Algebren $\{\sigma(\mathcal{E}_i)\}_{i \in I}$ ist unabhängig.
\end{enumerate}

--proof--
Die Implikation (2) $\implies$ (1) ist trivial, da $\mathcal{E}_i \subseteq \sigma(\mathcal{E}_i)$.
Für (1) $\implies$ (2) nutzt man das [[sigma_algebra_dynkin_system_erzeuger_satz|Dynkin-System]]-Argument. Man zeigt zuerst für zwei Systeme $\mathcal{E}_1, \mathcal{E}_2$, dass wenn $\{\mathcal{E}_1, \mathcal{E}_2\}$ unabhängig ist und $\mathcal{E}_1$ schnittstabil ist, auch $\{\sigma(\mathcal{E}_1), \mathcal{E}_2\}$ unabhängig ist. Dazu betrachtet man für festes $A \in \mathcal{E}_2$ das System $\mathcal{D}_A = \{ B \in \mathcal{F} \mid \{A, B\} \text{ ist unabhängig} \}$, welches ein [[sigma_algebra_dynkin_system_erzeuger_satz|Dynkin-System]] ist. Da $\mathcal{E}_1 \subseteq \mathcal{D}_A$ und $\mathcal{E}_1$ schnittstabil ist, folgt $\sigma(\mathcal{E}_1) \subseteq \mathcal{D}_A$. Der allgemeine Fall folgt per Induktion über endliche Teilmengen der Indexmenge.
