#ifndef CPU_IO_H
#define CPU_IO_H

typedef enum
{
    character,
    hex,
    num,
    unum
} io_mode;

void out(io_mode mode, void* data);
void *in(io_mode mode);

#endif