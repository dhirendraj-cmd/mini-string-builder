#ifndef STRINGBLDR_H
#define STRINGBLDR_H

#include <stddef.h>

typedef struct {
	char *buffermemo;
	size_t lengthTracker;
	size_t capacityTracker;
} StringBldr;

// create string bldr func which will return new stringbld pointer
StringBldr* create_str(size_t initial_capacity);


// append new string value in exisiting string
void append_str(StringBldr *sb, const char *str);

// get the current/new string
const char* get_string(const StringBldr *str);


// destroy stringbldr when not required
void free_stringbldr(StringBldr *sb);


#endif
