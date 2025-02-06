#include "Persona.cpp"

int main(void) {
    Persona pueblo[150];
    for(int i = 0; i < 150; i++) {
        Persona persona;
        pueblo[i] = persona;
    }

    for(int i = 0; i < 150; i++) {
        std::cout << pueblo[i].getName() << std::endl;
    }

    return 0;
}
