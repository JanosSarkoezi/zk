---
key: ableitungsregeln_arithmetik
title: Arithmetische Ableitungsregeln
type: satz
tags: [analysis, ableitung]
refs: [ableitung_definition]
---
Sind $f$ und $g$ an der Stelle $\xi$ differenzierbar, so gilt:
\begin{enumerate}[label=\arabic*.]
    \item **Summenregel**: $(f \pm g)'(\xi) = f'(\xi) \pm g'(\xi)$
    \item **Faktorregel**: $(c \cdot f)'(\xi) = c \cdot f'(\xi)$ für $c \in \mathbb{R}$
    \item **Produktregel**: $(f \cdot g)'(\xi) = f'(\xi)g(\xi) + f(\xi)g'(\xi)$
    \item **Quotientenregel**: $(f/g)'(\xi) = \frac{f'(\xi)g(\xi) - f(\xi)g'(\xi)}{g(\xi)^2}$ (falls $g(\xi) \neq 0$)
\end{enumerate}

--proof--
Heuser (Satz 47.1): Der Beweis nutzt die Grenzwertsätze für Funktionen. Bei der Produktregel verwendet man den Trick einer "nahrhaften Null":
$$\frac{f(x)g(x) - f(\xi)g(\xi)}{x - \xi} = \frac{f(x)-f(\xi)}{x-\xi}g(x) + f(\xi)\frac{g(x)-g(\xi)}{x-\xi}$$
Im Grenzübergang $x \to \xi$ liefert dies $f'(\xi)g(\xi) + f(\xi)g'(\xi)$. Die Quotientenregel folgt analog oder durch Anwendung der Produktregel auf $f \cdot (1/g)$.
