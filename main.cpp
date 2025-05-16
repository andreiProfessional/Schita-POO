#include "Meniu.h"
#include "CuloriText.h"

int main() {
    Meniu &Meniu = Meniu::acceseazaSingleton();
    Meniu.meniuInceput();

    return 0;
}