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

    }
    else if (!strcmp(name, "sta"))
    {

    }
    else if (!strcmp(name, "mov"))
    {

    }
    else if (!strcmp(name, "add"))
    {

    }
    else if (!strcmp(name, "sub"))
    {

    }
    else if (!strcmp(name, "mul"))
    {
        
    }
    else if (!strcmp(name, "div"))
    {

    }
    else if (!strcmp(name, "out"))
    {

    }
    else if (!strcmp(name, "stp"))
    {

    }
}

assemble_instruction assemble_new_instruction(uint8_t opcode, assemble_arg_type arg1, assemble_arg_type arg2)
{
    assemble_instruction ret;

    ret.opcode = opcode;
    ret.arg1 = arg1;
    ret.arg2 = arg2;

    return ret;
}