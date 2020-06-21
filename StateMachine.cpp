#include <iostream>

#include "StateMachine.hpp"

StateMachine::StateMachine(){
	m_total = 0;
	m_terminator = ";";
	m_stack = new Stack<std::string>;
	m_current_state = nullptr;
}

void StateMachine::insert(char key, State * state){
	m_states.insert(std::make_pair(key, state));
}

void StateMachine::run(){
	std::string input;
	std::cin >> input;

	int x;

	while(input != ";"){
		m_stack->push(input);
		std::cin >> input;
	}


	while(!m_stack->empty()){

		input = m_stack->pop();

		try{

			x = std::stoi(input);
			if(m_total == 0){
				m_total += x;
				continue;
			}else if(m_current_state != nullptr){
				m_total = m_current_state->transform(m_total, x);
			}

			m_current_state = nullptr;

		}catch(std::invalid_argument &e){

			// this is when we get an operator
			if(input.length() != 1) throw "Invalid operator";
			if(m_current_state != nullptr) throw "Two operators in a row";
			const char * operand = input.c_str();
			//  need to fix this
			m_current_state = m_states.at(*operand);
			// std::cout << m_current_state << std::endl;


		}catch(std::out_of_range & e){
			std::cout << "Number inputed is too large/small " << std::endl;
		}catch(...){

		}

	}

	std::cout << m_total << std::endl;

	// check if the type can be coerced to an integer
	// if not then check if it causes a state transition



}

