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

        /*!
            This is the copy constructor for the System Class.
            \param sys the system that is going to be cloned.
        */
        System (const System& sys){
            if (this == &sys){
                return;
            }
            
            name = sys.getName();
            value = sys.getValue();           
        }

        /*!
            This is the overloaded assignment operator for the System Class.
        */
        System& operator=(const System& sys){
            if (this == &sys){
                return *this;
            }

            name = sys.getName();
            value = sys.getValue();          

            return *this;
        }

    public:
        friend class Flow; /*!< This Class represents a flow in the General Systems Theory implemented in this code. */
        friend class Model; /*!< This Class represents a model in the General Systems Theory implemented in this code. */
        friend class UnitSystem; /*!< This Class is used to test the copy constructor and assignment operator of the System class. */

        /*!
            This is the default constructor for the System Class.
            \param name the name of the System.
            \param value the initial value of the System.
            \return System - a System Class object.
        */
        System(string name = "", double value = 0.0):name(name), value(value){}

        /*!
            This is the default destructor for the System Class.
        */
        virtual ~System(){}

        ////////////// Alt 07/07
        // virtual System* clone() {
        //     System* result = new System();
        //     CopyTo(*this, result);

        //     return result;
        // }

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
      
        /*!
            This is the overloaded "+" operator for the System Class.
        */
        double operator+(const System& sys){
            if (this == &sys){
                return 2.0 * value;
            }

            return value + sys.getValue();
        }
        
        /*!
            This is the overloaded "+" operator for the System Class.
        */
        friend double operator+(const double& valueSys, const System& sys){
            return valueSys + sys.getValue();
        }
        
        /*!
            This is the overloaded "+" operator for the System Class.
        */
        friend double operator+(const System& sys, const double& valueSys){
            return sys.getValue() + valueSys;
        }

        /*!
            This is the overloaded "-" operator for the System Class.
        */
        double operator-(const System& sys){
            if (this == &sys){
                return 0.0;
            }

            return value - sys.getValue();
        }
        
        /*!
            This is the overloaded "-" operator for the System Class.
        */
        friend double operator-(const System& sys, const double& valueSys){
            return sys.getValue() - valueSys;
        }
        
        /*!
            This is the overloaded "-" operator for the System Class.
        */
        friend double operator-(const double& valueSys, const System& sys){
            return valueSys - sys.getValue();
        }

        /*!
            This is the overloaded "*" operator for the System Class.
        */
        double operator*(const System& sys){
            if (this == &sys){
                return value * value;
            }

            return value * sys.getValue();
        }
        
        /*!
            This is the overloaded "*"" operator for the System Class.
        */
        friend double operator*(const System& sys, const double& valueSys){
            return sys.getValue() * valueSys;
        }
        
        /*!
            This is the overloaded "*"" operator for the System Class.
        */
        friend double operator*(const double& valueSys, const System& sys){
            return valueSys * sys.getValue();
        }

        /*!
            This is the overloaded "/" operator for the System Class.
        */
        double operator/(const System& sys){
            if (this == &sys){
                return 1.0;
            }

            return value / sys.getValue();
        }
        
        /*!
            This is the overloaded "/" operator for the System Class.
        */
        friend double operator/(const double& valueSys, const System& sys){
            return valueSys / sys.getValue();
        }
        
        /*!
            This is the overloaded "/" operator for the System Class.
        */
        friend double operator/(const System& sys, const double& valueSys){
            return sys.getValue() / valueSys;
        }    

};

#endif