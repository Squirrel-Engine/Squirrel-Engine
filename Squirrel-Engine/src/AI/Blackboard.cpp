#include "Blackboard.h"

void Blackboard::setVariable(std::string variableName, float variable)
{
	bbFloatMap.insert(std::pair<std::string, float>(variableName, variable));
}

void Blackboard::setVariable(std::string variableName, bool variable)
{
	bbBoolMap.insert(std::pair<std::string, bool>(variableName, variable));
}

void Blackboard::setVariable(std::string variableName, int variable)
{
	bbIntMap.insert(std::pair<std::string, int>(variableName, variable));
}