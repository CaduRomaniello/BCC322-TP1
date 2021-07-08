#include "./modelImpl.h"      

/*!        
    This is the copy constructor for the Model Class.
    \param model the model that is going to be cloned.
    \param systems the vector of system pointers, it prevents memory leak.
    \param flows the vector of flow pointers, it prevents memory leak.      
*/ 
ModelImpl::ModelImpl (const ModelImpl& model){
    if (this == &model){
        return;
    }

    for (System* item : systems){
        delete(item);
    }           
    systems.clear();            
    
    for (Flow* item : flows){
        delete(item);
    } 
    flows.clear();

    name = model.getName();
    time = model.getTime();

    for(System* it : model.systems){
    // for(auto it = model.beginSystems(); it < model.endSystems(); ++it){
        System* item = it;
        System* copy = new SystemImpl(item->getName(), item->getValue());
        add(copy);
    }
    
    int count = 0;
    for (Flow* item : model.flows){
        int posSource = -1;
        int posTarget = -1;
        size_t size = sizeof(*item);

        Flow* temp = (Flow*) malloc(size);
        *temp = *item;
        add(temp);
            
        for (System* sys : model.systems){
            if (item->getSource() == sys){
                posSource = count;
            }
            if (item->getTarget() == sys){
                posTarget = count;
            }
            if (posSource != -1 && posTarget != -1){
                break;
            }

            count++;
        } 

        if (posSource != -1){
            temp->setSource(systems[posSource]);
        }
        else{
            temp->setSource(NULL);
        }
        if (posTarget != -1){
            temp->setTarget(systems[posTarget]);
        }
        else{
            temp->setTarget(NULL);
        }
    }
}

/*!
    This is the overloaded assignment operator for the Model Class.
*/
ModelImpl& ModelImpl::operator=(const ModelImpl& model){
    if (this == &model){
        return *this;
    }

    for (System* item : systems){
        delete(item);
    } 
    systems.clear();
    
    for (Flow* item : flows){
        delete(item);
    } 
    flows.clear();

    name = model.getName();
    time = model.getTime();   
    
    for (System* item : model.systems){
        System* copy(item);
        add(copy);
    }         

    for (Flow* item : model.flows){
        int posSource = -1;
        int posTarget = -1;
        int count = 0;
        Flow* copy(item);

        for (System* sys : model.systems){
            if (item->getSource() == sys){
                posSource = count;
            }
            if (item->getTarget() == sys){
                posTarget = count;
            }

            if (posSource != -1 && posTarget != -1){
                break;
            }

            count++;
        } 

        if (posSource != -1){
            copy->setSource(systems[posSource]);
        }
        else{
            copy->setSource(NULL);
        }
        if (posTarget != -1){
            copy->setTarget(systems[posTarget]);
        }
        else{
            copy->setTarget(NULL);
        }

        add(copy);
    }

    return *this;
}

ModelImpl::systemIterator ModelImpl::beginSystems( void ){return systems.begin();}
ModelImpl::systemIterator ModelImpl::endSystems( void ){return systems.end();}
ModelImpl::flowIterator ModelImpl::beginFlows( void ){return flows.begin();} 
ModelImpl::flowIterator ModelImpl::endFlows( void ){return flows.end();}  

ModelImpl::ModelImpl(string name, double time):name(name), time(time){}

ModelImpl::~ModelImpl(){           
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
    
void ModelImpl::execute(double start, double final, double increment){
    cout << "Cheguei no execute" << endl;
    
    vector<double> results;
    int count = 0;

    for (double k = start; k < final; k += increment){
        // Executes each flow 'i' in the model
        cout << "Loop do Flow* item" << endl;
        for (Flow* item : flows) {
            //BO aqui pq n reconhece execute()            
            results.push_back(item->execute());
        }

        // Updates the system's values associated with each flow 'i' in the model
        count = 0;
        cout << "Começa o loop interno do execute" << endl;
        for (Flow* item : flows) {
            // System* origin = item->getSource();
            item->getSource()->setValue(item->getSource()->getValue() - results[count]);

            // System* destiny = item->getTarget();
            item->getTarget()->setValue(item->getTarget()->getValue() + results[count]);

            count++;
        }
        cout << "Termina o loop interno do execute" << endl;


        // Resetting the results vector
        cout << "Começa loop de pop result" << endl;
        for (auto i = beginFlows(); i != endFlows(); ++i){
            results.pop_back();
        }
        cout << "Termina loop de pop result" << endl;

        time += increment;
    }

}

void ModelImpl::add(System* sys){
    systems.insert(endSystems(), sys);            
}

void ModelImpl::add(Flow* flow){
    // cout << "Inserindo flow* no vetor" << endl;
    flows.insert(endFlows(), flow);       
    // cout << "Consegui inserir flow* no vetor" << endl;
}

void ModelImpl::remove(System* sys){

    auto i = beginSystems();
    for (System* item : systems){
        if (sys == item){
            systems.erase(i);                    
            break;
        }
        ++i;
    }

}

void ModelImpl::remove(Flow* flow){

    auto i = beginFlows();
    for (Flow* item : flows){
        if (flow == item){
            flows.erase(i);                   
            break;
        }
        ++i;
    }

}

void ModelImpl::setName(string modelName){
    name = modelName;
}

string ModelImpl::getName() const{
    return name;
}    

void ModelImpl::setTime(double currentTime){
    time = currentTime;
}

double ModelImpl::getTime() const{
    return time;
}    

void ModelImpl::incrementTime(double increment) {
    time += increment;
}

System* ModelImpl::getSystem(int index){
    return systems[index];
}

Flow* ModelImpl::getFlow(int index){
    return flows[index];
}

