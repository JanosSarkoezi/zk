---
key: grenzwert_funktion_definition
title: Grenzwert einer Funktion (an einer Stelle)
type: def
tags: [analysis, grenzwert]
refs: [stetigkeit_folgen_definition, grenzwert_definition]
---
Man sagt, $f: X \to \mathbb{R}$ habe an der Stelle $\xi$ (die ein Häufungspunkt von $X$ sein muss) den **Grenzwert** $\eta$, wenn für jede Folge $(x_n)$ aus $X \setminus \{\xi\}$ mit $x_n \to \xi$ gilt:
$$\lim_{n \to \infty} f(x_n) = \eta$$
Schreibweise: $\lim_{x \to \xi} f(x) = \eta$.

--proof--
Heuser (Nr. 38) betont den Unterschied zur Stetigkeit: Bei der Grenzwertbetrachtung wird die Stelle $\xi$ selbst explizit ausgeschlossen ($x_n \neq \xi$). Eine Funktion $f$ ist genau dann in $\xi$ stetig, wenn $\lim_{x \to \xi} f(x)$ existiert und gleich $f(\xi)$ ist.
