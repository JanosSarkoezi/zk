---
key: extremalsatz_weierstrass
title: Extremalsatz von Weierstraß
type: satz
tags: [analysis, stetigkeit, kompaktheit]
refs: [stetigkeit_folgen_definition, kompaktheit_folgen_definition]
---
Eine auf einer kompakten Menge $K$ stetige Funktion $f: K \to \mathbb{R}$ ist dort beschränkt und nimmt ihr Maximum sowie ihr Minimum an. Es gibt also $x_1, x_2 \in K$ mit:
$$f(x_1) \le f(x) \le f(x_2) \quad \forall x \in K$$

--proof--
Heuser (Satz 36.3): Angenommen $f$ wäre nicht nach oben beschränkt. Dann gäbe es eine Folge $(x_n)$ in $K$ mit $f(x_n) > n$. Wegen der Kompaktheit von $K$ gäbe es eine Teilfolge $x_{n_k} \to \xi \in K$. Da $f$ stetig ist, müsste $f(x_{n_k}) \to f(\xi)$ gelten. Dies widerspricht jedoch $f(x_{n_k}) \to \infty$. Damit ist $f$ beschränkt. Die Existenz des Maximums zeigt man analog unter Nutzung des Supremums der Bildmenge.
