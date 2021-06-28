#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

//! Class System
/**
* This Class represents a system in the General Systems Theory implemented in this code.
*/
class System{

    protected:
        string name; /*!< This attribute contains a name for the system. */
        double value; /*!< This attribute contains the actual value of the system. */

    public:

        /*!
            This is the default constructor for the System Class.
        */
        System(){}

        /*!
            This is a more elaborated constructor for the System Class.
            \param name the name of the System Class.
            \param value the initial value of the system.
            \return System - a System Class object.
        */
        System(string name="", double value=0.0):name(name), value(value){}

        /*!
            This is the default destructor for the System Class.
        */
        virtual ~System(){}

        /*!
            Sets the name attribute in the System Class.
            \param sysName which will be set to the current system.
        */
        void setName(string sysName){
            name = sysName;
        }

        /*!
            Returns the name attribute in the System Class.
            \return string - the content name attribute.  
        */
        string getName() const {
            return name;
        }    
        
        /*!
            Sets the value attribute in the System Class.
            \param sysValue which will be set to the current system.
        */
        void setValue(double sysValue){
            value = sysValue;
        }
        /*!
            Returns the value attribute in the System Class.
            \return double - the content value attribute.  
        */
        double getValue() const{
            return value;
        }
        
    private:    

        /*!
            This is the copy constructor for the System Class.
            \param sys the system that is going to be cloned.
        */
        System (const System& sys){
            if (this == &sys){
                return;
            }
            
            name = sys.name;
            value = sys.value;
        }

        /*!
            This is the overloaded equal operator for the System Class.
        */
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