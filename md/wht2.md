# Feedforward-Neural Networks

## Frage

Lass uns die Schritte der Backpropagation in einem FFNN matchematisch
beschreiben. Zuerst mit Formeln und dann mit einem Pseudocode. Danke dir.

## Antwort

Backpropagation ist ein Algorithmus, der in künstlichen neuronalen Netzen
verwendet wird, um die **Gewichte (weights)** und **Bias-Werte (biases)** zu
optimieren. Das Ziel ist, den Fehler des Netzes zu minimieren, indem die
Gradienten der Verlustfunktion bezüglich der Gewichte berechnet und diese dann
aktualisiert werden. Der Algorithmus besteht aus zwei Hauptschritten: einem
Vorwärtsdurchlauf (Forward Pass) und einem Rückwärtsdurchlauf (Backward Pass).

-----

## 1\. Vorwärtsdurchlauf (Forward Pass)

Im Vorwärtsdurchlauf wird die Eingabe durch das neuronale Netz geleitet, um
eine Ausgabe zu erzeugen. Für jede Schicht $l$ und jeden Neuron $j$ wird die
Aktivierung wie folgt berechnet:

1.  **Nettosummierung (Net Input)**:
    $$z_j^{(l)} = \sum_{i} w_{ji}^{(l)} a_i^{(l-1)} + b_j^{(l)}$$
    Hierbei ist $a_i^{(l-1)}$ die Aktivierung des Neurons $i$ in der
    vorhergehenden Schicht $l-1$. $w_{ji}^{(l)}$ sind die Gewichte von Neuron $i$
    in Schicht $l-1$ zu Neuron $j$ in Schicht $l$, und $b_j^{(l)}$ ist der
    Bias-Wert von Neuron $j$ in Schicht $l$.

2.  **Aktivierungsfunktion (Activation Function)**:
    $$a_j^{(l)} = f(z_j^{(l)})$$
    $f$ ist die Aktivierungsfunktion (z.B. Sigmoid, ReLU, Tanh), die auf die
    Nettosummierung angewendet wird, um die endgültige Aktivierung zu erhalten.

-----

## 2\. Rückwärtsdurchlauf (Backward Pass)

Nach dem Vorwärtsdurchlauf wird die Ausgabe des Netzes mit der gewünschten
Ausgabe (dem Label) verglichen, um den Fehler zu berechnen. Für diesen Schritt
benötigen wir eine **Verlustfunktion (loss function)**, z.B. die quadratische
Fehlerfunktion (Mean Squared Error, MSE):

$$E = \frac{1}{2} \sum_{k} (y_k - a_k^{(L)})^2$$

Hierbei ist $y_k$ der Sollwert und $a_k^{(L)}$ die tatsächliche Ausgabe des Netzes (in der letzten Schicht $L$).

Der Kern der Backpropagation ist nun die Berechnung der Gradienten des Fehlers bezüglich der Gewichte und Bias-Werte, um diese zu aktualisieren.

1.  **Fehler (Delta) der Ausgabeschicht:**
    Für die letzte Schicht $L$ wird das Fehlerdelta $\delta_k^{(L)}$ wie folgt berechnet:
    $$\delta_k^{(L)} = (a_k^{(L)} - y_k) \cdot f'(z_k^{(L)})$$
    $f'$ ist die Ableitung der Aktivierungsfunktion. Für MSE ist der Term
    $(a_k^{(L)} - y_k)$ die Ableitung des Fehlers nach der Aktivierung.

2.  **Fehler (Delta) der verborgenen Schichten:**
    Für jede verborgene Schicht $l$ (von $L-1$ bis 1) wird das Fehlerdelta $\delta_j^{(l)}$ rekursiv von der nachfolgenden Schicht $l+1$ berechnet:
    $$\delta_j^{(l)} = \left(\sum_{k} w_{kj}^{(l+1)} \delta_k^{(l+1)}\right) \cdot f'(z_j^{(l)})$$
    Die Summe über $k$ repräsentiert die gewichtete Summe der Fehlerdeltas der nachfolgenden Schicht.

