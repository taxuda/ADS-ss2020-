//
// Created by dat tran on 11.05.21.
//

#ifndef RINGBUFFER_PRINT_H
#define RINGBUFFER_PRINT_H
#include <iostream>
#include "Ring.h"
#include <string>
#define COMMAND_ADD 1
#define COMMAND_SEARCH 2
#define COMMAND_PRINT 3
#define COMMAND_QUIT 4

void print_menu(Ring &r);
void print_add(Ring &r);
void print_search(Ring &r);
void print_goback(Ring &r);

#endif //RINGBUFFER_PRINT_H
