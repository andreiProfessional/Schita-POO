#include "Meniu.h"

int main() {
    Meniu &meniu = Meniu::acceseazaSingleton();
    meniu.run();

    return 0;
}
