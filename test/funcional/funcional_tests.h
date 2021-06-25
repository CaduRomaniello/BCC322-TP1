#ifndef FUNCTIONAL_TEST
#define FUNCTIONAL_TEST

#include "../../src/system.h"
#include "../../src/flow.h"

void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

class ExponencialFlow : public Flow{
    public:
        ExponencialFlow(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class LogisticFlow : public Flow{
    public:
        LogisticFlow(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
        }
};

class ComplexFlowF : public Flow{
    public:
        ComplexFlowF(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class ComplexFlowT : public Flow{
    public:
        ComplexFlowT(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class ComplexFlowU : public Flow{
    public:
        ComplexFlowU(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class ComplexFlowV : public Flow{
    public:
        ComplexFlowV(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

class ComplexFlowG : public Flow{
    public:
        ComplexFlowG(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};
        
class ComplexFlowR: public Flow{
    public:
        ComplexFlowR(string name, System* source, System* target): Flow(name, source, target){}
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};

#endif