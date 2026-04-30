---
key: ring_erzeugter_halbring_satz
title: Der von einem Halbring erzeugte Ring
type: satz
tags: [masstheorie, mengensysteme]
refs: [halbring_definition, ring_definition]
---
Sei $\mathcal{H}$ ein Halbring auf $\Omega$. Der von $\mathcal{H}$ erzeugte Ring $\rho(\mathcal{H})$ besteht genau aus allen endlichen disjunkten Vereinigungen von Mengen aus $\mathcal{H}$:
$$\rho(\mathcal{H}) = \left\{ \sum_{i=1}^n H_i \mid n \in \mathbb{N}, H_1, \dots, H_n \in \mathcal{H} \text{ disjunkt} \right\}$$

--proof--
Man zeigt, dass das System $\mathcal{R}$ der endlichen disjunkten Vereinigungen von Mengen aus $\mathcal{H}$ tatsächlich ein Ring ist. Die Stabilität unter Durchschnitten folgt aus der $\cap$-Stabilität von $\mathcal{H}$. Die Stabilität unter Differenzbildung folgt aus der Differenzeigenschaft (iii) des [[halbring_definition|Halbrings]] und Induktion. Da jeder Ring, der $\mathcal{H}$ enthält, auch alle endlichen disjunkten Vereinigungen enthalten muss, ist $\mathcal{R}$ der kleinste solche Ring.
