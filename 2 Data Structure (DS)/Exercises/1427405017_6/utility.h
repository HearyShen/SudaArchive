#ifndef UTILITY_H
#define UTILITY_H

enum Error_code{success,fail,Range_error,underflow,overflow,fatal,not_present,
                duplicate_error,entry_inserted,entry_found,internal_error};

typedef int Record;
typedef int Key;

#include <iostream>
#include "ContiguousList.h"
#include "binary_search.h"
#include "sequential_search.h"

#endif