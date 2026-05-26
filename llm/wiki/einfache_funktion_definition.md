---
key: einfache_funktion_definition
title: Einfache Funktion (Treppenfunktion)
type: def
tags: [maßtheorie, messbare_funktionen]
refs: [messbarer_raum_definition, numerische_funktion_definition]
---
Sei $(\Omega, \mathcal{F})$ ein Messraum. Eine numerische Funktion $f: \Omega \to \bar{\mathbb{R}}$ heißt eine einfache Funktion (oder Treppenfunktion), wenn sie nur endlich viele Werte annimmt. Jede einfache Funktion $f$ besitzt eine Darstellung der Form
$$
f = \sum_{i=1}^n c_i \chi_{A_i}
$$
mit $n \in \mathbb{N}$, $c_1, \dots, c_n \in \mathbb{R}$ und messbaren Mengen $A_1, \dots, A_n \in \mathcal{F}$.
Die Standarddarstellung ist gegeben durch $f = \sum_{a \in f(\Omega)} a \chi_{\{f=a\}}$, wobei die Mengen $\{f=a\}$ disjunkt sind.

--proof--
Eine einfache Funktion ist genau dann messbar, wenn die Mengen $\{f=a\}$ für alle $a \in f(\Omega)$ messbar sind. In diesem Wiki betrachten wir einfache Funktionen im Kontext messbarer Räume meist als messbar.
