#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

/*Takes a matrix of numbers in it
  Outputs the sum of each row's 
  	maximum difference between 
  	any two elements in the row
*/
int main(int argc, char *argv[]){
	if (argc == 2){
		std::fstream fin;
		fin.open(argv[1], std::ifstream::in);
		std::string line;
		int i = 0;
		int sum = 0;
		int big, small, tmp;
		while(!fin.eof()){
			std::getline(fin, line);
			std::stringstream elems(line);
			elems >> small;
			big = small;
			while(elems.good()){
				elems >> tmp;
				if(tmp < small){
					small = tmp;
				}
				if(tmp > big){
					big = tmp;
				}
			}
			sum += big-small; 
		}
		std::cout << sum << "\n";
	}
	else{
		printf("One argument.\n Please...\n");
	}
	return 0;
}