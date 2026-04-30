---
key: stetigkeit_impliziert_messbarkeit_satz
title: Zusammenhang zwischen Stetigkeit und Messbarkeit
type: satz
tags: [topologie, masstheorie]
refs: [topologischer_raum_definition, messbarer_raum_definition, borelsche_sigma_algebra_definition]
---
Seien $(\Omega, \mathcal{T})$ und $(\Omega', \mathcal{T}')$ topologische Räume. Jede [[topologischer_raum_definition|stetige Abbildung]] $f: \Omega \to \Omega'$ ist $\mathcal{B}(\Omega, \mathcal{T})$-$\mathcal{B}(\Omega', \mathcal{T}')$-messbar.

--proof--
Nach Definition der Borelschen $\sigma$-Algebra ist $\mathcal{T}'$ ein Erzeuger von $\mathcal{B}(\Omega', \mathcal{T}')$. Da $f$ stetig ist, gilt $f^{-1}(\mathcal{T}') \subseteq \mathcal{T}$. Wegen $\mathcal{T} \subseteq \sigma(\mathcal{T}) = \mathcal{B}(\Omega, \mathcal{T})$ folgt:
$$f^{-1}(\mathcal{T}') \subseteq \mathcal{B}(\Omega, \mathcal{T})$$
Nach dem Satz über Messbarkeit und Erzeuger (Satz 2.3.3 / 2.3.2) folgt daraus die Messbarkeit von $f$ bezüglich der Borelschen $\sigma$-Algebren.
