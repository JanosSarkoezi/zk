---
key: sigma_additivitaet_stetigkeit_aequivalenz_satz
title: Äquivalente Charakterisierungen der sigma-Additivität
type: satz
tags: [masstheorie, inhalt, ring]
refs: [ring_definition, inhalt_definition, sigma_additivitaet_stetigkeit_unten_satz, stetigkeit_unten_impliziert_oben_lemma]
---
Sei $\mathcal{C}$ ein Ring und $\mu: \mathcal{C} \to [0, \infty]$ ein endlicher Inhalt. Dann sind äquivalent:
(a) $\mu$ ist $\sigma$-additiv.
(b) $\mu$ ist [[stetigkeit_unten_impliziert_oben_lemma|stetig]] [[sigma_additivitaet_stetigkeit_unten_satz|von unten]].
(c) $\mu$ ist [[stetigkeit_unten_impliziert_oben_lemma|stetig]] von [[stetigkeit_unten_impliziert_oben_lemma|oben]].
(d) $\mu$ ist $\emptyset$-[[stetigkeit_unten_impliziert_oben_lemma|stetig]].

--proof--
Die Äquivalenz (a) $\Leftrightarrow$ (b) und die Implikation (b) $\Rightarrow$ (c) wurden bereits gezeigt.
(c) $\Rightarrow$ (d) ist trivial (da $\emptyset \in \mathcal{C}$ und $\mu[\emptyset] = 0$).
Für (d) $\Rightarrow$ (c) betrachte man für eine fallende Folge $A_k \downarrow A$ die Folge $B_k := A_k \setminus A$. Dann gilt $B_k \downarrow \emptyset$. Aus der $\emptyset$-[[sigma_additivitaet_stetigkeit_unten_satz|Stetigkeit]] folgt $\inf \mu[B_k] = 0$, woraus mit $\mu[B_k] = \mu[A_k] - \mu[A]$ die [[sigma_additivitaet_stetigkeit_unten_satz|Stetigkeit]] von [[stetigkeit_unten_impliziert_oben_lemma|oben]] folgt.
Für endliche Inhalte gilt zudem (c) $\Rightarrow$ (b) (analog zum Beweis von (b) $\Rightarrow$ (c)).
--proof--
