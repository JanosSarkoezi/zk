---
key: sigma_algebra_erzeugte_definition
title: Erzeugte sigma-Algebra
type: def
tags: [masstheorie, mengensysteme]
refs: [sigma_algebra_definition, sigma_algebra_durchschnitt_satz]
---
Zu jedem Mengensystem $\mathcal{E} \subseteq 2^\Omega$ gibt es eine kleinste [[sigma_algebra_definition|$\sigma$-Algebra]], die $\mathcal{E}$ enthält. Diese $\sigma$-Algebra wird als die von $\mathcal{E}$ erzeugte $\sigma$-Algebra bezeichnet und mit $\sigma(\mathcal{E})$ abgekürzt. Das Mengensystem $\mathcal{E}$ wird als Erzeuger der $\sigma$-Algebra $\sigma(\mathcal{E})$ bezeichnet.

--examples--
Der Beweis ist identisch mit dem für die erzeugte Topologie: Man betrachtet den Durchschnitt aller [[sigma_algebra_definition|$\sigma$-Algebra]], die $\mathcal{E}$ enthalten. Da die Potenzmenge $2^\Omega$ eine solche [[sigma_algebra_definition|$\sigma$-Algebra]] ist, ist die Familie nichtleer. Der Durchschnitt ist nach dem [[sigma_algebra_durchschnitt_satz]] selbst eine $\sigma$-Algebra, enthält $\mathcal{E}$ und ist minimal.
