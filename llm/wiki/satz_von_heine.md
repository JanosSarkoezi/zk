---
key: satz_von_heine
title: Satz von Heine (Stetigkeit auf kompakten Mengen)
type: satz
tags: [analysis, stetigkeit, kompaktheit]
refs: [stetigkeit_gleichmaessig_definition, kompaktheit_folgen_definition]
---
Jede auf einer kompakten Menge $K$ [[stetigkeit_gleichmaessig_definition|stetige]] Funktion $f$ ist dort gleichmäßig [[stetigkeit_gleichmaessig_definition|stetig]].

--proof--
Heuser (Satz 36.5): Beweis durch Widerspruch. Angenommen, $f$ sei [[stetigkeit_gleichmaessig_definition|stetig]] auf $K$, aber nicht gleichmäßig [[stetigkeit_gleichmaessig_definition|stetig]]. Dann gäbe es ein $\epsilon > 0$, so dass für jedes $\delta_n = 1/n$ Punkte $x_n, y_n \in K$ existieren mit $|x_n - y_n| < 1/n$, aber $|f(x_n) - f(y_n)| \ge \epsilon$. Da $K$ kompakt ist, besitzt $(x_n)$ eine Teilfolge $x_{n_k} \to \xi \in K$. Wegen $|x_{n_k} - y_{n_k}| \to 0$ konvergiert auch $y_{n_k} \to \xi$. Aus der [[stetigkeit_gleichmaessig_definition|Stetigkeit]] folgt $f(x_{n_k}) \to f(\xi)$ und $f(y_{n_k}) \to f(\xi)$. Damit müsste $|f(x_{n_k}) - f(y_{n_k})| \to 0$ gelten, was im Widerspruch zur Annahme steht.
