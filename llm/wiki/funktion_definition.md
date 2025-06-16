---
key: funktion_definition
title: Definition einer Funktion (Abbildung)
type: def
tags: [analysis, mengen, funktionen]
refs: []
---
Seien $X$ und $Y$ zwei nichtleere Mengen. Eine **Funktion** (oder Abbildung) $f$ von $X$ nach $Y$ ist eine Vorschrift, die jedem Element $x \in X$ in eindeutiger Weise genau ein Element $y \in Y$ zuordnet.
Man schreibt:
$f: X \to Y, x \mapsto f(x)$.
Dabei heißt $X$ die **Definitionsmenge** und $Y$ die **Zielmenge**.

Für eine Teilmenge $A \subseteq X$ heißt $f(A) = \{ f(x) \mid x \in A \}$ das **Bild** von $A$.
Für eine Teilmenge $B \subseteq Y$ heißt $f^{-1}(B) = \{ x \in X \mid f(x) \in B \}$ das **Urbild** von $B$.

--proof--
(Definition erfordert keinen Beweis.)
Eine Funktion ist formal als Teilmenge des kartesischen Produkts $X \times Y$ definiert (der Graph von $f$), wobei für jedes $x \in X$ genau ein Paar $(x, y)$ in der Menge existiert.
