#include "cpu.h"
#include "ram.h"
#include "ops.h"
#include "reg.h"

#include <stdbool.h>
#include <stdint.h>

void cpu_run()
{
    *inr = 0;

    while (true)
    {
        uint8_t instruction = ram[*inr];
        uint8_t args[2] = {ram[(*inr) + 1], ram[(*inr) + 2]};
        (*inr) += 3;

        switch (instruction)
        {
            case 0:
                ops_lda(instruction, args);
                break;

            case 1:
                ops_sta(instruction, args);
                break;

            case 2:
                ops_mov(instruction, args);
                break;
            
            case 3:
                ops_add(instruction, args);
                break;
            
            case 4:
                ops_sub(instruction, args);
                break;
            
            case 5:
                ops_mul(instruction, args);
                break;
            
            case 6:
                ops_div(instruction, args);
                break;
            
            case 7:
                ops_out(instruction, args);
                break;

            case 8:
                ops_inp(instruction, args);
                break;
            
            case 9:
                ops_jmp(instruction, args);
                break;
            
            case 10:
                ops_jnz(instruction, args);
                break;
            
            case 11:
                ops_stp(instruction, args);
                break;
            
        }
    }
}