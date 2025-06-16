# Git Umbenennen von lokal und remote Braches

## Frage

Wie kann ich einen Branch lokal und remote umbenennen?

## Antwort
Das Umbenennen eines Branches erfordert Schritte, die lokal in deinem
Git-Repository und anschließend remote auf dem Server (z. B. GitHub, GitLab,
Bitbucket) ausgeführt werden müssen.

## 1\. Lokales Umbenennen des Branches

Angenommen, du möchtest den Branch von `alter-name` in `neuer-name` umbenennen.

### Wenn du dich auf dem Branch befindest, den du umbenennen möchtest:

1.  **Lokalen Branch umbenennen:**
    ```bash
    git branch -m neuer-name
    ```

### Wenn du dich *nicht* auf dem Branch befindest, den du umbenennen möchtest:

1.  **Lokalen Branch umbenennen:**
    ```bash
    git branch -m alter-name neuer-name
    ```

-----

## 2\. Remote Branch aktualisieren

Da Git nur eine *Verknüpfung* zu dem Remote-Branch speichert, musst du den
alten Remote-Branch löschen und den neu benannten lokalen Branch zum
Remote-Repository pushen.

### a. Alten Remote-Branch löschen

1.  **Alten Branch vom Remote-Repository löschen:**
    ```bash
    git push origin --delete alter-name
    ```
    *Alternativ:*
    ```bash
    git push origin :alter-name
    ```

### b. Neuen lokalen Branch pushen

1.  **Den neu benannten Branch zum Remote-Repository pushen:**
    ```bash
    git push -u origin neuer-name
    ```
    Der Flag `-u` (oder `--set-upstream`) ist wichtig, da er die
    **Upstream-Verbindung** für deinen neuen lokalen Branch einrichtet, sodass
    zukünftige `git pull` und `git push` Befehle diesen neuen Remote-Branch
    verwenden.

-----

## Zusammenfassung der Befehle

Wenn du dich auf dem Branch befindest, den du umbenennen möchtest (`alter-name`):

```bash
# 1. Lokal umbenennen
git branch -m neuer-name

# 2. Alten Remote-Branch löschen
git push origin --delete alter-name

# 3. Neuen Branch pushen und Upstream setzen
git push -u origin neuer-name
```
