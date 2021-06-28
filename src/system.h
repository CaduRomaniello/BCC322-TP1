#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

//! Class System
/**
* This class represents a system in the General Systems Theory implemented in this code.
*/

/**
 * Class System - Campos
 * name  -> string
 * value -> double
*/

class System{

    protected:
        string name;
        double value;

    public:

        // Construtores e Destrutores
        System(){}
        System(string name="", double value=0.0):name(name), value(value){}
        virtual ~System(){}

        // Setters e Getters
        void setName(string sysName){
            name = sysName;
        }
        string getName() const {
            return name;
        }    
        
        void setValue(double sysValue){
            value = sysValue;
        }
        double getValue() const{
            return value;
        }  

        
    private:    

        //Construtor de cópia
        System (const System& sys){
            if (this == &sys){
                return;
            }
            
            name = sys.name;
            value = sys.value;
        }

        //Sobrecarga do operador de atribuição
        System& operator=(const System& sys){
            if (this == &sys){
                return *this;
            }

            name = sys.name;
            value = sys.value;

            return *this;
        }    

};

#endif