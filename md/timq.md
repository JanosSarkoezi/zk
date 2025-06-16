# EJB und CDI Integration

## Frage

> Wenn ich mit javax.ejb ein Restservice erstelle, kann ich dann in der Klasse mit @Inject arbeiten?

## Antwort

Ja, du kannst in einer Klasse, die als REST-Service mit JAX-RS implementiert
wird, die CDI-Annotation @Inject verwenden, um Abhängigkeiten einzufügen.
Allerdings gibt es einige wichtige Voraussetzungen und potenzielle Stolpersteine
zu beachten:

## Voraussetzungen

1. CDI muss aktiviert sein: Damit @Inject funktioniert, muss CDI (Contexts and
   Dependency Injection) in deinem Projekt korrekt eingerichtet sein. Dies
   erfordert eine CDI-kompatible Umgebung und eine beans.xml-Datei im
   WEB-INF-Verzeichnis deiner WAR-Datei oder im entsprechenden Modul. Eine leere
   Datei reicht aus:
```xml
<beans xmlns="http://xmlns.jcp.org/xml/ns/javaee"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee
                           http://xmlns.jcp.org/xml/ns/javaee/beans_1_1.xsd"
       version="1.1">
</beans>
```

2. REST-Klasse muss CDI-konform sein: Deine REST-Klasse muss von CDI verwaltet
   werden. Eine JAX-RS-Resource-Klasse wird von CDI verwaltet, wenn:

- CDI aktiviert ist, und
- Die Klasse entweder eine CDI-Bean ist (z. B. @ApplicationScoped, 
  @RequestScoped, oder einfach keine Scopes definiert sind) oder
  standardmäßig ein REST-Service ist.

3. EJB und CDI Interoperabilität: Wenn du eine EJB mit JAX-RS kombinierst 
   (z. B. @Stateless), ist diese automatisch CDI-fähig, und @Inject sollte 
   problemlos funktionieren.
