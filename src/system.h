#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <ios>
#include <fstream>

using namespace std;

//! Class System
/**
* This Class represents a system in the General Systems Theory implemented in this code.
*/
class System{

    // protected:
        // string name; /*!< This attribute contains a name for the system. */
        // double value; /*!< This attribute contains the actual value of the system. */

        // /*!
        //     This is the copy constructor for the System Class.
        //     \param sys the system that is going to be cloned.
        // */
        // System (const System& sys){
        //     if (this == &sys){
        //         return;
        //     }
            
        //     name = sys.getName();
        //     value = sys.getValue();           
        // }

        // /*!
        //     This is the overloaded assignment operator for the System Class.
        // */
        // System& operator=(const System& sys){
        //     if (this == &sys){
        //         return *this;
        //     }

        //     name = sys.getName();
        //     value = sys.getValue();          

        //     return *this;
        // }

    public:
        /*!
            This is the default constructor for the System Class.
            \param name the name of the System.
            \param value the initial value of the System.
            \return System - a System Class object.
        */
        // System();

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
        virtual void setName(string sysName) = 0;

        /*!
            Returns the name attribute in the System Class.
            \return string - the content name attribute.  
        */
        virtual string getName() const = 0;
        
        /*!
            Sets the value attribute in the System Class.
            \param sysValue which will be set to the current system.
        */
        virtual void setValue(double sysValue) = 0;

        /*!
            Returns the value attribute in the System Class.
            \return double - the content value attribute.  
        */
        virtual double getValue() const = 0;
      
        /*!
            This is the overloaded "+" operator for the System Class using two systems.
        */
        friend double operator+(const System& sys, const System& sys2);

        /*!
            This is the overloaded "+" operator for the SystemImpl Class using the order value + system.
        */
        friend double operator+(const double& valueSys, const System& sys);
        /*!
            This is the overloaded "+" operator for the SystemImpl Class using the order system + value.
        */
        friend double operator+(const System& sys, const double& valueSys);

        /*!
            This is the overloaded "-" operator for the System Class using two systems.
        */
        friend double operator-(const System& sys, const System& sys2);

        /*!
            This is the overloaded "-" operator for the SystemImpl Class using the order value - system.
        */
        friend double operator-(const double& valueSys, const System& sys);
        /*!
            This is the overloaded "-" operator for the SystemImpl Class using the order system - value.
        */
        friend double operator-(const System& sys, const double& valueSys);

        /*!
            This is the overloaded "*" operator for the System Class using two systems.
        */
        friend double operator*(const System& sys, const System& sys2);

        /*!
            This is the overloaded "*" operator for the System Class using the order value * system.
        */
        friend double operator*(const double& valueSys, const System& sys);

        /*!
            This is the overloaded "*" operator for the System Class using the order system * value.
        */
        friend double operator*(const System& sys, const double& valueSys);

        /*!
            This is the overloaded "/" operator for the System Class using two systems.
        */
        friend double operator/(const System& sys, const System& sys2);

        /*!
            This is the overloaded "/" operator for the System Class the order value / system.
        */
        friend double operator/(const double& valueSys, const System& sys2);

        /*!
            This is the overloaded "/" operator for the System Class the order system / value.
        */
        friend double operator/(const System& sys, const double& valueSys);

};

#endif