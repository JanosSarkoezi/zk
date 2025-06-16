# Git Commit Bereinigen

## Frage

Angenommen ich habe aus versehen zu viele Dateien in einem Git Commit gepusht,
wie kann ich die Dateien aus dem Commit entfernen, die nicht reingehoehren?

## Antwort

Kein Problem – das lässt sich beheben, je nachdem, **ob du den Commit schon
gepusht hast oder nicht**, und ob du **den Commit behalten, ändern oder
komplett löschen möchtest**.

## Fall 1: Du hast den Commit **noch nicht gepusht**

Dann ist es einfach – du kannst die Historie problemlos neu schreiben.

### So entfernst du bestimmte Dateien aus dem Commit:

```bash
# Entferne die Datei(en) aus dem Index (nicht vom Dateisystem!)
git reset HEAD <datei1> <datei2>

# Erstelle den Commit neu ohne die Dateien
git commit --amend
```

### Beispiel:

```bash
git reset HEAD geheim.txt notizen.txt
git commit --amend
```

Damit wird der letzte Commit neu geschrieben und die beiden Dateien sind nicht mehr enthalten.

## Fall 2: Du hast den Commit **schon gepusht**

Dann musst du vorsichtig sein – besonders wenn du mit anderen im Team arbeitest.

### Option A: Du möchtest die Dateien aus dem Commit entfernen und **die Historie umschreiben**

> **Vorsicht:** Umschreiben der Historie nach Push ist problematisch, wenn andere den Branch schon haben. Dann müsstet ihr euch abstimmen.

```bash
git reset HEAD~1          # gehe einen Commit zurück
git restore --staged .    # alles aus dem Index entfernen
git add nur_die_dateien_die_du_willst.txt
git commit -m "Neuer Commit ohne die unerwünschten Dateien"
git push --force
```

### Option B: Du möchtest die Dateien im Repository **rückgängig machen**, ohne die Historie umzuschreiben

Dann kannst du einen neuen Commit machen, der die unerwünschten Dateien entfernt:

```bash
git rm geheim.txt notizen.txt
git commit -m "Entferne versehentlich hinzugefügte Dateien"
git push
```

## Optional: Dateien für die Zukunft ignorieren

Wenn du bestimmte Dateien **dauerhaft ignorieren** willst:

```bash
echo geheim.txt >> .gitignore
```
