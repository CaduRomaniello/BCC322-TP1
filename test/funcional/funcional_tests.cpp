#include <iostream>

#include "funcional_tests.h" 
#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/model.h"

using namespace std;

void exponentialFuncionalTest(){
    cout << "TESTE 4 - modelo simples com equacao exponencial" << endl;
    
    //Cria elementos do modelo
    System* pop1 = new System("Populacao 1", 100);
    System* pop2 = new System("Populacao 2", 0);
    ExponencialFlow* expFlow = new ExponencialFlow("Crescimento ilimitado", pop1, pop2);
    Model* expModel = new Model("Modelo Exponencial", 0.0);
    
    //Monta modelo
    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(expFlow);

    //Simula o modelo
    expModel->execute(0, 100, 1);

    delete (expModel);
    cout << "OK" << endl;
}

void logisticalFuncionalTest(){
    cout << "TESTE 5 - modelo simples com equacao logistica" << endl;
    
    //Cria elementos do modelo
    System* p1 = new System("Populacao 1", 100);
    System* p2 = new System("Populacao 2", 10);
    LogisticFlow* logFlow = new LogisticFlow("Crescimento limitado", p1, p2);
    Model* logModel = new Model("Modelo Logistico", 0.0);
    
    //Monta modelo
    logModel->add(p1);
    logModel->add(p2);
    logModel->add(logFlow);

    //Simula o modelo
    logModel->execute(0, 100, 1);

    delete(logModel);
    cout << "OK" << endl;
}

void complexFuncionalTest(){
    cout << "TESTE 6 - modelo complexo" << endl;
    
    //Cria elementos do modelo
    System* q1 = new System("Q1", 100);
    System* q2 = new System("Q2", 0);
    System* q3 = new System("Q3", 100);
    System* q4 = new System("Q4", 0);
    System* q5 = new System("Q5", 0);
    ComplexFlowF* comFlowF = new ComplexFlowF("Fluxo f", q1, q2);
    ComplexFlowT* comFlowT = new ComplexFlowT("Fluxo t", q2, q3);
    ComplexFlowU* comFlowU = new ComplexFlowU("Fluxo u", q3, q4);
    ComplexFlowV* comFlowV = new ComplexFlowV("Fluxo v", q4, q1);
    ComplexFlowG* comFlowG = new ComplexFlowG("Fluxo g", q1, q3);
    ComplexFlowR* comFlowR = new ComplexFlowR("Fluxo r", q2, q5);
    Model* comModel = new Model("Modelo Complexo", 0.0);
    
    //Monta modelo
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

    //Simula o modelo
    comModel->execute(0, 100, 1);

    delete(comModel);
    cout << "OK" << endl;
}