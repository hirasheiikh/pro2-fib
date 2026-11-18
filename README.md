# 🧩 pro2-fib · Programació 2 (C++ Orientat a Objectes)

> **Estructures de dades clàssiques, disseny modular, gestió de memòria dinàmica i pràctica de simulació en C++ de l'assignatura Programació 2 (PRO2) del Grau en Enginyeria Informàtica a la Facultat d'Informàtica de Barcelona (UPC · FIB).**

[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org)
[![University](https://img.shields.io/badge/UPC-FIB-0070BA?style=for-the-badge)](https://www.fib.upc.edu)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)](LICENSE)

---

## 🚲 Pràctica Principal: Simulador Bicing en C++
Implementació completa d'un sistema modular de gestió i distribució de bicicletes i estacions en xarxa:
- **Arquitectura de Classes:** `Bici`, `Estacio`, `Conj_bicis`, `Conj_estacions`, `BinTree`.
- **Estructures d'Arbre Binari (`BinTree`):** Distribució i redistribució òptima de recursos per recorreguts en arbre.
- **Modularitat:** Separació estricta entre especificació (`.hh`), implementació (`.cc`) i programa principal (`program.cc`).
- **Eficiència:** Gestió de memòria dinàmica amb complexitats temporals optimitzades.

---

## 📚 Tipus Abstractes de Dades (TAD)
- **Estructures Lineals:** Implementació de llistes enllaçades (`List`), piles (`Stack`) i cues (`Queue`).
- **Diccionaris i Mapatges:** Ús i disseny d'associacions clau-valor (`Map`).
- **Estructures Arborescents:** Arbres binaris, arbres generals (N-aris) i recorreguts (preordre, inordre, postordre).

---

## 🛠️ Compilació amb Makefile

```bash
cd PRÀCTICA
make
./program.exe < jp_public.in > out.txt
```
