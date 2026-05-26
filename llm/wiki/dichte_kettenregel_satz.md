---
key: dichte_kettenregel_satz
title: Kettenregel (Integration bezüglich eines Maßes mit Dichte)
type: satz
tags: [integration, masstheorie]
refs: [mass_mit_dichte_definition]
---
Sei $\nu = f \mu$ ein Maß mit $\mu$-Dichte $f$. Für jede messbare Funktion $h: \Omega \to \bar{\mathbb{R}}$ gilt:

\begin{enumerate}[label=(\arabic*)]
    \item Ist $h \ge 0$, so gilt $\int_\Omega h \, d\nu = \int_\Omega h f \, d\mu$.
    \item $h$ ist genau dann $\nu$-integrierbar, wenn $hf$ $\mu$-integrierbar ist. In diesem Fall gilt ebenfalls $\int_\Omega h \, d\nu = \int_\Omega h f \, d\mu$.
\end{enumerate}

--proof--
Der Beweis erfolgt durch algebraische Induktion:
\begin{enumerate}[label=(\arabic*)]
    \item Für Indikatorfunktionen $h = \chi_A$ gilt die Behauptung nach Definition von $\nu$.
    \item Durch Linearität folgt sie für einfache Funktionen.
    \item Durch den Satz von der monotonen Konvergenz folgt sie für positive messbare Funktionen.
    \item Durch Zerlegung $h = h^+ - h^-$ folgt sie für integrierbare Funktionen.
\end{enumerate}
