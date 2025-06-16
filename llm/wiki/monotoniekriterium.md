---
key: monotoniekriterium
title: Monotoniekriterium für Folgen
type: satz
tags: [analysis, folgen, konvergenz]
refs: [schnittaxiom, supremum_infimum]
---
Eine monotone Folge reeller Zahlen konvergiert genau dann, wenn sie beschränkt ist.
Ist $(a_n)$ monoton wachsend und nach oben beschränkt, dann gilt $\lim_{n \to \infty} a_n = \sup \{ a_n \mid n \in \mathbb{N} \}$.
Ist $(a_n)$ monoton fallend und nach unten beschränkt, dann gilt $\lim_{n \to \infty} a_n = \inf \{ a_n \mid n \in \mathbb{N} \}$.

--proof--
Sei $(a_n)$ monoton wachsend und nach oben beschränkt. Die Menge $A = \{ a_n \mid n \in \mathbb{N} \}$ ist nicht leer und nach oben beschränkt. Nach dem Vollständigkeitsaxiom von $\mathbb{R}$ existiert $a = \sup A$.
Für jedes $\epsilon > 0$ gibt es ein $a_{n_0} \in A$, so dass $a - \epsilon < a_{n_0} \le a$.
Da $(a_n)$ monoton wachsend ist, gilt für alle $n > n_0$:
$a - \epsilon < a_{n_0} \le a_n \le a < a + \epsilon$.
Daraus folgt $|a_n - a| < \epsilon$ für alle $n > n_0$. 
Somit konvergiert $(a_n)$ gegen $a$.
(Analog für den monoton fallenden Fall).
Jede konvergente Folge ist zudem nach Satz 20.3 beschränkt.
