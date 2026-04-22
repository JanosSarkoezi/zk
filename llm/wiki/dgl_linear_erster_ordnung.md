---
key: dgl_linear_erster_ordnung
title: Lineare Differentialgleichung erster Ordnung
type: satz
tags: [analysis, differentialgleichung]
refs: [dgl_getrennte_veraenderliche, stammfunktion_definition]
---
Eine lineare Differentialgleichung erster Ordnung hat die Form:
$$y' = a(x)y + s(x)$$
Die allgemeine Lösung ergibt sich aus der Summe einer partikulären Lösung $y_p$ und der allgemeinen Lösung der homogenen Gleichung $y_h$:
$$y(x) = y_h(x) + y_p(x) = C \cdot e^{A(x)} + e^{A(x)} \int s(x) e^{-A(x)} \, dx$$
wobei $A(x) = \int a(x) \, dx$ eine Stammfunktion von $a$ ist.

--proof--
Die homogene Gleichung $y' = a(x)y$ ist eine DGL mit getrennten Veränderlichen und hat die Lösung $y_h(x) = C e^{A(x)}$. Für die partikuläre Lösung nutzt man den Ansatz der **Variation der Konstanten**: $y_p(x) = C(x) e^{A(x)}$. Einsetzen in die inhomogene Gleichung liefert $C'(x) e^{A(x)} = s(x)$, woraus $C(x) = \int s(x) e^{-A(x)} \, dx$ folgt.
