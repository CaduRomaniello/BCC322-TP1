#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "./system.h"

using namespace std;

//! Class flow
/**
* This Class represents a flow in the General Systems Theory implemented in this code.
*/
class Flow{

    protected:
        string name; /*!< This variable contains a name for the flow. */
        System* source; /*!< This variable stores a pointer to the source system of a flow. */
        System* target; /*!< This variable stores a pointer to the target system of a flow. */

    public:
        /*!
            This is the default constructor for the Flow Class.
        */
        Flow(){}
        
        /*!
            This is a more elaborated constructor for the Flow Class.
            \param name the name of the Flow Class.
            \param source a pointer to the source system of the Flow Class.
            \param target a pointer to the target system of the Flow Class.
            \return Flow - a Flow Class object.
        */
        Flow(string name="", System* source = NULL, System* target = NULL):name(name), source(source), target(target){}
        
        /*!
            This is the default destructor for the Flow Class.
        */
        virtual ~Flow(){}

        /*!
            A pure virtual method that will be inherited by subClasses created by the user, and that will contain
            an equation that will be executed by the model.
        */
        virtual double execute() = 0;

        /*!
            Returns the name attribute in the Flow Class.
            \return String - the content name attribute.  
        */
        string getName() const{
            return name;
        }
                
        /*!
            Sets the name atributte in the Flow Class.
            \param flowName which will be set to the current flow.
        */
        void setName(string flowName){
            name = flowName;
        }

        /*!
            Returns the source atributte in the Flow Class.  
            \return System* - the pointer of the source system. 
        */
        System* getSource() const{
            return source;
        }

        /*!
            Sets the source atributte in the Flow Class. 
            \param sourceSys a pointer to the source target.
        */
        void setSource(System* sourceSys){
            source = sourceSys;
        }

        /*!
            Sets the pointer of the source atributte as NULL.
        */
        void clearSource() {
            source = NULL;
        }

        /*!
            Returns the target atributte in the Flow Class. 
            \return System* - the pointer of the target system. 
        */
        System* getTarget() const{
            return target;
        }
        
        /*!
            Sets the target atributte in the Flow Class.   
            \param targetSys a pointer to the target system.
        */
        void setTarget(System* targetSys) {
            target = targetSys;
        }

        /*!
            Sets the pointer of the target atributte as NULL.
        */
        void clearTarget() {
            target = NULL;
        }

    private:
        /*!
            This is the copy constructor for the Flow Class.
            \param flow the flow that is going to be cloned.
            \param sourceSys the pointer for the source system, it prevents memory leak.
            \param targetSys the pointer for the target system, it prevents memory leak.
        */
        Flow (const Flow& flow, System* sourceSys, System* targetSys){
            if (this == &flow){
                return;
            }
            
            name = flow.getName();            
            source = sourceSys;
            target = targetSys;
        }

        /*!
            This is the overloaded equal operator for the Flow Class.
        */
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