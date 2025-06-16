---
key: grenzwertsaetze_arithmetik
title: Arithmetische Grenzwertsätze
type: satz
tags: [analysis, folgen, grenzwert]
refs: [grenzwert_definition]
---
Seien $(a_n)$ und $(b_n)$ konvergente Folgen mit $\lim_{n \to \infty} a_n = a$ und $\lim_{n \to \infty} b_n = b$. Dann gilt:
\begin{enumerate}[label=\arabic*.]
    \item $\lim_{n \to \infty} (a_n \pm b_n) = a \pm b$
    \item $\lim_{n \to \infty} (a_n \cdot b_n) = a \cdot b$
    \item $\lim_{n \to \infty} (\alpha a_n) = \alpha a$ für jedes $\alpha \in \mathbb{R}$
    \item Falls $b \neq 0$ und $b_n \neq 0$ für fast alle $n$, dann gilt $\lim_{n \to \infty} \frac{a_n}{b_n} = \frac{a}{b}$.
\end{enumerate}

--proof--
\begin{enumerate}[label=\arabic*.]
    \item **Summe**: Zu $\epsilon > 0$ wähle $n_1, n_2$, so dass $|a_n - a| < \epsilon/2$ für $n > n_1$ und $|b_n - b| < \epsilon/2$ für $n > n_2$. Für $n > \max(n_1, n_2)$ gilt:
    $|(a_n + b_n) - (a + b)| \le |a_n - a| + |b_n - b| < \epsilon/2 + \epsilon/2 = \epsilon$.

    \item **Produkt**: Es gilt $a_n b_n - ab = a_n(b_n - b) + b(a_n - a)$. Da $(a_n)$ konvergent ist, ist sie beschränkt ($|a_n| \le K$). 
    $|a_n b_n - ab| \le |a_n||b_n - b| + |b||a_n - a| \le K|b_n - b| + |b||a_n - a|$.
    Wähle $n_0$, so dass $|b_n - b| < \frac{\epsilon}{2K}$ und $|a_n - a| < \frac{\epsilon}{2|b|+1}$ für $n > n_0$. Dann folgt $|a_n b_n - ab| < \epsilon$.

    \item **Quotient**: Es genügt zu zeigen, dass $1/b_n \to 1/b$.
    $|\frac{1}{b_n} - \frac{1}{b}| = \frac{|b - b_n|}{|b_n b|}$.
    Da $b_n \to b \neq 0$, gibt es ein $n_1$, so dass $|b_n| > |b|/2$ für $n > n_1$. Dann ist:
    $\frac{|b - b_n|}{|b_n b|} < \frac{|b - b_n|}{|b|^2/2}$.
    Wähle $n_2$, so dass $|b - b_n| < \epsilon \cdot |b|^2/2$. Dann folgt die Behauptung für $n > \max(n_1, n_2)$.
    Das Produktgesetz liefert dann $\lim \frac{a_n}{b_n} = \lim a_n \cdot \lim \frac{1}{b_n} = a \cdot \frac{1}{b}$.
\end{enumerate}
