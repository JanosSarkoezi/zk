# Projektion auf einen 1D Unterraum

Betrachten wir den Vektoren $u$ und einen 1D Unterraum, der duch einen Vektor $v$
aufgespannt wird

![](images/proj1.svg.md)

Teilen wir den Vektor $u$ in zwie Teile $u_\|$ und $u_\perp$ auf und betrachte
das geometrische Produkt von den Vektoren $u$ und $v$:
$$uv = u\cdot v + u\wedge v$$
aber wegen der Aufteilung von $u$ gilt auch
$$uv = (u_\| + u_\perp)v = u_\|v + u_\perp v.$$
Daraus folgt $u_\| v = u_\| \cdot v = u\cdot v$ und
$u_\perp v = u_\perp\wedge v = u\wedge v$. Sodass
$$u_\| = (u\cdot v)v^{-1}$$
$$u_\perp = (u\wedge v)v^{-1}$$

Die Proketion eines Vektors $u$ auf $v$ ist
$$u_\| := P_v(u) = (u\cdot v)v^{-1} = \frac{u\cdot v}{v\cdot v}v$$

## Referenzen
- [Geometrische Algebra](f35d.md)

:mathe:ga:

## Literatur
- Alan Macdonald - Linear and Geometric Algebra (2021) Seite 52
