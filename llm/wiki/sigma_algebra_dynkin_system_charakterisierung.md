---
key: sigma_algebra_dynkin_system_charakterisierung
title: Charakterisierung von sigma-Algebren durch Dynkin-Systeme
type: satz
tags: [masstheorie, mengensysteme]
refs: [sigma_algebra_definition, dynkin_system_definition, schnittstabiles_mengensystem_definition]
---
Für ein Mengensystem $\mathcal{F} \subseteq 2^\Omega$ sind folgende Aussagen äquivalent:

\begin{enumerate}[label=(\alph*)]
    \item $\mathcal{F}$ ist eine [[sigma_algebra_definition|$\sigma$-Algebra]].
    \item $\mathcal{F}$ ist ein [[schnittstabiles_mengensystem_definition|$\cap$-stabiles]] [[dynkin_system_definition|Dynkin-System]].
\end{enumerate}

--proof--
(a) $\implies$ (b): Jede [[sigma_algebra_definition|$\sigma$-Algebra]] ist ein [[dynkin_system_definition|Dynkin-System]] und stets $\cap$-stabil.
(b) $\implies$ (a): Sei $\mathcal{F}$ ein $\cap$-stabiles [[dynkin_system_definition|Dynkin-System]]. Wir müssen zeigen, dass $\mathcal{F}$ stabil unter beliebigen abzählbaren Vereinigungen ist. Seien $\{A_n\}_{n \in \mathbb{N}} \subseteq \mathcal{F}$. Wir setzen $B_1 := A_1$ und $B_n := A_n \setminus (\bigcup_{k=1}^{n-1} A_k)$. Da $\mathcal{F}$ ein $\cap$-stabiles [[dynkin_system_definition|Dynkin-System]] ist, ist es auch stabil unter endlichen Vereinigungen (wegen $A \cup B = (A^c \cap B^c)^c$) und unter der Differenzbildung $A \setminus B$ (wenn $B \subseteq A$). Damit sind die $B_n$ paarweise disjunkt und liegen in $\mathcal{F}$. Nach Axiom (iii) für [[dynkin_system_definition|Dynkin-Systeme]] gilt $\bigcup_{n=1}^\infty A_n = \bigcup_{n=1}^\infty B_n \in \mathcal{F}$.
