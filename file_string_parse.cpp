/*
 * =====================================================================================
 *
 *       Filename:  test3.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2018 12:59:57 PM
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
#include <sstream>

#include "json/json.h"

using namespace std;

int main()
{
	Json::CharReaderBuilder rbuilder;
	Json::CharReader* reader = rbuilder.newCharReader();

	rbuilder["collectComments"] = false;

	Json::Value root_group;
	JSONCPP_STRING errs;

	fstream f;
	f.open("Personal-details.json", ios::in);

	if(!f.is_open())
	{
		cout << "Open json file error!" << endl;
	}

	ostringstream os;
	os << f.rdbuf();
	string s = os.str();
	os.clear();
	os.str("");
	f.seekg(0);

	bool parse_ok = reader->parse(s.data(), s.data()+s.size(), &root_group, &errs);
	if(!parse_ok)
	{
		cout << "Parse json file error!" << endl;
	}
	else
	{
		cout << "Printf Eva's information:" << endl;
		cout << root_group.toStyledString() << endl;
		try{
			cout << "Personal-details:Name=" << root_group["Personal-details"][1]["Name"]<< endl;
			cout << "Personal-details:Age=" << root_group["Personal-details"][1]["Age"]<< endl;
			cout << "Personal-details:Live-City=" << root_group["Personal-details"][1]["Live-City"]<< endl;
			cout << "Personal-details:Phone-Number=" << root_group["Personal-details"][1]["Phone-Number"]<< endl;
			cout << "Personal-details:Phone-Number:1=" << root_group["Personal-details"][1]["Phone-Number"]["1"]<< endl;
			cout << "Personal-details:Phone-Number:2=" << root_group["Personal-details"][1]["Phone-Number"]["2"]<< endl;
			cout << "Personal-details:Index=" << root_group["Personal-details"][1]["Index"]<< endl;

		}catch(const Json::LogicError &ex)
			{
				cout << "Parse json string error!" << endl;
			}
	}

	f.close();

	return 0;
}
