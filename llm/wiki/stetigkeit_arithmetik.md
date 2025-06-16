---
key: stetigkeit_arithmetik
title: Arithmetische Operationen und Stetigkeit
type: satz
tags: [analysis, stetigkeit]
refs: [stetigkeit_folgen_definition, grenzwertsaetze_arithmetik]
---
Sind die Funktionen $f$ und $g$ an der Stelle $\xi$ stetig, so sind auch die Funktionen
\begin{enumerate}[label=\arabic*.]
    \item $f + g$
    \item $f - g$
    \item $f \cdot g$
    \item $|f|$
    \item $f/g$ (sofern $g(\xi) \neq 0$)
\end{enumerate}
an der Stelle $\xi$ stetig.

--proof--
Der Beweis folgt unmittelbar aus den Grenzwertsätzen für Folgen (Heuser, Satz 22.6). Da für jede Folge $x_n \to \xi$ gilt, dass $f(x_n) \to f(\xi)$ und $g(x_n) \to g(\xi)$, konvergiert auch die Summenfolge $f(x_n) + g(x_n) \to f(\xi) + g(\xi)$, was genau der Definition der Stetigkeit für $f+g$ entspricht. Analog verfährt man für die anderen Operationen.
