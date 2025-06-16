---
key: einschliessungssatz
title: Einschließungssatz (Sandwich-Theorem)
type: satz
tags: [analysis, folgen, grenzwert]
refs: [grenzwert_definition, vergleichssatz_grenzwerte]
---
Seien $(a_n), (b_n)$ und $(c_n)$ Folgen mit $a_n \le c_n \le b_n$ für fast alle $n$. Falls $\lim_{n \to \infty} a_n = \lim_{n \to \infty} b_n = a$, dann konvergiert auch $(c_n)$ gegen $a$.

--proof--
Zu $\epsilon > 0$ wähle $n_1, n_2$, so dass $|a_n - a| < \epsilon$ für $n > n_1$ und $|b_n - a| < \epsilon$ für $n > n_2$. Für $n > \max(n_1, n_2)$ gilt:
$a - \epsilon < a_n \le c_n \le b_n < a + \epsilon$,
also $a - \epsilon < c_n < a + \epsilon$, was gleichbedeutend ist mit $|c_n - a| < \epsilon$.
Dies beweist die Konvergenz von $(c_n)$ gegen $a$.
