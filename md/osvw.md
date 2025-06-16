# ripgrep: Suche nach bestimmten Dateien und Treffern

## Frage

> Wie kann ich mit ripgrep alle pom.xml Dateien in einem Verzeichnis und darunter durchsuchen lassen?

## Antwort

```bash
rg -g "pom.xml" <Suchbegriff> <Verzeichnis>
```

Beispiel:
```bash
rg -g "pom.xml" dependency .
```

Nur Dateien listen:
```bash
rg -g "pom.xml" -l .
```

---

## Frage

> Kann ich mit ripgrep auch in Dateien mit verschiedenen Dateiendungen suchen?

## Antwort

Ja, z. B.:

Mehrere `-g`:
```bash
rg -g "*.xml" -g "*.java" -g "*.md" Suchbegriff
```

Oder kompakter:
```bash
rg -g "*.{xml,java,md}" Suchbegriff
```

Oder mit `-t`:
```bash
rg -t xml -t java Suchbegriff
```

---

## Frage

> Wenn ich nach xhtml Dateien suche, dann kommt die Meldung: `rg: unrecognized file type: xhtml`. Warum?

## Antwort

Weil `-t` nur bekannte Dateitypen unterstützt. Lösung:

**Variante 1:**
```bash
rg -g "*.xhtml" Suchbegriff
```

**Variante 2:** (eigenen Typ definieren)
```bash
rg --type-add "xhtml:*.xhtml" -t xhtml Suchbegriff
```

Optional in `~/.ripgreprc`:
```
--type-add=xhtml:*.xhtml
```

---

## Frage

Kann ripgrep auch die Anzahl ausgeben und nicht den Inhalt oder den Dateinamen?

## Antwort

Anzahl pro Datei:
```bash
rg -c Suchbegriff
```

Nur die Summe:
```bash
rg -c --no-filename Suchbegriff
```

Nur die Endsumme:
```bash
rg -c Suchbegriff | awk -F: '{sum += $2} END {print sum}'
```

Dateien mit Treffern zählen:
```bash
rg -l Suchbegriff | wc -l
```

---

## Frage

Er sollte nur den Suchbegriff ausgeben und wie oft er gefunden wurde, könnte das gehen?

## Antwort

```bash
rg -o Suchbegriff | wc -l | awk -v word="Suchbegriff" '{print word ": " $1}'
```

Mehrere Begriffe:
```bash
for term in "foo" "bar" "baz"; do
    echo -n "$term: "
    rg -o "$term" | wc -l
done
```


