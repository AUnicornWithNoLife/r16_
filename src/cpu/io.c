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

void *in(io_mode mode)
{
    void *data = (void*)malloc(sizeof(uint16_t));

    switch (mode)
    {
        case character:
            scanf("%c", (char*)(data));
            break;

        case hex:
            //scanf("%#010x", (int16_t*)(data));
            break;

        case num:
            scanf("%hd", (int16_t*)(data));
            break;

        case unum:
            scanf("%hu", (uint16_t*)(data));
            break;
    }

    return data;
}