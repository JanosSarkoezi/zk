# Verkettung von Funktoren

## Frage

Was ist die Verkettung von zwie Funktoren?

## Antwort

Die **Verkettung (Komposition) von zwei Funktoren** ist ein grundlegendes
Konzept in der **Kategorientheorie**. Es beschreibt, wie man zwei Funktoren
„nacheinander“ anwenden kann, ähnlich wie bei der Verkettung (Komposition) von
Funktionen.

### Definition

Gegeben seien zwei Funktoren:

* $F: \mathcal{C} \to \mathcal{D}$
* $G: \mathcal{D} \to \mathcal{E}$

Dann ist die **Verkettung** (oder Komposition) der Funktoren $G \circ F$ ein Funktor

$$
G \circ F: \mathcal{C} \to \mathcal{E}
$$

definiert durch:

* **Auf Objekten:** $(G \circ F)(X) = G(F(X))$ für jedes Objekt $X \in \mathcal{C}$
* **Auf Morphismen:** $(G \circ F)(f) = G(F(f))$ für jeden Morphismus $f: X \to Y$ in $\mathcal{C}$

### Eigenschaften

* Die Verkettung $G \circ F$ ist wieder ein **Funktor**.
* Funktoren können **assoziativ** verkettet werden:

  $$
  H \circ (G \circ F) = (H \circ G) \circ F
  $$
* Es gibt einen **Identitätsfunktor** $\text{id}_\mathcal{C}: \mathcal{C} \to \mathcal{C}$, der mit jedem Funktor $F: \mathcal{C} \to \mathcal{D}$ die Eigenschaft hat:

  $$
  F \circ \text{id}_\mathcal{C} = F = \text{id}_\mathcal{D} \circ F
  $$

### Beispiel

Seien:

* $F: \textbf{Set} \to \textbf{Vect}_\mathbb{R}$, der jedem Set den freien Vektorraum darüber zuordnet.
* $G: \textbf{Vect}_\mathbb{R} \to \textbf{Ab}$, der den zugrundeliegenden abelschen Gruppenfunktor darstellt.

Dann ist $G \circ F: \textbf{Set} \to \textbf{Ab}$ ein Funktor, der jedem Set die abelsche Gruppe des freien Vektorraums darüber zuordnet.

Wenn du willst, kann ich das auch mit Diagrammen oder in konkreter Notation aus einer bestimmten Kategorie (z. B. **Top**, **Grp**, **Ring**) zeigen.


