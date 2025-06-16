---
key: polynomdivision_rest
title: Division von Polynomen mit Rest
type: satz
tags: [analysis, algebra, polynome]
refs: [identitaetssatz_polynome]
---
Zu zwei Polynomen $p$ und $s$ ($s$ nicht das Nullpolynom) gibt es eindeutig bestimmte Polynome $q$ und $r$, so dass gilt:
$p = qs + r$
wobei entweder $r = 0$ ist oder $\text{grad}(r) < \text{grad}(s)$.

--proof--
Die Existenz folgt durch den bekannten Algorithmus der schriftlichen Division von Polynomen. Man eliminiert schrittweise das Glied höchster Ordnung von $p$ durch Subtraktion eines geeigneten Vielfachen von $s$.
Zur Eindeutigkeit: Angenommen $p = q_1 s + r_1 = q_2 s + r_2$. Dann folgt $(q_1 - q_2)s = r_2 - r_1$. Wäre $q_1 \neq q_2$, so wäre der Grad der linken Seite mindestens $\text{grad}(s)$, während die rechte Seite einen Grad kleiner als $\text{grad}(s)$ hat. Dies ist nur möglich, wenn $q_1 = q_2$ und somit auch $r_1 = r_2$.
