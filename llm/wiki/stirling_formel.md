---
key: stirling_formel
title: Die Stirlingsche Formel
type: satz
tags: [analysis, fakultät, asymptotik]
refs: [wallis_produkt, euler_summenformel]
---
Die Stirlingsche Formel beschreibt das asymptotische Verhalten der Fakultät für große $n$:
$$n! \approx \sqrt{2\pi n} \left(\frac{n}{e}\right)^n$$
Dies bedeutet $\lim_{n \to \infty} \frac{n!}{\sqrt{2\pi n} (n/e)^n} = 1$.

--proof--
Man nutzt die Eulersche Summenformel für $f(x) = \ln x$. Daraus folgt $\ln n! \approx (n + \frac{1}{2}) \ln n - n + C$. Durch Exponenzieren erhält man $n! \approx e^C \sqrt{n} (n/e)^n$. Die Konstante $e^C$ wird durch Vergleich mit dem Wallisschen Produkt als $\sqrt{2\pi}$ bestimmt.
