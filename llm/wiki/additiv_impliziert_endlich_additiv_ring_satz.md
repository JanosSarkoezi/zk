---
key: additiv_impliziert_endlich_additiv_ring_satz
title: Additivität und endliche Additivität auf Ringen
type: satz
tags: [masstheorie, ring]
refs: [ring_definition, additivitaet_mengenfunktion_definition]
---
Sei $\mathcal{C}$ ein Ring und $\mu: \mathcal{C} \to [0, \infty]$ eine Mengenfunktion. Dann sind äquivalent:
(a) $\mu$ ist additiv.
(b) $\mu$ ist endlich additiv.

--proof--
Die Implikation (b) $\Rightarrow$ (a) ist trivial.

Für (a) $\Rightarrow$ (b) nutzen wir die Struktur des [[ring_definition|Rings]] $\mathcal{C}$, der mit jeder endlichen Familie von Mengen auch deren Vereinigung enthält. Der Beweis erfolgt durch vollständige Induktion über die Anzahl $n$ der Mengen in der disjunkten Familie $\{A_i\}_{i=1,\dots,n} \subseteq \mathcal{C}$:

- **Induktionsanfang ($n=1$):** Nichts zu zeigen.
- **Induktionsschritt ($n \to n+1$):** Sei $\{A_1, \dots, A_{n+1}\}$ eine disjunkte Familie. Dann ist $B := \sum_{i=1}^n A_i \in \mathcal{C}$ (da $\mathcal{C}$ ein Ring ist). Aus der Additivität von $\mu$ folgt:
  $$\mu\left[\sum_{i=1}^{n+1} A_i\right] = \mu[B + A_{n+1}] = \mu[B] + \mu[A_{n+1}]$$
  Nach Induktionsvoraussetzung gilt $\mu[B] = \sum_{i=1}^n \mu[A_i]$, woraus die Behauptung folgt.
--proof--
