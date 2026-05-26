# Wiki Log

## 2026-05-26
- Ingestion of Schmidt, "Maß und Wahrscheinlichkeit", Kapitel 10 (Wahrscheinlichkeitsräume).
- Added following entries:
    - `wahrscheinlichkeitsraum_definition` (def)
    - `diskreter_wahrscheinlichkeitsraum_definition` (def)
    - `symmetrischer_wahrscheinlichkeitsraum_definition` (def)
    - `projektive_familie_wahrscheinlichkeitsmasse_definition` (def)
    - `andersen_jessen_satz` (satz)

- Ingestion of Schmidt, "Maß und Wahrscheinlichkeit", Kapitel 09 (Berechnung des Lebesgue-Integrals).
- Added following entries:
    - `integral_induziertes_mass_satz` (satz)
    - `mass_mit_dichte_definition` (def)
    - `dichte_kettenregel_satz` (satz)
    - `mass_mit_dichte_eindeutigkeit_satz` (satz)
    - `absolutstetigkeit_mass_definition` (def)
    - `radon_nikodym_satz` (satz)
    - `singulaeres_mass_definition` (def)
    - `lebesgue_zerlegung_satz` (satz)
    - `substitutionsregel_mass_satz` (satz)
    - `produkt_mass_definition` (def)
    - `fubini_satz` (satz)

- Ingestion of Schmidt, "Maß und Wahrscheinlichkeit", Kapitel 08 (Lebesgue-Integral).
- Added following entries:
    - `einfache_funktion_definition` (def)
    - `lebesgue_integral_einfach_definition` (def)
    - `lebesgue_integral_einfach_linearitaet_satz` (satz)
    - `lebesgue_integral_positiv_definition` (def)
    - `monotone_konvergenz_satz` (satz)
    - `markov_ungleichung_satz` (satz)
    - `integral_nullmenge_lemma` (lemma)
    - `fatou_lemma` (satz)
    - `integrierbarkeit_definition` (def)
    - `integral_linearitaet_monotonie_satz` (satz)
    - `majorisierte_konvergenz_satz` (satz)

## 2026-05-25
- Ingestion of Schmidt, "Maß und Wahrscheinlichkeit", Kapitel 07 (Messbare Funktionen).
- Added following entries:
    - `numerische_funktion_definition` (def)
    - `messbarkeit_numerische_funktion_charakterisierung_satz` (satz)
    - `messbarkeit_funktionenfolgen_satz` (satz)
    - `messbarkeit_approximationssatz_positiv_satz` (satz)
    - `l0_raum_definition` (def)
    - `l_unendlich_raum_definition` (def)
    - `konvergenz_arten_definition` (def)

## 2026-05-25
- Ingestion of Schmidt, "Maß und Wahrscheinlichkeit", Kapitel 06 (Transformation von Maßen).
- Added following entries:
    - `bildmass_definition` (def)
    - `translationsinvarianz_mass_definition` (def)
    - `lebesgue_mass_charakterisierung_satz` (satz)
    - `lebesgue_mass_transformation_linear_satz` (satz)

## 2026-05-25
- Ingestion of Schmidt, "Maß und Wahrscheinlichkeit", Kapitel 05 (Fortsetzung von Maßen).
- Added following entries:
    - `mass_eindeutigkeitssatz` (satz)
    - `aeusseres_mass_definition` (def)
    - `messbarkeit_aeusseres_mass_definition` (def)
    - `caratheodory_fortsetzungssatz` (satz)
    - `lebesgue_mass_definition` (def)

## 2026-05-03
- Ingestion of Schmidt, "Maß und Wahrscheinlichkeit", Kapitel 04.
- Added following entries:
    - `mengenfunktion_definition` (def)
    - `additivitaet_mengenfunktion_definition` (def)
    - `inhalt_definition` (def)
    - `additiv_impliziert_endlich_additiv_ring_satz` (satz)
    - `inhalt_fortsetzung_satz` (satz)
    - `monotonie_subadditivitaet_definition` (def)
    - `inhalt_monoton_subadditiv_lemma` (lemma)
    - `sigma_additivitaet_mass_definition` (def)
    - `mass_fortsetzung_satz` (satz)
    - `stetigkeit_mengenfunktionen_definition` (def)
    - `sigma_additivitaet_stetigkeit_unten_satz` (satz)
    - `stetigkeit_unten_impliziert_oben_lemma` (lemma)
    - `sigma_additivitaet_stetigkeit_aequivalenz_satz` (satz)
    - `mass_sigma_subadditiv_lemma` (lemma)
    - `signiertes_mass_definition` (def)
    - `jordan_zerlegung_satz` (satz)
    - `hahn_zerlegung_satz` (satz)

