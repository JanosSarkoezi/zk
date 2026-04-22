---
key: variation_der_konstanten_zweite_ordnung
title: Variation der Konstanten (Zweite Ordnung)
type: satz
tags: [analysis, differentialgleichung]
refs: [dgl_linear_erster_ordnung, dgl_linear_inhomogen_n_ordnung]
---
Zur Lösung einer inhomogenen linearen DGL zweiter Ordnung $y'' + a y' + b y = s(x)$ mit bekannten Lösungen $y_1, y_2$ der homogenen Gleichung nutzt man den Ansatz:
$$y_p(x) = C_1(x) y_1(x) + C_2(x) y_2(x)$$
Die Ableitungen $C'_1, C'_2$ ergeben sich aus dem Gleichungssystem:
\begin{enumerate}
    \item $C'_1 y_1 + C'_2 y_2 = 0$
    \item $C'_1 y'_1 + C'_2 y'_2 = s(x)$
\end{enumerate}

--proof--
Durch Einsetzen des Ansatzes in die DGL und die Forderung (1) zur Vereinfachung der ersten Ableitung $y'_p$ erhält man die zweite Gleichung (2). Da $y_1, y_2$ linear unabhängig sind, verschwindet die Wronski-Determinante $N = y_1 y'_2 - y'_1 y_2$ nie, und das System ist eindeutig lösbar für $C'_1, C'_2$.
