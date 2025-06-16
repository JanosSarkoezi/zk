---
key: nullfolgenkriterium_reihe
title: Notwendige Konvergenzbedingung für Reihen
type: satz
tags: [analysis, reihen, konvergenz]
refs: [reihe_definition, grenzwert_definition]
---
Ist die Reihe $\sum_{n=0}^\infty a_n$ konvergent, so bilden die Reihenglieder $(a_n)$ eine Nullfolge, d.h.
$\lim_{n \to \infty} a_n = 0$.

--proof--
Sei $s = \lim_{n \to \infty} s_n$ der Grenzwert der Partialsummen. Da $a_n = s_n - s_{n-1}$ für $n \ge 1$ gilt, folgt mit den Grenzwertsätzen für Folgen:
$\lim_{n \to \infty} a_n = \lim_{n \to \infty} (s_n - s_{n-1}) = \lim_{n \to \infty} s_n - \lim_{n \to \infty} s_{n-1} = s - s = 0$.
Dies beweist, dass $a_n$ gegen 0 strebt. Die Umkehrung gilt nicht (Gegenbeispiel: harmonische Reihe).
