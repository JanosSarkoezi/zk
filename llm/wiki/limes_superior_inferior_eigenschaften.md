---
key: limes_superior_inferior_eigenschaften
title: Eigenschaften des Limes superior und Limes inferior
type: satz
tags: [analysis, folgen]
refs: [limes_superior_inferior_definition, grenzwert_definition]
---
Für beschränkte Folgen $(a_n)$ und $(b_n)$ gelten folgende Eigenschaften:

1. **Einschließung**: $\inf \{a_n\} \le \liminf_{n \to \infty} a_n \le \limsup_{n \to \infty} a_n \le \sup \{a_n\}$.
2. **Konvergenzkriterium**: Eine Folge $(a_n)$ konvergiert (oder divergiert bestimmt gegen $\pm\infty$) genau dann, wenn $\liminf_{n \to \infty} a_n = \limsup_{n \to \infty} a_n$. In diesem Fall gilt:
   $$\lim_{n \to \infty} a_n = \liminf_{n \to \infty} a_n = \limsup_{n \to \infty} a_n$$
3. **Subadditivität**: $\limsup_{n \to \infty} (a_n + b_n) \le \limsup_{n \to \infty} a_n + \limsup_{n \to \infty} b_n$.
4. **Teilfolgen**: Für jede konvergente Teilfolge $(a_{n_k})$ von $(a_n)$ gilt:
   $$\liminf_{n \to \infty} a_n \le \lim_{k \to \infty} a_{n_k} \le \limsup_{n \to \infty} a_n$$

--proof--
Die Beweise ergeben sich aus der Definition der Häufungswerte und der Extremaleigenschaft von Limes superior/inferior innerhalb der Menge aller Häufungswerte. Die Gleichheit im Konvergenzfall folgt daraus, dass eine Folge genau dann konvergiert, wenn sie beschränkt ist und nur einen einzigen Häufungswert besitzt.
