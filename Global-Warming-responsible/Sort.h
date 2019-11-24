#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;


///Sort map class

class Sort
{
protected:


	
	vector<pair <double, std::string>> keyValue;
	//vector<int> value;



public :

	Sort(map<std::string,double>MapTop) {

		for (auto map : MapTop) {
	
			keyValue.push_back(make_pair(map.second, map.first));
		}

	}


	map<std::string, double> Mapsort() {
		map<std::string, double>L_Map;


		sort(keyValue.begin(), keyValue.end(), greater <>());

		//sort first 5
		for (int index = 0; index < 5; index++) {

			L_Map.insert(make_pair( keyValue[index].second, keyValue[index].first));
		}
		
		

		return L_Map;
	}

};

