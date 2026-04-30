---
key: stetigkeit_mengenfunktionen_definition
title: Stetigkeitseigenschaften von Mengenfunktionen
type: def
tags: [masstheorie, grundlagen]
refs: [mengenfunktion_definition]
---
Eine [[mengenfunktion_definition|Mengenfunktion]] $\mu: \mathcal{C} \to [0, \infty]$ heißt:

- **stetig von unten**, wenn für jede monoton wachsende Folge $\{A_k\}_{k \in \mathbb{N}} \subseteq \mathcal{C}$ mit $\bigcup_{k \in \mathbb{N}} A_k \in \mathcal{C}$ gilt:
  $$\mu\left[\bigcup_{k \in \mathbb{N}} A_k\right] = \sup_{k \in \mathbb{N}} \mu[A_k]$$

- **stetig von oben**, wenn für jede monoton fallende Folge $\{A_k\}_{k \in \mathbb{N}} \subseteq \mathcal{C}$ mit $\bigcap_{k \in \mathbb{N}} A_k \in \mathcal{C}$ und $\mu[A_1] < \infty$ gilt:
  $$\mu\left[\bigcap_{k \in \mathbb{N}} A_k\right] = \inf_{k \in \mathbb{N}} \mu[A_k]$$

- **$\emptyset$-stetig** (stetig gegen die leere Menge), wenn für jede monoton fallende Folge $\{A_k\}_{k \in \mathbb{N}} \subseteq \mathcal{C}$ mit $\bigcap_{k \in \mathbb{N}} A_k = \emptyset$ und $\mu[A_1] < \infty$ gilt:
  $$\inf_{k \in \mathbb{N}} \mu[A_k] = 0$$

--proof--
Diese Eigenschaften beschreiben das Verhalten der [[mengenfunktion_definition|Mengenfunktion]] bei Grenzübergängen von Mengenfolgen. Die Bedingung $\mu[A_1] < \infty$ ist bei der Stetigkeit von oben essenziell, um unbestimmte Ausdrücke der Form $\infty - \infty$ zu vermeiden.
