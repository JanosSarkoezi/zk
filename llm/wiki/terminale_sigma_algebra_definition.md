---
key: terminale_sigma_algebra_definition
title: Terminale sigma-Algebra
type: def
tags: wahrscheinlichkeit, sigma_algebra
refs: [sigma_algebra_definition]
---
Sei $\{\mathcal{E}_n\}_{n \in \mathbb{N}}$ eine Folge von Ereignissystemen in einem Wahrscheinlichkeitsraum $(\Omega, \mathcal{F}, P)$. Die **terminale $\sigma$-Algebra** (oder $\sigma$-Algebra der fernen Ereignisse) der Folge $\{\mathcal{E}_n\}$ ist definiert als
$$\mathcal{E}_\infty := \bigcap_{m=1}^\infty \sigma\left( \bigcup_{n=m}^\infty \mathcal{E}_n \right)$$

Ein Ereignis $A \in \mathcal{E}_\infty$ heißt **terminales Ereignis**.

--proof--
Ein Ereignis ist genau dann terminal, wenn es für jedes $m \in \mathbb{N}$ in der $\sigma$-Algebra liegt, die von den Systemen ab dem Index $m$ erzeugt wird. Das bedeutet, dass die Information, ob das Ereignis eintritt, nicht von endlich vielen der ersten Ereignissysteme abhängt. Typische Beispiele für terminale Ereignisse sind der Limes superior oder Limes inferior einer Folge von Ereignissen, sowie Aussagen über die Konvergenz einer Folge von Zufallsvariablen.
