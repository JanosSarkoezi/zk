# Bildschirmfoto in Linux Zwischenablage

## Frage

Angenommen ich moechte mit dem Befehlt

```sh

import image.png

```

ein Bildschirmfoto machen un dann mit einem anderem Tool in das Zwischenlager
in Linux kopieren, sodass ich aus dem Zwischenlager das Bild in Mattermost
kopieren kann, wie ginge das?

## Antwort

 * **Installation:** Wenn `import` oder `xclip` nicht installiert sind, müssen Sie sie möglicherweise nachinstallieren. Auf Debian-basierten Systemen (wie Ubuntu) geht das so:

   ```sh
   sudo apt-get update
   sudo apt-get install imagemagick xclip
   ```

 * **Interaktives Screenshot-Tool:** Wenn Sie nur einen Teil des Bildschirms aufnehmen möchten, können Sie `import` auch ohne `-window root` ausführen. Der Befehl `import screenshot.png` ändert den Mauszeiger in ein Fadenkreuz. Sie können dann einen Bereich aufziehen, den Sie aufnehmen möchten. Um dies mit der Zwischenablage zu kombinieren, wäre der Befehl:

   ```sh
   import png:- | xclip -selection clipboard -target image/png
   ```

   Dieser Befehl wartet darauf, dass Sie einen Bereich auf dem Bildschirm auswählen.

 * **Alternativen:** Es gibt auch andere Tools für Screenshots, die diesen Prozess vereinfachen, wie **`scrot`** oder **`gnome-screenshot`**. Diese sind oft leichter zu bedienen und haben oft schon integrierte Funktionen, um das Bild in die Zwischenablage zu kopieren.
