# Verkettung von natuerliche Transformation mit Funktor

## Frage

## Antowrt

Die **Verkettung (oder Komposition) einer natürlichen Transformation mit einem
Funktor** ist ebenfalls ein fundamentales Konzept in der **Kategorientheorie**
– sie beschreibt, wie man natürliche Transformationen „weiterträgt“ entlang
eines Funktors. Es gibt dabei zwei Arten:

---

## 🔁 Horizontale Komposition

### Situation:

Gegeben seien Kategorien $\mathcal{C}, \mathcal{D}, \mathcal{E}$, Funktoren und eine natürliche Transformation:

* Funktoren: $F, G: \mathcal{C} \to \mathcal{D}$
* Natürliche Transformation: $\alpha: F \Rightarrow G$
* Weiterer Funktor: $H: \mathcal{D} \to \mathcal{E}$

Dann definiert man die **horizontale Komposition** $H \circ \alpha$ als eine natürliche Transformation:

$$
H \circ \alpha : H \circ F \Rightarrow H \circ G
$$

### Komponentenweise:

Für jedes Objekt $X \in \mathcal{C}$ ist die Komponente:

$$
(H \circ \alpha)_X = H(\alpha_X)
$$

Das bedeutet: Man wendet einfach $H$ auf jede Komponente $\alpha_X: F(X) \to G(X)$ an.

---

## 🔁 Dual: Vorkomposition mit einem Funktor

Gegeben sei jetzt:

* Funktoren $F, G: \mathcal{D} \to \mathcal{E}$
* Natürliche Transformation $\beta: F \Rightarrow G$
* Funktor $H: \mathcal{C} \to \mathcal{D}$

Dann ergibt sich eine neue natürliche Transformation durch **Vorkomposition**:

$$
\beta \circ H: F \circ H \Rightarrow G \circ H
$$

### Komponentenweise:

Für jedes Objekt $X \in \mathcal{C}$:

$$
(\beta \circ H)_X = \beta_{H(X)}
$$

Man wählt einfach die Komponente der Transformation $\beta$ an der Stelle $H(X)$.

---

## 🔄 Zusammenfassung

| Art der Komposition  | Ergebnis                          | Komponente an $X$ |
| -------------------- | --------------------------------- | ----------------- |
| **$H \circ \alpha$** | $H \circ F \Rightarrow H \circ G$ | $H(\alpha_X)$     |
| **$\beta \circ H$**  | $F \circ H \Rightarrow G \circ H$ | $\beta_{H(X)}$    |

---

## 🧠 Intuition

Die horizontale Komposition „trägt“ eine natürliche Transformation durch einen Funktor **weiter**, während die vertikale Komposition (die du nicht direkt gefragt hast) Transformationen **zwischen** Funktoren derselben Richtung kombiniert. Beides ist Teil der **2-Kategorientheorie**, wo:

* Objekte: Kategorien
* 1-Morphismen: Funktoren
* 2-Morphismen: natürliche Transformationen

Wenn du ein konkretes Beispiel möchtest, kann ich dir gern eines machen – z. B. mit Mengen, Gruppen oder Vektorräumen.
