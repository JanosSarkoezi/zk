---
key: absolute_konvergenz
title: Absolute Konvergenz von Reihen
type: satz
tags: [analysis, reihen, konvergenz]
refs: [reihe_definition, cauchy_kriterium]
---
Eine unendliche [[reihe_definition|Reihe]] $\sum a_n$ heißt **absolut konvergent**, wenn die [[reihe_definition|Reihe]] der Absolutbeträge $\sum |a_n|$ [[cauchy_kriterium|konvergiert]].
Jede absolut [[cauchy_kriterium|konvergente]] [[reihe_definition|Reihe]] ist auch (im gewöhnlichen Sinne) konvergent, und es gilt:
$|\sum_{n=0}^\infty a_n| \le \sum_{n=0}^\infty |a_n|$.

--proof--
Die [[cauchy_kriterium|Konvergenz]] folgt aus dem Cauchy-Kriterium für [[reihe_definition|Reihen]]. Für $m > n$ gilt mit der allgemeinen Dreiecksungleichung:
$|s_m - s_n| = |\sum_{k=n+1}^m a_k| \le \sum_{k=n+1}^m |a_k|$.
Da $\sum |a_n|$ [[cauchy_kriterium|konvergiert]], ist die rechte Seite für große $n, m$ beliebig klein. Somit erfüllt auch $\sum a_n$ das Cauchy-Kriterium und ist konvergent. 
Die Ungleichung folgt durch Grenzübergang aus der endlichen Dreiecksungleichung.
