# Doom Source Ports für Ubuntu

Wenn ich gzdoom von github klone, wie kann ich unter linux eine ausfuehrbare
Version erstellen?

Das Kompilieren von GZDoom unter Ubuntu ist ein tolles Projekt, erfordert aber
ein paar Vorbereitungen, da GZDoom von mehreren Bibliotheken abhängt. Eine
Besonderheit ist die **ZMusic**-Bibliothek, die seit einiger Zeit separat
gebaut werden muss.

Hier ist der Schritt-für-Schritt-Guide für das Terminal:

### 1. Abhängigkeiten installieren

Zuerst installierst du alle Werkzeuge und Bibliotheken, die zum Bauen benötigt werden:

```bash
sudo apt update
sudo apt install g++ make cmake libsdl2-dev git zlib1g-dev libbz2-dev \
libjpeg-dev libfluidsynth-dev libgme-dev libopenal-dev libmpg123-dev \
libsndfile1-dev libgtk-3-dev timidity nasm libgl1-mesa-dev libvpx-dev

```

### 2. ZMusic kompilieren (Wichtig!)

GZDoom benötigt `ZMusic`. Da dies oft nicht in den Standard-Quellen ist, bauen
wir es schnell selbst:

```bash
cd ~
git clone https://github.com/ZDoom/ZMusic.git
mkdir ZMusic/build && cd ZMusic/build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)
sudo make install

```

### 3. GZDoom klonen und erstellen

Nun kommen wir zum eigentlichen Hauptprogramm:

```bash
cd ~
git clone https://github.com/ZDoom/gzdoom.git
mkdir gzdoom/build && cd gzdoom/build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)

```

*Hinweis: `-j$(nproc)` nutzt alle deine CPU-Kerne, um den Vorgang zu beschleunigen.*

### 4. Das Programm starten

Nachdem der Vorgang abgeschlossen ist, findest du die ausführbare Datei im
Ordner `~/gzdoom/build`. Du kannst sie so testen:

```bash ./gzdoom

```

**Damit du Doom auch wirklich spielen kannst:** GZDoom wird dich beim ersten
Start nach den WAD-Dateien fragen. Kopiere deine `.wad`-Dateien von der CD am
besten in den Ordner, in dem auch die `gzdoom`-Binary liegt, oder nach
`~/.config/gzdoom/`.

---

### Profi-Tipp: Installation "sauber" machen

Wenn du GZDoom systemweit verfügbar machen willst, kannst du im Build-Ordner
noch `sudo make install` ausführen. Dann kannst du das Spiel einfach durch
Eingabe von `gzdoom` in jedem beliebigen Terminal starten.

**Ein kleiner Hinweis zu den CDs:** Da Linux-Dateisysteme (anders als Windows)
zwischen Groß- und Kleinschreibung unterscheiden, benenne deine Dateien
sicherheitshalber in Kleinschreibung um (z. B. `doom2.wad` statt `DOOM2.WAD`),
falls das Programm sie nicht sofort erkennt.

Möchtest du auch wissen, wie du eine Desktop-Verknüpfung (Icon) für deine
selbst kompilierte Version erstellst?

