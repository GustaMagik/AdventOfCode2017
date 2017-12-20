#include <string>
#include <utility>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//key +/- amount "if" key cmp int 

int main(int argc, char *argv[]){
	if(argc==2){
		fstream fin;
		fin.open(argv[1], ifstream::in);
		string elem, line;
		list<string> list;
		int max2 = 0;
		unordered_map<string, int> m;
		while(!fin.eof()){
			getline(fin, line);
			istringstream lin(line);
			while(getline(lin, elem, ' ')){
				list.push_back(elem);
			}
			string name = list.front();
			list.pop_front();
			string decInt = list.front();
			list.pop_front();
			int mod = atoi(list.front().c_str());
			if ("dec" == decInt){
				mod *= -1;
			}
			unordered_map<string,int>::iterator it = m.find(name);
			if (it != m.end()){
				mod += (*it).second;
			}else{
				m.emplace(name,0);
			}
			list.pop_front();
			list.pop_front();
			it = m.find(list.front());
			int c = 0;
			if(it != m.end()){
				c = (*it).second;
			}
			list.pop_front();
			string cmp = list.front();
			list.pop_front();
			int c1 = atoi(list.front().c_str());
			if(cmp == "==" && c==c1){
				m.at(name) = mod;
			}else if(cmp == "!=" && c!=c1){
				m.at(name) = mod;
			}else if(cmp == "<" && c<c1){
				m.at(name) = mod;
			}else if(cmp == ">" && c>c1){
				m.at(name) = mod;
			}else if(cmp == "<=" && c<=c1){
				m.at(name) = mod;
			}else if(cmp == ">=" && c>=c1){
				m.at(name) = mod;
			}
			list.clear();
			if(m.at(name) > max2){
				max2 = m.at(name);
			}
		}
		int max = 0;
		for(auto i : m){
			if(max < i.second)
				max = i.second;
		}
		cout << "task1: " << max << "\n" << "task2:" << max2 <<"\n";

	}
	return 0;
}
