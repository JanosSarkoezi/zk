# Der $k$-Vektorteil eines Multivektors

Der $k$-Vektorteil eines Multivektors aus dem $\mathscr{G}^n$ besteht nur aus der Linearkombination der $k$-Blades. Wenn $A$ ein Multivektor ist dann wird mit

$$
\langle A\rangle_k
$$

der $k$-Vektorteil bezeichnet.

Die Abbildung $\langle ...\rangle_k$ wird auch als Gradoperator genannt. Sie erfüllt folgende Eigenschaften:

$$
\begin{align*}
  \langle A + B\rangle_k &= \langle A \rangle_k + \langle B \rangle_k \\
  \langle \lambda A\rangle_k &= \lambda \langle A \rangle_k = \langle
  A\rangle_k\lambda\hspace3ex\textrm{wenn }\lambda = \langle\lambda\rangle_0 \\
  \langle\langle A\rangle_k\rangle_k &= \langle A \rangle_k
\end{align*}
$$

## Beispiele

- Sei ein $A$ ein Multivektor aus dem $\mathscr{G}^3$. Dann kann $A$ als Summe der
  $k$-Vektorteile dargestellt werden:
  
  $$
  A = \langle A\rangle_0 + \langle A\rangle_1 + \langle A\rangle_2 + \langle A\rangle_3
  $$

- Das geometische Produkt der Vektoren $u$ und $v$ kann auch in die
  $k$-Vektorteile aufgespalten werden.
  
  $$
  uv = \langle uv\rangle_0 + \langle uv\rangle_1 + \langle uv\rangle_2
  $$
  
  wobei $\langle uv\rangle_0 = u \cdot v$, $\langle uv\rangle_1 = 0$ und $\langle uv\rangle_2 = u\wedge v$ ist.

## Referenzen

- [Geometrische Algebra](f35d.md)
- [$k$-Blades](kikd.md)
- [$k$-Vektoren](93t3.md)
- [Die Umkehrung eines Multivektors](eelx.md)

:mathe:ga:

## Literatur

- Alan Macdonald - Linear and Geometric Algebra (2021) Seite 96
- David Hestenes - New Foundations for Classical Mechanics (2002) Seite 34
