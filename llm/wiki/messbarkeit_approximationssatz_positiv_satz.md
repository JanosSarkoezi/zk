---
key: messbarkeit_approximationssatz_positiv_satz
title: Approximationssatz für positive messbare Funktionen
type: satz
tags: [maßtheorie]
refs: [einfache_funktion_definition, messbarkeit_numerische_funktion_charakterisierung_satz]
---
Sei $f: \Omega \to [0, \infty]$ eine numerische Funktion. Dann sind folgende Aussagen äquivalent:

\begin{enumerate}[label=(\arabic*)]
    \item $f$ ist messbar.
    \item Es gibt eine monoton wachsende Folge $\{f_n\}_{n \in \mathbb{N}}$ von nichtnegativen einfachen Funktionen, die punktweise gegen $f$ konvergiert ($f_n \uparrow f$).
\end{enumerate}

--proof--
"2 $\Rightarrow$ 1": Jede einfache Funktion ist messbar, und das punktweise Supremum einer Folge messbarer Funktionen ist nach dem [[messbarkeit_funktionenfolgen_satz|Satz über die Messbarkeit von Limites]] ebenfalls messbar.
"1 $\Rightarrow$ 2": Man konstruiert die Folge explizit durch:
$f_n(\omega) = \sum_{k=1}^{n 2^n} \frac{k-1}{2^n} \chi_{\{ \frac{k-1}{2^n} \le f < \frac{k}{2^n} \}}(\omega) + n \chi_{\{f \ge n\}}(\omega)$.
Diese Funktionen sind einfach, messbar (da $f$ messbar ist) und wachsen monoton gegen $f$.
--proof--
