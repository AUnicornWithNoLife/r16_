#include "ops.h"

#include "ram.h"
#include "reg.h"
#include "io.h"

#include <stdint.h>
#include <stdlib.h>

void ops_setup()
{
    
}

cpu_op_func_ret ops_lda(cpu_op_func_args)
{
    uint16_t ra = ram[arg[0]];

    switch (arg[1])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            r1[arg[1]] = ra;
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            ((uint8_t*)r1)[arg[1] - 4] = (uint8_t)ra;
            break;
    }
}

cpu_op_func_ret ops_sta(cpu_op_func_args)
{
    switch (arg[0])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            ram[arg[1]] = r1[arg[0]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            ram[arg[1]] = (uint16_t)(((uint8_t*)r1)[arg[0] - 4]);
            break;
    }
}

cpu_op_func_ret ops_mov(cpu_op_func_args)
{
    uint16_t r;

    switch (arg[0])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            r = r1[arg[0]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            r = (uint16_t)(((uint8_t*)r1)[arg[0] - 4]);
            break;
    }

    switch (arg[1])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            r1[arg[1]] = r;
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            ((uint8_t*)r1)[arg[1] - 4] = (uint8_t)r;
            break;
    }
}

cpu_op_func_ret ops_add(cpu_op_func_args)
{
    uint16_t a, b;

    switch (arg[0])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            a = r1[arg[0]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            a = (uint16_t)(((uint8_t*)r1)[arg[0] - 4]);
            break;
    }

    switch (arg[1])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            b = r1[arg[1]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            b = (uint16_t)(((uint8_t*)r1)[arg[1] - 4]);
            break;
    }

    *acu = a + b;
}

cpu_op_func_ret ops_sub(cpu_op_func_args)
{
    uint16_t a, b;

    switch (arg[0])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            a = r1[arg[0]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            a = (uint16_t)(((uint8_t*)r1)[arg[0] - 4]);
            break;
    }

    switch (arg[1])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            b = r1[arg[1]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            b = (uint16_t)(((uint8_t*)r1)[arg[1] - 4]);
            break;
    }

    *acu = a - b;
}

cpu_op_func_ret ops_mul(cpu_op_func_args)
{
    uint16_t a, b;

    switch (arg[0])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            a = r1[arg[0]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            a = (uint16_t)(((uint8_t*)r1)[arg[0] - 4]);
            break;
    }

    switch (arg[1])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            b = r1[arg[1]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            b = (uint16_t)(((uint8_t*)r1)[arg[1] - 4]);
            break;
    }

    *acu = a * b;
}

cpu_op_func_ret ops_div(cpu_op_func_args)
{
    uint16_t a, b;

    switch (arg[0])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            a = r1[arg[0]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            a = (uint16_t)(((uint8_t*)r1)[arg[0] - 4]);
            break;
    }

    switch (arg[1])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            b = r1[arg[1]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            b = (uint16_t)(((uint8_t*)r1)[arg[1] - 4]);
            break;
    }

    *acu = a / b;
}

cpu_op_func_ret ops_out(cpu_op_func_args)
{
    uint16_t o;

    switch (arg[0])
    {
        case 0: // 16
        case 1: 
        case 2: 
        case 3:
            o = r1[arg[0]];
            break;

        case 4: // 8????
        case 5:
        case 6:
        case 7:
            o = (uint16_t)(((uint8_t*)r1)[arg[0] - 4]);
            break;
    }

    out(hex, (void*)&o);
}

cpu_op_func_ret ops_stp(cpu_op_func_args)
{
    exit(69);
}
