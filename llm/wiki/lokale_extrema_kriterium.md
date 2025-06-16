---
key: lokale_extrema_kriterium
title: Kriterien für lokale Extrema
type: satz
tags: [analysis, ableitung, extrema]
refs: [ableitung_definition, mittelwertsatz_differentialrechnung]
---
Sei $f$ in einer Umgebung von $\xi$ zweimal differenzierbar. 
\begin{enumerate}[label=\arabic*.]
    \item **Notwendige Bedingung**: Hat $f$ in einem inneren Punkt $\xi$ ein lokales Extremum, so gilt $f'(\xi) = 0$.
    \item **Hinreichende Bedingung**: Gilt $f'(\xi) = 0$ und $f''(\xi) < 0$, so hat $f$ in $\xi$ ein isoliertes lokales Maximum. Gilt $f'(\xi) = 0$ und $f''(\xi) > 0$, so liegt ein isoliertes lokales Minimum vor.
\end{enumerate}

--proof--
Heuser (Satz 49.6): Die notwendige Bedingung folgt aus dem Differenzenquotienten. Für die hinreichende Bedingung nutzt man die Taylor-Approximation oder betrachtet das Vorzeichen von $f'$ in einer Umgebung von $\xi$. Ist $f''(\xi) > 0$, so ist $f'$ in einer Umgebung streng wachsend. Da $f'(\xi) = 0$, muss $f'(x) < 0$ für $x < \xi$ und $f'(x) > 0$ für $x > \xi$ gelten, was einem Minimum entspricht.
