#ifndef UNIT_MODEL
#define UNIT_MODEL

#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/model.h"
#include "./unit_flow.h"

#define RESET "\033[0m"  /* Escape sequence to reset color output to default. */
#define GREEN "\033[32m" /* Escape sequence to a green color output. */

void unit_model_constructor();
void unit_model_copy_constructor();
void unit_model_destructor();
void unit_model_addSystem();
void unit_model_removeSystem();
void unit_model_addFlow();
void unit_model_removeFlow();
void unit_model_getName();
void unit_model_setName();
void unit_model_getTime();
void unit_model_setTime();
void unit_model_incrementTime();
void unit_model_assingmentOperator();
void run_unit_tests_model();

#endif