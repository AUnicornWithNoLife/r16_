#include "assemble.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

uint8_t* assemble(char* data, bool resize, uint16_t *r_l)
{
    uint8_t *ret = (uint8_t*)malloc(sizeof(uint8_t) * UINT16_MAX);
    uint16_t r_len = 0;

    char *dat = assemble_format_nice(data);
    char *d = dat;

    do
    {
        char i_n[4] = {d[0], d[1], d[2], '\0'};
        d += 3;

        assemble_instruction instruct = assemble_get_op(i_n);

        uint16_t arg0, arg1;

        switch (instruct.arg0)
        {
            case none:
                arg0 = 0;
                break;

            case reg:
                if (*d == 'A')
                {
                    arg0 = REG_ACU;
                }
                else if (*d == 'I')
                {
                    arg0 = REG_INR;
                }
                else if (*(d + 1) == '0')
                {
                    if (*(d + 2) == 'A')
                    {
                        arg0 = REG_R0A;
                    }
                    else if (*(d + 2) == 'B')
                    {
                        arg0 = REG_R0B;
                    }
                    else
                    {
                        arg0 = REG_R0;
                    }
                }
                else if (*(d + 1) == '1')
                {
                    if (*(d + 2) == 'A')
                    {
                        arg0 = REG_R1A;
                    }
                    else if (*(d + 2) == 'B')
                    {
                        arg0 = REG_R1B;
                    }
                    else
                    {
                        arg0 = REG_R1;
                    }
                }
                break;

            case ram:
                sscanf(d, "%u", &arg0);
                break;
        }

        switch (instruct.arg1)
        {
            case none:
                arg1 = 0;
                break;

            case reg:
                if (*d == 'A')
                {
                    arg1 = REG_ACU;
                }
                else if (*d == 'I')
                {
                    arg1 = REG_INR;
                }
                else if (*(d + 1) == '0')
                {
                    if (*(d + 2) == 'A')
                    {
                        arg1 = REG_R0A;
                    }
                    else if (*(d + 2) == 'B')
                    {
                        arg1 = REG_R0B;
                    }
                    else
                    {
                        arg1 = REG_R0;
                    }
                }
                else if (*(d + 1) == '1')
                {
                    if (*(d + 2) == 'A')
                    {
                        arg1 = REG_R1A;
                    }
                    else if (*(d + 2) == 'B')
                    {
                        arg1 = REG_R1B;
                    }
                    else
                    {
                        arg1 = REG_R1;
                    }
                }
                break;

            case ram:
                sscanf(d, "%u", &arg1);
                break;
        }

        ret[r_len++] = instruct.opcode;
        ret[r_len++] = arg0;
        ret[r_len++] = arg1;
    } while (*(++d) != '\0');
    
    if (r_l != NULL)
    {
        *r_l = r_len;
    }
    
    return (uint8_t*)realloc(ret, r_len);
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

assemble_instruction assemble_new_instruction(uint8_t opcode, assemble_arg_type arg0, assemble_arg_type arg1)
{
    assemble_instruction ret;

    ret.opcode = opcode;
    ret.arg0 = arg0;
    ret.arg1 = arg1;

    return ret;
}

char* assemble_format_nice(char* str)
{
    char *ret = (char*)malloc(sizeof(char) * ASSEMBLE_STR_CHUNK_SIZE);
    uint64_t len = 0;
    uint64_t alloc = ASSEMBLE_STR_CHUNK_SIZE;

    char *r_p = ret, *s_p = str;

    while (true)
    {
        do
        {
            if (*str == '\0')
                break;

            if
            (
                (*str == ' ') &&
                (
                    (len > 0) &&
                    (*ret != ' ')
                )
            )
            {
                *r_p = ' ';

                r_p++;
                len++;
            }
            else
            {
                bool alphanumeric = assemble_is_alphanumeric(*s_p);

                if (!alphanumeric)
                {
                    break;
                }

                *r_p = *s_p;

                r_p++;
                len++;
            }
        } while (0);
        
        if (len + 1 >= alloc)
        {
            alloc += ASSEMBLE_STR_CHUNK_SIZE;
            ret = (char*)realloc(ret, (sizeof(char) * alloc));
        }
    }

    return (char*)realloc(ret, sizeof(char) * len);
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