---
key: gliedweise_differentiation
title: Satz über die gliedweise Differentiation
type: satz
tags: [analysis, ableitung, konvergenz]
refs: [stetigkeitssatz_funktionenfolgen, mittelwertsatz_differentialrechnung]
---
Sei $(f_n)$ eine Folge auf $[a, b]$ differenzierbarer Funktionen. Wenn
\begin{enumerate}
    \item die abgeleitete Folge $(f'_n)$ auf $[a, b]$ gleichmäßig konvergiert, und
    \item die Folge $(f_n(x_0))$ für mindestens ein $x_0 \in [a, b]$ konvergiert,
\end{enumerate}
dann konvergiert $(f_n)$ auf $[a, b]$ gleichmäßig gegen eine differenzierbare Funktion $f$, und es gilt:
$$f'(x) = \lim_{n \to \infty} f'_n(x)$$

--proof--
Durch Anwendung des Mittelwertsatzes auf $f_n - f_m$ zeigt man, dass $(f_n)$ eine Cauchy-Folge bzgl. der Supremumsnorm ist, also gleichmäßig konvergiert. Die Differenzierbarkeit von $f$ und die Gleichheit der Ableitung folgen durch Betrachtung der Differenzenquotienten und Vertauschung der Grenzwerte (Netz-Konvergenz).
