#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include "./unit_system.h"
#include "./unit_flow.h"
#include "./unit_model.h"

int main(){

    cout << "\n========== Testes unitarios da Classe System ===========\n" << endl;
    run_unit_tests_system();
    cout << "\n=========== Testes unitarios da Classe Flow ============\n" << endl;
    run_unit_tests_flow();
    cout << "\n=========== Testes unitarios da Classe Model ===========\n"<< endl;
    cout << "Descomentar para funcionar." << endl;
    //run_unit_tests_model();
    cout << "\n========================================================\n" << endl;

    return 0;
}

#endif