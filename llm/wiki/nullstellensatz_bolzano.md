---
key: nullstellensatz_bolzano
title: Nullstellensatz von Bolzano
type: satz
tags: [analysis, stetigkeit, bolzano]
refs: [stetigkeit_folgen_definition, schnittaxiom]
---
Sei $f: [a, b] \to \mathbb{R}$ eine stetige Funktion. Gilt $f(a) < 0$ und $f(b) > 0$ (oder umgekehrt), so gibt es mindestens ein $\xi \in (a, b)$ mit $f(\xi) = 0$.

--proof--
Der Beweis erfolgt durch Intervallschachtelung (Heuser, Satz 35.5). Man setzt $a_0 = a$ und $b_0 = b$. In jedem Schritt prüft man den Mittelpunkt $m = (a_k + b_k)/2$. Ist $f(m) = 0$, ist man fertig. Andernfalls wählt man das Teilintervall, in dem ein Vorzeichenwechsel stattfindet. Die resultierenden Folgen $(a_k)$ und $(b_k)$ konvergieren gegen eine Zahl $\xi$. Da $f$ stetig ist, muss $f(\xi) = \lim f(a_k) \le 0$ und $f(\xi) = \lim f(b_k) \ge 0$ gelten, also $f(\xi) = 0$.
