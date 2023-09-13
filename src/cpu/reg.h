#ifndef CPU_REG_H
#define CPU_REG_H

#include <stdint.h>

uint16_t *r1, *r2, *inr, *acu;
uint8_t *r1a, *r1b, *r2a, *r2b;

void reg_setup();
void reg_clean();

#endif