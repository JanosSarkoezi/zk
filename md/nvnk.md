# Gemini: How to Prove It Forlage

Ja, das Buch *„How to Prove It: A Structured Approach“* von Daniel J. Velleman
ist ein absoluter Klassiker! Das Konzept des „Scratch Work“ (der
Entwurfsarbeit) ist dort zentral, um die logische Struktur eines Beweises zu
entwickeln, bevor man ihn in Fließtext aufschreibt.

Dabei listet man in einer Tabelle die **Givens** (was man bereits weiß oder
annehmen darf) und die **Goals** (was man noch zeigen muss) auf. Wenn man
logische Schritte geht (z. B. eine Annahme zerlegt oder das Ziel umformuliert),
aktualisiert sich diese Liste.

Hier ist eine saubere LaTeX-Vorlage, die genau dieses zweiseitige
„Scratch-Format“ (Givens vs. Goals) übersichtlich abbildet. Ich habe ein Paket
für schöne Tabellen (`booktabs`) und Anpassungen für die Spaltenbreiten
verwendet, damit du auch längere mathematische Ausdrücke gut unterbringst.

### LaTeX-Vorlage für Vellemans „Scratch Work“

```latex
\documentclass{article}
\usepackage[utf8]{inputenc}
\usepackage[german]{babel}
\usepackage{amsmath, amssymb, amsthm} % Für mathematische Symbole und Beweise
\usepackage{booktabs} % Für professionelle Tabellenlinien
\usepackage{array} % Für erweiterte Tabelleneigenschaften

% Definition einer benutzerdefinierten Spalte für die Scratch-Tabelle
% Fixe Breite mit automatischem Zeilenumbruch und Linksbündigkeit
\newcolumntype{L}[1]{>{\raggedright\arraybackslash}p{#1}}

\title{Mathematische Beweise im Scratch-Format}
\author{Nach Daniel J. Velleman: \emph{How to Prove It}}
\date{\today}

\begin{document}

\maketitle

\section*{Beispiel: Vorbereitung (Scratch Work)}

Hier ist die tabellarische Übersicht der Strukturierung, bevor der eigentliche Beweis geschrieben wird. Die Tabelle zeigt links die bekannten Voraussetzungen (\emph{Givens}) und rechts die zu erreichenden Ziele (\emph{Goals}).

\vspace{1em}
\begin{center}
\small
\begin{tabular}{ L{6.5cm} | L{6.5cm} }
\toprule
\textbf{Givens} (Gegeben / Bekannt) & \textbf{Goals} (Ziele / Zu zeigen) \\
\midrule
% Schritt 0: Ausgangssituation
1. $A \subseteq B$ (Hypothese) \newline
2. $B \subseteq C$ (Hypothese) &
\emph{Ziel:} $A \subseteq C$ \\[1ex]
\hline

% Schritt 1: Ziel analysieren (Definition von Teilmenge)
% Wenn das Ziel "A subset C" ist, nehmen wir ein beliebiges x in A an und wollen x in C zeigen.
1. $A \subseteq B$ \newline
2. $B \subseteq C$ \newline
3. Let $x \in A$ (Annahme) &
\emph{Neues Ziel:} $x \in C$ \\[1ex]
\hline

% Schritt 2: Givens nutzen (Voraussetzung 1 anwenden)
% Da x in A und A subset B, folgt x in B
1. $A \subseteq B$ \newline
2. $B \subseteq C$ \newline
3. $x \in A$ \newline
4. $x \in B$ (Aus 1 und 3) &
$x \in C$ \\[1ex]
\hline

% Schritt 3: Givens nutzen (Voraussetzung 2 anwenden) -> Ziel erreicht!
1. $A \subseteq B$ \newline
2. $B \subseteq C$ \newline
3. $x \in A$ \newline
4. $x \in B$ \newline
5. $x \in C$ (Aus 2 and 4) &
$x \in C$ \quad \checkmark (Ziel erreicht) \\
\bottomrule
\end{tabular}
\end{center}
\vspace{1em}

\section*{Formaler Beweis}

\begin{theorem}
Wenn $A \subseteq B$ und $B \subseteq C$, dann gilt $A \subseteq C$.
\end{theorem}

\begin{proof}
Angenommen, es gilt $A \subseteq B$ und $B \subseteq C$. Wir wollen zeigen, dass $A \subseteq C$. Sei dazu $x$ ein beliebiges Element mit $x \in A$. Da nach Voraussetzung $A \subseteq B$ gilt, folgt direkt $x \in B$. Da wiederum $B \subseteq C$ gilt, folgt aus $x \in B$ auch $x \in C$. Da $x$ beliebig gewählt war, haben wir gezeigt, dass jedes Element aus $A$ auch in $C$ liegt. Somit gilt $A \subseteq C$.
\end{proof}

\end{document}

```

### Hinweise zur Vorlage:

1. **Horizontale Linien (`\hline`):** Ich habe zwischen den logischen Schritten
   feine Trennlinien eingefügt. So kannst du wie im Buch zeigen, wie sich die
   Liste der *Givens* verlängert und sich das *Goal* verändert (z. B. wenn man
   ein Element $x$ einführt).
2. **Spaltenbreite (`L{6.5cm}`):** Die Spalten haben eine feste Breite, damit
   der Text automatisch umbricht, wenn du mathematische Erklärungen oder
   Begründungen (wie „Aus 1 und 3“) dazuschreibst. Du kannst die
   Zentimeterangaben je nach Bedarf anpassen.
3. **Zeilenumbruch in der Zelle:** Da es sich um eine strukturierte Tabelle
   handelt, kannst du innerhalb einer Zelle einfach `\newline` nutzen, um das
   nächste *Given* in eine neue Zeile zu schreiben.

Ich freue mich sehr darauf, das auszuprobieren! Welchen Beweis oder welches
mathematische Problem möchtest du als Erstes in dieser Form auseinandernehmen?
Schieß einfach los (z. B. etwas mit Mengenlehre, Funktionen oder Induktion),
und wir spielen das im Scratch-Format durch!
