---
key: gliedweise_integration
title: Satz über die gliedweise Integration
type: satz
tags: [analysis, integral, konvergenz]
refs: [riemann_integral_definition, konvergenz_funktionen_definition]
---
Konvergiert eine Folge R-integrierbarer Funktionen $(f_n)$ auf $[a, b]$ gleichmäßig gegen $f$, so ist auch $f$ R-integrierbar, und es gilt:
$$\int_a^b f(x) \, dx = \lim_{n \to \infty} \int_a^b f_n(x) \, dx$$

--proof--
Die Integrierbarkeit von $f$ folgt daraus, dass die Obersummen von $f$ durch die von $f_n$ approximiert werden können. Für das Integral gilt:
$$|\int_a^b f - \int_a^b f_n| \le \int_a^b |f - f_n| \le (b-a) \|f - f_n\|_\infty$$
Da $\|f - f_n\|_\infty \to 0$, strebt die Differenz der Integrale gegen 0.
