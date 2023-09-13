#include <stdlib.h>
#include <stdint.h>

#include "ram.h"

uint8_t *ram;

void ram_setup()
{
    ram = (uint8_t*)malloc(sizeof(uint8_t) * UINT16_MAX);
}

void ram_clean()
{
    free(ram);
}