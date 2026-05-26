import os

wiki_dir = 'wiki'
files = [f for f in os.listdir(wiki_dir) if f.endswith('.md')]
keys = {f[:-3] for f in files}

# Extended mapping based on Schmidt's Table of Contents and pdftotext analysis
mapping = {
    'Kapitel 01 (Mengensysteme)': [
        'topologie_definition', 'topologie_durchschnitt_satz', 'topologie_erzeugte_definition',
        'sigma_algebra_definition', 'sigma_algebra_durchschnitt_satz', 'sigma_algebra_erzeugte_definition',
        'borelsche_sigma_algebra_definition', 'dynkin_system_definition', 'dynkin_system_durchschnitt_satz',
        'dynkin_system_erzeugtes_definition', 'schnittstabiles_mengensystem_definition',
        'sigma_algebra_dynkin_system_charakterisierung', 'sigma_algebra_dynkin_system_erzeuger_satz',
        'halbring_definition', 'ring_definition', 'ring_erzeugter_halbring_satz',
        'limes_inferior_superior_mengen'
    ],
    'Kapitel 02 (Topologische & Messbare Räume)': [
        'urbild_eigenschaften_lemma', 'urbild_mengensystem_definition', 'topologischer_raum_definition',
        'stetigkeit_erzeuger_satz', 'messbarer_raum_definition', 'messbarkeit_erzeuger_satz',
        'stetigkeit_impliziert_messbarkeit_satz'
    ],
    'Kapitel 03 (Produkträume)': [
        'produkt_mengen_projektion_definition', 'produkttopologie_definition', 'produkt_sigma_algebra_definition',
        'stetigkeit_produkt_raum_satz', 'produkttopologie_erzeuger_satz', 'produkttopologie_endlich_satz',
        'messbarkeit_produkt_raum_satz', 'produkt_sigma_algebra_erzeuger_satz', 'produkt_sigma_algebra_abzaehlbar_satz'
    ],
    'Kapitel 04 (Mengenfunktionen)': [
        'mengenfunktion_definition', 'additivitaet_mengenfunktion_definition', 'inhalt_definition',
        'additiv_impliziert_endlich_additiv_ring_satz', 'inhalt_fortsetzung_satz', 'sigma_additivitaet_mass_definition',
        'stetigkeit_mengenfunktionen_definition', 'sigma_additivitaet_stetigkeit_unten_satz',
        'stetigkeit_unten_impliziert_oben_lemma', 'sigma_additivitaet_stetigkeit_aequivalenz_satz',
        'signiertes_mass_definition', 'jordan_zerlegung_satz', 'hahn_zerlegung_satz'
    ],
    'Kapitel 05 (Fortsetzung von Maßen)': [
        'mass_eindeutigkeitssatz', 'aeusseres_mass_definition', 'messbarkeit_aeusseres_mass_definition',
        'caratheodory_fortsetzungssatz', 'mass_fortsetzung_satz', 'mass_approximationssatz',
        'lebesgue_mass_definition'
    ]
}

for chapter, required_keys in mapping.items():
    print(f"--- {chapter} ---")
    missing = [k for k in required_keys if k not in keys]
    if missing:
        print(f"  Missing: {', '.join(missing)}")
    else:
        print("  Status: Complete")