3.  **Berechnung der Gradienten:**
    Mit den Deltas können nun die Gradienten für die Gewichte und Bias-Werte berechnet werden.

      * **Gradient für Gewichte:**
        $$\frac{\partial E}{\partial w_{ji}^{(l)}} = a_i^{(l-1)} \cdot \delta_j^{(l)}$$
      * **Gradient für Bias:**
        $$\frac{\partial E}{\partial b_{j}^{(l)}} = \delta_j^{(l)}$$

4.  **Aktualisierung der Gewichte und Bias-Werte:**
    Die Gewichte und Bias-Werte werden mit einem Lernrateparameter $\eta$ (eta) aktualisiert:

      * **Gewichtsaktualisierung:**
        $$w_{ji}^{(l)} = w_{ji}^{(l)} - \eta \frac{\partial E}{\partial w_{ji}^{(l)}}$$
      * **Bias-Aktualisierung:**
        $$b_{j}^{(l)} = b_{j}^{(l)} - \eta \frac{\partial E}{\partial b_{j}^{(l)}}$$
        Dieser Prozess wird für eine bestimmte Anzahl von Epochen oder bis zur Konvergenz wiederholt.

-----

## Pseudocode für Backpropagation

```
Funktion Backpropagation(Netzwerk, Eingabe, Sollwert, Lernrate):
    // 1. Vorwärtsdurchlauf
    Für jede Schicht l von 1 bis L:
        Berechne die gewichtete Summe z für jedes Neuron:
            z_j^(l) = Summe(w_ji^(l) * a_i^(l-1)) + b_j^(l)
        Berechne die Aktivierung a:
            a_j^(l) = Aktivierungsfunktion(z_j^(l))

    // 2. Fehlerberechnung
    Berechne den Fehler E für die Ausgabeschicht L:
        E = 0.5 * Summe((Sollwert_k - Ausgabe_k)^2)
        
    // 3. Rückwärtsdurchlauf
    // Berechne Delta für die Ausgabeschicht
    Für jedes Neuron k in der Ausgabeschicht L:
        delta_k^(L) = (a_k^(L) - Sollwert_k) * Ableitung_Aktivierungsfunktion(z_k^(L))

    // Berechne Delta für die verborgenen Schichten
    Für jede Schicht l von L-1 bis 1 (rückwärts):
        Für jedes Neuron j in der Schicht l:
            delta_j^(l) = (Summe(w_kj^(l+1) * delta_k^(l+1))) * Ableitung_Aktivierungsfunktion(z_j^(l))

    // 4. Gradienten berechnen und Gewichte/Bias aktualisieren
    Für jede Schicht l von 1 bis L:
        Für jedes Neuron j in der Schicht l:
            Für jedes Neuron i in der vorherigen Schicht l-1:
                Gradient_w = a_i^(l-1) * delta_j^(l)
                w_ji^(l) = w_ji^(l) - Lernrate * Gradient_w
            
            Gradient_b = delta_j^(l)
            b_j^(l) = b_j^(l) - Lernrate * Gradient_b
            
    Gib das aktualisierte Netzwerk zurück
```

## Frage

Kannst du bitte die kompakte mathematische Form eines Trainingforganges des
FFNN schildern? Danke dir.

## Antowrt

Absolut! Hier ist die kompakte mathematische Formulierung eines vollständigen
Trainingsdurchgangs (Epoche) eines Feedforward-Neural Networks (FFNN) mit
Backpropagation und SGD.

## Gegeben:
- **Eingabevektor**: $\mathbf{x} \in \mathbb{R}^{n}$
- **Zielvektor**: $\mathbf{y} \in \mathbb{R}^{m}$
- **Gewichtsmatrizen**: $W^{(l)}$ für Schicht $l$
- **Bias-Vektoren**: $\mathbf{b}^{(l)}$ für Schicht $l$
- **Aktivierungsfunktion**: $\sigma(\cdot)$ (z.B. Sigmoid, ReLU)
- **Loss-Funktion**: $L(\mathbf{\hat{y}}, \mathbf{y})$ (z.B. MSE, Cross-Entropy)
- **Lernrate**: $\eta$

---

## 1. Forward Pass (Vorwärtsdurchlauf)

