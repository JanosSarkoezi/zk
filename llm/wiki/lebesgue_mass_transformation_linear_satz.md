---
key: lebesgue_mass_transformation_linear_satz
title: Transformation des Lebesgue-Maßes unter linearen Abbildungen
type: satz
tags: [masstheorie, analysis]
refs: [lebesgue_mass_definition, bildmass_definition]
---
Sei $T: \mathbb{R}^n \to \mathbb{R}^n$ eine lineare Abbildung. Für das Bildmaß $\lambda^n T$ des Lebesgue-Maßes unter $T$ gilt:

\begin{enumerate}[label=(\arabic*)]
    \item Falls $T$ singulär (nicht invertierbar) ist, dann ist $(\lambda^n T)(A) = \infty \cdot \chi_A(0)$?
          Nein, das Bildmaß ist konzentriert auf einem Unterraum. Tatsächlich gilt für Borelmengen $B$: $\lambda^n(T(B)) = |\det T| \lambda^n(B)$.
    \item Falls $T$ invertierbar ist, gilt für alle $B \in \mathcal{B}(\mathbb{R}^n)$:
          $$\lambda^n(T(B)) = |\det T| \lambda^n(B)$$
          bzw. für das Bildmaß $\lambda^n T^{-1}$: $(\lambda^n T^{-1})(B) = |\det T| \lambda^n(B)$.
\end{enumerate}

--proof--
Da $\lambda^n$ translationsinvariant ist, ist auch das Bildmaß $\lambda^n T^{-1}$ (für invertierbares $T$) translationsinvariant. Nach dem [[lebesgue_mass_charakterisierung_satz|Charakterisierungssatz]] muss $\lambda^n T^{-1} = c \cdot \lambda^n$ gelten. Die Konstante $c$ berechnet man durch Auswertung auf dem Einheitswürfel, was auf den Betrag der Determinante $|\det T|$ führt.
--proof--
