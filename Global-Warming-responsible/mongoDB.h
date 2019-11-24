#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map> 

//Qt
#include <QDebug>

//MongoDB & bson
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>


#include "Continent.h"
#include "Sort.h"


using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

using bsoncxx::builder::basic::document;

using namespace bsoncxx;
using namespace std;



class mongoDB
{


private: 

		static mongoDB * instance;


protected:

		Continent Continents;

		std::string str_uri = "mongodb://127.0.0.1:27017";
		std::string str_db = "GlobWarm";

		std::string strcontry_coll = "countries";
		std::string strinfo_coll = "info";


		 // This should be done only once.
		mongocxx::instance InstanceDB{};


		mongoDB();
		~mongoDB();





public: 


		static mongoDB* getInstance();
	

		map<std::string, double> GetValue_Country_ByName(std::string Name_country );
		map<std::string, double> mongoDB::GetValue_Countries_ByContinent(std::string Continent_Name);
		map<std::string, double> GetValueWorld();

		map<std::string, double> mongoDB::GetTOP();


		std::string GetValue_Info_ByCountry();


		std::string GetValueTest();
		std::string GetValue_Test(std::string P_Name, std::string P_Year);





};

inline mongoDB::mongoDB() 
{
}

inline mongoDB::~mongoDB()
{
}


