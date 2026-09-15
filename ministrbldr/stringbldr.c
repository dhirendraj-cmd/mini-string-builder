#include "stringbldr.h"
#include <stdio.h>
#include <stdlib.h>



StringBldr* create_str(size_t initialCapacity){

    
    // check if capacity is 0
    if(initialCapacity == 0){
        initialCapacity = 16;
    }
    
    // stringbld allocation to heap memory
    StringBldr *sb = malloc(sizeof(StringBldr));
    
    // if not memory then return null
    if (!sb){
        return NULL;
    }

    // set buffer to size of inital capacity
    sb->buffermemo = malloc(initialCapacity);

    // if not buffer then free sb
    if(!sb->buffermemo){
        free(sb);
        return NULL;
    }

    sb->buffermemo[0] = '\0';
    sb->lengthTracker = 0;
    sb->capacityTracker = initialCapacity;

    return sb;

}

