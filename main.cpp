#include "Meniu.h"

int main() {
    Meniu &Meniu = Meniu::acceseazaSingleton();
    Meniu.meniuInceput();

    return 0;
}