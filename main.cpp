#include <iostream>
#include <cstring>

#include "State.cpp"
#include "Stack.cpp"
#include "StateMachine.cpp"
using namespace std;

int main(int argc, char const *argv[])
{

	State * multiplication = new State();
	multiplication->identifier = '*';
	multiplication->transform = [] (double x, double y) {return x*y;};


	State * addition = new State();
	addition->identifier = '+';
	addition->transform = [] (double x, double y) {return x+y;};


	State * subtraction = new State();
	subtraction->identifier = '-';
	subtraction->transform = [] (double x, double y) {return x-y;};

	State * division = new State();
	division->identifier = '/';
	division->transform = [] (double x, double y) {return x/y;};

	StateMachine * deus_ex_machine = new StateMachine();

	deus_ex_machine->insert(multiplication->identifier, multiplication);
	deus_ex_machine->insert(subtraction->identifier, subtraction);
	deus_ex_machine->insert(addition->identifier, addition);
	deus_ex_machine->insert(division->identifier, division);

	try{
		deus_ex_machine->run();
	}catch(const char * msg){
		cout << msg << endl;
	}catch(out_of_range & e){
		cout << "The number inputed is too large/small" << endl;
	}

	delete deus_ex_machine;
	// delete the statemachine before deleting the states to reduce the likelihood of UAF bugs
	delete multiplication;
	delete subtraction;
	delete addition;
	delete division;

	return 0;
}