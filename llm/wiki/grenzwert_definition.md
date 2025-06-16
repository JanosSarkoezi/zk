---
key: grenzwert_definition
title: Definition des Grenzwerts einer Folge
type: def
tags: [analysis, folgen, grenzwert]
refs: [metrische_axiome]
---
Eine Folge $(a_n)$ reeller Zahlen heißt **konvergent** gegen die Zahl $a \in \mathbb{R}$, wenn zu jedem $\epsilon > 0$ ein Index $n_0(\epsilon) \in \mathbb{N}$ existiert, so dass für alle $n > n_0(\epsilon)$ gilt:
$|a_n - a| < \epsilon$.
In diesem Fall heißt $a$ der **Grenzwert** (oder Limes) der Folge $(a_n)$.
Man schreibt dafür:
$\lim_{n \to \infty} a_n = a$ oder $a_n \to a$ für $n \to \infty$.

Eine Folge, die keinen Grenzwert besitzt, heißt **divergent**.
Eine Folge, die gegen 0 konvergiert, wird als **Nullfolge** bezeichnet.

--proof--
(Kein Beweis für eine Definition erforderlich.)
Die anschauliche Bedeutung ist: In jeder beliebig kleinen $\epsilon$-Umgebung von $a$ liegen fast alle (d.h. alle bis auf höchstens endlich viele) Glieder der Folge.
