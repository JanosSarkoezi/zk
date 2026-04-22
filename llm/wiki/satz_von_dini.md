---
key: satz_von_dini
title: Satz von Dini
type: satz
tags: [analysis, konvergenz, kompaktheit]
refs: [stetigkeit_folgen_definition, kompaktheit_folgen_definition]
---
Sei $X$ eine kompakte Menge und $(f_n)$ eine Folge stetiger Funktionen auf $X$, die **monoton** (d.h. $f_1 \le f_2 \le \dots$ oder $f_1 \ge f_2 \ge \dots$) gegen eine stetige Grenzfunktion $f$ konvergiert. Dann ist die Konvergenz auf $X$ bereits gleichmäßig.

--proof--
Ohne Einschränkung sei $f_n \nearrow f$. Setze $g_n = f - f_n$. Dann sind $g_n$ stetig, $g_n \ge 0$ und $g_n \searrow 0$. Zu $\epsilon > 0$ definiere $K_n = \{x \in X : g_n(x) \ge \epsilon\}$. Da $g_n$ stetig ist, sind die $K_n$ kompakt. Wegen der Monotonie gilt $K_{n+1} \subset K_n$. Da $g_n(x) \to 0$ für jedes $x$, ist der Durchschnitt aller $K_n$ leer. Nach der Durchschnittseigenschaft kompakter Mengen muss dann bereits ein $K_{n_0}$ leer sein. Das bedeutet $g_n(x) < \epsilon$ für alle $n \ge n_0$ und alle $x \in X$.
