#include <stdio.h>
#include "../inc/packet.h"

struct packet packet_generate(int placeholder)
{
    struct packet p = { 
        .placeholder = placeholder 
    };
    
    return p;
}

#define POINTER_PRINT(varname, field) \
do { printf(#varname "->" #field ": %i\n", varname->field); } while(0)

void packet_print(const struct packet *p)
{
    POINTER_PRINT(p, placeholder);
}
