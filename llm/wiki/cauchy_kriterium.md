---
key: cauchy_kriterium
title: Cauchy-Konvergenzkriterium
type: satz
tags: [analysis, folgen, vollstaendigkeit]
refs: [bolzano_weierstrass, beschraenktheit_konvergenter_folgen]
---
Eine Folge $(a_n)$ reeller Zahlen konvergiert genau dann, wenn sie eine Cauchy-Folge ist. 
Das heißt: Zu jedem $\epsilon > 0$ existiert ein $n_0 \in \mathbb{N}$, so dass für alle $m, n > n_0$ gilt: $|a_n - a_m| < \epsilon$.

--proof--
\begin{enumerate}[label=\arabic*.]
    \item **Notwendigkeit**: Falls $a_n \to a$, dann gilt $|a_n - a_m| \le |a_n - a| + |a - a_m| < \epsilon/2 + \epsilon/2 = \epsilon$ für große $n, m$.

    \item **Hinlänglichkeit**: Sei $(a_n)$ eine Cauchy-Folge. 
    Zunächst ist jede Cauchy-Folge beschränkt. 
    Nach Bolzano-Weierstraß gibt es eine konvergente Teilfolge $a_{n_k} \to a$.
    Wir zeigen nun $a_n \to a$:
    Zu $\epsilon > 0$ wähle $N$, so dass $|a_n - a_m| < \epsilon/2$ für $n, m > N$.
    Wähle $k$, so dass $n_k > N$ und $|a_{n_k} - a| < \epsilon/2$.
    Für $n > N$ gilt dann:
    $|a_n - a| \le |a_n - a_{n_k}| + |a_{n_k} - a| < \epsilon/2 + \epsilon/2 = \epsilon$.
    Somit konvergiert die gesamte Folge gegen $a$.
\end{enumerate}
