#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "lib/carg-parse/carg-parse.h"

#include "cpu/io.h"
#include "cpu/ops.h"
#include "cpu/ram.h"
#include "cpu/reg.h"

#include "assemble/assemble.h"

int main(int argc, char** argv)
{
    carg_parse_data* args = carg_parse(argc, argv);

    char *f_n = args->values[0];
    char *f = (char*)malloc(4096);
    FILE *f_p = fopen(f_n, "r");

    fscanf(f_p, "%4095c", f);

    printf("loaded\n");

    uint16_t asm_len = 0;
    uint16_t *asm_v = assemble(f, true, &asm_len);

    printf("assembled");

    ram_setup();
    reg_setup();

    for (uint16_t i = 0; i < asm_len; i++)
    {
        printf("written %u of %u", i, asm_len);

        ram[i] = (uint8_t)asm_v[i];
    }

    

    carg_parse_free(args);
}