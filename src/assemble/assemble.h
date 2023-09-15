#ifndef ASSEMBLE_ASSEMBLE_H
#define ASSEMBLE_ASSEMBLE_H

#include <stdint.h>
#include <stdbool.h>

#define ASSEMBLE_STR_CHUNK_SIZE 4096

typedef enum
{
    none,
    reg,
    ram
} assemble_arg_type;

typedef struct
{
    uint8_t opcode;
    
    assemble_arg_type arg1;
    assemble_arg_type arg2;
} assemble_instruction;

typedef struct
{
    char* label;

    uint16_t label_pointer;
} assemble_label;


uint8_t* assemble(char* data);
assemble_instruction assemble_get_op(char* name);
assemble_instruction assemble_new_instruction(uint8_t opcode, assemble_arg_type arg1, assemble_arg_type arg2);
bool assemble_is_alphanumeric(char c);

#endif