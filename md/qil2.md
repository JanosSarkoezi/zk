# Kernel-Versionen unter Ubuntu ermitteln

## Frage

Wie kann ich die liste der vorhandenen kernel unter ubuntu 24.04 ermitteln?


## Antwort

Unter **Ubuntu 24.04** kannst du die Liste der installierten (vorhandenen)
Kernel-Versionen auf verschiedene Arten ermitteln. Hier sind die gängigsten
Methoden:

### 1. Mit `dpkg` – Anzeige installierter Kernel-Pakete**

```bash
dpkg --list | grep linux-image
```

Dies listet alle installierten `linux-image`-Pakete, also Kernel-Versionen.

Beispielausgabe:

```
ii  linux-image-6.8.0-25-generic     6.8.0-25.25     amd64        Signed kernel image generic
ii  linux-image-6.8.0-26-generic     6.8.0-26.26     amd64        Signed kernel image generic
ii  linux-image-generic              6.8.0.26.26     amd64        Generic Linux kernel image
```

### 2. Mit `ls` – Anzeige installierter Kernel-Dateien im Boot-Verzeichnis**

```bash
ls -l /boot/vmlinuz-*
```

Dies zeigt die Kernel-Versionen, für die ein Kernel-Image im `/boot`-Verzeichnis liegt.

Beispielausgabe:

```
/boot/vmlinuz-6.8.0-25-generic
/boot/vmlinuz-6.8.0-26-generic
```

### 3. Mit `update-grub` (indirekt, über GRUB-Konfiguration)**

Die Datei `/boot/grub/grub.cfg` enthält Boot-Einträge für alle installierten Kernel. Um nur die Kernel daraus zu extrahieren:

```bash
grep "menuentry 'Ubuntu" /boot/grub/grub.cfg
```

### 4. Mit `uname` – Anzeige des aktuell laufenden Kernels**

Falls du wissen willst, **welcher Kernel gerade aktiv ist**:

```bash
uname -r
```

Beispiel:

```
6.8.0-26-generic
```

### Optional: Alte Kernel auflisten und löschen**

Falls du alte Kernel löschen möchtest, kannst du z. B. `apt` verwenden:

```bash
sudo apt autoremove --purge
```

Oder gezielt:

```bash
sudo apt remove linux-image-6.8.0-25-generic
```

> **Achtung:** Entferne niemals den aktuell laufenden Kernel.

## Frage

Was kann man bei einer kernel panic tun?

## Antwort

Eine **Kernel Panic** ist ein kritischer Fehler im Linux-Kernel, bei dem das
System anhält, weil es nicht mehr sicher weiterarbeiten kann. Das bedeutet oft,
dass das Betriebssystem nicht mehr reagiert und ein manueller Eingriff
notwendig ist.

Hier sind die **wichtigsten Schritte zur Diagnose und Behebung einer Kernel
Panic** unter Ubuntu (auch für 24.04 relevant):

## **1. Sofortmaßnahmen**

### **System neu starten**

* In den meisten Fällen hilft nur ein **erzwungener Neustart**:

  ```bash
  REISUB-Taste (bei hängendem System): Alt + Druck (SysRq) + R, E, I, S, U, B
  ```

  (gibt Befehle an den Kernel – sicherer als hart ausschalten)

### 🧯 **Im GRUB-Menü einen anderen Kernel starten**

* Beim Booten `Shift` (BIOS) oder `Esc` (UEFI) drücken → **Erweiterte Optionen für Ubuntu** → älteren Kernel wählen.

## 2. Ursachen eingrenzen**

### Kernel-Panic-Meldung lesen**

* Häufig enthält die Meldung einen Hinweis: z. B. „Unable to mount root fs“, „not syncing“, „VFS error“, „BUG: unable to handle kernel NULL pointer dereference“, etc.
* Fotografieren oder abschreiben (wenn möglich).

### Logdateien analysieren (sofern System vorher startete)**

Nach einem Reboot kannst du Folgendes prüfen:

```bash
journalctl -b -1
```

Zeigt das Log des letzten Boot-Versuchs.

Oder:

```bash
cat /var/log/kern.log
cat /var/log/syslog
```

## 3. Häufige Ursachen & Lösungen**

| Ursache                                                       | Lösung                                                                                                     |
| ------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| ❌ **Defekter oder inkompatibler Kernel**                     | Starte mit älterem Kernel → entferne defekten: `sudo apt remove linux-image-VERSION`                       |
| 🧩 **Defekte Module oder Treiber (Nvidia, VirtualBox, etc.)** | Boot mit `nomodeset` oder im Wiederherstellungsmodus, problematische Treiber entfernen                     |
| 💾 **Dateisystemfehler / defekte Festplatte**                 | Starte Live-System → führe `fsck` aus                                                                      |
| 🧠 **RAM-Fehler**                                             | Memtest über GRUB starten (wenn installiert)                                                               |
| ⚙️ **Falsche Initramfs oder GRUB-Probleme**                   | Initramfs neu erzeugen: <br> `sudo update-initramfs -u -k all` <br> GRUB neu schreiben: `sudo update-grub` |

## 4. Letzte Rettung: Live-System**

Wenn das System **gar nicht mehr bootet**:

1. Ubuntu-Live-USB starten
2. Partitionen einhängen (`/`, ggf. `/boot`)
3. In ein **chroot-Umgebung** wechseln:

   ```bash
   sudo mount /dev/sdXn /mnt        # Root-Partition
   sudo mount --bind /dev /mnt/dev
   sudo mount --bind /proc /mnt/proc
   sudo mount --bind /sys /mnt/sys
   sudo chroot /mnt
   ```
4. Dort Kernel reparieren, GRUB neu installieren, fsck durchführen usw.

## **5. Vorbeugung**

* Keine experimentellen Kernel aus PPAs oder `mainline`-Quellen ohne Backup
* Immer **alten Kernel behalten**, nie direkt ersetzen
* Backup erstellen, bevor Kernel oder GRUB aktualisiert wird
