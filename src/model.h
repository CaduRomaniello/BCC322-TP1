#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include "./system.h"
#include "./flow.h"

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

    public:
    
        /*!
            This is the default constructor for the Model Class.
        */
        Model(){}
        
        /*!
            This is a more elaborated constructor for the Model Class.
            \param name the name of the Model Class.
            \param time the time for the Model Class to run.
            \return Model - a Model Class object.
        */
        Model(string name="", double time=0.0):name(name), time(time){}
        
        /*!
            This is the default destructor for the Model Class.
        */
        virtual ~Model(){
            
            // Deletes Systems
            int count = 0;
            for (auto i = systems.begin(); i != systems.end(); ++i){
                delete (systems[count]);
                count++;
            }
            
            // Deletes Flows
            count = 0;
            for (auto i = flows.begin(); i != flows.end(); ++i){
                delete (flows[count]);
                count++;
            }

        }

        /*!
            Executes all the flows in the model.
            \param start the initial time.
            \param final the final time.
            \param increment represents the iteration step.
        */
        void execute(double start=0.0, double final=0.0, double increment=1.0){
            
            vector<double> results;

            for (double k = start; k < final; k += increment){
                // Executes each flow 'i' in the model
                for (int i = 0; i < (int) flows.size(); i++){
                    double result = flows[i]->execute();
                    results.push_back(result);
                }

                // Updates the system's values associated with each flow 'i' in the model
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
        
        /*!        
           Adds a system's pointer to the systems vector. 
           \param sys the system to be added.
        */ 
        void add(System* sys){
            systems.push_back(sys);
        }
        
        /*!        
           Adds a flow's pointer to the flows vector. 
           \param flow the flow to be added.
        */ 
        void add(Flow* flow){
            flows.push_back(flow);
        }
        
        /*!        
           Removes a system's pointer on the systems vector.
           \param sys which will be removed from the vector flows.  
        */ 
        void remove(System* sys){

            int count = 0;
            for (auto i = systems.begin(); i < systems.end(); ++i){
                if (sys == systems[count]){
                    systems.erase(i);
                }
                count++;
            }

        }
        
        /*!        
           Removes a flow's pointer on the flows vector.
           \param flow which will be removed from the vector flows. 
        */ 
        void remove(Flow* flow){

            int count = 0;
            for (auto i = flows.begin(); i < flows.end(); ++i){
                if (flow == flows[count]){
                    flows.erase(i);
                }
                count++;
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

    private: 

        /*!        
           This is the copy constructor for the Model Class.
           \param model the model that is going to be cloned.
           \param systemsVector the vector of system pointers, it prevents memory leak.
           \param flowsVector the vector of flow pointers, it prevents memory leak.      
        */ 
        Model (const Model& model, vector<System*> systemsVector, vector<Flow*> flowsVector){
            if (this == &model){
                return;
            }
    
            systems = systemsVector;
            flows = flowsVector;
            name  = model.name;
            time  = model.time;
        }
        
        /*!
            This is the overloaded equal operator for the Model Class.
        */
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