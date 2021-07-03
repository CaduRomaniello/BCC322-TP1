#ifndef UNIT_SYSTEM
#define UNIT_SYSTEM

#include <assert.h>
#include <iostream>
#include <string>
#include <ios>
#include <iostream>
#include <fstream>

#include "../../src/system.h"
#include "./utils/mem_usage.h"

#define RESET "\033[0m"  /* Escape sequence to reset color output to default. */
#define GREEN "\033[32m" /* Escape sequence to a green color output. */

void unit_system_constructor();
void unit_system_copy_constructor();
void unit_system_destructor();

void unit_system_getName();
void unit_system_setName();

void unit_system_getValue();
void unit_system_setValue();

void unit_system_assingmentOperator();

void run_unit_tests_system();

#endif