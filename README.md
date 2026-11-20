# 💻 pro2-fib · Programació 2 (C++)

> **Estructures de dades, programació orientada a objectes i disseny modular en C++ de l'assignatura Programació 2 (PRO2) · Grau en Enginyeria Informàtica (UPC · FIB).**

[![Language](https://img.shields.io/badge/Language-C%2B%2B17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org)
[![University](https://img.shields.io/badge/UPC-FIB-0070BA?style=for-the-badge)](https://www.fib.upc.edu)
[![Platform](https://img.shields.io/badge/Judge-Jutge.org-FFA116?style=for-the-badge)](https://jutge.org)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)](LICENSE)

---

## 📌 Descripció

Aquest repositori recull les implementacions, sessions de laboratori, el projecte pràctic de curs i més de **70 resolucions de problemes oficials de Jutge.org** desenvolupats durant el curs de **Programació 2 (PRO2)** a la Facultat d'Informàtica de Barcelona (FIB · UPC).

El focus principal del repositori se centra en:
- **Programació Orientada a Objectes i Modularitat:** Disseny modular, encapsulació d'estats, interfícies (`.hh`), implementacions (`.cc`) i patrons de disseny.
- **Gestió de Memòria i Punteros:** Memòria dinàmica, constructors de còpia, destructors recursius i prevenció de fuites de memòria (*memory leaks*).
- **Tipus Abstractes de Dades (TADs):** Implementació interna i ús avançat d'estructures de dades lineals (piles `Stack`, cues `Queue`, llistes doblement encadenades `List`, diccionaris `Map` i conjunts `Set`) i arborescents (`BinTree`, arbres generals, arbres binaris de cerca).
- **Projecte Pràctic de Laboratori:** Disseny i desenvolupament d'un sistema complet de gestió de xarxa de bicicletes públiques (*Bicing Bifurcat*) amb múltiples mòduls i Makefile automatitzat.

---

## 📂 Organització del Repositori

```text
pro2-fib/
├── 0- Repàs/                              # Sessions inicials de repàs d'estructures
├── SESSIONS/                              # Sessions setmanals de laboratori
├── evaluate/                              # Utilitats i proves d'avaluació
└── Jutge/                                 # Més de 70 resolucions de problemes Jutge.org
    ├── BinTree (1), (2), (3)/             # Arbres binaris, recorreguts i manipulació
    ├── Classe List/                       # Operacions amb llistes encadenades
    ├── Classe Queue/                      # Cues i cues de prioritat
    ├── Classe Stack/                      # Piles i avaluació d'expressions
    ├── Classes Arbre/                     # Arbres generals i propietats estructurals
    ├── List & Map/                        # Combinació de llistes i mapes
    ├── Map & Set/                         # Diccionaris i conjunts associatius
    ├── Modularitat (1), (2)/              # Disseny de TADs i classes col·laboratives
    ├── Pair & Vector/                     # Manipulació de vectors de parells
    ├── Pràctica/                          # Codi font complet de la Pràctica Bicing
    ├── Sessió 1, Sessió 2/                # Problemes d'avaluació de sessions
    └── Stack & Queue/                     # Piles i cues combinades
```

---

## 🛠️ Compilació i Execució

```bash
# Compilació estàndard C++17
g++ -O2 -std=c++17 -Wall -Wextra nom_problema.cc -o nom_problema

# Execució de la pràctica amb Makefile
cd "Jutge/Pràctica/X42354_Practica_Tardor_2023"
make
./program.exe < jp_public.in
```

---

## 📄 Llicència

Distribuït sota la llicència MIT.
