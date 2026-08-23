#include <stdio.h>

struct cannon {
    char *name;
    double caliber;
    char *ammo[3];
};

struct tank {
    double weight;
    char *engine;
    struct cannon main_cannon;
};


int main(void) {
    struct tank t34 = {
        .weight = 32,
        .engine = "Kharkiv V-2",

        // esses aqui são inicializadores aninhados: 
        // iniciam uma struct que é parâmetro de outra.
        .main_cannon.name = "ZiS-S-53",
        .main_cannon.caliber = 85,
        .main_cannon.ammo = {"APHEBC", "APCR", "HE"},
    };

    struct tank panther = {
        .weight = 45.5,
        .engine = "Maybach HL230",

        // outra forma permitida de inicializar uma struct aninhada,
        // essa é mais padrão.
        .main_cannon = {
            .name = "KwK 42 L/70",
            .caliber = 75,
            .ammo = {"AP, APHE, HE"},
        },
    };

    return 0;
}