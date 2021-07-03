#include <iostream>

#include "funcional_tests.h" 
#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/model.h"

using namespace std;

// Function for exponential functional test.
void exponentialFuncionalTest(){
    cout << "TEST 1 - Simple model with exponential equation" << endl;

    //Creates elements of the model
    System* pop1 = new System("Population 1", 100);
    System* pop2 = new System("Population 2", 0);
    ExponencialFlow* expFlow = new ExponencialFlow("Unlimited Growth", pop1, pop2);
    Model* expModel = new Model("Exponential Model", 0.0);
    
    //Building the model
    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(expFlow);

    //Executes the model
    expModel->execute(0, 100, 1);

    delete (expModel);
    cout << GREEN << "OK!"<< RESET << endl;
}

// Function for logistical functional test.
void logisticalFuncionalTest(){
    cout << "TEST 2 - Simple model with logistic equation" << endl;
    
    //Creates elements of the model
    System* p1 = new System("Population 1", 100);
    System* p2 = new System("Population 2", 10);
    LogisticFlow* logFlow = new LogisticFlow("Limited Growth", p1, p2);
    Model* logModel = new Model("Logistic Model", 0.0);
    
    //Building the model
    logModel->add(p1);
    logModel->add(p2);
    logModel->add(logFlow);

    //Executes the model
    logModel->execute(0, 100, 1);

    delete(logModel);
    cout << GREEN << "OK!"<< RESET << endl;
}

// Function for complex functional test.
void complexFuncionalTest(){
    cout << "TEST 3 - Complex model" << endl;
    
    //Creates elements of the model
    System* q1 = new System("Q1", 100);
    System* q2 = new System("Q2", 0);
    System* q3 = new System("Q3", 100);
    System* q4 = new System("Q4", 0);
    System* q5 = new System("Q5", 0);
    ComplexFlowF* comFlowF = new ComplexFlowF("Flow f", q1, q2);
    ComplexFlowT* comFlowT = new ComplexFlowT("Flow t", q2, q3);
    ComplexFlowU* comFlowU = new ComplexFlowU("Flow u", q3, q4);
    ComplexFlowV* comFlowV = new ComplexFlowV("Flow v", q4, q1);
    ComplexFlowG* comFlowG = new ComplexFlowG("Flow g", q1, q3);
    ComplexFlowR* comFlowR = new ComplexFlowR("Flow r", q2, q5);
    Model* comModel = new Model("Complex Model", 0.0);
    
    //Building the model
    comModel->add(q1);
    comModel->add(q2);
    comModel->add(q3);
    comModel->add(q4);
    comModel->add(q5);
    comModel->add(comFlowF);
    comModel->add(comFlowT);
    comModel->add(comFlowU);
    comModel->add(comFlowV);
    comModel->add(comFlowG);
    comModel->add(comFlowR);

    //Executes the model
    comModel->execute(0, 100, 1);

    delete(comModel);
    cout << GREEN << "OK!"<< RESET << endl;
}