**Für jede Schicht $l = 1, ..., L$:**
$$
\begin{align*}
\mathbf{z}^{(l)} &= W^{(l)} \mathbf{a}^{(l-1)} + \mathbf{b}^{(l)} \quad &\text{(Netz-Eingabe)} \\
\mathbf{a}^{(l)} &= \sigma(\mathbf{z}^{(l)}) \quad &\text{(Aktivierung)} \\
\end{align*}
$$
mit $\mathbf{a}^{(0)} = \mathbf{x}$ (Eingabe) und $\mathbf{a}^{(L)} = \mathbf{\hat{y}}$ (Ausgabe)

**Loss-Berechnung:**
$$
J = L(\mathbf{\hat{y}}, \mathbf{y})
$$

---

## 2. Backward Pass (Rückwärtsdurchlauf - Backpropagation)

**Outputschicht ($l = L$):**
$$
\begin{align*}
\mathbf{\delta}^{(L)} &= \nabla_{\mathbf{\hat{y}}} L \odot \sigma'(\mathbf{z}^{(L)}) \quad &\text{(Fehlerterm)} \\
\frac{\partial J}{\partial W^{(L)}} &= \mathbf{\delta}^{(L)} (\mathbf{a}^{(L-1)})^T \\
\frac{\partial J}{\partial \mathbf{b}^{(L)}} &= \mathbf{\delta}^{(L)}
\end{align*}
$$

**Für versteckte Schichten ($l = L-1, ..., 1$):**
$$
\begin{align*}
\mathbf{\delta}^{(l)} &= \left( (W^{(l+1)})^T \mathbf{\delta}^{(l+1)} \right) \odot \sigma'(\mathbf{z}^{(l)}) \\
\frac{\partial J}{\partial W^{(l)}} &= \mathbf{\delta}^{(l)} (\mathbf{a}^{(l-1)})^T \\
\frac{\partial J}{\partial \mathbf{b}^{(l)}} &= \mathbf{\delta}^{(l)}
\end{align*}
$$

---

## 3. Parameterupdate (Gradient Descent)

**Für alle Schichten $l = 1, ..., L$:**
$$
\begin{align*}
W^{(l)} &\leftarrow W^{(l)} - \eta \frac{\partial J}{\partial W^{(l)}} \\
\mathbf{b}^{(l)} &\leftarrow \mathbf{b}^{(l)} - \eta \frac{\partial J}{\partial \mathbf{b}^{(l)}}
\end{align*}
$$

---

## 🔄 Kompakter Algorithmus (Pseudocode)

```
Für jede Trainingsepoche:
    Für jeden Datenpunkt (x, y) im Batch:
        # Forward Pass
        a⁰ = x
        Für l = 1 bis L:
            zˡ = Wˡ·aˡ⁻¹ + bˡ
            aˡ = σ(zˡ)
        
        # Loss Berechnung
        J = L(aᴸ, y)
        
        # Backward Pass
        δᴸ = ∇_aᴸ L ⊙ σ'(zᴸ)
        Für l = L-1 bis 1:
            δˡ = (Wˡ⁺¹)ᵀ·δˡ⁺¹ ⊙ σ'(zˡ)
        
        # Gradienten akkumulieren
        Für l = 1 bis L:
            ∇Wˡ += δˡ·(aˡ⁻¹)ᵀ
            ∇bˡ += δˡ
    
    # Parameterupdate (nach Batch)
    Für l = 1 bis L:
        Wˡ -= η · ∇Wˡ
        bˡ -= η · ∇bˡ
```

---

## 🎯 Wichtige Konzepte in kompakter Form:

- **$\odot$**: Elementweises Produkt (Hadamard-Produkt)
- **$\sigma'(\cdot)$**: Ableitung der Aktivierungsfunktion
- **$\delta^{(l)}$**: Fehlerterm der Schicht $l$ ("Wie sehr ist jede Neuron schuld?")
- **Chain Rule**: $\frac{\partial J}{\partial W} = \frac{\partial J}{\partial a} \frac{\partial a}{\partial z} \frac{\partial z}{\partial W}$

Dieser Prozess wird iterativ wiederholt bis Konvergenz erreicht ist!
