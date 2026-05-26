---
key: integral_linearitaet_monotonie_satz
title: Linearität und Monotonie des Lebesgue-Integrals
type: satz
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [integrierbarkeit_definition, lebesgue_integral_einfach_linearitaet_satz]
---
Seien $f, g$ integrierbare Funktionen und $a, b \in \mathbb{R}$. Dann gilt:

\begin{enumerate}[label=(\arabic*)]
    \item **Linearität**: $af + bg$ ist integrierbar und $\int_\Omega (af + bg) \, d\mu = a \int_\Omega f \, d\mu + b \int_\Omega g \, d\mu$.
    \item **Monotonie**: Falls $f \le g$ fast überall, dann gilt $\int_\Omega f \, d\mu \le \int_\Omega g \, d\mu$.
    \item **Dreiecksungleichung**: $\left| \int_\Omega f \, d\mu \right| \le \int_\Omega |f| \, d\mu$.
\end{enumerate}

--proof--
Die Linearität folgt aus der Zerlegung in Positiv- und Negativteil und der Linearität des Integrals für positive messbare Funktionen (Lemma 8.3.7). Die Monotonie ergibt sich analog. Die Dreiecksungleichung folgt aus $f \le |f|$ und $-f \le |f|$ mittels Monotonie.
