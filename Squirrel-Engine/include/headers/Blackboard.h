#pragma once

class Blackboard
{
public:
	Blackboard() {}

	std::map<std::string, float*> T_bbFloatMap;
	std::map<std::string, int*> T_bbIntMap;
	std::map<std::string, bool*> T_bbBoolMap;

	std::map<std::string, float*> bbFloatMap;
	std::map<std::string, int*> bbIntMap;
	std::map<std::string, bool*> bbBoolMap;

	void setVariable(std::string variableName, float* variable);
	void setVariable(std::string variableName, int* variable);
	void setVariable(std::string variableName, bool* variable);

	bool isBlackboardUpdated();

	inline float* getFloatVariable(std::string variableName) {
		return bbFloatMap[variableName];
	}

	inline int* getIntVariable(std::string variableName) {
		return bbIntMap[variableName];
	}

	inline bool* getBoolVariable(std::string variableName) {
		return bbBoolMap[variableName];
	}
};

