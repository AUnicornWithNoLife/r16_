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
#include "cpu/cpu.h"

int main(int argc, char** argv)
{
    carg_parse_data* args = carg_parse(argc, argv);

    ops_setup();
    ram_setup();
    reg_setup();

    char *fn;

    if (args->values_len > 0)
    {
        fn = args->values[0];
    }
    else
    {
        fn = (char*)malloc(sizeof(char) * 1024);

        scanf("%s", fn);
    }

    FILE* bin = fopen(fn, "rb");
    uint16_t i = 0;
    int tbit = 0;

    while ((tbit = getc(bin)) != EOF)
    {
        ram[i++] = (uint8_t)tbit;

        printf("write %u\n", i);
    }

    cpu_run();

    carg_parse_free(args);
}