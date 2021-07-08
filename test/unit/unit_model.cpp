#include "unit_model.h"

using namespace std;

// Function for Model class's constructor unit test.
void unit_model_constructor(){
    cout << "TEST 1 - Default constructor of the Model class without passing parameters" << endl;

    Model* model1 = new Model();

    // Making assertion to verify if the name property was initialized with the default data.
    assert(model1->getName() == "");

    // Making assertion to verify if the time property was initialized with the default data.
    assert(model1->getTime() == 0.0);

    cout << GREEN << "OK!" << RESET << endl;
    cout << "TEST 2 - Default constructor of the Model class with passing parameters" << endl;

    System* system1 = new System("System 1");
    System* system2 = new System("System 2");

    vector<System*> systems;
    
    systems.push_back(system1);
    systems.push_back(system2);
    
    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    Model* model2 = new Model("Test Model", 1.0);

    model2->add(system1);
    model2->add(system2);
    model2->add(flow1);    
    
    // Making assertion to verify if the name property was initialized with the parameter specified.
    assert(model2->getName() == "Test Model");
    // Making assertion to verify if the time property was initialized with the parameter specified.
    assert(model2->getTime() == 1.0);
    // Making assertion to verify if the Flow object was added to the Model's flows parameter.
    assert((*(model2->beginFlows()))->getName() == "Flow 1");    
   
    int counter = 0;    
    for (auto sys = model2->beginSystems(); sys != model2->endSystems(); ++sys){
        // Making assertion to verify if the systems were added to the systems property.
        assert((*sys)->getName() == systems[counter]->getName());
        counter++;
    }

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for Model class's copy constructor unit test.
void UnitModel::unit_model_copy_constructor(){
    cout << "TEST 3 - Copy constructor of the Model class" << endl;

    System* system1 = new System("System 1", 100.0);    
    System* system2 = new System("System 2", 0.0);

    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1", system1, system2);
    Model* model1 = new Model("Model 1", 0.0);
    model1->add(system1);
    model1->add(system2);   
    model1->add(flow1); 

    // cout << "OOO CARAIO" << endl;

    Model* model2 = new Model(*model1);
    // cout << model1->systems[0] << " " << model2->systems[0] << endl;

    // cout << model2->getName() << endl;
    // Model* model2 = new Model(*model1);
    
    model1->setName("Original Model 1");
    
    // cout << model2->getName() << endl;
    // cout << model2->systems[0]->getValue() << endl;
    model1->execute(0.0, 100.0, 1.0);
    
    // Making assertion to verify changes made after model1 execution.
    // cout << model2->systems[0]->getValue() << endl;
    assert(abs(model2->systems[0]->getValue() - 100.0000) < 0.0001);
    assert(abs(model2->systems[1]->getValue() - 0.0000) < 0.0001);
    assert(abs(model2->getTime() - 0.0000) < 0.0001);
    
    model2->execute(0.0, 100.0, 1.0);

    assert(abs(model2->systems[0]->getValue() - 36.6032) < 0.0001);
    assert(abs(model2->systems[1]->getValue() - 63.3968) < 0.0001);
    assert(abs(model2->getTime() - 100.0) < 0.0001);
    
    // Making assertion to verify if the name property was copied before being changed.
    assert(model2->getName() == "Model 1");
    
    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' destructor unit test.
void unit_model_destructor(){
    cout << "TEST 4 - Default destructor of the Model class" << endl;
    
    double vmBefore, vmAfter, rss;

    // Getting the memory usage previous to the creation of a model.
    memory_usage(vmBefore, rss);
    
    System* system1 = new System("System 1");
    System* system2 = new System("System 2");
    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1");
    Model* model = new Model("Test Model", 1.0);

    model->add(system1);
    model->add(system2);
    model->add(flow1);

    delete model;

    // Getting the memory usage after the creation and destruction of a Flow object.
    memory_usage(vmAfter, rss);

    // Making assertion to verify if the memory usage after the creation and deletion
    // is the same as before the creation of Model object.
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' getName() method unit test.
void unit_model_getName(){
    cout << "TEST 5 - Model class's getName() method" << endl;
    
    Model* model = new Model("Test Model", 0.0);
    
    // Making assertion to verify if the method returns the Model class name and if it's
    // equal to the parameter previously passed.
    assert(model->getName() == "Test Model");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' setName() method unit test.
void unit_model_setName(){
    cout << "TEST 6 - Model class's setName() method" << endl;

    Model* model = new Model();
    model->setName("Test Model");
    
    // Making assertion to verify if the data of the name property has been altered.
    assert(model->getName() == "Test Model");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' getTime() method unit test.
void unit_model_getTime(){
    cout << "TEST 7 - Model class's getTime() method" << endl;

    Model* model = new Model("Test Model", 0.0);

    // Making assertion to verify if the method returns the Model class time and if it's
    // equal to the parameter previously passed.
    assert(model->getTime() == 0.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' setTime() method unit test.
void unit_model_setTime(){
    cout << "TEST 8 - Model class's setTime() method" << endl;

    Model* model = new Model("Test Model", 0.0);
    model->setTime(1.0);

    // Making assertion to verify if the data of the time property has been altered.
    assert(model->getTime() == 1.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' incrementTime() method unit test.
void unit_model_incrementTime(){
    cout << "TEST 9 - Model class's incrementTime() method" << endl;

    Model* model = new Model("Test Model", 1.0);
    model->incrementTime(1.0);
    
    // Making assertion to verify if the data of the time property has been incremented.
    assert(model->getTime() == 2.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' addSystem() method unit test.
void unit_model_addSystem(){
    cout << "TEST 10 - Model class's addSystem() method" << endl;
    
    System* system = new System("System 1");

    Model* model = new Model("Test Model", 1.0);
    model->add(system);

    // Making assertion to verify if the system has been added to the systems property.
    assert((*(model->beginSystems()))->getName() == system->getName());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' removeSystem() method unit test.
void unit_model_removeSystem(){
    cout << "TEST 11 - Model class's removeSystem() method" << endl;

    System* system = new System("System 1");

    Model* model = new Model("Test Model", 1.0);
    model->add(system);
    model->remove(system);
    
    // Making assertion to verify if the system has been removed from the systems property.
    assert(model->beginSystems() == model->endSystems());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' addFlow() method unit test.
void unit_model_addFlow(){
    cout << "TEST 12 - Model class's addFlow() method" << endl;

    ExponencialFlow* flow = new ExponencialFlow("Flow 1");
    Model* model = new Model("Test Model", 1.0);
    model->add(flow);
    
    // Making assertion to verify if the flow has been added to the flows property.
    assert((*(model->beginFlows()))->getName() == flow->getName());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' removeFlow() method unit test.
void unit_model_removeFlow(){
    cout << "TEST 13 - Model class's removeFlow() method" << endl;

    ExponencialFlow* flow = new ExponencialFlow("Flow 1");
    Model* model = new Model("Test Model", 1.0);
    model->add(flow);
    model->remove(flow);

    // Making assertion to verify if the system has been removed from the systems property.
    assert(model->beginFlows() == model->endFlows());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' assignment operator unit test.
void UnitModel::unit_model_assingmentOperator(){
    cout << "TEST 14 - Model class assignment operator" << endl;

    System* system1 = new System("System 1", 100.0);    
    System* system2 = new System("System 2", 0.0);

    ExponencialFlow* flow1 = new ExponencialFlow("Flow 1", system1, system2);
    Model* model1 = new Model("Model 1", 0.0);
    model1->add(system1);
    model1->add(system2);   
    model1->add(flow1); 

    Model* model2 = new Model();
    *model2 = *model1;
    
    model1->setName("Original Model 1");
    model1->execute(0.0, 100.0, 1.0);

    // Making assertion to verify changes made after model1 execution.
    assert(abs(model2->systems[0]->getValue() - 100.0) < 0.0001);
    assert(abs(model2->systems[1]->getValue() - 0.0) < 0.0001);
    assert(abs(model2->getTime() - 0.0) < 0.0001);
    
    model2->execute(0.0, 100.0, 1.0);

    assert(abs(model2->systems[0]->getValue() - 36.6032) < 0.0001);
    assert(abs(model2->systems[1]->getValue() - 63.3968) < 0.0001);
    assert(abs(model2->getTime() - 100.0) < 0.0001);
    
    // Making assertion to verify if the name property was copied before being changed.
    assert(model2->getName() == "Model 1");
    
    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' execute() method unit test.
void unit_model_execute(){
    cout << "TEST 15 - Model class's execute() method" << endl;
    
    System* pop1 = new System("Population 1", 100.0);
    System* pop2 = new System("Population 2", 0.0);
    ExponencialFlow* expFlow = new ExponencialFlow("Unlimited Growth", pop1, pop2);
    Model* expModel = new Model("Exponential Model", 0.0);
    
    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(expFlow);

    // Making assertions for the unit test before execution
    assert(pop1->getName() == "Population 1");
    assert(pop2->getName() == "Population 2");
    assert(expFlow->getName() == "Unlimited Growth");
    assert(expModel->getName() == "Exponential Model");

    assert(abs(pop1->getValue() - 100.0) < 0.0001);
    assert(abs(pop2->getValue() - 0.0) < 0.0001);
    assert(abs(expModel->getTime() - 0.0) < 0.0001);

    expModel->execute(0, 100, 1);

    // Making assertions for the unit test after execution
    assert(abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);
    assert(abs(expModel->getTime() - 100.0) < 0.0001);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function to run all the Model class' unit tests.
void run_unit_tests_model(){

    UnitModel* unit_model = new UnitModel();
    
    // Calling all the Model class' unit test functions.
    unit_model_constructor();
    unit_model->unit_model_copy_constructor();
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
    unit_model->unit_model_assingmentOperator();
    unit_model_execute();

    delete(unit_model);
}