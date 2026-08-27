#


## 1. Audio aufnehmen (mit ffmpeg)
Dieser Befehl nimmt direkt vom Mikrofon im exakten Format auf, das Whisper benötigt (16 kHz, Mono, 16-Bit):

```sh
ffmpeg -f pulse -i default -ar 16000 -ac 1 aufnahme.wav
```

* Aufnahme beenden: Drücke einfach Strg + C auf deiner Tastatur. Die Datei wird sauber gespeichert.

## 2. Text herausschreiben (mit whisper-cli)
Dieser Befehl konvertiert die soeben erstellte Datei und zwingt das Modell, reines Deutsch auszugeben:

```sh
./build/bin/whisper-cli -m models/ggml-base.bin -l de -f aufnahme.wav
```

---

## Bonus: Der "Alles-in-einem-Rutsch"-Befehl
Wenn du das Ganze als eine zusammenhängende Aktion starten willst (erst aufnehmen, nach Strg + C sofort transkribieren), kannst du die beiden Befehle mit einem Semikolon verknüpfen:

```sh
ffmpeg -f pulse -i default -ar 16000 -ac 1 aufnahme.wav ; ./build/bin/whisper-cli -m models/ggml-base.bin -l de -f aufnahme.wav
```

## Für Linux-Profis (Direkt in vim "pipen")
Wenn du die Datei aufnahme.wav nach der Konvertierung gar nicht als Textdatei auf der Festplatte behalten, sondern den Text direkt in ein leeres vim-Fenster jagen willst, nutzt du die Pipe (|):

```sh
./build/bin/whisper-cli -m models/ggml-base.bin -l de -f aufnahme.wav -nt | vim -
```

* -nt: Schaltet die Zeitstempel im Terminal aus.
* | vim -: Das Minuszeichen am Ende sagt vim, dass es den Text direkt aus der Whisper-Ausgabe einlesen soll.

