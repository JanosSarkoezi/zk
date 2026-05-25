---
key: messbarkeit_numerische_funktion_charakterisierung_satz
title: Charakterisierung der Messbarkeit numerischer Funktionen
type: satz
tags: [maßtheorie]
refs: [messbarer_raum_definition, numerische_funktion_definition]
---
Sei $(\Omega, \mathcal{F})$ ein Messraum und $f: \Omega \to \bar{\mathbb{R}}$ eine numerische Funktion. Folgende Aussagen sind äquivalent:

\begin{enumerate}[label=(\arabic*)]
    \item $f$ ist $(\mathcal{F}, \mathcal{B}(\bar{\mathbb{R}}))$-messbar.
    \item $\{f \le a\} = \{ \omega \in \Omega \mid f(\omega) \le a \} \in \mathcal{F}$ für alle $a \in \mathbb{R}$.
    \item $\{f < a\} \in \mathcal{F}$ für alle $a \in \mathbb{R}$.
    \item $\{f \ge a\} \in \mathcal{F}$ für alle $a \in \mathbb{R}$.
    \item $\{f > a\} \in \mathcal{F}$ für alle $a \in \mathbb{R}$.
\end{enumerate}

--proof--
Da die Intervalle $(-\infty, a]$ für $a \in \mathbb{R}$ zusammen mit den Mengen $\{-\infty\}$ und $\{\infty\}$ die Borelsche $\sigma$-Algebra $\mathcal{B}(\bar{\mathbb{R}})$ erzeugen, folgt die Messbarkeit bereits aus der Messbarkeit der Urbilder eines solchen Erzeugersystems. Die Äquivalenz der verschiedenen Intervalltypen folgt aus den Eigenschaften einer $\sigma$-Algebra (Komplementbildung, abzählbare Vereinigungen/Durchschnitte), z.B. $\{f < a\} = \bigcup_{n=1}^\infty \{f \le a - 1/n\}$.
--proof--
