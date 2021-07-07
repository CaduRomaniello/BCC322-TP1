#ifndef FLOW_H
#define FLOW_H

#include <string>
#include <iostream>
#include "./system.h"

using namespace std;

//! Class Flow
/**
* This Class represents a flow in the General Systems Theory implemented in this code.
*/
class Flow{

    protected:
        string name; /*!< This attribute contains a name for the flow. */
        System* source; /*!< This attribute stores a pointer to the source system of a flow. */
        System* target; /*!< This attribute stores a pointer to the target system of a flow. */

        /*!
            This is the copy constructor for the Flow Class.
            \param flow the flow that is going to be cloned.
        */
        Flow (const Flow& flow){
            if (this == &flow){
                return;
            }
            
            name = flow.getName();
            source = NULL;
            target = NULL;
        }

        /*!
            This is the overloaded assignment operator for the Flow Class.
        */
        Flow& operator=(const Flow& flow){
            // cout << "Entrei operador de atribuição" << endl;
            if (this == &flow){
                return *this;
            }
            // cout << "E não sou o mesmo ponteiro" << endl;

            setName(flow.getName());
            // cout << "Setei o nome" << endl;
            setSource(NULL);
            // cout << "Setei o source" << endl;
            setTarget(NULL);
            // cout << "Setei o target" << endl;
            // cout << "To mandando retorno" << endl;

            return *this;
        }


        //////////////////////// Alterado dia 07/07
        // static void CopyTo(const Flow& from, Flow& to){
            
        //     to.source = from.source->clone();

        // }

        // virtual Flow* clone(){
        //     Flow* result = new Flow();
        //     CopyTo(*this, result);

        //     return result;
        // }

    public:
        friend class Model; /*!< This Class represents a model in the General Systems Theory implemented in this code. */
        friend class UnitFlow; /*!< This Class is used to test the copy constructor and assignment operator of the Flow class. */

        /*!
            This is the default constructor for the Flow Class.
            \param name the name of the Flow.
            \param source a pointer to the source system of the Flow.
            \param target a pointer to the target system of the Flow.
            \return Flow - a Flow Class object, with it's isCopy attribute set to false.
        */
        Flow(string name = "", System* source = NULL, System* target = NULL):name(name), source(source), target(target){}
        
        /*!
            This is the default destructor for the Flow Class.
        */
        virtual ~Flow(){}

        /*!
            A pure virtual method that will be inherited by subclasses created by the user, and that will contain
            an equation that will be executed by the model.
        */
        virtual double execute() = 0;

        /*!
            Returns the name attribute in the Flow Class.
            \return string - the content name attribute.  
        */
        string getName() const{
            return name;
        }
                
        /*!
            Sets the name attribute in the Flow Class.
            \param flowName which will be set to the current flow.
        */
        void setName(string flowName){
            name = flowName;
        }

        /*!
            Returns the source attribute in the Flow Class.  
            \return System* - the pointer of the source system. 
        */
        System* getSource() const{
            return source;
        }

        /*!
            Sets the source attribute in the Flow Class. 
            \param sourceSys a pointer to the source target.
        */
        void setSource(System* sourceSys){
            source = sourceSys;
        }

        /*!
            Sets the pointer of the source attribute as NULL.
        */
        void clearSource() {
            source = NULL;
        }

        /*!
            Returns the target attribute in the Flow Class. 
            \return System* - the pointer of the target system. 
        */
        System* getTarget() const{
            return target;
        }
        
        /*!
            Sets the target attribute in the Flow Class.   
            \param targetSys a pointer to the target system.
        */
        void setTarget(System* targetSys) {
            target = targetSys;
        }

        /*!
            Sets the pointer of the target attribute as NULL.
        */
        void clearTarget() {
            target = NULL;
        }
};

#endif