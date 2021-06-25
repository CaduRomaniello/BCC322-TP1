#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "./system.h"

using namespace std;

/**
 * Class Flow - Campos
 * name   -> string
 * source -> System*
 * target -> System*
*/

class Flow{

    protected:
        string name;
        System* source;
        System* target;

    public:
        // Construtores e Destrutores
        Flow(){}
        Flow(string name="", System* source = NULL, System* target = NULL):name(name), source(source), target(target){}
        virtual ~Flow(){}

        // Execute
        virtual double execute() = 0;

        // Setters e Getters
        string getName() const{
            return name;
        }
                
        void setName(string flowName){
            name = flowName;
        }

        System* getSource() const{
            return source;
        }

        void setSource(System* sourceSys){
            source = sourceSys;
        }

        void clearSource() {
            source = NULL;
        }

        System* getTarget() const{
            return target;
        }

        void setTarget(System* targetSys) {
            target = targetSys;
        }

        void clearTarget() {
            target = NULL;
        }

    private:    

        //Construtor de cópia
        Flow (const Flow& flow, System* sourceSys, System* targetSys){
            if (this == &flow){
                return;
            }
            
            name = flow.getName();            
            source = sourceSys;
            target = targetSys;
        }

        //Sobrecarga do operador de atribuição
        Flow& operator=(const Flow& flow){
            if (this == &flow){
                return *this;
            }

            name = flow.name;
            source = flow.source;
            target = flow.target;

            return *this;
        }

};

#endif