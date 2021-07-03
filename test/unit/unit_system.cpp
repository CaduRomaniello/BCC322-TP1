#include "unit_system.h" 

using namespace std;

void unit_system_constructor(){
    cout << "TEST 1 - Default constructor of the System class without passing parameters" << endl;
    
    System* system1 = new System();
    assert(system1->getName() == ""); 
    assert(system1->getValue() == 0.0);

    cout << GREEN << "OK!" << RESET << endl;

    cout << "TEST 2 - Default constructor of the Flow class with passing parameters" << endl; 
    
    System* system2 = new System("Sistema de teste", 10.0);
    assert(system2->getName() == "Sistema de teste"); 
    assert(system2->getValue() == 10.0);

    cout << GREEN << "OK!"<< RESET << endl;
}

void unit_system_copy_constructor(){
    cout << "TEST 3 - Copy constructor of the System class" << endl;
    
    System* system1 = new System("Sistema de teste", 10.0);
    System* system2 = new System(*system1);
    assert(system2->getName() == "Sistema de teste");
    assert(system2->getValue() == 10.0);

    assert(system1 != system2);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_destructor(){
    cout << "TEST 4 - Default destructor of the System class" << endl;

    double vmBefore, vmAfter, rss;
    memory_usage(vmBefore, rss);
  
    System* system = new System("Sistema de teste", 10.0);
    delete system;

    memory_usage(vmAfter, rss);
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_getName(){
    cout << "TEST 5 - System class's getName() method" << endl;
    
    System* system = new System("Sistema de teste", 10.0);
    assert(system->getName() == "Sistema de teste");

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_setName(){
    cout << "TEST 6 - System class's setName() method" << endl;
    
    System* system = new System("Sistema de teste", 10.0);
    system->setName("Nome alterado");
    assert(system->getName() == "Nome alterado");

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_getValue(){
    cout << "TEST 7 - System class's getValue() method" << endl;
    
    System* system = new System("Sistema de teste", 10.0);
    assert(system->getValue() == 10.0);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_setValue(){
    cout << "TEST 8 - System class's setValue() method" << endl;
    
    System* system = new System("Sistema de teste", 10.0);;
    system->setValue(20.0);
    assert(system->getValue() == 20.0);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_assingmentOperator(){
    cout << "TEST 9 - System class assignment operator" << endl;
    
    System* system1 = new System("Sistema de teste", 10.0);
    System* system2 = new System();
    *system2 = *system1;

    assert(system2->getName() == "Sistema de teste");
    assert(system2->getValue() == 10.0);
    
    assert(system1 != system2);

    cout << GREEN << "OK!" << RESET << endl;
}

void run_unit_tests_system(){
    unit_system_constructor();
    unit_system_copy_constructor();
    unit_system_destructor();
    unit_system_getName();
    unit_system_setName();
    unit_system_getValue();
    unit_system_setValue();
    unit_system_assingmentOperator();
}