---
key: uneigentliches_integral_konvergenzkriterien
title: Konvergenzkriterien für uneigentliche Integrale
type: satz
tags: [analysis, integralrechnung]
refs: [uneigentliches_integral_unbeschraenkt_definition, cauchy_kriterium]
---
Für die [[cauchy_kriterium|Konvergenz]] uneigentlicher [[uneigentliches_integral_unbeschraenkt_definition|Integrale]] $\int_{a}^{\infty} f(x) \, dx$ gelten folgende Kriterien:

\begin{enumerate}
    \item \textbf{Cauchy-Kriterium}: Das [[uneigentliches_integral_unbeschraenkt_definition|Integral]] [[cauchy_kriterium|konvergiert]] genau dann, wenn zu jedem $\epsilon > 0$ ein $s_0$ existiert, so dass für alle $t > s > s_0$ gilt:
    $$\left| \int_{s}^{t} f(x) \, dx \right| < \epsilon$$

    \item \textbf{Monotoniekriterium}: Ist $f \ge 0$ auf $[a, \infty)$, so [[cauchy_kriterium|konvergiert]] $\int_{a}^{\infty} f(x) \, dx$ genau dann, wenn die Teilintegrale $\int_{a}^{t} f(x) \, dx$ nach oben beschränkt sind.

    \item \textbf{Majorantenkriterium}: Gilt $|f| \le g$ auf $[a, \infty)$ und [[cauchy_kriterium|konvergiert]] $\int_{a}^{\infty} g(x) \, dx$, so [[cauchy_kriterium|konvergiert]] $\int_{a}^{\infty} f(x) \, dx$ (sogar absolut).

    \item \textbf{Minorantenkriterium}: Gilt $0 \le h \le f$ und divergiert $\int_{a}^{\infty} h(x) \, dx$, so divergiert auch $\int_{a}^{\infty} f(x) \, dx$.

    \item \textbf{Grenzwertkriterium}: Sind $f, g > 0$ und existiert der Grenzwert $\lim_{x \to \infty} \frac{f(x)}{g(x)} = L$ mit $L \in (0, \infty)$, so haben beide [[uneigentliches_integral_unbeschraenkt_definition|Integrale]] dasselbe Konvergenzverhalten.
\end{enumerate}

--proof--
Diese Kriterien sind direkte Übertragungen der Kriterien für Zahlenfolgen und unendliche Reihen auf die Funktion $F(t) = \int_{a}^{t} f(x) \, dx$. Die absolute [[cauchy_kriterium|Konvergenz]] (Punkt 3) folgt aus der Vollständigkeit von $\mathbb{R}$.
