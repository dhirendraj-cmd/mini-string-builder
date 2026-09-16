#include "stringbldr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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


// get length of str passsed in append usaing custom func instead of strlen
int get_length(const char *str){
    int length=0;

    while (str[length]!='\0')
    {
        length++;
    }
    return length;
}


void append_str(StringBldr *sb, const char *str){
    // if not str passed or not sb is there
    if (!sb || !str){
        return ;
    }


    size_t textlength;
    size_t neededSize;

    // get current text length
    textlength = get_length(str);
    printf("Length of current text is: %zu\n", textlength);
    
    // create required size
    neededSize = sb->lengthTracker + textlength + 1;
    printf("Needed Size is: %zu\n", neededSize);


    // check required size is more than capacitytracker
    if(neededSize > sb->capacityTracker){

        // multiply capacitytracker by 2 until capacity exceeds neededsize
        while (neededSize > sb->capacityTracker)
        {
            sb->capacityTracker *= 2;
        }

        // finally reallocate new memory
        char *newBuffmemo = realloc(sb->buffermemo, sb->capacityTracker);

        if (!newBuffmemo){
            return;
        }

        sb->buffermemo = newBuffmemo;

    }

    // if nneededsize < capacitytracker then copy in buffer
    strcpy(sb->buffermemo + sb->lengthTracker, str);
    sb->lengthTracker+=textlength;

    printf("Total Capacity is %zu\n", sb->capacityTracker);

}

const char* get_string(const StringBldr *sb){
    if(sb){
        return sb->buffermemo;
    } else {
        return "";
    }
}


void free_stringbldr(StringBldr *sb){
    if(sb){
        free(sb->buffermemo);
        free(sb);
    }
}

