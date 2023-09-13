#include "reg.h"

#include <stdlib.h>
#include <stdint.h>

uint16_t *r1, *r2, *inr, *acu;
uint8_t *r1a, *r1b, *r2a, *r2b;

void reg_setup()
{
    r1 = (uint16_t*)malloc(sizeof(uint16_t) * 4);
    r2 = r1 + 1;

    inr = r2 + 1;
    acu = inr + 1;

    r1a = (uint8_t*)r1;
    r1b = r1a + 1;

    r2a = (uint8_t*)r2;
    r2b = r2a + 1;
}

void reg_clean()
{
    free(r1);
}

