#include "Blackboard.h"

void Blackboard::setVariable(std::string variableName, float* variable)
{
	bbFloatMap.insert(std::pair<std::string, float*>(variableName, variable));
}

void Blackboard::setVariable(std::string variableName, bool* variable)
{
	bbBoolMap.insert(std::pair<std::string, bool*>(variableName, variable));
}

bool Blackboard::isBlackboardUpdated()
{
	int temp = 0;

	if (bbFloatMap.size() != 0){
		for (const auto& firstVal : bbFloatMap) {
			if (T_bbFloatMap.size() == 0) {
				for (const auto& e : bbFloatMap)
				{
					T_bbFloatMap[e.first] = new float(*e.second);
				}
				temp++;
			}
			else {
				for (const auto& secondVal : T_bbFloatMap) {
					if (*firstVal.first.c_str() == *secondVal.first.c_str() && *firstVal.second == *secondVal.second) {}
					else {
						for (const auto& e : bbFloatMap)
						{
							T_bbFloatMap[e.first] = new float(*e.second);
						}
						temp++;
					}
				}
			}
		}
	}

	if (bbBoolMap.size() != 0){
		for (const auto& firstVal : bbBoolMap) {
			if (T_bbBoolMap.size() == 0) {
				for (const auto& e : bbBoolMap)
				{
					T_bbBoolMap[e.first] = new bool(*e.second);
				}
				temp++;
			}
			else {
				for (const auto& secondVal : T_bbBoolMap) {
					if (*firstVal.first.c_str() == *secondVal.first.c_str() && *firstVal.second == *secondVal.second) {}
					else {
						for (const auto& e : bbBoolMap)
						{
							T_bbBoolMap[e.first] = new bool(*e.second);
						}
						temp++;
					}
				}
			}
		}
	}

	if (bbIntMap.size() != 0) {
		for (const auto& firstVal : bbIntMap) {
			if (T_bbIntMap.size() == 0) {
				for (const auto& e : bbIntMap)
				{
					T_bbIntMap[e.first] = new int(*e.second);
				}
				temp++;
			}
			else {
				for (const auto& secondVal : T_bbIntMap) {
					if (*firstVal.first.c_str() == *secondVal.first.c_str() && *firstVal.second == *secondVal.second) {}
					else {
						for (const auto& e : bbIntMap)
						{
							T_bbIntMap[e.first] = new int(*e.second);
						}
						temp++;
					}
				}
			}
		}
	}

	if (temp > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Blackboard::setVariable(std::string variableName, int* variable)
{
	bbIntMap.insert(std::pair<std::string, int*>(variableName, variable));
}