# Maven-Phasen und Profile

## Frage
wie kann ich in einem Pofil von Maven eine Pahse aufrufen, sodass das dazu assoziierte Plugin aus gefuert wrid?

## Antwort
In Maven kannst du eine spezifische **Phase** innerhalb eines **Build-Lifecycles** aufrufen, um alle damit assoziierten **Plugins** und **Goals** auszuführen. Jedes Plugin ist dabei mit bestimmten Phasen verknüpft, sodass es automatisch aufgerufen wird, wenn diese Phase ausgeführt wird.

### Beispiel:

Nehmen wir an, du möchtest die Phase `package` ausführen. Diese Phase ist Teil des Standard-Lifecycle von Maven und führt alle Schritte bis einschließlich des Packaging eines Projekts aus.

Um das zu erreichen, kannst du einfach den folgenden Befehl verwenden:

```bash
mvn package
```

Hier sind die Schritte, die Maven durchführen wird:

1. **validate**: Prüfen, ob das Projekt korrekt ist und alle benötigten Informationen zur Verfügung stehen.
2. **compile**: Den Quellcode kompilieren.
3. **test**: Tests ausführen.
4. **package**: Ein JAR, WAR oder eine andere Artefakt-Datei basierend auf der Projektkonfiguration erstellen.

### Plugins in einem Profil aktivieren

Falls du ein **Profil** in der `pom.xml` definiert hast und möchtest, dass ein bestimmtes Plugin innerhalb eines Profils ausgeführt wird, kannst du das Profil aktivieren und eine bestimmte Phase ausführen.

Angenommen, dein Profil heißt `my-profile` und du möchtest die Phase `verify` aufrufen:

```bash
mvn verify -Pmy-profile
```

In diesem Fall werden alle Plugins und Goals, die an die Phase `verify` gebunden sind, im Rahmen des Profils `my-profile` ausgeführt.

### Beispiel für eine Profilkonfiguration

In deiner `pom.xml` könntest du ein Profil mit einem Plugin definieren, das an eine bestimmte Phase gebunden ist:

```xml
<profiles>
  <profile>
    <id>my-profile</id>
    <build>
      <plugins>
        <plugin>
          <groupId>org.apache.maven.plugins</groupId>
          <artifactId>maven-clean-plugin</artifactId>
          <version>3.1.0</version>
          <executions>
            <execution>
              <id>clean</id>
              <phase>pre-clean</phase>
              <goals>
                <goal>clean</goal>
              </goals>
            </execution>
          </executions>
        </plugin>
      </plugins>
    </build>
  </profile>
</profiles>
```

Um dieses Profil zu aktivieren und das `clean`-Plugin in der Phase `pre-clean` auszuführen, kannst du den folgenden Befehl verwenden:

```bash
mvn clean -Pmy-profile
```

### Zusammenfassung
1. **Phase ausführen**: `mvn <phase>`
2. **Profil aktivieren**: `mvn <phase> -P<profilname>`
3. **Plugins und Goals in einer Phase definieren**: In der `pom.xml` unter dem entsprechenden Profil und der Build-Sektion.


