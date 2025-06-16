---
key: eindeutigkeit_grenzwert
title: Eindeutigkeit des Grenzwerts
type: satz
tags: [analysis, folgen, grenzwert]
refs: [grenzwert_definition]
---
Jede konvergente Folge $(a_n)$ besitzt genau einen Grenzwert.

--proof--
Angenommen, $a_n \to a$ und $a_n \to b$ mit $a \neq b$. 
Sei $\epsilon = \frac{|a - b|}{2} > 0$. 
Nach Definition gibt es $n_1, n_2$, so dass $|a_n - a| < \epsilon$ für $n > n_1$ und $|a_n - b| < \epsilon$ für $n > n_2$.
Für $n > \max(n_1, n_2)$ folgt mit der Dreiecksungleichung:
$|a - b| = |a - a_n + a_n - b| \le |a - a_n| + |a_n - b| < \epsilon + \epsilon = 2\epsilon = |a - b|$.
Daraus ergibt sich $|a - b| < |a - b|$, ein Widerspruch.
Also muss $a = b$ gelten.
