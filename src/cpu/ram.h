#ifndef CPU_RAM_H
#define CPU_RAM_H

#include <stdint.h>

uint8_t *ram;

void ram_setup();
void ram_clean();

#endif