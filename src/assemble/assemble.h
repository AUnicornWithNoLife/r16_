#ifndef ASSEMBLE_ASSEMBLE_H
#define ASSEMBLE_ASSEMBLE_H

#include <stdint.h>
#include <stdbool.h>

#define ASSEMBLE_STR_CHUNK_SIZE 4096

#define REG_R0 0
#define REG_R1 1
#define REG_INR 2
#define REG_ACU 3

#define REG_R0A 4
#define REG_R0B 5
#define REG_R1A 6
#define REG_R1B 7

typedef enum
{
    none,
    reg,
    ram
} assemble_arg_type;

typedef struct
{
    uint8_t opcode;
    
    assemble_arg_type arg0;
    assemble_arg_type arg1;
} assemble_instruction;

typedef struct
{
    char* label;

    uint16_t label_pointer;
} assemble_label;


uint8_t* assemble(char* data, bool resize, uint16_t *r_l);
assemble_instruction assemble_get_op(char* name);
assemble_instruction assemble_new_instruction(uint8_t opcode, assemble_arg_type arg0, assemble_arg_type arg1);
bool assemble_is_alphanumeric(char c);
char* assemble_format_nice(char* str);

#endif