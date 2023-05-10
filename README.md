# Domaći zadaci iz stručnih predmeta
Luka Jelisavac 2022/0554
## Principi Programiranja: Seminarski rad 📝
### O Projektu 🔰
Rezultat projekta - edukativni softver za prikaz geometrijskih figura (dvodimenzionih oblika) i upoznavanje korisnika sa njihovim svojstvima kao i primenom teorema za izračunavanje određenih dužina tih figura.

#### Tehnički zahtevi 📜
* Kod pisan u programskom jeziku C, koji iscrtava geometrijske figure, izračunava dužine i objašnjava postupak, kao i vrši operacije translacije i rotacije nad njima.
* Dokumentacija pisana ćiriličnim pismom, na papiru formata A4 fontovima Times New Roman 12 (za paragrafe) i Consolas 12 (za izvorni kod). Margina sa leve strane 2+1, a ostale po 2 cm.

### Uputstvo za instalaciju razvojnog okruženja 🔨
1. Instalirati MinGW-ov C/C++ kompajler
2. Instalirati odgovarajuću `SDL2` biblioteku, namenjenu za C/C++ i MinGW kompajler
3. Locirati folder `.\i686-w64-mingw32`, u daljem tekstu folder (uz predpostavku da se kod kompajlira za 32-bitne sisteme)
4. U folderu locirati podfolder `lib` i kopirati sve `.a` fajlove u `MinGW\lib` folder
5. U folderu locirati podfolder `include` i kopirati podfolder `SDL` u `MinGW\include` folder
6. U folderu locirati podfolder `bin` i kopirati `SDL2.dll` u direktorijum u kojem će se nalaziti izvršivi (`.exe`) fajl

Kao editor teksta najbolje je koristiti VS Code, mada alternative poput Notepad++a, Vim-a i Nano-a su potpuno legitimne opcije.
Kontrolna komanda za kompajliranje koda: 
`g++ -o test.exe test.c -lmingw32 -lSDL2main -lSDL2 my.res`
