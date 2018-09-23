/*
 * =====================================================================================
 *
 *       Filename:  test2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2018 12:49:05 PM
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
#include <string>

#include "json/json.h"

using namespace std;

int main(void)
{
	Json::CharReaderBuilder rbuilder;
	rbuilder["collectComments"] = false;
	Json::Value root_group;
	JSONCPP_STRING errs;

	fstream f;
	f.open("Personal-details.json", ios::in);
	if(!f.is_open())
	{
		cout << "Open json file error!" << endl;
	}

	bool parse_ok = Json::parseFromStream(rbuilder, f, &root_group, &errs);
	if(!parse_ok)
	{
		cout << "Parse json file error!" << endl;
	}
	else
	{
		cout << "Printf jeremy's information:" << endl;
		cout << root_group.toStyledString() << endl;
		try{
			cout << "Personal-details:Name=" << root_group["Personal-details"][0]["Name"]<< endl;
			cout << "Personal-details:Age=" << root_group["Personal-details"][0]["Age"]<< endl;
			cout << "Personal-details:Live-City=" << root_group["Personal-details"][0]["Live-City"]<< endl;
			cout << "Personal-details:Phone-Number=" << root_group["Personal-details"][0]["Phone-Number"]<< endl;
			cout << "Personal-details:Phone-Number:1=" << root_group["Personal-details"][0]["Phone-Number"]["1"]<< endl;
			cout << "Personal-details:Phone-Number:2=" << root_group["Personal-details"][0]["Phone-Number"]["2"]<< endl;
			cout << "Personal-details:Index=" << root_group["Personal-details"][0]["Index"]<< endl;

		}catch(const Json::LogicError &ex)
			{
				cout << "Parse json string error!" << endl;
			}
	}

	f.close();

	return 0;
}
