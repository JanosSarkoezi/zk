---
key: messbarkeit_monotone_funktionen_beispiel
title: Messbarkeit monotoner Funktionen
type: info
tags: [masstheorie, analysis]
refs: [messbarkeit_erzeuger_satz, borelsche_sigma_algebra_definition]
---
Jede monotone Funktion $f: \mathbb{R} \to \mathbb{R}$ ist Borel-messbar.

--proof--
Wir betrachten den Fall einer monoton wachsenden Funktion $f$. Die Borelsche $\sigma$-Algebra $\mathcal{B}(\mathbb{R})$ wird durch das System $\mathcal{E} := \{ (-\infty, c] \mid c \in \mathbb{R} \}$ erzeugt. Da $f$ monoton wachsend ist, ist das Urbild $f^{-1}((-\infty, c])$ entweder leer, ganz $\mathbb{R}$ oder ein Intervall der Form $(-\infty, a)$ oder $(-\infty, a]$. Alle diese Mengen sind Borel-Mengen (da sie offen oder abgeschlossen sind). Somit gilt $f^{-1}(\mathcal{E}) \subseteq \mathcal{B}(\mathbb{R})$. Nach dem Satz über Messbarkeit und Erzeuger folgt die Messbarkeit von $f$.
Der Fall einer monoton fallenden Funktion lässt sich durch Komposition mit $g(x) = -x$ auf den monoton wachsenden Fall zurückführen.
