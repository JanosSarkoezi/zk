# Axiome von Chisolm

Die Geometrische Algebra ist eine Menge $\mathscr{G}$ mit zwei Verknüpungen.
Eine Addition und eine Multiplikation (auch als geometisches Produkt genannt)
und gehorcht den folgenden Axiomen:

- $\mathscr{G}$ ist ein Ring mit Einheit. Die additive Einheit ist die $0$ und
  die multiplikative Einheit ist die $1$.
- $\mathscr{G}$ enthält einen Körper $\mathscr{G}_0$ mit Charakteristik Null.
  Er enthält die $0$ und die $1$.
- $\mathscr{G}$ enthält eine Teilmenge $\mathscr{G}_1$, die abgeschlossen unter
  der Addition ist und wenn $\lambda\in\mathscr{G}_0$ und $v\in\mathscr{G}_1$,
  dann ist $\lambda v=v\lambda\in\mathscr{G}_1$.
  - Die Elemente von $\mathscr{G}_1$ werden $1$-Vektor, homogener Vektor des
    Grades $1$ oder einfach Vektor genannt.
- Das Quadrat von jedem Vektor ist ein Skalar.
- Das Skalarprodukt ist nicht degeneriert.
  - Die nicht Degeneriertheit bedeutet, das nur der Nullvektor $0$ zu allen
    Vektoren senkrecht seht.
  - Das Skalarprodukt kann mit dem geometischen Produkt definiert werden:
    $$u\cdot v :=\frac{1}{2}(uv+vu)$$
- Wenn $\mathscr{G}_0=\mathscr{G}_1$, dann ist $\mathscr{G}=\mathscr{G}_0$.
  Sonst ist $\mathscr{G}$ die direkte Summe von $\mathscr{G}_r$.
  - Die Menge $\mathscr{G}_r$ ist die Menge der $r$-Vektoren.
  - Ein $r$-Vektor ist die Summen von $r$-Blades.
  - Ein $r$-Blade ist das Produkt von $r$ orthogonalen (anti kommutierenden)
    Vektoren.
  - Wenn $\lambda\in\mathscr{G}_0$ und $A\in\mathscr{G}_r$,
    dann ist
    $$\lambda A=A\lambda\in\mathscr{G}_r$$
  - Diese Axiom sagt aus, Wenn $A\in\mathscr{G}$, dann kann $A$ nur auf genau
    eine Art in $r$-Vektoren zerlegt werden. $A=\sum_r A_r$ mit
    $A_r\in\mathscr{G}_r$.
  - Führt man ein Operator $\langle \rangle_r:\mathscr{G}\to\mathscr{G}_r$ ein,
    so soll dieser Operator die folgenden Aussagen erfüllen:
    - $A$ ist genau dann ein $r$-Vektor, wenn $A = \langle A\rangle_r$ ist.
    - $\langle\lambda A\rangle_r=\langle A\lambda\rangle_r=\lambda\langle A\rangle_r$.
    - $\langle\langle A\rangle_r\rangle_s = \langle A\rangle_r\delta_r^s$
    - $\sum_r A_r = A$ für alle $A\in\mathscr{G}$.
    - $\langle A\rangle_r = 0$ wenn $r<0$ für alle $A\in\mathscr{G}$.

## Referencen

- [Geometrische Algebra](f35d.md)
- [Axiomatische sichtweise](il6v.md)
- [Axiome von Hestenes](ciuz.md)

:mathe:ga:

## Literatur

- Eric Chisolm - Geomeric Algebra (2012) Seite 10-12
