#include "Blackboard.h"

template <typename Map>
bool map_compare(Map const& lhs, Map const& rhs) {
	return lhs == rhs;
}

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
	
	if (map_compare(bbFloatMap, T_bbFloatMap)){}
	else{
		T_bbFloatMap.insert(bbFloatMap.begin(), bbFloatMap.end());
		return true;
	}

	if (map_compare(bbBoolMap, T_bbBoolMap)){}
	else{ 
	
		T_bbBoolMap.insert(bbBoolMap.begin(), bbBoolMap.end());
		return true;
	}

	for (const auto& firstVal : bbIntMap) {
		if (T_bbIntMap.size() == 0) {
			for (const auto& e : bbIntMap)
			{
				T_bbIntMap[e.first] = new int(*e.second);
			}
			return true;
		}
		else {
			for (const auto& secondVal : T_bbIntMap) {
				if (*firstVal.first.c_str() == *secondVal.first.c_str() && *firstVal.second == *secondVal.second) {}
				else {
					for (const auto& e : bbIntMap)
					{
						T_bbIntMap[e.first] = new int(*e.second);
					}
					return true;
				}
			}
		}
	}

	return false;
}

void Blackboard::setVariable(std::string variableName, int* variable)
{
	bbIntMap.insert(std::pair<std::string, int*>(variableName, variable));
}