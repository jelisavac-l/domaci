# Domaći zadaci iz stručnih predmeta
Luka Jelisavac 2022/0554
## Principi Programiranja: Seminarski rad 📝
### Uputstvo za instalaciju razvojnog okruženja
1. Instalirati MinGW-ov C/C++ kompajler
2. Instalirati odgovarajuću `SDL2` biblioteku, namenjenu za C/C++ i MinGW kompajler
3. Locirati folder `.\i686-w64-mingw32`, u daljem tekstu folder (uz predpostavku da se kod kompajlira za 32-bitne sisteme)
4. U folderu locirati podfolder `lib` i kopirati sve `.a` fajlove u `MinGW\lib` folder
5. U folderu locirati podfolder `include` i kopirati podfolder `SDL` u `MinGW\include` folder
6. U folderu locirati podfolder `bin` i kopirati `SDL2.dll` u direktorijum u kojem će se nalaziti izvršivi (`.exe`) fajl

Kao editor teksta najbolje je koristiti VS Code, mada alternative poput Notepad++a, Vim-a i Nano-a su potpuno legitimne opcije.

