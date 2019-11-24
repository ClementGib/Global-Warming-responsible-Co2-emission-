#include "mongoDB.h"



/*
MEMO :
static, but non-const data members should be defined outside of the class definition and inside the namespace enclosing the class.
The usual practice is to define it in the translation unit (*.cpp) because it is considered to be an implementation detail
//
//*/


mongoDB* mongoDB::instance;

bool compar(const pair<std::string, int>& a1, const pair<std::string, int>& a2)
{
	return a1.second < a2.second;
}

mongoDB* mongoDB::getInstance()
{
	if (instance == 0)
	{
		instance = new mongoDB();
	}

	return instance;
}

map<std::string, double> mongoDB::GetValue_Country_ByName(std::string Name_country)
{

	map<std::string, double> Co2Emissions;

	mongocxx::uri L_Uri(str_uri);
	mongocxx::client L_Conn(L_Uri);

	mongocxx::database Database = L_Conn[str_db];
	mongocxx::collection Countries = Database[strcontry_coll];
	mongocxx::collection info = Database[strcontry_coll];

	//Document creation
	auto builder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value doc_value = builder << "Country Name" << Name_country << bsoncxx::builder::stream::finalize;




	//findone document
	bsoncxx::stdx::optional<bsoncxx::document::value> result = Countries.find_one({ doc_value });
	bsoncxx::document::view L_View = result.value().view();

	int Date = 1960;
	for (Date; Date <= 2014; Date++) {	

		bsoncxx::document::element element = L_View[std::to_string(Date)];

		if (element.type() != bsoncxx::type::k_double) {
			// vide
			Co2Emissions.insert(pair<std::string, double>(std::to_string(Date), 0.0));
		}
		else {
			Co2Emissions.insert(pair<std::string, double>(std::to_string(Date), element.get_double().value));
		}
		

	}


	return Co2Emissions;
}



map<std::string, double> mongoDB::GetValue_Countries_ByContinent(std::string Continent_Name)
{
	map<std::string, double> Co2Emissions;
	vector<std::string> L_continent = Continents.GetContinentByName(Continent_Name);
	

	mongocxx::uri L_Uri(str_uri);
	mongocxx::client L_Conn(L_Uri);

	mongocxx::database Database = L_Conn[str_db];
	mongocxx::collection Countries = Database[strcontry_coll];


	///Create document for find evevry country of an continent
	builder::stream::document builder{};
	auto in_array = builder << "$or" << builder::stream::open_array;
	for (int index_vector = 0; index_vector<L_continent.size();index_vector++)
{
		in_array = in_array << builder::stream::open_document << "Country Name" << L_continent.at(index_vector)
			<< builder::stream::close_document;
	}
	auto after_array = in_array << builder::stream::close_array;
	bsoncxx::document::value doc_value = after_array << builder::stream::finalize;



	mongocxx::cursor cursor = Countries.find({ doc_value });



	int index_map = 0;
	for (auto L_Country : cursor) {

		int Date = 1960;

		//Create field of map first
		if (index_map == 0) {
			
			for (Date; Date <= 2014; Date++) {

				bsoncxx::document::element element = L_Country[std::to_string(Date)];

				if (element.type() != bsoncxx::type::k_double) {
					// vide
					Co2Emissions.insert(pair<std::string, double>(std::to_string(Date), 0.0));
				}
				else {
					Co2Emissions.insert(pair<std::string, double>(std::to_string(Date), element.get_double().value));
				}


			}
			index_map++;

		}	
		else {
			//add other value in the map
			for (Date; Date <= 2014; Date++) {

				bsoncxx::document::element element = L_Country[std::to_string(Date)];

				if (element.type() != bsoncxx::type::k_double) {
					// vide +=0.0
					
				}
				else {
					Co2Emissions[to_string(Date)] += element.get_double().value;
				}

				index_map++;
			}


		}


		
	

	}


	

		
	return Co2Emissions;
}

map<std::string, double> mongoDB::GetValueWorld()
{
	map<std::string, double> Co2Emissions;
	vector<std::string> L_continent = Continents.GetContinentByName("World");


	mongocxx::uri L_Uri(str_uri);
	mongocxx::client L_Conn(L_Uri);

	mongocxx::database Database = L_Conn[str_db];
	mongocxx::collection Countries = Database[strcontry_coll];


	///Create document for find evevry country of an continent
	builder::stream::document builder{};
	auto in_array = builder << "$or" << builder::stream::open_array;
	for (int index_vector = 0; index_vector < L_continent.size(); index_vector++)
	{
		in_array = in_array << builder::stream::open_document << "Country Name" << L_continent.at(index_vector)
			<< builder::stream::close_document;
	}
	auto after_array = in_array << builder::stream::close_array;
	bsoncxx::document::value doc_value = after_array << builder::stream::finalize;



	mongocxx::cursor cursor = Countries.find({ doc_value });

	int index_map=0;
	for (auto L_Country : cursor) {

		int Date = 1960;

		//Create field of map first
		if (index_map == 0) {

			for (Date; Date <= 2014; Date++) {

				bsoncxx::document::element element = L_Country[std::to_string(Date)];

				if (element.type() != bsoncxx::type::k_double) {
					// vide
					Co2Emissions.insert(pair<std::string, double>(std::to_string(Date), 0.0));
				}
				else {
					Co2Emissions.insert(pair<std::string, double>(std::to_string(Date), element.get_double().value));
				}


			}
			index_map++;
		
		}
		
		else {
			//add other value in the map
			for (Date; Date <= 2014; Date++) {

				bsoncxx::document::element element = L_Country[std::to_string(Date)];

				if (element.type() != bsoncxx::type::k_double) {
					// vide +=0.0

				}
				else {
					Co2Emissions[to_string(Date)] += element.get_double().value;
				}

				index_map++;
			}


		}





	}


	return Co2Emissions;
}

