---
key: uneigentliches_integral_unbeschraenkt_definition
title: Uneigentliche Integrale über unbeschränkte Intervalle
type: def
tags: [analysis, integralrechnung]
refs: [riemann_integral_definition, grenzwert_funktion_definition]
---
Ein Integral über ein unbeschränktes Intervall wird als Grenzwert von Riemann-Integralen über endlichen Teilintervallen definiert.

\begin{enumerate}
    \item Sei $f$ für jedes $t > a$ auf $[a, t]$ R-integrierbar. Existiert der Grenzwert
    $$\int_{a}^{\infty} f(x) \, dx := \lim_{t \to \infty} \int_{a}^{t} f(x) \, dx$$
    als endliche Zahl, so heißt das uneigentliche Integral \textbf{konvergent}. Andernfalls heißt es \textbf{divergent}.

    \item Entsprechend definiert man für eine auf $[t, b]$ integrierbare Funktion:
    $$\int_{-\infty}^{b} f(x) \, dx := \lim_{t \to -\infty} \int_{t}^{b} f(x) \, dx$$

    \item Ein Integral über $(-\infty, \infty)$ heißt konvergent, wenn für ein beliebiges $a \in \mathbb{R}$ beide Integrale $\int_{-\infty}^{a} f(x) \, dx$ und $\int_{a}^{\infty} f(x) \, dx$ konvergieren. Man setzt dann:
    $$\int_{-\infty}^{\infty} f(x) \, dx := \int_{-\infty}^{a} f(x) \, dx + \int_{a}^{\infty} f(x) \, dx$$
\end{enumerate}

--proof--
Die Definition erweitert den Integralbegriff durch einen Grenzübergang. Die Wahl von $a$ im dritten Fall ist unerheblich, da für $a < b$ gilt:
$$\int_{t}^{a} f(x) \, dx + \int_{a}^{\infty} f(x) \, dx = \int_{t}^{b} f(x) \, dx - \int_{a}^{b} f(x) \, dx + \int_{a}^{\infty} f(x) \, dx$$
Beim Grenzübergang $t \to -\infty$ heben sich die konstanten Anteile konsistent auf.
