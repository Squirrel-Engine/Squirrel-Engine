#pragma once

class RuntimeManager
{
public:
	RuntimeManager();

	static RuntimeManager& getInstance();
	void engineStartup();
	void engineShutdown();
};
