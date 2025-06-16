---
key: limes_superior_inferior_definition
title: Definition des Limes superior und Limes inferior
type: def
tags: [analysis, folgen, konvergenz]
refs: [bolzano_weierstrass, grenzwert_definition]
---
Jede beschränkte Folge $(a_n)$ reeller Zahlen besitzt einen größten und einen kleinsten Häufungswert.

\begin{enumerate}
    \item Der größte Häufungswert von $(a_n)$ heißt **Limes superior** und wird mit $\limsup_{n \to \infty} a_n$ bezeichnet.
    \item Der kleinste Häufungswert von $(a_n)$ heißt **Limes inferior** und wird mit $\liminf_{n \to \infty} a_n$ bezeichnet.
\end{enumerate}

Eine Zahl $a$ ist genau dann der Limes inferior einer beschränkten Folge $(a_n)$, wenn für jedes $\epsilon > 0$ gilt:
\begin{itemize}
    \item $a_n < a + \epsilon$ für unendlich viele $n$,
    \item $a_n < a - \epsilon$ für höchstens endlich viele $n$.
\end{itemize}

Entsprechend ist $a'$ der Limes superior, wenn für jedes $\epsilon > 0$ gilt:
\begin{itemize}
    \item $a_n > a' - \epsilon$ für unendlich viele $n$,
    \item $a_n > a' + \epsilon$ für höchstens endlich viele $n$.
\end{itemize}

--proof--
Nach dem Satz von Bolzano-Weierstraß besitzt jede beschränkte Folge mindestens einen Häufungswert. Die Menge $H$ aller Häufungswerte einer beschränkten Folge ist selbst beschränkt und abgeschlossen, besitzt also ein Maximum und ein Minimum. Diese Extremwerte definieren den Limes superior bzw. Limes inferior.
