---
key: grenzwert_funktion_definition
title: Grenzwert einer Funktion (an einer Stelle)
type: def
tags: [analysis, grenzwert]
refs: [stetigkeit_folgen_definition, grenzwert_definition]
---
Man sagt, $f: X \to \mathbb{R}$ habe an der Stelle $\xi$ (die ein Häufungspunkt von $X$ sein muss) den **[[grenzwert_definition|Grenzwert]]** $\eta$, wenn für jede [[grenzwert_definition|Folge]] $(x_n)$ aus $X \setminus \{\xi\}$ mit $x_n \to \xi$ gilt:
$$\lim_{n \to \infty} f(x_n) = \eta$$
Schreibweise: $\lim_{x \to \xi} f(x) = \eta$.

--examples--
Heuser (Nr. 38) betont den Unterschied zur [[stetigkeit_folgen_definition|Stetigkeit]]: Bei der Grenzwertbetrachtung wird die Stelle $\xi$ selbst explizit ausgeschlossen ($x_n \neq \xi$). Eine Funktion $f$ ist genau dann in $\xi$ [[stetigkeit_folgen_definition|stetig]], wenn $\lim_{x \to \xi} f(x)$ existiert und gleich $f(\xi)$ ist.
