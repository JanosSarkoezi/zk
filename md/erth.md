# Maven WAR für JBoss WildFly

## Frage

> Wenn man fuer Jboss Wildfly mit Maven eine WEB Applikation erstellt, worauf muss geachtet werden bei der Erstellung der WAR-Datei?

## Antwort

Beim Erstellen einer **WAR-Datei** für **JBoss WildFly** mit **Maven** gibt es mehrere wichtige Punkte zu beachten:

---

### ✅ 1. Maven-Projektstruktur
```
my-webapp/
├── src/
│   ├── main/
│   │   ├── java/
│   │   ├── resources/
│   │   ├── webapp/
│   │   │   ├── WEB-INF/
│   │   │   │   └── web.xml
│   │   │   └── index.jsp
├── pom.xml
```

---

### ✅ 2. POM.XML – Maven Konfiguration
```xml
<packaging>war</packaging>

<build>
  <plugins>
    <plugin>
      <groupId>org.apache.maven.plugins</groupId>
      <artifactId>maven-war-plugin</artifactId>
      <version>3.3.2</version>
      <configuration>
        <failOnMissingWebXml>false</failOnMissingWebXml>
      </configuration>
    </plugin>
  </plugins>
</build>
```

**Beispielhafte Abhängigkeiten:**
```xml
<dependencies>
  <dependency>
    <groupId>javax.ws.rs</groupId>
    <artifactId>javax.ws.rs-api</artifactId>
    <version>2.1.1</version>
    <scope>provided</scope>
  </dependency>
  <dependency>
    <groupId>javax.faces</groupId>
    <artifactId>javax.faces-api</artifactId>
    <version>2.3</version>
    <scope>provided</scope>
  </dependency>
</dependencies>
```

---

### ✅ 3. Richtige Abhängigkeiten setzen
- `provided`: Wird vom Application Server (WildFly) bereitgestellt.
- `compile`: Muss in WAR enthalten sein.

---

### ✅ 4. Deployment Descriptor (`web.xml`)
```xml
<web-app xmlns="http://java.sun.com/xml/ns/javaee"
         version="3.1">
  <display-name>My WebApp</display-name>
</web-app>
```

---

### ✅ 5. `jboss-web.xml`
```xml
<jboss-web>
  <context-root>/meineApp</context-root>
</jboss-web>
```

---

### ✅ 6. Build & Deployment
```sh
mvn clean package
cp target/my-webapp.war $WILDFLY_HOME/standalone/deployments/
```

---

### ✅ 7. WildFly-spezifische Konfiguration
- `persistence.xml` → `src/main/resources/META-INF/`
- DataSources über `standalone.xml`

---

## Frage

> Werden die Abhaengigkeiten, die mit compile markiert sind in dem WEB-INF/lib Verzeichnis kopiert?

## Antwort

Ja, **Abhängigkeiten mit `compile`-Scope** werden in das **`WEB-INF/lib`** Verzeichnis kopiert.

| Scope     | In `WEB-INF/lib`? | Erklärung |
|-----------|-------------------|-----------|
| compile   | ✅ Ja              | Standard-Scope |
| provided  | ❌ Nein            | Wird vom Server bereitgestellt |
| runtime   | ✅ Ja              | Nur zur Laufzeit benötigt |
| test      | ❌ Nein            | Nur für Tests |

**Beispiel:**
```xml
<dependency>
  <groupId>org.apache.commons</groupId>
  <artifactId>commons-lang3</artifactId>
  <version>3.12.0</version>
  <scope>compile</scope>
</dependency>
```

**Prüfen mit:**
```sh
mvn dependency:tree
jar tf target/my-webapp.war | grep WEB-INF/lib
```

---

## Frage

> Wie kann das sein, das im WEB-INF/lib Verzeichnis zwei JAR Dateien sind, wobie die eine Datei keine Versionsendung hat und die andere ja. Beispiel: Sei die erste JAR  Datei asdf-qwer.jar und die zweite asdf-qwer-2.1.0.jar

## Antwort

Das kann mehrere Ursachen haben:

---

### 🔍 Mögliche Gründe

#### 1️⃣ Doppelte Version in `pom.xml`
```xml
<dependency>
  <groupId>com.example</groupId>
  <artifactId>asdf-qwer</artifactId>
  <version>2.1.0</version>
</dependency>
<dependency>
  <groupId>com.example</groupId>
  <artifactId>asdf-qwer</artifactId>
  <version>1.9.0</version>
</dependency>
```
**Lösung:**  
Verwende `mvn dependency:tree` und bereinige doppelte Einträge.

---

#### 2️⃣ Manuell hinzugefügte JAR in `src/main/webapp/WEB-INF/lib`
**Lösung:**  
```sh
rm src/main/webapp/WEB-INF/lib/asdf-qwer.jar
```

---

#### 3️⃣ Maven-Plugin erzeugt JAR ohne Version (z. B. `maven-shade-plugin`)
**Lösung:**  
Überprüfe deine `pom.xml` auf Plugins wie:
```xml
<plugin>
  <groupId>org.apache.maven.plugins</groupId>
  <artifactId>maven-shade-plugin</artifactId>
</plugin>
```

---

#### 4️⃣ Multi-Module-Projekt erzeugt doppelte Artefakte
**Lösung:**  
Korrigiere `artifactId` und `version` in `pom.xml` deiner Module.

---

### ✅ Zusammenfassung
- Prüfe `dependency:tree`
- Entferne manuell kopierte JARs
- Vermeide Mehrfachversionen
- Überprüfe Build-Plugins
