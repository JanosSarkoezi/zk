---
key: stetigkeit_epsilon_delta_definition
title: Epsilon-Delta-Definition der Stetigkeit
type: def
tags: [analysis, stetigkeit]
refs: [stetigkeit_folgen_definition]
---
Eine Funktion $f: X \to \mathbb{R}$ ist genau dann stetig in $\xi \in X$, wenn zu jedem $\epsilon > 0$ ein $\delta > 0$ existiert, so dass für alle $x \in X$ gilt:
$$|x - \xi| < \delta \implies |f(x) - f(\xi)| < \epsilon$$

--proof--
Heuser (Satz 34.6) beweist die Äquivalenz zur Folgendefinition.
\begin{enumerate}[label=\arabic*.]
    \item ($\delta \implies$ Folge): Sei die $\epsilon$-$\delta$-Bedingung erfüllt und $x_n \to \xi$. Zu $\epsilon > 0$ wähle $\delta > 0$. Da $x_n \to \xi$, gibt es ein $n_0$ mit $|x_n - \xi| < \delta$ für $n > n_0$. Dann ist $|f(x_n) - f(\xi)| < \epsilon$, also $f(x_n) \to f(\xi)$.
    \item (Folge $\implies \delta$): Per Widerspruchsbeweis. Wäre die Bedingung falsch, gäbe es ein $\epsilon > 0$, so dass für jedes $\delta = 1/n$ ein $x_n$ existiert mit $|x_n - \xi| < 1/n$ aber $|f(x_n) - f(\xi)| \ge \epsilon$. Dann $x_n \to \xi$, aber $f(x_n) \not\to f(\xi)$, im Widerspruch zur Folgenstetigkeit.
\end{enumerate}
