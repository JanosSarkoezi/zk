---
key: energiesatz_mechanik
title: Energiesatz der Mechanik
type: satz
tags: [analysis, physik, integral]
refs: [stammfunktion_definition, hauptsatz_differential_integralrechnung]
---
In einem konservativen Kraftfeld $K(x) = -U'(x)$ ist die Summe aus kinetischer Energie $T$ und potentieller Energie $U$ zeitlich konstant:
$$E = T + U = \frac{1}{2}mv^2 + U(x) = \text{const.}$$

--proof--
Nach dem 2. Newtonschen Gesetz gilt $m \ddot{x} = K(x)$. Multiplikation mit $\dot{x}$ liefert $m \ddot{x} \dot{x} = K(x) \dot{x}$. Dies lässt sich schreiben als $\frac{d}{dt}(\frac{1}{2}m\dot{x}^2) = -U'(x) \frac{dx}{dt} = -\frac{d}{dt}U(x)$. Daraus folgt $\frac{d}{dt}(\frac{1}{2}m\dot{x}^2 + U(x)) = 0$, also ist die Gesamtenergie konstant.
