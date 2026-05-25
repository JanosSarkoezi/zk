---
key: messbarkeit_aeusseres_mass_definition
title: Messbarkeit bezüglich eines äußeren Maßes (Carathéodory-Kriterium)
type: def
tags: [masstheorie]
refs: [aeusseres_mass_definition]
---
Sei $\mu^*$ ein äußeres Maß auf $\Omega$. Eine Teilmenge $A \subseteq \Omega$ heißt **$\mu^*$-messbar** (oder messbar im Sinne von Carathéodory), wenn für alle Testmengen $T \subseteq \Omega$ gilt:
$$\mu^*(T) = \mu^*(T \cap A) + \mu^*(T \cap A^c)$$

Die Menge aller $\mu^*$-messbaren Teilmengen wird oft mit $\mathcal{F}(\mu^*)$ bezeichnet.

--proof--
Das Kriterium besagt anschaulich, dass eine Menge $A$ jede beliebige Testmenge $T$ "additiv zerlegt". Da die Ungleichung $\mu^*(T) \le \mu^*(T \cap A) + \mu^*(T \cap A^c)$ stets durch die $\sigma$-Subadditivität gegeben ist, muss für Messbarkeit nur $\mu^*(T) \ge \mu^*(T \cap A) + \mu^*(T \cap A^c)$ gezeigt werden.
