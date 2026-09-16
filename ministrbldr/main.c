#include "stringbldr.h"
#include <stdio.h>
#include <stdlib.h>



int main(){


    // lets first create strbldr
    StringBldr *sb = create_str(16);


    // append new str to arr
    append_str(sb, "Dynamic String Builder in C");

    // print string
    printf("Passed string is: %s\n", get_string(sb));


    // call free func
    free_stringbldr(sb);


    return 0;
}

