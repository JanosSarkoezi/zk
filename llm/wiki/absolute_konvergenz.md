---
key: absolute_konvergenz
title: Absolute Konvergenz von Reihen
type: satz
tags: [analysis, reihen, konvergenz]
refs: [reihe_definition, cauchy_kriterium]
---
Eine unendliche Reihe $\sum a_n$ heißt **absolut konvergent**, wenn die Reihe der Absolutbeträge $\sum |a_n|$ konvergiert.
Jede absolut konvergente Reihe ist auch (im gewöhnlichen Sinne) konvergent, und es gilt:
$|\sum_{n=0}^\infty a_n| \le \sum_{n=0}^\infty |a_n|$.

--proof--
Die Konvergenz folgt aus dem Cauchy-Kriterium für Reihen. Für $m > n$ gilt mit der allgemeinen Dreiecksungleichung:
$|s_m - s_n| = |\sum_{k=n+1}^m a_k| \le \sum_{k=n+1}^m |a_k|$.
Da $\sum |a_n|$ konvergiert, ist die rechte Seite für große $n, m$ beliebig klein. Somit erfüllt auch $\sum a_n$ das Cauchy-Kriterium und ist konvergent. 
Die Ungleichung folgt durch Grenzübergang aus der endlichen Dreiecksungleichung.
