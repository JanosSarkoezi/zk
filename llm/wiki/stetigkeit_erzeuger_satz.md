---
key: stetigkeit_erzeuger_satz
title: Stetigkeit und Erzeuger der Topologie
type: satz
tags: [topologie]
refs: [topologischer_raum_definition, topologie_erzeugte_definition]
---
Seien $(\Omega, \mathcal{T})$ und $(\Omega', \mathcal{T}')$ topologische Räume und sei $\mathcal{E}'$ ein Erzeuger von $\mathcal{T}'$ (d.h. $\tau(\mathcal{E}') = \mathcal{T}'$). Eine [[topologischer_raum_definition|Abbildung]] $f: \Omega \to \Omega'$ ist genau dann stetig, wenn
$$f^{-1}(\mathcal{E}') \subseteq \mathcal{T}$$
gilt.

--proof--
Wegen $\mathcal{E}' \subseteq \tau(\mathcal{E}') = \mathcal{T}'$ folgt aus der Stetigkeit von $f$ unmittelbar $f^{-1}(\mathcal{E}') \subseteq f^{-1}(\mathcal{T}') \subseteq \mathcal{T}$.
Zum Nachweis der umgekehrten Inklusion betrachten wir das Mengensystem
$$\mathcal{T}'_0 := \{ A' \in \mathcal{T}' \mid f^{-1}(A') \in \mathcal{T} \}$$
Da das Urbild mit den Mengenoperationen kommutiert, ist $\mathcal{T}'_0$ eine [[topologie_erzeugte_definition|Topologie]] auf $\Omega'$. Gilt $f^{-1}(\mathcal{E}') \subseteq \mathcal{T}$, so folgt $\mathcal{E}' \subseteq \mathcal{T}'_0$. Da $\mathcal{T}'_0$ eine [[topologie_erzeugte_definition|Topologie]] ist, die $\mathcal{E}'$ enthält, muss sie auch die kleinste solche [[topologie_erzeugte_definition|Topologie]] enthalten, also $\mathcal{T}' = \tau(\mathcal{E}') \subseteq \mathcal{T}'_0$. Dies impliziert $f^{-1}(\mathcal{T}') \subseteq \mathcal{T}$, also ist $f$ stetig.
