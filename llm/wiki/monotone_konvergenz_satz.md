---
key: monotone_konvergenz_satz
title: Satz von der monotonen Konvergenz (Beppo Levi)
type: satz
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [lebesgue_integral_positiv_definition]
---
Sei $\{f_n\}_{n \in \mathbb{N}}$ eine monoton wachsende Folge von positiven messbaren Funktionen $f_n: \Omega \to [0, \infty]$. Dann gilt
$$
\int_\Omega \sup_{n \in \mathbb{N}} f_n \, d\mu = \sup_{n \in \mathbb{N}} \int_\Omega f_n \, d\mu
$$
Oder äquivalent: $\lim_{n \to \infty} \int_\Omega f_n \, d\mu = \int_\Omega \lim_{n \to \infty} f_n \, d\mu$.

--proof--
Die Ungleichung $\ge$ folgt sofort aus der Monotonie des Integrals, da $f_n \le \sup f_k$ für alle $n$.
Für $\le$ betrachtet man eine einfache Funktion $h$ mit $0 \le h \le \sup f_n$ und ein $\alpha \in (0, 1)$. Sei $D_n := \{ f_n \ge \alpha h \}$. Dann ist $D_n$ monoton wachsend gegen $\Omega$. Es gilt
$$
\int_\Omega f_n \, d\mu \ge \int_{D_n} f_n \, d\mu \ge \int_{D_n} \alpha h \, d\mu = \alpha \int_\Omega h \chi_{D_n} \, d\mu
$$
Da $\mu$ stetig von unten ist, konvergiert $\int_\Omega h \chi_{D_n} \, d\mu$ gegen $\int_\Omega h \, d\mu$. Somit $\sup \int f_n \, d\mu \ge \alpha \int h \, d\mu$. Mit $\alpha \to 1$ und Supremum über $h$ folgt die Behauptung.
