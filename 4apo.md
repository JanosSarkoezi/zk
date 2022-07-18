# BSN-7993 Testfälle

## Vorbereigungen

Bei der Anlage des Vertrages des Produktes '20015 DFV-ZahnSchutz Exklusiv V02' muss die Zahlart Lastschft angelegt werden. Dafür kann die IBAN DE02120300000000202051 genommen werden.
Nennen wir den Vertrag V.

Es müssen zwei Schäden für den V angelegt werden. Wenn die die Schäden mit S1 und S2 abkürzen, dann sollte folgendes beachtet werden:
- Der V sollte 1,5 Monate in der Vergangenheit angelegt werden.
- Der S1 sollte 1 Monat in der Vergangenheit angelegt werden.
-- Teilprodukt: 'TP Zahnprophylaxe ZahnSchutz Exklusiv V2'
-- Leistungsart: 'Prophylaxemaßnahme'
-- Ein Anspruch von 99,97 Euro muss ausgezahl werden.
--- Forderung: 99.97
--- Zahlbetrag: 99.97
--- Verwendungszweck: test
--- Leistungskod: Sollte ein (E) hinten haben.
--- Zahlungsart: Überweisung
- Der S2 wird über ein Schadenimport erstellt.
-- Die MainPersonId kann über den 4GB aus der URL kopiert werden.
-- Die PaymentMethodId kann auf der Vertragsseite im imput field vom Typ hidden über dem Feld 'Allgemein' ausgelesen werden. :)
-- Der Anspruch kann 10 Euro sein (sollte größer sein als 0,05 Euro). 
-- Das Meldedatum: Heute
-- Leistungsdatum von: Heute
-- Leistungsdatum bis: Heute
-- Schadendaten (AttributeId=Value): 8386=abc
-- Leistungsbest. (AttributeId=Value): 8386=abc
-- Anspruch-Betrag: 10

## Testfall

Angenommen es gibt einen aktiven V von dem Vermittler Emil Pelle.
Wenn der Prozess Beitrag angehalten wurde
Und ein S1 angelegt und mit dem genannte Betrag ein Anspruch ausgezahl wurde
Und ein S2 über den Schadenimport erstellt wurde
Und das Ereignis 'Ablehnung Leistungsgrenze erschöpft' gefeuert ist
Und ein Schreiben SCHADEN_ABLEHNUNGSSCHREIBEN("05_02", "Ablehnungsschreiben"), // C027, C028 erstellt wurde
Und der S2 sich beendet hat
Dann ist alles OK.

## Referenzen
[BSN-7993](14a5)

## Literatur
https://ticket.intervista-ag.de/browse/BSN-7993
