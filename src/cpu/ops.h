#ifndef CPU_OPS_H
#define CPU_OPS_H

#include <stdint.h>

#define cpu_op_func_ret void
#define cpu_op_func_args uint16_t op, uint16_t arg[2]

typedef cpu_op_func_ret (*cpu_op_func)(cpu_op_func_args);

typedef struct
{
    char name[4];
    uint16_t identifier;

    cpu_op_func handler;
} cpu_ops;

void ops_setup();

#endif