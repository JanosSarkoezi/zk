---
key: majorisierte_konvergenz_satz
title: Satz von der majorisierten Konvergenz (Lebesgue)
type: satz
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [integrierbarkeit_definition, fatou_lemma]
---
Sei $\{f_n\}_{n \in \mathbb{N}}$ eine Folge von messbaren reellen Funktionen auf $\Omega$, die punktweise fast überall gegen eine Funktion $f$ konvergieren. Existiert eine integrierbare Funktion $g$ (eine sogenannte Majorante), so dass $|f_n| \le g$ fast überall für alle $n \in \mathbb{N}$ gilt, dann ist auch $f$ integrierbar und es gilt:
$$
\lim_{n \to \infty} \int_\Omega f_n \, d\mu = \int_\Omega f \, d\mu
$$
Darüber hinaus gilt sogar $\lim_{n \to \infty} \int_\Omega |f_n - f| \, d\mu = 0$ (Konvergenz im ersten Mittel).

--proof--
Da $|f_n| \le g$ und $f_n \to f$ fast überall, gilt auch $|f| \le g$ fast überall, also ist $f$ integrierbar. 
Betrachte $h_n := 2g - |f_n - f| \ge 0$. Nach dem Lemma von Fatou gilt:
$$
\int_\Omega \liminf h_n \, d\mu \le \liminf \int_\Omega h_n \, d\mu
$$
Wegen $\liminf h_n = 2g$ fast überall folgt:
$$
2 \int_\Omega g \, d\mu \le 2 \int_\Omega g \, d\mu - \limsup \int_\Omega |f_n - f| \, d\mu
$$
Da $\int g \, d\mu < \infty$, folgt $\limsup \int |f_n - f| \, d\mu \le 0$, also $\lim \int |f_n - f| \, d\mu = 0$. Die Behauptung folgt dann aus $|\int f_n - \int f| \le \int |f_n - f|$.
