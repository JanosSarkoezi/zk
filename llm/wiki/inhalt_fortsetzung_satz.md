---
key: inhalt_fortsetzung_satz
title: Fortsetzungssatz für Inhalte
type: satz
tags: [masstheorie, halbring, ring]
refs: [halbring_definition, ring_erzeugter_halbring_satz, inhalt_definition]
---
Sei $\mathcal{C}$ ein Halbring. Dann besitzt jeder Inhalt $\mu: \mathcal{C} \to [0, \infty]$ eine eindeutige Fortsetzung zu einem Inhalt $\bar{\mu}: \rho(\mathcal{C}) \to [0, \infty]$, wobei $\rho(\mathcal{C})$ der von $\mathcal{C}$ [[ring_erzeugter_halbring_satz|erzeugte Ring]] ist.

--proof--
Nach dem Satz über den erzeugten [[ring_erzeugter_halbring_satz|Ring]] [[halbring_definition|eines Halbrings]] gilt:
$$\rho(\mathcal{C}) = \left\{ A \in 2^\Omega \mid A = \sum_{i \in I} H_i \text{ mit } I \text{ endlich und } \{H_i\}_{i \in I} \subseteq \mathcal{C} \text{ disjunkt} \right\}$$

Für eine Fortsetzung $\bar{\mu}$ muss gelten: $\bar{\mu}[A] = \sum_{i \in I} \mu[H_i]$.

\begin{enumerate}[label=(\arabic*)]
    \item **Wohldefiniertheit**: Man zeigt, dass die Summe $\sum \mu[H_i]$ unabhängig von der
          gewählten Zerlegung von $A$ in disjunkte Halbring-Elemente ist. Dies folgt aus der
          Additivität von $\mu$ auf dem Halbring (durch Betrachtung der gemeinsamen Verfeinerung
          zweier Zerlegungen).
    \item **Inhaltseigenschaft**: Es ist leicht zu prüfen, dass $\bar{\mu}[\emptyset] = 0$ und
          $\bar{\mu}$ additiv auf $\rho(\mathcal{C})$ ist. Da $\rho(\mathcal{C})$ ein
          [[ring_erzeugter_halbring_satz|Ring]] ist, folgt aus der Additivität bereits die endliche Additivität.
    \item **Eindeutigkeit**: Da jedes Element von $\rho(\mathcal{C})$ eine endliche disjunkte
          Vereinigung von Elementen aus $\mathcal{C}$ ist, ist der Wert von $\bar{\mu}$ durch
          die Werte auf $\mathcal{C}$ zwingend festgelegt.
\end{enumerate}
--proof--
