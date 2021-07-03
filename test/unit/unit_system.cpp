#include "unit_system.h" 

using namespace std;

void unit_system_constructor(){
    cout << "Teste 1 - Construtor default da classe System sem passagem de parametros" << endl;
    
    System* system1 = new System();
    assert(system1->getName() == ""); 
    assert(system1->getValue() == 0.0);

    cout << GREEN << "OK!" << RESET << endl;

    cout << "Teste 2 - Construtor default da classe System com passagem de parametros" << endl; 
    
    System* system2 = new System("Sistema de teste", 10.0);
    assert(system2->getName() == "Sistema de teste"); 
    assert(system2->getValue() == 10.0);

    cout << GREEN << "OK!"<< RESET << endl;
}

void unit_system_copy_constructor(){
    cout << "Teste 3 - Construtor de copia da classe System" << endl;
    
    System* system1 = new System("Sistema de teste", 10.0);
    System* system2 = new System(*system1);
    assert(system2->getName() == "Sistema de teste");
    assert(system2->getValue() == 10.0);

    assert(system1 != system2);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_destructor(){
    cout << "Teste 4 - Destrutor default da classe System" << endl;

    double vmBefore, vmAfter, rss;
    memory_usage(vmBefore, rss);
  
    System* system = new System("Sistema de teste", 10.0);
    delete system;

    memory_usage(vmAfter, rss);
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_getName(){
    cout << "Teste 5 - Metodo getName() da classe System" << endl;
    
    System* system = new System("Sistema de teste", 10.0);
    assert(system->getName() == "Sistema de teste");

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_setName(){
    cout << "Teste 6 - Metodo setName() da classe System" << endl;
    
    System* system = new System("Sistema de teste", 10.0);
    system->setName("Nome alterado");
    assert(system->getName() == "Nome alterado");

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_getValue(){
    cout << "Teste 7 - Metodo getValue() da classe System" << endl;
    
    System* system = new System("Sistema de teste", 10.0);
    assert(system->getValue() == 10.0);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_setValue(){
    cout << "Teste 8 - Metodo setValue() da classe System" << endl;
    
    System* system = new System("Sistema de teste", 10.0);;
    system->setValue(20.0);
    assert(system->getValue() == 20.0);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_system_assingmentOperator(){
    cout << "Teste 9 - Operador de atribuicao da classe System" << endl;
    
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