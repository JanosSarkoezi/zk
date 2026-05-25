---
key: mass_eindeutigkeitssatz
title: Eindeutigkeitssatz für Maße
type: satz
tags: [masstheorie, fortsetzung]
refs: [sigma_algebra_definition, schnittstabiles_mengensystem_definition]
---
Sei $\Omega$ eine Menge, $\mathcal{F} = \sigma(\mathcal{E})$ die von einem $\cap$-stabilen Mengensystem $\mathcal{E}$ erzeugte $\sigma$-Algebra.

Sind $\mu, \nu: \mathcal{F} \to [0, \infty]$ zwei Maße mit:
\begin{enumerate}[label=(\arabic*)]
    \item $\mu(E) = \nu(E)$ für alle $E \in \mathcal{E}$
    \item Es gibt eine Folge $\{E_n\}_{n \in \mathbb{N}} \subseteq \mathcal{E}$ mit $\Omega = \bigcup_{n=1}^\infty E_n$ und $\mu(E_n) < \infty$ für alle $n$ ($\sigma$-Endlichkeit auf $\mathcal{E}$)
\end{enumerate}

Dann gilt $\mu = \nu$ auf der gesamten $\sigma$-Algebra $\mathcal{F}$.

--proof--
Der Beweis verwendet das Prinzip der guten Mengen und die Tatsache, dass ein Dynkin-System, das ein $\cap$-stabiles Erzeugersystem enthält, bereits die erzeugte $\sigma$-Algebra umfasst.
Zunächst betrachtet man den endlichen Fall $\mu(\Omega) = \nu(\Omega) < \infty$. Die Menge $\mathcal{D} := \{A \in \mathcal{F} \mid \mu(A) = \nu(A)\}$ bildet ein Dynkin-System. Da $\mathcal{E} \subseteq \mathcal{D}$ und $\mathcal{E}$ $\cap$-stabil ist, folgt $\sigma(\mathcal{E}) \subseteq \mathcal{D}$.
Der allgemeine $\sigma$-endliche Fall wird durch Einschränkung auf die Mengen $E_n$ und anschließenden Grenzübergang (Stetigkeit von unten) bewiesen.
