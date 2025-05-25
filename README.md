# SuperCity - Simulator al vieții cotidiene din mediul urban
### Proiectul urmărește simularea unor elemente uzuale din viața de zi cu zi a unui orășean.
#### Jucatorii trebuie să își mențină statisticile cât mai sus, având ocazia să interacționeze cu diverse locații care îi pot ajuta în acest sens.
#### Pentru transportul prin oraș acestora li se pune la dispoziție o rețea generoasă de transport în comun, precum și cel mai eficient serviciu de taxi-uri din lumea simulatoarelor scrise in limbajul C++.
#### O lume palpitantă te așteaptă în acest joc fabulaçao care transformă rutina cronofagă și stresantă a orașului tău într-un mediu ludic și relaxant precum o pajiște montană!
#
## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

1. Pasul de configurare
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# sau ./scripts/cmake.sh configure
```

Sau pe Windows cu GCC:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
# sau ./scripts/cmake.sh configure -g Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.


2. Pasul de compilare
```sh
cmake --build build --config Debug --parallel 6
# sau ./scripts/cmake.sh build
```

Cu opțiunea `parallel` specificăm numărul de fișiere compilate în paralel.


3. Pasul de instalare (opțional)
```sh
cmake --install build --config Debug --prefix install_dir
# sau ./scripts/cmake.sh install
```

Vezi și [`scripts/cmake.sh`](scripts/cmake.sh).

Observație: folderele `build/` și `install_dir/` sunt adăugate în fișierul `.gitignore` deoarece
conțin fișiere generate și nu ne ajută să le versionăm.
