#include "assemble.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

uint8_t* assemble(char* data)
{

}

assemble_instruction assemble_get_op(char* name)
{
    if (!strcmp(name, "lda"))
    {
        return assemble_new_instruction(0, ram, reg);
    }
    else if (!strcmp(name, "sta"))
    {
        return assemble_new_instruction(1, reg, ram);
    }
    else if (!strcmp(name, "mov"))
    {
        return assemble_new_instruction(2, reg, reg);
    }
    else if (!strcmp(name, "add"))
    {
        return assemble_new_instruction(3, reg, reg);
    }
    else if (!strcmp(name, "sub"))
    {
        return assemble_new_instruction(4, reg, reg);
    }
    else if (!strcmp(name, "mul"))
    {
        return assemble_new_instruction(5, reg, reg);
    }
    else if (!strcmp(name, "div"))
    {
        return assemble_new_instruction(6, reg, reg);
    }
    else if (!strcmp(name, "out"))
    {
        return assemble_new_instruction(7, reg, none);
    }
    else if (!strcmp(name, "stp"))
    {
        return assemble_new_instruction(8, none, none);
    }

    return assemble_new_instruction(0, none, none);
}

assemble_instruction assemble_new_instruction(uint8_t opcode, assemble_arg_type arg1, assemble_arg_type arg2)
{
    assemble_instruction ret;

    ret.opcode = opcode;
    ret.arg1 = arg1;
    ret.arg2 = arg2;

    return ret;
}

char* assemble_format_nice(char* str)
{
    char *ret = (char*)malloc(sizeof(char) * ASSEMBLE_STR_CHUNK_SIZE);
    uint64_t len = 0;

    char *r_p = ret, *s_p = str;

    while (true)
    {
        if (*str == '\0')
            break;

        bool alphanumeric = assemble_is_alphanumeric(s_p);
    }
}

bool assemble_is_alphanumeric(char c)
{
    if (c < 48)
        return false;

    if (c <= 57)
        return true;

    if (c < 65)
        return false;

    if (c <= 90)
        return true;

    if (c < 97)
        return false;

    if (c <= 122)
        return true;

    return false;
}