## 2026-05-01
- **Exporter-Infrastruktur**:
    - Automatische Gliederung des LaTeX-Exports mittels `\section` (Axiome, Definitionen, Sätze).
    - Implementierung von `\autoref` für kontextsensitive Nummerierung (z.B. "Definition 1.1").
    - Integration von `hyperref` für klickbare Links im PDF (Farbe: blau).
    - Rekursive Abhängigkeitsauflösung: Exporter zieht automatisch alle im Text referenzierten Keys in den Export ein.
- **Automatisierung**:
    - Refactoring des Python-Tools: Umzug von `update_refs.py` und `mapping.txt` nach `tools/`.
    - Erstellung einer Dokumentation (`tools/README.md`) und Aktualisierung der technischen Spezifikation (`docs/specs.md`).
- **Content-Vernetzung**:
    - Systematische Überarbeitung aller Wiki-Dateien (Bulk-Update).
    - Einführung der Syntax `[[key|text]]` für lesbare Querverweise im Fließtext.
    - Vernetzung der Kernbereiche Maßtheorie und Analysis.

## 2026-04-30
- Initial ingestion of Schmidt, "Maß und Wahrscheinlichkeit", Kapitel 01.
- Added following entries:
    - `limes_inferior_superior_mengen` (def)
    - `topologie_definition` (def)
    - `topologie_durchschnitt_satz` (satz)
    - `topologie_erzeugte_definition` (def)
    - `sigma_algebra_definition` (def)
    - `sigma_algebra_eigenschaften_lemma` (lemma)
    - `sigma_algebra_durchschnitt_satz` (satz)
    - `sigma_algebra_erzeugte_definition` (def)
    - `borelsche_sigma_algebra_definition` (def)
    - `dynkin_system_definition` (def)
    - `dynkin_system_durchschnitt_satz` (satz)
    - `dynkin_system_erzeugtes_definition` (def)
    - `schnittstabiles_mengensystem_definition` (def)
    - `sigma_algebra_dynkin_system_charakterisierung` (satz)
    - `sigma_algebra_dynkin_system_erzeuger_satz` (satz)
    - `halbring_definition` (def)
    - `ring_definition` (def)
    - `ring_erzeugter_halbring_satz` (satz)

## 2026-04-30
- Ingestion of Schmidt, "Maß und Wahrscheinlichkeit", Kapitel 02.
- Added following entries:
    - `urbild_eigenschaften_lemma` (lemma)
    - `urbild_mengensystem_definition` (def)
    - `topologischer_raum_definition` (def)
    - `stetigkeit_erzeuger_satz` (satz)
    - `messbarer_raum_definition` (def)
    - `messbarkeit_erzeuger_satz` (satz)
    - `stetigkeit_impliziert_messbarkeit_satz` (satz)
    - `messbarkeit_monotone_funktionen_beispiel` (info)

## 2026-04-30
- Ingestion of Schmidt, "Maß und Wahrscheinlichkeit", Kapitel 03.
- Added following entries:
    - `produkt_mengen_projektion_definition` (def)
    - `produkttopologie_definition` (def)
    - `produkt_sigma_algebra_definition` (def)
    - `stetigkeit_produkt_raum_satz` (satz)
    - `produkttopologie_erzeuger_satz` (satz)
    - `produkttopologie_endlich_satz` (satz)
    - `messbarkeit_produkt_raum_satz` (satz)
    - `produkt_sigma_algebra_erzeuger_satz` (satz)
    - `produkt_sigma_algebra_abzaehlbar_satz` (satz)
