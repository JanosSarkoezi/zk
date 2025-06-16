---
key: supremum_infimum
title: Supremum und Infimum
type: def
tags: [analysis, mengen, ordnung]
refs: [ordnungsaxiome, schnittaxiom]
---
Sei $M \subseteq \mathbb{R}$ eine nichtleere Teilmenge.

\begin{enumerate}[label=\arabic*.]
    \item Ein Element $s \in \mathbb{R}$ heißt **Supremum** (kleinste obere Schranke) von $M$, geschrieben $s = \sup M$, falls:
    \begin{itemize}
        \item $x \le s$ für alle $x \in M$ ($s$ ist obere Schranke).
        \item Für jedes $\epsilon > 0$ existiert ein $x \in M$ mit $x > s - \epsilon$ ($s$ ist die kleinste obere Schranke).
    \end{itemize}

    \item Ein Element $i \in \mathbb{R}$ heißt **Infimum** (größte untere Schranke) von $M$, geschrieben $i = \inf M$, falls:
    \begin{itemize}
        \item $x \ge i$ für alle $x \in M$ ($i$ ist untere Schranke).
        \item Für jedes $\epsilon > 0$ existiert ein $x \in M$ mit $x < i + \epsilon$ ($i$ ist die größte untere Schranke).
    \end{itemize}
\end{enumerate}

--proof--
Die Existenz des Supremums für jede nach oben beschränkte, nichtleere Teilmenge von $\mathbb{R}$ ist durch das **Schnittaxiom** (Vollständigkeitsaxiom) garantiert. Besitzt $M$ zudem ein Maximum, so gilt $\max M = \sup M$.
