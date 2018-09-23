/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2018 10:43:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include "./json/json.h"

using namespace std;

int main(void)
{
	string message = "{ \"Personal-details\" : \
						{\"Name\" : \"jeremy\",\
						\"Age\" : 20,\
						\"Live-City\": \"Shanghai\",\
						\"Phone-Number\" : \
								{\"1\" : \"123456789\",\
								 \"2\":\"987654321\"},\
						\"Index\":1}\
					}";
	Json::CharReaderBuilder rbuilder;
	Json::CharReader* reader = rbuilder.newCharReader();

	rbuilder["collectcomments"] = false;
	Json::Value root;
	JSONCPP_STRING errs;

	bool parse_ok = reader->parse(message.c_str(),message.c_str() + message.length(), &root, &errs);
	if(!parse_ok)
	{
		cout << "Parse json string error!" << endl;
	}
	else
	{
		cout << "Printf jeremy's information:" << endl;
		cout << root.toStyledString() << endl;
		try{
			cout << "Personal-details:Name=" << root["Personal-details"]["Name"]<< endl;
			cout << "Personal-details:Age=" << root["Personal-details"]["Age"]<< endl;
			cout << "Personal-details:Live-City=" << root["Personal-details"]["Live-City"]<< endl;
			cout << "Personal-details:Phone-Number=" << root["Personal-details"]["Phone-Number"]<< endl;
			cout << "Personal-details:Phone-Number:1=" << root["Personal-details"]["Phone-Number"]["1"]<< endl;
			cout << "Personal-details:Phone-Number:2=" << root["Personal-details"]["Phone-Number"]["2"]<< endl;
			cout << "Personal-details:Index=" << root["Personal-details"]["Index"]<< endl;

		}catch(const Json::LogicError &ex)
		{
			cout << "Parse json string error!" << endl;
		}
	}


	Json::Value root_temp;

	root_temp["Personal-details"]["Age"] = 23;
	root_temp["Personal-details"]["Name"] = "Eva";
	root_temp["Personal-details"]["Live-City"] = "Wuhan";
	root_temp["Personal-details"]["Phone-Number"]["1"] = "222222222";
	root_temp["Personal-details"]["Phone-Number"]["2"] = "111111111";
	root_temp["Personal-details"]["Index"] = 2;
	cout << "Add Eva's information:" << endl;
	cout << root_temp.toStyledString() << endl;

	Json::Value root_group;
	cout << "Add jeremy and Eva together:" << endl;
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

	cout << root_group.toStyledString() << endl;
	return 0;
}
