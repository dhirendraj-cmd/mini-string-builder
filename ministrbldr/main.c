#include "stringbldr.h"
#include <stdio.h>
#include <stdlib.h>



int main(){


    // lets first create strbldr
    StringBldr *sb = create_str(16);


    // append new str to arr
    append_str(sb, "Dynamic String Builder in C, ");
    append_str(sb, "Testing with multiple append func, ");
    append_str(sb, "Rahul Dravid is class, ");
    append_str(sb, "Holmes is the best detective ");

    // print string
    printf("Passed string is: %s\n", get_string(sb));


    // call free func
    free_stringbldr(sb);


    return 0;
}

