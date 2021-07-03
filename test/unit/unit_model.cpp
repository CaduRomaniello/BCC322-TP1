#include "unit_model.h"

using namespace std;

void unit_model_constructor(){
    cout << "Teste 1 - Construtor default da classe Model sem passagem de parametros" << endl;

    Model* model1 = new Model();

    assert(model1->getName() == "");
    assert(model1->getTime() == 0.0);

    cout << GREEN << "OK!" << RESET << endl;
    cout << "Teste 2 - Construtor default da classe Model com passagem de parametros" << endl;

    System* system1 = new System("System 1");
    System* system2 = new System("System 2");

    vector<System*> systems;
    systems.push_back(system1);
    systems.push_back(system2);

    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    Model* model2 = new Model("Model de teste", 1.0);

    model2->add(system1);
    model2->add(system2);
    model2->add(flow1);    
    
    assert(model2->getName() == "Model de teste");
    assert(model2->getTime() == 1.0);
    assert((*(model2->beginFlows()))->getName() == "Flow 1");
    
    int counter = 0;
    for (auto sys = model2->beginSystems(); sys != model2->endSystems(); ++sys){
        assert((*sys)->getName() == systems[counter]->getName());
        counter++;
    }

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_copy_constructor(){
    cout << "Teste 3 - Construtor de cópia da classe Model" << endl;

    Model* model1 = new Model();

    System* system1 = new System("System 1");
    System* system2 = new System("System 2");

    vector<System*> systems;
    systems.push_back(system1);
    systems.push_back(system2);

    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    Model* model2 = new Model(*model1);

    model2->add(system1);
    model2->add(system2);
    model2->add(flow1);    
    
    assert(model2->getName() == "");
    assert(model2->getTime() == 0.0);
    assert((*(model2->beginFlows()))->getName() == "Flow 1");
    
    int counter = 0;
    for (auto sys = model2->beginSystems(); sys != model2->endSystems(); ++sys){
        assert((*sys)->getName() == systems[counter]->getName());
        counter++;
    }

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_destructor(){
    cout << "Teste 4 - Destrutor default da classe Model" << endl;

    double vmBefore, vmAfter, rss;
    memory_usage(vmBefore, rss);
  
    System* system1 = new System("System 1");
    System* system2 = new System("System 2");

    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    Model* model = new Model("Model de teste", 1.0);

    model->add(system1);
    model->add(system2);
    model->add(flow1);   
    delete model;

    memory_usage(vmAfter, rss);
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_getName(){
    cout << "Teste 5 - Metodo getName() da classe Model" << endl;

    Model* model = new Model("Modelo Teste", 0.0);
    assert(model->getName() == "Modelo Teste");

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_setName(){
    cout << "Teste 6 - Metodo setName() da classe Model" << endl;

    Model* model = new Model();
    model->setName("Modelo Teste");
    assert(model->getName() == "Modelo Teste");

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_getTime(){
    cout << "Teste 7 - Metodo getTime() da classe Model" << endl;

    Model* model = new Model("Modelo Teste", 0.0);
    assert(model->getTime() == 0.0);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_setTime(){
    cout << "Teste 8 - Metodo setTime() da classe Model" << endl;

    Model* model = new Model("Modelo Teste", 0.0);
    model->setTime(1.0);
    assert(model->getTime() == 1.0);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_incrementTime(){
    cout << "Teste 9 - Metodo incrementTime() da classe Model" << endl;

    Model* model = new Model("Modelo Teste", 1.0);
    model->incrementTime(1.0);
    assert(model->getTime() == 2.0);

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_addSystem(){
    cout << "Teste 10 - Metodo addSystem() da classe Model" << endl;

    System* system = new System("System 1");

    Model* model = new Model("Modelo Teste", 1.0);
    model->add(system);
    assert((*(model->beginSystems()))->getName() == system->getName());

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_removeSystem(){
    cout << "Teste 11 - Metodo removeSystem() da classe Model" << endl;

    System* system = new System("System 1");

    Model* model = new Model("Modelo Teste", 1.0);
    model->add(system);
    model->remove(system);
    
    assert(model->beginSystems() == model->endSystems());

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_addFlow(){
    cout << "Teste 12 - Metodo addFlow() da classe Model" << endl;

    ExponencialFlow* flow = new ExponencialFlow("Flow 1");
    Model* model = new Model("Modelo Teste", 1.0);
    model->add(flow);
    
    assert((*(model->beginFlows()))->getName() == flow->getName());

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_removeFlow(){
    cout << "Teste 13 - Metodo removeFlow() da classe Model" << endl;

    ExponencialFlow* flow = new ExponencialFlow("Flow 1");
    Model* model = new Model("Modelo Teste", 1.0);
    model->add(flow);
    model->remove(flow);

    assert(model->beginFlows() == model->endFlows());

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_assingmentOperator(){
    cout << "Teste 14 - Operador de atribuicao da classe Model" << endl;

    Model* model1 = new Model();

    System* system1 = new System("System 1");
    System* system2 = new System("System 2");

    vector<System*> systems;
    systems.push_back(system1);
    systems.push_back(system2);

    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    Model* model2 = new Model();
    *model2 = *model1;

    model2->add(system1);
    model2->add(system2);
    model2->add(flow1);    
    
    assert(model2->getName() == "");
    assert(model2->getTime() == 0.0);
    assert((*(model2->beginFlows()))->getName() == "Flow 1");
    
    int counter = 0;
    for (auto sys = model2->beginSystems(); sys != model2->endSystems(); ++sys){
        assert((*sys)->getName() == systems[counter]->getName());
        counter++;
    }

    cout << GREEN << "OK!" << RESET << endl;
}

void unit_model_execute(){
    cout << "Teste 15 - Metodo execute() da classe Model" << endl;
    
    //Creates elements of the model
    System* pop1 = new System("Populacao 1", 100.0);
    System* pop2 = new System("Populacao 2", 0.0);
    ExponencialFlow* expFlow = new ExponencialFlow("Crescimento ilimitado", pop1, pop2);
    Model* expModel = new Model("Modelo Exponencial", 0.0);
    
    // Building the model
    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(expFlow);

    // Making assertions for the unit test before execution
    assert(pop1->getName() == "Populacao 1");
    assert(pop2->getName() == "Populacao 2");
    assert(expFlow->getName() == "Crescimento ilimitado");
    assert(expModel->getName() == "Modelo Exponencial");

    assert(abs(pop1->getValue() - 100.0) < 0.0001);
    assert(abs(pop2->getValue() - 0.0) < 0.0001);
    assert(abs(expModel->getTime() - 0.0) < 0.0001);

    // Executes the model
    expModel->execute(0, 100, 1);

    // Making assertions for the unit test after execution
    assert(abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);
    assert(abs(expModel->getTime() - 100.0) < 0.0001);

    cout << GREEN << "OK!" << RESET << endl;
}

void run_unit_tests_model(){
    unit_model_constructor();
    unit_model_copy_constructor();
    unit_model_destructor();
    unit_model_getName();
    unit_model_setName();
    unit_model_getTime();
    unit_model_setTime();
    unit_model_incrementTime();
    unit_model_addSystem();
    unit_model_removeSystem();
    unit_model_addFlow();
    unit_model_removeFlow();
    unit_model_assingmentOperator();
    unit_model_execute();
}