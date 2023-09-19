#ifndef CPU_OPS_H
#define CPU_OPS_H

#include <stdint.h>

#define cpu_op_func_ret void
#define cpu_op_func_args uint8_t op, uint8_t arg[2]

typedef cpu_op_func_ret (*cpu_op_func)(cpu_op_func_args);

void ops_setup();

cpu_op_func_ret ops_lda(cpu_op_func_args);
cpu_op_func_ret ops_sta(cpu_op_func_args);
cpu_op_func_ret ops_mov(cpu_op_func_args);
cpu_op_func_ret ops_add(cpu_op_func_args);
cpu_op_func_ret ops_sub(cpu_op_func_args);
cpu_op_func_ret ops_mul(cpu_op_func_args);
cpu_op_func_ret ops_div(cpu_op_func_args);
cpu_op_func_ret ops_out(cpu_op_func_args);
cpu_op_func_ret ops_inp(cpu_op_func_args);
cpu_op_func_ret ops_jmp(cpu_op_func_args);
cpu_op_func_ret ops_jnz(cpu_op_func_args);
cpu_op_func_ret ops_stp(cpu_op_func_args);

#endif