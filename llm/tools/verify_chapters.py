import os
import re

wiki_dir = 'wiki'
files = [f for f in os.listdir(wiki_dir) if f.endswith('.md') and f not in ['index.md', 'log.md']]

found_keys = set()
for f in files:
    found_keys.add(f[:-3])

chapters = {
    'Kapitel 01': [
        'topologie_definition', 'topologie_durchschnitt_satz', 'topologie_erzeugte_definition',
        'sigma_algebra_definition', 'sigma_algebra_durchschnitt_satz', 'sigma_algebra_erzeugte_definition',
        'borelsche_sigma_algebra_definition', 'dynkin_system_definition', 'dynkin_system_durchschnitt_satz',
        'dynkin_system_erzeugtes_definition', 'schnittstabiles_mengensystem_definition',
        'sigma_algebra_dynkin_system_charakterisierung', 'sigma_algebra_dynkin_system_erzeuger_satz',
        'halbring_definition', 'ring_definition', 'ring_erzeugter_halbring_satz'
    ],
    'Kapitel 02': [
        'urbild_eigenschaften_lemma', 'urbild_mengensystem_definition', 'topologischer_raum_definition',
        'stetigkeit_erzeuger_satz', 'messbarer_raum_definition', 'messbarkeit_erzeuger_satz',
        'stetigkeit_impliziert_messbarkeit_satz'
    ],
    'Kapitel 03': [
        'produkt_mengen_projektion_definition', 'produkttopologie_definition', 'produkt_sigma_algebra_definition',
        'stetigkeit_produkt_raum_satz', 'produkttopologie_erzeuger_satz', 'produkttopologie_endlich_satz',
        'messbarkeit_produkt_raum_satz', 'produkt_sigma_algebra_erzeuger_satz', 'produkt_sigma_algebra_abzaehlbar_satz'
    ],
    'Kapitel 04': [
        'mengenfunktion_definition', 'additivitaet_mengenfunktion_definition', 'inhalt_definition',
        'additiv_impliziert_endlich_additiv_ring_satz', 'inhalt_fortsetzung_satz', 'sigma_additivitaet_mass_definition',
        'stetigkeit_mengenfunktionen_definition', 'sigma_additivitaet_stetigkeit_unten_satz',
        'stetigkeit_unten_impliziert_oben_lemma', 'sigma_additivitaet_stetigkeit_aequivalenz_satz',
        'signiertes_mass_definition', 'jordan_zerlegung_satz', 'hahn_zerlegung_satz'
    ]
}

for ch, keys in chapters.items():
    print(f"--- {ch} ---")
    missing = []
    for k in keys:
        if k not in found_keys:
            missing.append(k)
    if missing:
        print(f"Missing: {', '.join(missing)}")
    else:
        print("All key concepts found.")
