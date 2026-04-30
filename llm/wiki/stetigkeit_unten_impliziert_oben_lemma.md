---
key: stetigkeit_unten_impliziert_oben_lemma
title: Zusammenhang zwischen Stetigkeit von unten und oben
type: lemma
tags: [masstheorie, inhalt, ring]
refs: [ring_definition, inhalt_definition, stetigkeit_mengenfunktionen_definition]
---
Sei $\mathcal{C}$ ein Ring und $\mu: \mathcal{C} \to [0, \infty]$ ein Inhalt. Ist $\mu$ [[stetigkeit_mengenfunktionen_definition|stetig]] von unten, so ist $\mu$ auch [[stetigkeit_mengenfunktionen_definition|stetig]] von oben.

--proof--
Sei $\{A_k\}$ monoton fallend mit $A := \bigcap A_k \in \mathcal{C}$ und $\mu[A_1] < \infty$.
Betrachte die Folge $B_k := A_1 \setminus A_k$. Da $\mathcal{C}$ ein Ring ist, ist $B_k \in \mathcal{C}$. Die Folge $\{B_k\}$ ist monoton wachsend mit $\bigcup B_k = A_1 \setminus A$.
Aus der [[stetigkeit_mengenfunktionen_definition|Stetigkeit]] von unten folgt:
$$\mu[A_1 \setminus A] = \sup_{k \in \mathbb{N}} \mu[A_1 \setminus A_k]$$
Wegen $\mu[A_k] \le \mu[A_1] < \infty$ und der Subtraktivität von Inhalten ($\mu[X \setminus Y] = \mu[X] - \mu[Y]$ für $Y \subseteq X$) gilt:
$$\mu[A_1] - \mu[A] = \sup_{k \in \mathbb{N}} (\mu[A_1] - \mu[A_k]) = \mu[A_1] - \inf_{k \in \mathbb{N}} \mu[A_k]$$
Daraus folgt $\mu[A] = \inf \mu[A_k]$.
--proof--
