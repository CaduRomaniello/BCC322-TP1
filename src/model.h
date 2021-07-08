#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <map>
#include "./system.h"
#include "./flow.h"
#include <cstring>

using namespace std;

//! Class Model
/**
* This Class represents a model in the General Systems Theory implemented in this code.
*/
class Model{

    protected:
        string name; /*!< This attribute contains a name for the model. */
        double time; /*!< This attribute contains the current time in which the operations in the model is being executed. */
        vector<System*> systems; /*!< This attribute stores pointers to the systems contained in the model. */
        vector<Flow*> flows; /*!< This attribute stores pointers to the flows contained in the model. */       

        /*!        
           This is the copy constructor for the Model Class.
           \param model the model that is going to be cloned.
           \param systemsVector the vector of system pointers, it prevents memory leak.
           \param flowsVector the vector of flow pointers, it prevents memory leak.      
        */ 
        Model (const Model& model){
            // if (this == &model){
            //     return;
            // }
            // // cout << "*==========================*"<< endl;

            // for (System* item : systems){
            //     delete(item);
            // }           
            // systems.clear();            
            
            // for (Flow* item : flows){
            //     delete(item);
            // } 
            // flows.clear();

            // name = model.getName();
            // time = model.getTime();   
            
            // for (System* item : model.systems){
            //     System* copy = new System(*item);
            //     add(copy);
            // }         
            
            // int count = 0;
            // cout <<"Comeca loop" <<endl;
            // for (Flow* item : model.flows){
            //     int posSource = -1;
            //     int posTarget = -1;
            //     size_t size = sizeof(*item);
                
            //     // cout << "Cheguei" << endl;

            //     Flow* temp = (Flow*) malloc(size);
            //     // cout << "Oi" << endl;
            //     *temp = *item;
            //     // cout << "Tudo joia" << endl;
            //     add(temp);
                
            //     // cout << "Imprimindo endereços de memória" << endl;
            //     // cout << temp << " " << item << endl;
            //     // cout << "Endereço impresso" << endl;
            
            //     cout <<"Começa loop interno" <<endl;
            //     for (System* sys : model.systems){
            //         if (item->getSource() == sys){
            //             posSource = count;
            //         }
            //         if (item->getTarget() == sys){
            //             posTarget = count;
            //         }
            //         if (posSource != -1 && posTarget != -1){
            //             break;
            //         }

            //         count++;
            //     } 
            //     cout << "Terminei o loop interno" << endl;

            //     if (posSource != -1){
            //         temp->setSource(systems[posSource]);
            //     }
            //     else{
            //         temp->setSource(NULL);
            //     }
            //     if (posTarget != -1){
            //         temp->setTarget(systems[posTarget]);
            //     }
            //     else{
            //         temp->setTarget(NULL);
            //     }

            //     // add(temp);

            //     count++;
            // }
            // cout <<"Termina loop" <<endl;
            
        }
        
        /*!
            This is the overloaded assignment operator for the Model Class.
        */
        Model& operator=(const Model& model){
            // if (this == &model){
            //     return *this;
            // }

            // for (System* item : systems){
            //     delete(item);
            // } 
            // systems.clear();
           
            // for (Flow* item : flows){
            //     delete(item);
            // } 
            // flows.clear();

            // name = model.getName();
            // time = model.getTime();   
            
            // for (System* item : model.systems){
            //     System* copy(item);
            //     add(copy);
            // }         

            // for (Flow* item : model.flows){
            //     int posSource = -1;
            //     int posTarget = -1;
            //     int count = 0;
            //     Flow* copy(item);

            //     for (System* sys : model.systems){
            //         if (item->getSource() == sys){
            //             posSource = count;
            //         }
            //         if (item->getTarget() == sys){
            //             posTarget = count;
            //         }

            //         if (posSource != -1 && posTarget != -1){
            //             break;
            //         }

            //         count++;
            //     } 

            //     if (posSource != -1){
            //         copy->setSource(systems[posSource]);
            //     }
            //     else{
            //         copy->setSource(NULL);
            //     }
            //     if (posTarget != -1){
            //         copy->setTarget(systems[posTarget]);
            //     }
            //     else{
            //         copy->setTarget(NULL);
            //     }

            //     add(copy);
            // }

            return *this;
        }

