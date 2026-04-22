---
key: wallis_produkt
title: Das Wallissche Produkt
type: satz
tags: [analysis, integral, reihe, pi]
refs: [riemann_integral_definition, hauptsatz_differential_integralrechnung]
---
Das Wallissche Produkt ist eine Darstellung der Kreiszahl $\pi$ als unendliches Produkt:
$$\frac{\pi}{2} = \lim_{k \to \infty} \frac{2^2 \cdot 4^2 \cdots (2k)^2}{1^2 \cdot 3^2 \cdots (2k-1)^2} \cdot \frac{1}{2k}$$
Dies führt zur asymptotischen Gleichheit für die zentralen Binomialkoeffizienten:
$$\frac{\binom{2k}{k}}{2^{2k}} \approx \frac{1}{\sqrt{\pi k}} \quad (k \to \infty)$$

--proof--
Man betrachte die Integrale $I_n = \int_0^{\pi/2} \sin^n x \, dx$. Mittels partieller Integration ergibt sich die Rekursionsformel:
$$I_n = \frac{n-1}{n} I_{n-2}$$
mit $I_0 = \pi/2$ und $I_1 = 1$. Durch sukzessive Anwendung für $n=2k$ und $n=2k+1$ erhält man:
$$I_{2k} = \frac{2k-1}{2k} \cdot \frac{2k-3}{2k-2} \cdots \frac{1}{2} \cdot \frac{\pi}{2}$$
$$I_{2k+1} = \frac{2k}{2k+1} \cdot \frac{2k-2}{2k-1} \cdots \frac{2}{3} \cdot 1$$
Wegen $\sin^{2k+1} x \le \sin^{2k} x \le \sin^{2k-1} x$ auf $[0, \pi/2]$ gilt $I_{2k+1} \le I_{2k} \le I_{2k-1}$. Der Quotient $I_{2k}/I_{2k+1}$ strebt gegen 1, woraus die Produktdarstellung folgt.
