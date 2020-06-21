#include <map>

#include "State.hpp"
#include "Stack.hpp"

class StateMachine{

private:
	int m_total;
	std::string m_terminator;

	Stack<std::string> * m_stack;
	State * m_current_state;

	std::map<char, State*> m_states;

public:
	StateMachine();
	void insert(char key, State *state);
	void run();

};