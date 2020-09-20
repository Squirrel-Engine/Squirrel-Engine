#pragma once
#include <iostream>

#include "Application.h"

extern Squirrel::Application* Squirrel::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Squirrel::CreateApplication();
	app->Run();
	delete app;
}