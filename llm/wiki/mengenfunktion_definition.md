---
key: mengenfunktion_definition
title: Definition einer Mengenfunktion
type: def
tags: [masstheorie, grundlagen]
refs: [sigma_algebra_definition]
---
Sei $\Omega$ eine nichtleere Menge und $\mathcal{C} \subseteq 2^\Omega$ ein Mengensystem mit $\emptyset \in \mathcal{C}$. Eine Abbildung
$$\mu: \mathcal{C} \to [0, \infty] \quad \text{oder} \quad \mu: \mathcal{C} \to [-\infty, \infty]$$
wird als **Mengenfunktion** bezeichnet.

Für eine Mengenfunktion $\mu: \mathcal{C} \to [0, \infty]$ und ein nichtleeres Mengensystem $\mathcal{D} \subseteq \mathcal{C}$ bezeichnen wir die Abbildung $\mu|_\mathcal{D}: \mathcal{D} \to [0, \infty]$ mit
$$\mu|_\mathcal{D}[D] := \mu[D]$$
als **Restriktion** von $\mu$ auf $\mathcal{D}$.

Für Mengenfunktionen $\mu, \nu: \mathcal{C} \to [0, \infty]$ und $\alpha \in \mathbb{R}_+$ sind Summe und skalares Vielfaches punktweise definiert:
- $(\mu + \nu)[C] := \mu[C] + \nu[C]$
- $(\alpha\mu)[C] := \alpha\mu[C]$

Ferner schreiben wir $\mu \le \nu$, wenn für alle $C \in \mathcal{C}$ gilt: $\mu[C] \le \nu[C]$.

--proof--
Diese Definitionen folgen der Standard-Notation für Funktionen auf Mengensystemen. Die Wertebereiche $[0, \infty]$ und $[-\infty, \infty]$ erlauben den Umgang mit unendlichen Maßen, was in der Maßtheorie essenziell ist.
