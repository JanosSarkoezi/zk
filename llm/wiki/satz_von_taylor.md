---
key: satz_von_taylor
title: Satz von Taylor
type: satz
tags: [analysis, ableitung, approximation]
refs: [mittelwertsatz_differentialrechnung, mittelwertsatz_hoehere_differenzen]
---
Die Funktion $f$ besitze auf dem kompakten Intervall $I = \langle x_0, x \rangle$ eine stetige Ableitung $n$-ter Ordnung, während $f^{(n+1)}$ im Innern $\mathring{I}$ existiere. Dann gibt es in $\mathring{I}$ mindestens eine Zahl $\xi$, so dass gilt:
$$f(x) = \sum_{k=0}^n \frac{f^{(k)}(x_0)}{k!}(x-x_0)^k + R_n(x)$$
mit dem **Lagrangeschen Restglied**:
$$R_n(x) = \frac{f^{(n+1)}(\xi)}{(n+1)!}(x-x_0)^{n+1}$$
Das Polynom $T_n(x) = \sum_{k=0}^n \frac{f^{(k)}(x_0)}{k!}(x-x_0)^k$ heißt das **$n$-te Taylorpolynom** von $f$ an der Stelle $x_0$.

--proof--
Der Beweis kann durch sukzessive Anwendung des Satzes von Rolle auf eine geschickt gewählte Hilfsfunktion (z.B. $F(t) = f(x) - \sum_{k=0}^n \frac{f^{(k)}(t)}{k!}(x-t)^k - K(x-t)^{n+1}$) geführt werden.
