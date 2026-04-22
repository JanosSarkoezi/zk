---
key: numerische_integrationsregeln
title: Numerische Integrationsregeln
type: satz
tags: [analysis, integral, numerik]
refs: [riemann_integral_definition, satz_von_taylor]
---
Zur näherungsweisen Berechnung von Integralen $\int_a^b f(x) \, dx$ werden häufig die Trapezregel und die Simpsonsche Regel verwendet:
- **Trapezregel**: $\int_a^b f(x) \, dx \approx \frac{b-a}{2} [f(a) + f(b)]$
- **Simpsonsche Regel (Keplersche Fassregel)**: $\int_a^b f(x) \, dx \approx \frac{b-a}{6} [f(a) + 4f(\frac{a+b}{2}) + f(b)]$

--proof--
Die Regeln lassen sich durch Integration von Interpolationspolynomen herleiten. Die Trapezregel nutzt ein lineares Polynom durch $(a, f(a))$ und $(b, f(b))$. Die Simpsonsche Regel nutzt eine Parabel durch die Endpunkte und den Mittelpunkt. Die Fehlerabschätzungen folgen aus dem Satz von Taylor; der Fehler der Trapezregel ist proportional zu $(b-a)^3 f''(\xi)$, der der Simpson-Regel proportional zu $(b-a)^5 f^{(4)}(\xi)$.
