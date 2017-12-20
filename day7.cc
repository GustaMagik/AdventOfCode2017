#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int weights(string);
int imbalance(string);

unordered_map<string, int> finalWeights;
unordered_map<string, list<string>> myCopy;
unordered_map<string, int> myWeights;
		

int main(int argc, char *argv[]){
	if(argc==2){
		fstream fin;
		fin.open(argv[1], ifstream::in);
		string line, elem;
		list<string> value;
		unordered_map<string, list<string>> myMap;
		while(!fin.eof()){
			getline(fin, line);
			line.push_back(',');
			istringstream lin(line);
			int i = 0;
			string key;
			int weight;
			value.clear();
			while(getline(lin, elem, ' ')){
				if(i ==0){key=elem;}
				if(i == 1){
					elem.erase(std::remove(elem.begin(),elem.end(), '('), elem.end());
					elem.erase(std::remove(elem.begin(),elem.end(), ')'), elem.end());
					elem.erase(std::remove(elem.begin(),elem.end(), ','), elem.end());
					weight = atoi(elem.c_str());}
				if(i > 2){elem.pop_back(); value.push_back(elem);}
				i++;
			}
			myCopy.emplace(key, value);
			myMap.emplace(key,value);
			myWeights.emplace(key,weight);
		}
		//Map constructed
		for(auto it = myMap.begin();it != myMap.end();it++){
			list<string> children = it->second;
			bool t = true;
			while(!children.empty()){
				string f = children.front();
				children.pop_front();
				if(myMap.find(f) != myMap.end()){
					list<string> more = myMap.at(f);
					myMap.erase(f);
					children.insert(children.end(), more.begin(),more.end());
				}
			}
		}
		for(auto it = myMap.begin();it != myMap.end();it++){
			string t1 = it->first;
			cout << "Task1: " << t1 << "\n";
			weights(t1);
			int rootsum = 0;
			for(auto it = myWeights.begin(); it != myWeights.end();it++){
				rootsum += it->second;
			}
			cout << rootsum << " " << finalWeights.at(t1) << "\n";
			cout << imbalance(t1) << "\n";
		}
		

	}

}


int imbalance (string root){
	string f;
	string s;
	int first = -1;
	int second = -1;
	int same = 0;
	int res = 0;
	cout << root << ": ";
	list<string> lis = myCopy.at(root);
	for(string& child : lis){
		cout << child << ": " << finalWeights.at(child) << " ";
		if(first == -1){
			first = finalWeights.at(child);
			f = child;
			same++;
		}else if(first == finalWeights.at(child)){
			same++;
		}else{
			second = finalWeights.at(child);
			s = child;
		}
		cout << same << "\n";
	}
	cout << "\n";
	if(same == lis.size()){
		return -1;
	}else if(same == 1){
		res = imbalance(f);
	}else {
		res = imbalance(s);
	}
	if(res == -1){
		if (same == 1){
			res = myWeights.at(f) + second - first;
		}else{
			res = myWeights.at(s) + first - second;  
		}
	}
	return res;	
}

int weights(string child){
	if (finalWeights.find(child) == finalWeights.end()){
		int w = myWeights.at(child);
		for(string& c : myCopy.at(child)){
			w += weights(c);
		}
		finalWeights.emplace(child, w);
		return w;
	}else{
		return finalWeights.at(child);
	}
}