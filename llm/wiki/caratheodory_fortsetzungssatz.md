---
key: caratheodory_fortsetzungssatz
title: Fortsetzungssatz von Carathéodory
type: satz
tags: [masstheorie, fortsetzung]
refs: [halbring_definition, aeusseres_mass_definition, messbarkeit_aeusseres_mass_definition, mass_eindeutigkeitssatz]
---
Sei $\mathcal{E}$ ein Halbring auf $\Omega$ und $\mu: \mathcal{E} \to [0, \infty]$ ein $\sigma$-endliches Maß.

Dann existiert genau eine Fortsetzung von $\mu$ zu einem Maß $\bar{\mu}$ auf der erzeugten $\sigma$-Algebra $\sigma(\mathcal{E})$.
Diese Fortsetzung ist ebenfalls $\sigma$-endlich.

--proof--
\begin{enumerate}[label=\arabic*.]
    \item **Existenz**: Man definiert ein äußeres Maß $\mu^*$ durch
          $$\mu^*(A) := \inf \left\{ \sum_{n=1}^\infty \mu(E_n) \mid \{E_n\} \subseteq \mathcal{E}, A \subseteq \bigcup E_n \right\}$$
          Nach dem Satz von Carathéodory ist die Menge $\mathcal{F}(\mu^*)$ der $\mu^*$-messbaren Mengen eine $\sigma$-Algebra und die Einschränkung von $\mu^*$ darauf ein Maß. Da $\sigma(\mathcal{E}) \subseteq \mathcal{F}(\mu^*)$ und $\mu^*(E) = \mu(E)$ für $E \in \mathcal{E}$, ist $\bar{\mu} := \mu^*|_{\sigma(\mathcal{E})}$ die gesuchte Fortsetzung.
    \item **Eindeutigkeit**: Folgt direkt aus dem [[mass_eindeutigkeitssatz|Eindeutigkeitssatz für Maße]], da $\mathcal{E}$ ein $\cap$-stabiles Erzeugersystem ist und $\mu$ darauf $\sigma$-endlich vorausgesetzt wurde.
\end{enumerate}
