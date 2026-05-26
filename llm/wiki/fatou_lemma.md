---
key: fatou_lemma
title: Lemma von Fatou
type: satz
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [monotone_konvergenz_satz]
---
Sei $\{f_n\}_{n \in \mathbb{N}}$ eine Folge von positiven messbaren Funktionen $f_n: \Omega \to [0, \infty]$. Dann gilt:
$$
\int_\Omega \liminf_{n \to \infty} f_n \, d\mu \le \liminf_{n \to \infty} \int_\Omega f_n \, d\mu
$$

--proof--
Sei $g_n := \inf_{k \ge n} f_k$. Dann ist $g_n$ eine monoton wachsende Folge positiver messbarer Funktionen mit $g_n \le f_n$ und $\sup g_n = \liminf f_n$. Aus dem Satz von der monotonen Konvergenz folgt:
$$
\int_\Omega \liminf f_n \, d\mu = \int_\Omega \sup g_n \, d\mu = \sup \int_\Omega g_n \, d\mu = \lim_{n \to \infty} \int_\Omega g_n \, d\mu
$$
Da $g_n \le f_n$ für alle $n$ gilt, folgt $\int g_n \, d\mu \le \int f_n \, d\mu$ und somit
$$
\lim_{n \to \infty} \int_\Omega g_n \, d\mu \le \liminf_{n \to \infty} \int_\Omega f_n \, d\mu
$$
was die Behauptung beweist.
