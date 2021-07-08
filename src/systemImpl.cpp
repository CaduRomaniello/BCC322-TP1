#include "systemImpl.h"

using namespace std;

SystemImpl::SystemImpl (const SystemImpl& sys){
    if (this == &sys){
        return;
    }
    
    name = sys.getName();
    value = sys.getValue();           
}

SystemImpl& SystemImpl::operator=(const SystemImpl& sys){
    if (this == &sys){
        return *this;
    }

    setName(sys.getName());
    setValue(sys.getValue());          

    return *this;
}

SystemImpl::SystemImpl(string name, double value):name(name), value(value){}

SystemImpl::~SystemImpl(){}

void SystemImpl::setName(string sysName){
    name = sysName;
}

string SystemImpl::getName() const {
    return name;
}    

void SystemImpl::setValue(double sysValue){
    value = sysValue;
}

double SystemImpl::getValue() const{
    return value;
}


double operator+(const SystemImpl& sys, const SystemImpl& sys2){
    if (&sys == &sys2){
        return 2.0 * sys.getValue();
    }

    return sys.getValue() + sys2.getValue();
}

double operator+(const double& valueSys, const SystemImpl& sys){
    return valueSys + sys.getValue();
}


double operator+(const SystemImpl& sys, const double& valueSys){
    return sys.getValue() + valueSys;
}

double operator-(const SystemImpl& sys, const SystemImpl& sys2){
    if (&sys == &sys2){
        return 0.0;
    }

    return sys.getValue() - sys2.getValue();
}

double operator-(const SystemImpl& sys, const double& valueSys){
    return sys.getValue() - valueSys;
}

double operator-(const double& valueSys, const SystemImpl& sys){
    return valueSys - sys.getValue();
}

double operator*(const SystemImpl& sys, const SystemImpl& sys2){
    if (&sys == &sys2){
        return sys.getValue() * sys.getValue();
    }

    return sys.getValue() * sys2.getValue();
}

double operator*(const SystemImpl& sys, const double& valueSys){
    return sys.getValue() * valueSys;
}

double operator*(const double& valueSys, const SystemImpl& sys){
    return valueSys * sys.getValue();
}

double operator/(const SystemImpl& sys, const SystemImpl& sys2){
    if (&sys == &sys2){
        return 1.0;
    }

    return sys.getValue() / sys2.getValue();
}

double operator/(const double& valueSys, const SystemImpl& sys){
    return valueSys / sys.getValue();
}

double operator/(const SystemImpl& sys, const double& valueSys){
    return sys.getValue() / valueSys;
}