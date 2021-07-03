#include "unit_flow.h"

using namespace std;

void unit_flow_constructor() {
    cout << "Teste 1 - Construtor default da classe Flow sem passagem de parametros" << endl;

    ExponencialFlow* flow1 = new ExponencialFlow();
    
    assert(flow1->getName() == "");
    assert(flow1->getSource() == NULL);
    assert(flow1->getTarget() == NULL);

    cout << GREEN << "OK!" << RESET << endl;
    cout << "Teste 2 - Construtor default da classe Flow com passagem de parametros" << endl;

    System* source = new System("System1", 5.0);
    System* target = new System("System2", 10.0);

    ExponencialFlow* flow2 = new ExponencialFlow("Flow2", source, target);
    
    assert(flow2->getName() == "Flow2");
    assert(flow2->getSource() == source);
    assert(flow2->getTarget() == target);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_copy_constructor() {
    cout << "Teste 3 - Construtor de copia da classe Flow" << endl;

    ExponencialFlow* flow1 = new ExponencialFlow("Flow1");
    ExponencialFlow* flow2(flow1);
    
    assert(flow2->getName() == "Flow1");
    assert(flow2->getSource() == NULL);
    assert(flow2->getTarget() == NULL);

    cout << GREEN << "OK!" << RESET << endl;
} 

void unit_flow_destructor() {
    cout << "Teste 4 - Destrutor default da classe Flow" << endl;

    double vmBefore, vmAfter, rss;
    memory_usage(vmBefore, rss);
  
    ExponencialFlow* flow = new ExponencialFlow("Flow");
    delete flow;

    memory_usage(vmAfter, rss);
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_getName() {
    cout << "Teste 5 - Metodo getName() da classe Flow" << endl;
    
    ExponencialFlow* flow = new ExponencialFlow("Flow1");
    assert(flow->getName() == "Flow1");
    
    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_setName() {
    cout << "Teste 6 - Metodo setName() da classe Flow" << endl;

    ExponencialFlow* flow = new ExponencialFlow();
    
    flow->setName("Flow1");
    assert(flow->getName() == "Flow1");

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_getSource(){
    cout << "Teste 7 - Metodo getSource() da classe Flow" << endl;
    
    System* system = new System("System de teste");
    ExponencialFlow* flow = new ExponencialFlow("Flow1",system);
    
    assert(flow->getSource()->getName() == "System de teste");
    
    cout << GREEN << "OK!" << RESET << endl;  
}

void unit_flow_setSource(){
    cout << "Teste 8 - Metodo setSource() da classe Flow" << endl;
    
    System* system = new System("System de teste");
    ExponencialFlow* flow1 = new ExponencialFlow("Flow1");
   
    flow1->setSource(system);
    assert(flow1->getSource()->getName() == "System de teste");
    
    cout << GREEN << "OK!" << RESET << endl;  
}

void unit_flow_clearSource(){
    cout << "Teste 9 - Metodo clearSource() da classe Flow" << endl;
    
    System* system = new System("System de teste");
    ExponencialFlow* flow1 = new ExponencialFlow("Flow1",system);
    
    flow1->clearSource();
    assert(flow1->getSource() == NULL);
    
    cout << GREEN << "OK!" << RESET << endl;  
}

void unit_flow_getTarget(){
    cout << "Teste 10 - Metodo getTarget() da classe Flow" << endl;
    
    System* system = new System("System de teste");    
    ExponencialFlow* flow = new ExponencialFlow("Flow1",NULL,system);    
    
    assert(flow->getTarget()->getName() == "System de teste");
    
    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_setTarget(){
    cout << "Teste 11 - Metodo setTarget() da classe Flow" << endl;
    
    System* system = new System("System de teste");
    ExponencialFlow* flow = new ExponencialFlow("Flow1");
    
    flow->setTarget(system);
    assert(flow->getTarget()->getName() == "System de teste");
    
    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_clearTarget(){
    cout << "Teste 12 - Metodo clearTarget() da classe Flow" << endl;
    
    System* system = new System("System de teste");    
    ExponencialFlow* flow = new ExponencialFlow("Flow", NULL, system); 
    
    flow->clearTarget();
    assert(flow->getTarget() == NULL);
    
    cout << GREEN << "OK!" << RESET << endl;  
}

void unit_flow_assingmentOperator(){
    cout << "Teste 13 - Operador de atribuicao da classe Flow" << endl;
    
    ExponencialFlow* flow1 = new ExponencialFlow("Flow1");
    ExponencialFlow* flow2 = new ExponencialFlow();
    *flow2 = *flow1;
    
    assert(flow2->getName() == "Flow1");
    assert(flow2->getSource() == NULL);
    assert(flow2->getTarget() == NULL);
    
    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_execute(){
    cout << "Teste 14 - Metodo execute() da classe Flow" << endl;
    
    System* system1 = new System("System de teste 1", 10.0);    
    System* system2 = new System("System de teste 2", 0.0);    
    ExponencialFlow* flow = new ExponencialFlow("Flow", system1, system2); 
    system2->setValue(flow->execute());

    assert(abs(flow->getTarget()->getValue() - 0.1) < 0.01);
    
    cout << GREEN << "OK!" << RESET << endl;
}

void run_unit_tests_flow() {
    unit_flow_constructor();  
    unit_flow_copy_constructor();
    unit_flow_destructor(); 
    unit_flow_getName();
    unit_flow_setName();
    unit_flow_getSource();
    unit_flow_setSource();
    unit_flow_clearSource();
    unit_flow_getTarget();
    unit_flow_setTarget();
    unit_flow_clearTarget();
    unit_flow_assingmentOperator();
    unit_flow_execute();
}