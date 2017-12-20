#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
	if(argc==2){
		fstream fin;
		fin.open(argv[1], ifstream::in);
		string elem, line;
		int a[16];
		list<string> list;
		int i = 0;   
		while(!fin.eof()){
			getline(fin, line);
			istringstream lin(line);
			while(getline(lin, elem, '\t')){
				a[i++] = atoi(elem.c_str());
			}
		}
		bool t = true;
		int step = 0;
		int loopS = 0;
		while(t){
			step++;
			string ins = to_string(a[0]);
			for(int i = 1; i < 16;i++){
				ins += "," + to_string(a[i]);
			}
			if(find(list.begin(), list.end(), ins) != list.end()){
				t=false;
				loopS = distance(find(list.begin(),list.end(),ins), list.end());
			}
			list.push_back(ins);
			int * p = max_element(a, a+16);
			int share = *p;
			*p = 0;
			for(int i=0; i < share;i++){
				p++;
				if(p==end(a))
					p= begin(a);
				(*p)++;
			}
		}
		cout << "Task1: " << --step << "\n";
		cout << "Task2: " << loopS << "\n"; 
	}
	return 0;
}
