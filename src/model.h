#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include "./system.h"
#include "./flow.h"

using namespace std;

/**
 * Class Model - Campos
 * time -> double
*/

class Model{

    protected:
        string name;
        double time;
        vector<System*> systems;
        vector<Flow*> flows;

    public:
    
        // Construtores e Destrutores
        Model(){}
        Model(string name="", double time=0.0):name(name), time(time){}
        virtual ~Model(){

            // Deleta Systems
            int count = 0;
            for (auto i = systems.begin(); i != systems.end(); ++i){
                delete (systems[count]);
                count++;
            }
            
            // Deleta Flows
            count = 0;
            for (auto i = flows.begin(); i != flows.end(); ++i){
                delete (flows[count]);
                count++;
            }

        }

        // Executa modelo
        void execute(double start=0.0, double final=0.0, double increment=1.0){
            
            vector<double> results;

            for (double k = start; k < final; k += increment){
                // Para cada fluxo 'i' pertencente ao modelo executa ele
                for (int i = 0; i < (int) flows.size(); i++){
                    double result = flows[i]->execute();
                    results.push_back(result);
                }

                // Para cada fluxo 'i' pertencente ao modelo realiza o fluxo de dados
                for (int i = 0; i < (int) flows.size(); i++){
                    System* origin = flows[i]->getSource();
                    origin->setValue(origin->getValue() - results[i]);

                    System* destiny = flows[i]->getTarget();
                    destiny->setValue(destiny->getValue() + results[i]);
                }

                for (int i = 0; i < (int) flows.size(); i++){
                    results.pop_back();
                }
                time += increment;
            }

        }
        
        // Adiciona um System
        void add(System* sys){
            systems.push_back(sys);
        }
        
        // Adiciona um Flow
        void add(Flow* flow){
            flows.push_back(flow);
        }
        
        // Remove um System
        void remove(System* sys){

            int count = 0;
            for (auto i = systems.begin(); i < systems.end(); ++i){
                if (sys == systems[count]){
                    systems.erase(i);
                }
                count++;
            }

        }
        
        // Remove um Flow
        void remove(Flow* flow){

            int count = 0;
            for (auto i = flows.begin(); i < flows.end(); ++i){
                if (flow == flows[count]){
                    flows.erase(i);
                }
                count++;
            }

        }

        // Setters e Getters        
        void setName(string modelName){
            name = modelName;
        }

        string getName() const{
            return name;
        }    

        void setTime(double currentTime){
            time = currentTime;
        }

        double getTime() const{
            return time;
        }    

        // Incrementa tempo
        void incrementTime(double increment) {
            time += increment;
        }

    private: 

        //Construtor de cópia
        Model (const Model& model, vector<System*> systemsVector, vector<Flow*> flowsVector){
            if (this == &model){
                return;
            }
    
            systems = systemsVector;
            flows = flowsVector;
            name  = model.name;
            time  = model.time;
        }
        
        //Sobrecarga do operador de atribuição
        Model& operator=(const Model& model){
            if (this == &model){
                return *this;
            }

            name = model.name;
            time = model.time;
            systems = model.systems;
            flows = model.flows;

            return *this;
        }
};

#endif