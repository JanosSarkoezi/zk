---
key: partielle_integration
title: Partielle Integration
type: satz
tags: [analysis, integration]
refs: [hauptsatz_differential_integralrechnung, ableitungsregeln_arithmetik]
---
Sind $u$ und $v$ auf $[a, b]$ stetig differenzierbare Funktionen, so gilt:
$$\int_a^b u(x) v'(x) \, dx = [u(x)v(x)]_a^b - \int_a^b u'(x) v(x) \, dx$$

--proof--
Die Regel folgt durch Integration der Produktregel $(uv)' = u'v + uv'$ und Anwendung des Hauptsatzes der Differential- und Integralrechnung.
