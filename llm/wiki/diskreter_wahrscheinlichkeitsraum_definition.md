---
key: diskreter_wahrscheinlichkeitsraum_definition
title: Diskreter Wahrscheinlichkeitsraum
type: def
tags: [wahrscheinlichkeitstheorie]
refs: [wahrscheinlichkeitsraum_definition]
---
Ein Wahrscheinlichkeitsraum $(\Omega, \mathcal{F}, P)$ heißt **diskret**, wenn $\Omega$ eine höchstens abzählbare Menge ist und $\mathcal{F} = 2^\Omega$ gilt.
In diesem Fall ist $P$ durch eine **Wahrscheinlichkeitsfunktion** $p: \Omega \to [0, 1]$ mit $\sum_{\omega \in \Omega} p(\omega) = 1$ eindeutig bestimmt, wobei
$$
P(A) = \sum_{\omega \in A} p(\omega)
$$

--proof--
Die $\sigma$-Additivität folgt direkt aus der absoluten Konvergenz der Summe über $p(\omega)$. Da $\sum_\Omega p(\omega) = 1$ und $p(\omega) \ge 0$, ist $P$ ein Wahrscheinlichkeitsmaß auf $2^\Omega$.
