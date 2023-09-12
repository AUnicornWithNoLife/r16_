#include <stdlib.h>
#include <stdint.h>

#include "ram.h"

uint8_t *ram;

void setup_ram()
{
    ram = (uint8_t*)malloc(sizeof(uint8_t) * UINT16_MAX);
}
