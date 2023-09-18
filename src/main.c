#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "lib/carg-parse/carg-parse.h"

#include "cpu/io.h"
#include "cpu/ops.h"
#include "cpu/ram.h"
#include "cpu/reg.h"

int main(int argc, char** argv)
{
    carg_parse_data* args = carg_parse(argc, argv);

    carg_parse_free(args);
}