map<std::string, double> mongoDB::GetTOP()
{
	//return 10 most responsible countries "Upper middle income" && "High income"
	vector<std::string> L_continent = Continents.GetContinentByName("World");


	mongocxx::uri L_Uri(str_uri);
	mongocxx::client L_Conn(L_Uri);

	mongocxx::database Database = L_Conn[str_db];
	mongocxx::collection Countries = Database[strcontry_coll];
	mongocxx::collection Info = Database[strinfo_coll];

	///Document for income high en upper middle
	auto builder_name = bsoncxx::builder::stream::document{};
	bsoncxx::document::value doc_name = builder_name
		<< "$or" << builder::stream::open_array
		<< builder::stream::open_document 
		<< "IncomeGroup" << "High income"
		<< builder::stream::close_document
		<< builder::stream::open_document
		<< "IncomeGroup" << "Upper middle income"
		<< builder::stream::close_document
		<< builder::stream::close_array
		<< bsoncxx::builder::stream::finalize;

	mongocxx::cursor cursor_name = Info.find({ doc_name });

	vector<std::string> Country_Names;
	for (auto L_Country : cursor_name) {

		bsoncxx::document::element element_name = L_Country["TableName"];
		if (element_name.type() != bsoncxx::type::k_utf8) {
			// Error
			Country_Names.push_back("NoName");
		}
		else {

			Country_Names.push_back(element_name.get_utf8().value.to_string());
		}
	}












	//////////FIND TOP RESPONSIBLE COUNTRIES

	///Create document for find evevry country of an continent
	builder::stream::document builder_co2{};
	auto in_array = builder_co2 << "$or" << builder::stream::open_array;
	for (int index_vector = 0; index_vector < Country_Names.size(); index_vector++)
	{
		in_array = in_array << builder::stream::open_document << "Country Name" << Country_Names.at(index_vector)
			<< builder::stream::close_document;
	}
	auto after_array = in_array << builder::stream::close_array;
	bsoncxx::document::value doc_value = after_array << builder::stream::finalize;


	mongocxx::cursor cursor_co2 = Countries.find({ doc_value });




	map<std::string, double> Responsible_list;
	

	for (auto L_Country : cursor_co2) {	

		int Date = 1960;
		

		std::string Country_Code = "";
		int Sum_CO2 = 0;

		for (Date; Date <= 2014; Date++) {

			bsoncxx::document::element element_code = L_Country["Country Code"];
			if (element_code.type() != bsoncxx::type::k_utf8) {
				// vide
				Country_Code = "N/A";
			}
			else {
				Country_Code = element_code.get_utf8().value.to_string();
			}


			bsoncxx::document::element element_co2 = L_Country[std::to_string(Date)];

			if (element_co2.type() != bsoncxx::type::k_double) {
				// vide
				Sum_CO2 += 0.0;
			}
			else {
				Sum_CO2 += element_co2.get_double().value;
			}


		}



			Responsible_list.insert(std::pair<std::string, double>(Country_Code, Sum_CO2));
	
	

	}


//	//sort map 

	// vector <std::string, int> v;

	// populate map somehow

	//for (MapType::iterator it = m.begin(); it != m.end(); ++it) {
	//	v.push_back(it->second);
	//}

	//sort(Responsible_list.begin(), Responsible_list.end(), compar);


	Sort Classeur(Responsible_list);
	map<std::string, double> TOP_responsible = Classeur.Mapsort();
	
	//
	////insert top 10
	//map<std::string, double> TOP_responsible;
	//
	//map<std::string, double> ::iterator it2;
	//int index = 0;
	//for (it2 = Responsible_list.begin(); it2 != Responsible_list.end(); it2++)
	//{
	//	TOP_responsible.insert(make_pair(it2->first, it2->second));

	//	
	//	index++;
	//	if (index == 5) break;
	//	
	//}








	return TOP_responsible;
}


std::string mongoDB::GetValue_Info_ByCountry()
{

	mongocxx::uri L_Uri(str_uri);
	mongocxx::client L_Conn(L_Uri);

	mongocxx::database Database = L_Conn[str_db];
	mongocxx::collection info = Database[strcontry_coll];

	return std::string();
}

std::string mongoDB::GetValueTest()
{
	mongocxx::uri L_Uri(str_uri);
	mongocxx::client L_Conn(L_Uri);

	mongocxx::database Database = L_Conn[str_db];
	mongocxx::collection Countries = Database[strcontry_coll];




	bsoncxx::stdx::optional<bsoncxx::document::value> result = Countries.find_one({});

	if (result) {

		//qDebug() << "Bonjour :" << bsoncxx::to_json(*result) << endl;
		cout << "Test :" << bsoncxx::to_json(*result) << endl;

		return "TEST !";
	}
	return "";
}


std::string mongoDB::GetValue_Test(std::string P_Name, std::string P_Year)
{
	mongocxx::uri L_Uri(str_uri);
	mongocxx::client L_Conn(L_Uri);

	mongocxx::database Database = L_Conn[str_db];
	mongocxx::collection Countries = Database[strcontry_coll];


	bsoncxx::stdx::optional<bsoncxx::document::value> result = Countries.find_one({});

	if (result) {

		//qDebug() << "Bonjour :" << bsoncxx::to_json(*result) << endl;
		cout << "Test :" << bsoncxx::to_json(*result) << endl;

		return "hello";
	}
	return "";
}

