---
key: jordan_zerlegung_satz
title: Satz von der Jordan-Zerlegung
type: satz
tags: [masstheorie, signiertes_mass]
refs: [sigma_algebra_definition, signiertes_mass_definition]
---
Sei $\mathcal{C}$ eine $\sigma$-Algebra und $\nu: \mathcal{C} \to \bar{\mathbb{R}}$ ein signiertes Maß. Dann existieren zwei Maße $\nu^+$ und $\nu^-$, von denen mindestens eines endlich ist, sodass:
$$\nu = \nu^+ - \nu^-$$
Die Maße $\nu^+$ und $\nu^-$ werden als **Positivteil** (positive Variation) bzw. **Negativteil** (negative Variation) von $\nu$ bezeichnet. Sie sind definiert durch:
$$\nu^+[A] := \sup_{B \in \mathcal{C}, B \subseteq A} \nu[B], \quad \nu^-[A] := \sup_{B \in \mathcal{C}, B \subseteq A} (-\nu[B])$$

--proof--
Man zeigt in mehreren Schritten:
1. $\nu^+$ und $\nu^-$ sind tatsächlich Maße auf $\mathcal{C}$. Insbesondere wird die $\sigma$-Additivität durch Variation über disjunkte Zerlegungen nachgewiesen.
2. Da $\nu$ höchstens einen der Werte $\pm\infty$ annimmt, ist zwingend $\nu^+(\Omega) < \infty$ oder $\nu^-(\Omega) < \infty$.
3. Die Identität $\nu = \nu^+ - \nu^-$ folgt aus der Definition der Suprema.
--proof--
