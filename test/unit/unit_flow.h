#ifndef UNIT_FLOW
#define UNIT_FLOW

#include <assert.h>
#include <iostream>
#include <string>

#include "../../src/system.h"
#include "../../src/flow.h"
#include "./utils/mem_usage.h"

#define RESET "\033[0m"  /* Escape sequence to reset color output to default. */
#define GREEN "\033[32m" /* Escape sequence to a green color output. */

class ExponencialFlow : public Flow{
    public:
        /*!
            This is a more elaborated constructor for the ExponencialFlow Class.
            \param name the name of the ExponencialFlow Class.
            \param source a pointer to the source system of the ExponencialFlow Class.
            \param target a pointer to the target system of the ExponencialFlow Class.
        */
        ExponencialFlow(string name = "", System* source = NULL, System* target = NULL): Flow(name, source, target){}
        
        /*!
            A method created by the user, that contains an equation that will be executed by the exponencial model.                        
        */
        virtual double execute(){
            return (0.01 * getSource()->getValue());
        }
};

void unit_flow_constructor();
void unit_flow_copy_constructor();
void unit_flow_destructor();

void unit_flow_getName();
void unit_flow_setName();

void unit_flow_getSource();
void unit_flow_setSource();
void unit_flow_clearSource();

void unit_flow_getTarget();
void unit_flow_setTarget();
void unit_flow_clearTarget();

void unit_flow_assingmentOperator();
void unit_flow_execute();

void run_unit_tests_flow();

#endif