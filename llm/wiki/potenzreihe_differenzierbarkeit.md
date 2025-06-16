---
key: potenzreihe_differenzierbarkeit
title: Differenzierbarkeit von Potenzreihen
type: satz
tags: [analysis, potenzreihe, ableitung]
refs: [potenzreihe_definition_konvergenz, stetigkeit_gleichmaessig_definition]
---
Eine Potenzreihe $f(x) = \sum_{n=0}^\infty a_n (x-x_0)^n$ ist im Innern ihres Konvergenzintervalls $K = (x_0-r, x_0+r)$ beliebig oft differenzierbar. Die Ableitungen können durch **gliedweise Differentiation** berechnet werden:
$$f'(x) = \sum_{n=1}^\infty n a_n (x-x_0)^{n-1}$$
Die abgeleitete Reihe hat denselben Konvergenzradius $r$ wie die ursprüngliche Reihe.

--proof--
Der Beweis nutzt die Tatsache, dass eine Potenzreihe innerhalb ihres Konvergenzradius lokal gleichmäßig konvergiert. Da $\limsup \sqrt[n]{n|a_n|} = \limsup \sqrt[n]{|a_n|}$ (wegen $\sqrt[n]{n} \to 1$), bleibt der Konvergenzradius erhalten.
