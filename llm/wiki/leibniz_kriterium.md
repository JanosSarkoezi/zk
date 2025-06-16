---
key: leibniz_kriterium
title: Leibniz-Kriterium für alternierende Reihen
type: satz
tags: [analysis, reihen, konvergenz]
refs: [reihe_definition, monotoniekriterium]
---
Sei $(a_n)$ eine monoton fallende Nullfolge reeller Zahlen mit $a_n \ge 0$. Dann konvergiert die alternierende Reihe
$\sum_{n=0}^\infty (-1)^n a_n = a_0 - a_1 + a_2 - a_3 \pm \dots$.

--proof--
Betrachte die Teilsummen $s_{2n+1}$ und $s_{2n}$.
Es gilt $s_{2n+1} = s_{2n-1} + (a_{2n} - a_{2n+1}) \ge s_{2n-1}$, da $(a_n)$ monoton fallend ist. Die ungeraden Teilsummen wachsen also monoton.
Analog ist $s_{2n+2} = s_{2n} - (a_{2n+1} - a_{2n+2}) \le s_{2n}$, die geraden Teilsummen fallen monoton.
Wegen $s_{2n+1} = s_{2n} - a_{2n+1} \le s_{2n}$ und $s_1 \le s_{2n+1} \le s_{2n} \le s_0$ sind beide Folgen beschränkt und monoton, besitzen also nach dem Monotoniekriterium Grenzwerte. 
Wegen $s_{2n} - s_{2n-1} = a_{2n} \to 0$ müssen diese Grenzwerte identisch sein.
