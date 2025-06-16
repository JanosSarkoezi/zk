# Regiter der x86_64-Welt 

Hier sind die drei verschiedenen Layout-Typen, die in der x86_64-Welt existieren:

### 1. Die "Klassiker" (A, B, C, D)
Nur diese vier haben das alte `High` (H) Byte-Layout aus den 70er/80er Jahren behalten.

```txt
64-Bit:  R  A/B/C/D  X  [________________________________________________________________]
32-Bit:  E  A/B/C/D  X                  [________________________________________________]
16-Bit:     A/B/C/D  X                                          [________________________]
 8-Bit:     A/B/C/D  H/L                                        [____________][__________]
                                                                      High          Low
```
*Gilt für: **RAX** (EAX, AX, AH, AL), **RBX**, **RCX**, **RDX***

---

### 2. Die Index- und Pointer-Register
Diese wurden später "standardisiert". Sie haben kein "High"-Byte mehr adressierbar, dafür ein dediziertes "Low"-Byte-Suffix (`L`).

```txt
64-Bit:  R  SI / DI / BP / SP  [________________________________________________________________]
32-Bit:  E  SI / DI / BP / SP                  [________________________________________________]
16-Bit:     SI / DI / BP / SP                                          [________________________]
 8-Bit:     SI/DI/BP/SP  L                                                           [__________]
                                                                                         Low
```
*Gilt für:*
* **RSI** (ESI, SI, SIL) — *Dein 2. Argument*
* **RDI** (EDI, DI, DIL) — *Dein 1. Argument*
* **RBP** (EBP, BP, BPL) — *Stack Base Pointer*
* **RSP** (ESP, SP, SPL) — *Stack Pointer*

---

### 3. Die "Numerischen" (R8 bis R15)
Diese wurden mit x64 eingeführt und folgen einem sehr logischen Benennungsschema mit Suffixen.

```txt
64-Bit:  R8 - R15      [________________________________________________________________]
32-Bit:  R8D - R15D                    [________________________________________________] (D = Doubleword)
16-Bit:  R8W - R15W                                            [________________________] (W = Word)
 8-Bit:  R8B - R15B                                                          [__________] (B = Byte)
```
*Gilt für: **R8, R9, R10, R11, R12, R13, R14, R15***

---

### Warum ist das für deinen `printf`-Fall so wichtig?

Schau dir nochmal deine Zeile an:
`0x00001161  89c6  mov esi, eax`

Dank der Diagramme weißt du jetzt:
1.  **`eax`** ist die untere Hälfte von **`RAX`**. Da dein `i` ein `int` (32 Bit) ist, "lebt" es dort.
2.  **`esi`** ist die untere Hälfte von **`RSI`**. Da die System V ABI (Linux Standard) sagt: "Das 2. Argument muss in `RSI`", kopiert der Compiler den Wert von `eax` nach `esi`.

**Ein kleiner Bonus-Fakt:**
Wenn du in `eax` oder `esi` schreibst, löscht die CPU automatisch die obere Hälfte des 64-Bit-Registers (sie wird mit Nullen gefüllt). Das verhindert, dass "Müll" aus alten Berechnungen in den oberen 32 Bit stehen bleibt, wenn man später das ganze 64-Bit-Register (`RAX`/`RSI`) liest.
