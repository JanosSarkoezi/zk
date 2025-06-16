---
key: grenzwertsatz_cauchy_mittel
title: Cauchyscher Grenzwertsatz (Arithmetisches Mittel)
type: satz
tags: [analysis, folgen, cauchy]
refs: [grenzwert_definition, beschraenktheit_konvergenter_folgen]
---
Konvergiert die Folge $(a_n)$ gegen $a$, so konvergiert auch die Folge ihrer arithmetischen Mittel $(s_n)$ mit
$s_n = \frac{a_1 + a_2 + \dots + a_n}{n}$
gegen $a$.

--proof--
Sei zunächst $a = 0$. Zu $\epsilon > 0$ gibt es ein $m$, so dass $|a_k| < \epsilon/2$ für alle $k > m$. 
Für $n > m$ gilt:
$|s_n| \le \frac{|a_1 + \dots + a_m|}{n} + \frac{|a_{m+1} + \dots + a_n|}{n} < \frac{|a_1 + \dots + a_m|}{n} + \frac{(n-m)\epsilon/2}{n} < \frac{|a_1 + \dots + a_m|}{n} + \frac{\epsilon}{2}$.
Da der erste Term für $n \to \infty$ gegen 0 geht, gibt es ein $n_0$, so dass dieser Term kleiner als $\epsilon/2$ ist. Somit ist $|s_n| < \epsilon$ für $n > n_0$.
Für $a \neq 0$ betrachte die Folge $(a_n - a)$, die gegen 0 konvergiert. Die Linearität des Mittels liefert dann die Behauptung.
