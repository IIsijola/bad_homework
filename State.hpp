#pragma once

class State{
public:
	char identifier;
	double (*transform)(double, double);
};
