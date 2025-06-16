---
key: ableitung_definition
title: Definition der Ableitung
type: def
tags: [analysis, ableitung]
refs: [grenzwert_funktion_definition]
---
Eine Funktion $f: I \to \mathbb{R}$ heißt an einer Stelle $\xi \in I$ **differenzierbar**, wenn der Grenzwert des Differenzenquotienten
$$f'(\xi) = \lim_{x \to \xi} \frac{f(x) - f(\xi)}{x - \xi}$$
oder äquivalent
$$f'(\xi) = \lim_{h \to 0} \frac{f(\xi + h) - f(\xi)}{h}$$
existiert und endlich ist. Der Wert $f'(\xi)$ heißt die **Ableitung** von $f$ an der Stelle $\xi$.

--proof--
Heuser (Nr. 46) führt die Ableitung als Maß für die lokale Änderungsrate ein. Geometrisch entspricht $f'(\xi)$ der Steigung der Tangente an den Graphen von $f$ im Punkt $(\xi, f(\xi))$. Ist $f$ in jedem Punkt eines Intervalls $I$ differenzierbar, so erhält man die Ableitungsfunktion $f': I \to \mathbb{R}$.
