#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void out(io_mode mode, void* data)
{
    switch (mode)
    {
        case character:
            printf("%c", (*(char*)(data)));
            break;

        case hex:
            printf("%#010x", (*(int16_t*)(data)));
            break;

        case num:
            printf("%d", (*(int16_t*)(data)));
            break;

        case unum:
            printf("%u", (*(uint16_t*)(data)));
            break;
    }
}