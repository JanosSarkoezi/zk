# Grahm-Schmidtsches Orthogonalisieung

Für das Verständis des Verfahrens reicht es in 3D anzuschauen. Seien $u_1, u_2$
und $u_3$ linear unabhängige Vektoren aus einem reelem Vektorraum $V$ mit
Skalarprodukt. Die orhtogonalen Vektoren seien mit $b_1, b_2$ und $b_3$
bezeichnet.
- Setze
$$b_1 := u_1$$
- Projiziere $u_2$ auf $b_1$ und ziehe die Projektion von $u_2$ ab.
$$b_2=u_2 - \frac{u_2\cdot b_1}{b_1\cdot b_1}b_1$$
- Projiziere $u_3$ auf $b_1$ und auf $b_2$ und ziehe die Projetionen von $u_3$
  ab.
$$b_3=u_3 - \frac{u_3\cdot b_1}{b_1\cdot b_1}b_1 - \frac{u_3\cdot b_2}{b_2\cdot b_2}b_2$$

## Referenzen
- [Lineare Algebra](jtfm.md)
- [Lineare Unabhängigkeit](v332.md)
- [Geometrische Algebra](f35d.md)
- [$k$-Blades](kikd.md)
- [$k$-Vektoren](93t3.md)


:mathe:ga:

## Literatur
- Alan Macdonald - Linear and Geometric Algebra (2021) Seite 64
