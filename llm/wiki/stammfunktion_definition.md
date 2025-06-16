---
key: stammfunktion_definition
title: Definition der Stammfunktion
type: def
tags: [analysis, integral]
refs: [ableitung_definition]
---
Eine Funktion $F$ heißt **Stammfunktion** von $f$ auf einem Intervall $I$, wenn $F$ auf $I$ differenzierbar ist und für alle $x \in I$ gilt:
$$F'(x) = f(x)$$

--proof--
Heuser (Nr. 55): Ist $F_0$ eine Stammfunktion von $f$, so sind alle Funktionen der Form $F(x) = F_0(x) + C$ mit einer Konstanten $C \in \mathbb{R}$ ebenfalls Stammfunktionen von $f$. Dies folgt daraus, dass die Ableitung einer Konstanten null ist und Funktionen mit verschwindender Ableitung auf einem Intervall konstant sind (Folgerung aus dem Mittelwertsatz).
