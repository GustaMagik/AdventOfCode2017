#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char *argv[]){
	if(argc==2){
		fstream fin;
		fin.open(argv[1], ifstream::in);
		char c;
		int level = 0;
		int value = 0;
		int chars = 0;
		bool ignore = false;
		bool garbage = false;
		while(fin.get(c)){
			if(!ignore){
				if(c == '!'){ignore = true;chars--;}
				if(c == '>'){garbage = false;}
				if(!garbage){
					if(c == '<'){garbage = true;}
					if(c == '{'){level++;}
					if(c == '}'){value += level--;}
				}else{
					chars++;
				}
			}else{
				ignore = false;
			}
		}
		cout << "Task1: " << value << "\n" << "Task2: " << chars << "\n";
	}
}