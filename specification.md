# Terminál alapú fájlkezelő

## 1. A projekt áttekintése

A projekt célja egy **C programozási nyelven megvalósított, terminál alapú fájlkezelő alkalmazás** fejlesztése.

Az alkalmazás interaktív felületet biztosít a fájlrendszer böngészéséhez és kezeléséhez. Támogatja többek között a könyvtárakban való navigációt, fájlok és könyvtárak létrehozását, törlését, másolását, áthelyezését és átnevezését, valamint fájlok keresését és részletes információinak megjelenítését.

---

# 2. Fő célok

A kész alkalmazás lehetővé teszi a felhasználó számára, hogy:

1. Navigáljon a fájlrendszerben
2. Megtekintse a fájlokat és könyvtárakat
3. Fájlokat és könyvtárakat hozzon létre és töröljön
4. Fájlokat és könyvtárakat másoljon és helyezzen át
5. Fájlokat és könyvtárakat átnevezzen
6. Részletes információkat jelenítsen meg a fájlokról
7. Fájlokat keressen
8. Rendezze a könyvtár tartalmát
9. Szöveges fájlok tartalmát megtekintse
10. A fájlrendszerrel kapcsolatos hibákat megfelelően kezelje
11. Interaktív terminálos felületen keresztül használja az alkalmazást

---

# 3. Felhasználói felület

A program terminálban fut.

Kétféle felület valósítható meg.

## 3.1 Parancsalapú felület

Például:

```text
> pwd
/home/user

> ls

Documents/
Downloads/
Projects/
main.c
README.txt

> cd Projects

> mkdir Test

> cp main.c Test/

> mv README.txt Test/

> info main.c
```

## 3.2 Interaktív felület

Kiegészítő funkcióként az alkalmazás megvalósíthat egy billentyűzettel vezérelhető felületet is:

```text
┌────────────────────────────────────────────────────┐
│ /home/user/Projects                                │
├────────────────────────────────────────────────────┤
│ > C                                                │
│   Python                                           │
│   README.md                                        │
│   main.c                                           │
│                                                    │
├────────────────────────────────────────────────────┤
│ ↑ ↓ Navigáció  Enter Megnyitás  D Törlés Q Kilépés │
└────────────────────────────────────────────────────┘
```

---

# 4. Funkcionális követelmények

## 4.1 Könyvtárak közötti navigáció

Az alkalmazásnak támogatnia kell a fájlrendszerben történő navigációt.

Szükséges parancsok:

```text
pwd
ls
cd <könyvtár>
cd ..
cd ~
```

A programnak megfelelően kell kezelnie:

- Abszolút elérési utakat
- Relatív elérési utakat
- `.` és `..` használatát
- Szóközt tartalmazó elérési utakat
- Érvénytelen elérési utakat
- Jogosultsági hibákat

---

## 4.2 Könyvtár tartalmának megjelenítése

A felhasználónak lehetőséget kell biztosítani az aktuális könyvtár tartalmának listázására.

A megjelenítésnek legalább az alábbiakat kell tartalmaznia:

- Név
- Fájl/könyvtár típus
- Fájl mérete

Példa:

```text
TÍPUS      MÉRET      NÉV
KÖNYVTÁR   -          Documents
KÖNYVTÁR   -          Projects
FÁJL       4832       main.c
FÁJL       15284      README.txt
```

A programnak meg kell tudnia különböztetni a könyvtárakat a normál fájloktól.

---

## 4.3 Fájlok és könyvtárak létrehozása

A felhasználó számára lehetővé kell tenni:

```text
mkdir <könyvtár>
touch <fájl>
```

használatát.

A programnak hibát kell jeleznie, ha:

- Az adott elem már létezik
- A szülőkönyvtár nem létezik
- A felhasználónak nincs megfelelő jogosultsága

---

## 4.4 Fájlok és könyvtárak törlése

A programnak lehetővé kell tennie fájlok és könyvtárak törlését.

Például:

```text
rm file.txt
rmdir Test
```

A programnak lehetőség szerint meg kell akadályoznia a véletlen törlést, például megerősítés bekérésével.

---

## 4.5 Fájlok másolása

A programnak támogatnia kell fájlok másolását.

Például:

```text
cp source.txt destination.txt
cp source.txt Documents/
```

A megvalósításnak:

- Meg kell nyitnia a forrásfájlt
- Létre kell hoznia vagy meg kell nyitnia a célfájlt
- Át kell másolnia annak tartalmát
- Kezelnie kell az esetleges hibákat
- Megfelelően le kell zárnia a megnyitott fájlokat


---

## 4.6 Fájlok áthelyezése

A programnak támogatnia kell fájlok és könyvtárak áthelyezését.

Például:

```text
mv file.txt Documents/
```

---

## 4.7 Átnevezés

A programnak támogatnia kell fájlok és könyvtárak átnevezését.

Például:

```text
rename old_name.txt new_name.txt
```

---

# 5. Fájlokkal kapcsolatos információk

A felhasználónak lehetőséget kell biztosítani egy fájl részletes információinak lekérdezésére.

Példa:

```text
> info main.c

Név:          main.c
Típus:        Normál fájl
Méret:        4832 bájt
Módosítva:    2026-10-07 18:42
Jogosultság:  rw-r--r--
```

Az információk lehetőség szerint tartalmazzák:

- Fájl neve
- Teljes elérési út
- Fájl típusa
- Mérete
- Utolsó módosítás időpontja
- Jogosultságok

---

# 6. Keresés

Az alkalmazásnak támogatnia kell a fájlok rekurzív keresését.

Például:

```text
> find report
```

Lehetséges eredmény:

```text
/home/user/Documents/report.pdf
/home/user/University/report.c
/home/user/Projects/report_final.pdf
```

A keresésnek rekurzívan végig kell járnia a könyvtárakat.

A felhasználónak legalább fájlnév alapján kell tudnia keresni.

Opcionális keresési paraméterek:

```text
find report --type file
find report --type directory
find report --extension pdf
```

---

# 7. Rendezés

A könyvtár tartalmának rendezhetőnek kell lennie.

Legalább az alábbi rendezési szempontokat kell támogatni:

```text
sort name
sort size
sort modified
sort type
```

Az eredménynek növekvő és csökkenő sorrendben is rendezhetőnek kell lennie.

Példa:

```text
sort size desc
```

---

# 8. Hibakezelés

Az alkalmazásnak megfelelően kell kezelnie a hibákat, és nem szabad összeomlania.

Példák:

- A fájl nem létezik
- A könyvtár nem létezik
- Nincs megfelelő jogosultság
- Érvénytelen parancs
- Érvénytelen argumentum
- Már létező fájl felülírása
- Elfogyott a memória
- A fájl nem nyitható meg
- A könyvtár nem hozható létre
- Érvénytelen elérési út

Példa:

```text
> cp nonexistent.txt test.txt

Hiba: A forrásfájl nem nyitható meg:
nonexistent.txt

Ok: A fájl nem létezik
```

Helytelen felhasználói bemenet nem eredményezhet nem definiált működést vagy szegmentációs hibát.

---