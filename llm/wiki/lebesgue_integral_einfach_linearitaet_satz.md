---
key: lebesgue_integral_einfach_linearitaet_satz
title: Linearität und Monotonie des Integrals für positive einfache Funktionen
type: satz
tags: [integration, mass_und_wahrscheinlichkeit]
refs: [lebesgue_integral_einfach_definition]
---
Seien $f, g: \Omega \to [0, \infty)$ positive einfache Funktionen und $a \in [0, \infty)$. Dann gilt:

\begin{enumerate}[label=(\arabic*)]
    \item **Linearität**: $\int_\Omega (f+g) \, d\mu = \int_\Omega f \, d\mu + \int_\Omega g \, d\mu$ und $\int_\Omega af \, d\mu = a \int_\Omega f \, d\mu$.
    \item **Monotonie**: Falls $f \le g$, dann gilt $\int_\Omega f \, d\mu \le \int_\Omega g \, d\mu$.
\end{enumerate}

--proof--
Der Beweis folgt aus [[lebesgue_integral_einfach_definition|Lemma 8.1.1]] (allgemeine Darstellung des Integrals). Man wählt eine gemeinsame disjunkte Zerlegung $\{B_i\}$ von $\Omega$, so dass $f = \sum c_i \chi_{B_i}$ und $g = \sum d_i \chi_{B_i}$. Dann ist $f+g = \sum (c_i+d_i) \chi_{B_i}$ und $af = \sum a c_i \chi_{B_i}$. Die Behauptungen folgen dann direkt aus der Definition und der Additivität des Maßes.
