#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

/*Takes a file with numbers in it.
  Calculates a sum with the rules: 
  The input string is a circular 
  	list with even length
  If two elements that are len/2 elements 
  	appart are the same add their value to 
  	the sum
*/
int main(int argc, char *argv[]){
	if (argc == 2){
		std::fstream fin;
		fin.open(argv[1], std::ifstream::in);
		int s = 0;
		std::string line;
		fin >> line;
		int size = line.length();
		int ptr = 0;
		while (ptr < size/2){
			if (line.at(ptr)==line.at(ptr+size/2)){
				s += (line.at(ptr)- '0')*2;
			}
			ptr++;
		}
		std::cout << s << "\n";

	}
	else{
		printf("One argument.\n Please...\n");
	}
	return 0;	
}