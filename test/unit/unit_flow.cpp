#include "unit_flow.h"

using namespace std;

void unit_flow_constructor() {
    cout << "TEST 1 - Default constructor of the Flow class without passing parameters" << endl;

    ExponencialFlow* flow1 = new ExponencialFlow();
    
    assert(flow1->getName() == "");
    assert(flow1->getSource() == NULL);
    assert(flow1->getTarget() == NULL);

    cout << GREEN << "OK!" << RESET << endl;
    cout << "TEST 2 - Default constructor of the Flow class with passing parameters" << endl;

    System* source = new System("System1", 5.0);
    System* target = new System("System2", 10.0);

    ExponencialFlow* flow2 = new ExponencialFlow("Flow2", source, target);
    
    assert(flow2->getName() == "Flow2");
    assert(flow2->getSource() == source);
    assert(flow2->getTarget() == target);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_copy_constructor() {
    cout << "TEST 3 - Copy constructor of the Flow class" << endl;

    ExponencialFlow* flow1 = new ExponencialFlow("Flow1");
    ExponencialFlow* flow2(flow1);
    
    assert(flow2->getName() == "Flow1");
    assert(flow2->getSource() == NULL);
    assert(flow2->getTarget() == NULL);

    cout << GREEN << "OK!" << RESET << endl;
} 

void unit_flow_destructor() {
    cout << "TEST 4 - Default destructor of the Flow class" << endl;

    double vmBefore, vmAfter, rss;
    memory_usage(vmBefore, rss);
  
    ExponencialFlow* flow = new ExponencialFlow("Flow");
    delete flow;

    memory_usage(vmAfter, rss);
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_getName() {
    cout << "TEST 5 - Flow class's getName() method" << endl;
    
    ExponencialFlow* flow = new ExponencialFlow("Flow1");
    assert(flow->getName() == "Flow1");
    
    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_setName() {
    cout << "TEST 6 - Flow class's setName() method" << endl;

    ExponencialFlow* flow = new ExponencialFlow();
    
    flow->setName("Flow1");
    assert(flow->getName() == "Flow1");

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_getSource(){
    cout << "TEST 7 - Flow class's getSource() method" << endl;
    
    System* system = new System("System de teste");
    ExponencialFlow* flow = new ExponencialFlow("Flow1",system);
    
    assert(flow->getSource()->getName() == "System de teste");
    
    cout << GREEN << "OK!" << RESET << endl;  
}

void unit_flow_setSource(){
    cout << "TEST 8 - Flow class's setSource() method" << endl;
    
    System* system = new System("System de teste");
    ExponencialFlow* flow1 = new ExponencialFlow("Flow1");
   
    flow1->setSource(system);
    assert(flow1->getSource()->getName() == "System de teste");
    
    cout << GREEN << "OK!" << RESET << endl;  
}

void unit_flow_clearSource(){
    cout << "TEST 9 - Flow class's clearSource() method" << endl;
    
    System* system = new System("System de teste");
    ExponencialFlow* flow1 = new ExponencialFlow("Flow1",system);
    
    flow1->clearSource();
    assert(flow1->getSource() == NULL);
    
    cout << GREEN << "OK!" << RESET << endl;  
}

void unit_flow_getTarget(){
    cout << "TEST 10 - Flow class's getTarget() method" << endl;
    
    System* system = new System("System de teste");    
    ExponencialFlow* flow = new ExponencialFlow("Flow1",NULL,system);    
    
    assert(flow->getTarget()->getName() == "System de teste");
    
    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_setTarget(){
    cout << "TEST 11 - Flow class's setTarget() method" << endl;
    
    System* system = new System("System de teste");
    ExponencialFlow* flow = new ExponencialFlow("Flow1");
    
    flow->setTarget(system);
    assert(flow->getTarget()->getName() == "System de teste");
    
    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_clearTarget(){
    cout << "TEST 12 - Flow class's clearTarget() method" << endl;
    
    System* system = new System("System de teste");    
    ExponencialFlow* flow = new ExponencialFlow("Flow", NULL, system); 
    
    flow->clearTarget();
    assert(flow->getTarget() == NULL);
    
    cout << GREEN << "OK!" << RESET << endl;  
}

void unit_flow_assingmentOperator(){
    cout << "TEST 13 - Flow class assignment operator" << endl;
    
    ExponencialFlow* flow1 = new ExponencialFlow("Flow1");
    ExponencialFlow* flow2 = new ExponencialFlow();
    *flow2 = *flow1;
    
    assert(flow2->getName() == "Flow1");
    assert(flow2->getSource() == NULL);
    assert(flow2->getTarget() == NULL);
    
    cout << GREEN << "OK!" << RESET << endl;
}

void unit_flow_execute(){
    cout << "TEST 14 - Flow class's execute() method" << endl;
    
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