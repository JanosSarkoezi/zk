# Jira GitLab Commit Verweis

## Frage

Angeommmen ich moechte in Jira auf eine Zeile eines Commits in einer Date im
gltilab verweisen, wie mache ich das?

## Antwort


Wenn du in **Jira** auf eine **bestimmte Zeile einer Datei in einem Commit in
GitLab** verweisen möchtest, kannst du dies tun, indem du den **permanenten
Link** zur entsprechenden Zeile oder zum Bereich im GitLab-Repository kopierst
und in deinen Jira-Kommentar oder in ein Jira-Ticket einfügst.

### Schritte:

1. **Gehe zum Commit in GitLab**, den du referenzieren möchtest:

   * Öffne dein GitLab-Projekt.
   * Gehe zu **Repository → Commits**.
   * Wähle den gewünschten Commit aus.

2. **Öffne die Datei**, die du referenzieren willst, im Diff dieses Commits:

   * Klicke auf den Dateinamen in der Commit-Ansicht.

3. **Wähle die Zeile(n)** aus, auf die du verlinken möchtest:

   * Fahre mit der Maus über die Zeilennummer. Ein kleines **Link-Symbol** (🔗)
   erscheint.
   * Klicke darauf, um den Link zur spezifischen Zeile in der Datei zu
   kopieren.
   * Alternativ kannst du den Link aus der Adressleiste kopieren — die URL
   enthält dann z. B. `#L42` für Zeile 42 oder `#L42-55` für mehrere Zeilen.

   **Beispiel-Link:**

   ``` https://gitlab.com/<group>/<project>/-/commit/<commit-hash>#L42 ```

4. **Füge den Link in Jira ein:**

   * In Jira kannst du den Link direkt in den Beschreibungstext oder Kommentar
   einfügen.
   * Jira erkennt ihn meist automatisch als Link.
   * Du kannst ihn auch mit Markdown oder der Jira-Syntax verlinken:

   **Beispiel (in Jira-Markup):**

   ``` 
   [Zeile 42 im Commit|https://gitlab.com/<group>/<project>/-/commit/<commit-hash>#L42]
   ```

### Hinweis:

* Der Link ist dauerhaft gültig und verweist auf den spezifischen Commit,
**nicht auf den aktuellen Stand der Datei**.
* Achte darauf, dass die GitLab-Instanz öffentlich zugänglich oder für deine
Jira-Nutzer zugänglich ist.



