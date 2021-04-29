#pragma once
#include <map>
#include <iostream>
class Blackboard
{
public:
	Blackboard() {}

	std::map<std::string, float> bbFloatMap;
	std::map<std::string, int> bbIntMap;
	std::map<std::string, bool> bbBoolMap;

	void setVariable(std::string variableName, float variable);
	void setVariable(std::string variableName, int variable);
	void setVariable(std::string variableName, bool variable);

	template <typename T>
	T getVariable(std::string variableName)
	{
		std::cout << "TESTTT: " << typeid(T).name() << std::endl;

		if (strcmp(typeid(T).name(), "float") == 0) {
			return bbFloatMap[variableName];
		}

		if (strcmp(typeid(T).name(), "int") == 0) {
			return bbIntMap[variableName];
		}

		if (strcmp(typeid(T).name(), "bool") == 0) {
			return bbBoolMap[variableName];
		}
	}
};

