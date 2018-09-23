/*
 * =====================================================================================
 *
 *       Filename:  test1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2018 12:39:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>

#include "json/json.h"

using namespace std;

int main(void)
{
	Json::Value root_group;
	root_group["Personal-details"][0]["Age"] = 20;
	root_group["Personal-details"][0]["Name"] = "jeremy";
	root_group["Personal-details"][0]["Live-City"] = "Shanghai";
	root_group["Personal-details"][0]["Phone-Number"]["1"] = "123456789";
	root_group["Personal-details"][0]["Phone-Number"]["2"] = "987654321";
	root_group["Personal-details"][0]["Index"] = 1;
	root_group["Personal-details"][1]["Age"] = 23;
	root_group["Personal-details"][1]["Name"] = "Eva";
	root_group["Personal-details"][1]["Live-City"] = "Wuhan";
	root_group["Personal-details"][1]["Phone-Number"]["1"] = "222222222";
	root_group["Personal-details"][1]["Phone-Number"]["2"] = "111111111";
	root_group["Personal-details"][1]["Index"] = 2;
	fstream f;
	f.open("Personal-details.json", ios::out);

	if( !f.is_open())
	{
		cout << "Open file error!" << endl;
	}

	f << root_group.toStyledString();
	f.close();
}
