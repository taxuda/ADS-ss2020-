/*************************************************
* ADS Praktikum 2.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <iostream>
#include <string>
#include "Ring.h"
#include "print.h"
using namespace std;


int main()
{
	int result = Catch::Session().run();
    Ring backup;
    print_menu(backup);
	///////////////////////////////////////
	return 0;
}
