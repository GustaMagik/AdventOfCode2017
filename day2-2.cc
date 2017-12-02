#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <list>
#include <iterator>

/*Takes a matrix of numbers in it
  Finds each rows only two values 
  which divide evenly. Adds up each
  rows "division".
*/
int main(int argc, char *argv[]){
	if (argc == 2){
		std::fstream fin;
		fin.open(argv[1], std::ifstream::in);
		std::string line;
		std::list<int> ml;
		std::list<int>::iterator it;
		int tmp;
		int sum = 0;
		while(!fin.eof()){
			std::getline(fin, line);
			std::stringstream elems(line);
			while(elems.good()){
				elems >> tmp;
				ml.push_back(tmp);
			}
			ml.sort();
			it = ml.begin();
			for(int i = 0; i < ml.size();i++){
				std::advance(it, i);
				tmp = *it; 
				for(int j = i+1; j < ml.size();j++){
					std::advance(it, 1);
					if (*it % tmp == 0){
						i = ml.size();
						j = i;
						sum += *it/tmp;
					}		
				}
				it = ml.begin();
			}
			ml.clear();
		}
		std::cout << sum << "\n";
	}
	else{
		printf("One argument.\n Please...\n");
	}
	return 0;
}