    public:
        friend class UnitModel; /*!< This Class is used to test the copy constructor and assignment operator of the Model class. */

        auto beginSystems( void ) const {return systems.begin();} /*!< Returns the iterator to the beginning of systems attribute. */
        auto endSystems( void ) const {return systems.end();} /*!< Returns the iterator to the end of systems attribute. */
        auto beginFlows( void ) const {return flows.begin();} /*!< Returns the iterator to the beginning of flows attribute. */
        auto endFlows( void ) const {return flows.end();} /*!< Returns the iterator to the end of flows attribute. */
        
        /*!
            This is the default constructor for the Model Class. 
            \param name the name of the Model Class.
            \param time the time for the Model Class to run.
            \return Model - a Model Class object.
        */
        Model(string name="", double time=0.0):name(name), time(time){cout << "Construtor default" << endl;}
        
        /*!
            This is the default destructor for the Model Class.
        */
        virtual ~Model(){           
            // Deletes Flows
            for (Flow* item : flows) {
                delete (item);
            }
            flows.clear();

            // Deletes Systems
            for (System* item : systems) {
                delete (item);
            }
            systems.clear();
        }
            
        /*!
            Executes all the flows in the model.
            \param start the initial time.
            \param final the final time.
            \param increment represents the iteration step.
        */
        void execute(double start=0.0, double final=0.0, double increment=1.0){
            // cout << "Cheguei no execute" << endl;
            
            vector<double> results;
            int count = 0;

            for (double k = start; k < final; k += increment){
                // Executes each flow 'i' in the model
                for (Flow* item : flows) {
                    double result = item->execute();
                    results.push_back(result);
                }

                // Updates the system's values associated with each flow 'i' in the model
                count = 0;
                // cout << "Começa o loop interno do execute" << endl;
                for (Flow* item : flows) {
                    // System* origin = item->getSource();
                    item->getSource()->setValue(item->getSource()->getValue() - results[count]);

                    // System* destiny = item->getTarget();
                    item->getTarget()->setValue(item->getTarget()->getValue() + results[count]);

                    count++;
                }
                // cout << "Termina o loop interno do execute" << endl;


                // Resetting the results vector
                // cout << "Começa loop de pop result" << endl;
                for (auto i = beginFlows(); i != endFlows(); ++i){
                    results.pop_back();
                }
                // cout << "Termina loop de pop result" << endl;

                time += increment;
            }

        }
        
        /*!        
           Adds a system's pointer to the systems vector.
           \param sys the system to be added.
        */ 
        void add(System* sys){
            systems.insert(endSystems(), sys);            
        }
        
        /*!        
           Adds a flow's pointer to the flows vector. 
           \param flow the flow to be added.
        */ 
        void add(Flow* flow){
            // cout << "Inserindo flow* no vetor" << endl;
            flows.insert(endFlows(), flow);       
            // cout << "Consegui inserir flow* no vetor" << endl;
        }
        
        /*!        
           Removes a system's pointer on the systems vector.
           \param sys which will be removed from the vector flows.  
        */ 
        void remove(System* sys){

            auto i = beginSystems();
            for (System* item : systems){
                if (sys == item){
                    systems.erase(i);                    
                    break;
                }
                ++i;
            }

        }
      
        /*!
           Removes a flow's pointer on the flows vector.
           \param flow which will be removed from the vector flows. 
        */
        void remove(Flow* flow){

            auto i = beginFlows();
            for (Flow* item : flows){
                if (flow == item){
                    flows.erase(i);                   
                    break;
                }
                ++i;
            }

        }

        /*!
            Sets the name attribute in the Model Class.
            \param modelName which will be set to the current model.
        */
        void setName(string modelName){
            name = modelName;
        }

        /*!
            Returns the name attribute in the Model Class.
            \return string - the name attribute.
        */
        string getName() const{
            return name;
        }    

        /*!
            Sets the time attribute in the Model Class.
            \param currentTime which will be set to the current model.
        */
        void setTime(double currentTime){
            time = currentTime;
        }

        /*!
            Returns the time attribute in the Model Class.
            \return double - the time attribute.
        */
        double getTime() const{
            return time;
        }    

        /*!
            This method increments the time attribute in the Model Class.
            \param increment which will define by how much time should increment.
        */
        void incrementTime(double increment) {
            time += increment;
        }

};

#endif