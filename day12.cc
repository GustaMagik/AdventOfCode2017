#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(int argc, char *argv[]){
	if(argc==2){
		fstream fin;
		fin.open(argv[1], ifstream::in);
		string line, elem, key;
		list<string> lis;
		unordered_map<string, list<string> > myMap;
		while(getline(fin,line)){
			replace(line.begin(),line.end(), ',', ' ');
			istringstream lin(line);
			int i = 0;
			lis.clear();
			while(getline(lin,elem, ' ')){
				if(i == 0){
					key = elem;
				}
				if(i > 1){
					lis.push_back(elem);
				}
				i++;
			}
			myMap.emplace(key, lis);

		}
		
		int maxSize = 0;
		while(maxSize != cluster.size()){
			
		}
		cout << "Task1: " << "\n" << "Task2: "  << "\n";
	}
}