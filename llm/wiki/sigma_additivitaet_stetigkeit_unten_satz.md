---
key: sigma_additivitaet_stetigkeit_unten_satz
title: Äquivalenz von sigma-Additivität und Stetigkeit von unten
type: satz
tags: [masstheorie, inhalt, ring]
refs: [ring_definition, inhalt_definition, sigma_additivitaet_mass_definition, stetigkeit_mengenfunktionen_definition]
---
Sei $\mathcal{C}$ ein Ring und $\mu: \mathcal{C} \to [0, \infty]$ ein Inhalt. Dann sind äquivalent:
(a) $\mu$ ist $\sigma$-additiv.
(b) $\mu$ ist [[stetigkeit_mengenfunktionen_definition|stetig]] von unten.

--proof--
**(a) $\Rightarrow$ (b):** Sei $\{A_k\}$ monoton wachsend mit $A := \bigcup A_k \in \mathcal{C}$. Definiere $B_1 := A_1$ und $B_k := A_k \setminus A_{k-1}$ für $k > 1$. Dann ist $\{B_k\}$ disjunkt, $B_k \in \mathcal{C}$ und $\sum_{k=1}^\infty B_k = A$. Aus der $\sigma$-Additivität folgt:
$$\mu[A] = \sum_{k=1}^\infty \mu[B_k] = \lim_{n \to \infty} \sum_{k=1}^n \mu[B_k] = \lim_{n \to \infty} \mu[A_n] = \sup_{n \in \mathbb{N}} \mu[A_n]$$

**(b) $\Rightarrow$ (a):** Sei $\{A_k\}$ eine disjunkte Folge mit $A := \sum A_k \in \mathcal{C}$. Definiere $B_n := \sum_{k=1}^n A_k$. Dann ist $\{B_n\}$ monoton wachsend mit $\bigcup B_n = A$. Aus der [[stetigkeit_mengenfunktionen_definition|Stetigkeit]] von unten folgt:
$$\mu[A] = \sup_{n \in \mathbb{N}} \mu[B_n] = \lim_{n \to \infty} \mu\left[\sum_{k=1}^n A_k\right] = \lim_{n \to \infty} \sum_{k=1}^n \mu[A_k] = \sum_{k=1}^\infty \mu[A_k]$$
--proof--
