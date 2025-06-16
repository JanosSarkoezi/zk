---
key: vergleichssatz_grenzwerte
title: Vergleichssatz für Grenzwerte
type: satz
tags: [analysis, folgen, grenzwert]
refs: [grenzwert_definition]
---
Seien $(a_n)$ und $(b_n)$ konvergente Folgen mit $a_n \le b_n$ für fast alle $n$. Dann gilt für die Grenzwerte:
$\lim_{n \to \infty} a_n \le \lim_{n \to \infty} b_n$.

--proof--
Angenommen, $a = \lim a_n > \lim b_n = b$. Setze $\epsilon = \frac{a - b}{2} > 0$. 
Dann gibt es $n_1, n_2$, so dass $|a_n - a| < \epsilon$ für $n > n_1$ und $|b_n - b| < \epsilon$ für $n > n_2$.
Für $n > \max(n_1, n_2)$ folgt:
$a_n > a - \epsilon = a - \frac{a - b}{2} = \frac{a + b}{2}$
$b_n < b + \epsilon = b + \frac{a - b}{2} = \frac{a + b}{2}$
Somit gilt $b_n < \frac{a + b}{2} < a_n$, im Widerspruch zur Voraussetzung $a_n \le b_n$. 
Also muss $a \le b$ gelten.
