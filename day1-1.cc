#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

/*Takes a file with numbers in it.
  Calculates a sum with the rules: 
  the input string is a circular list
  if two consecutive elements are the same
  	add their value to the sum
*/
int main(int argc, char *argv[]){
	if (argc == 2){
		std::fstream fin;
		fin.open(argv[1], std::ifstream::in);
		char n, p, f;
		int s = 0;
		int check = 0;
		fin.get(f);
		while(!fin.eof()){
			if(check==0){
				p = f;
				check++;
			}
			else{
				if(p==n){
					s += n - '0';
				}
				p = n;
			}
			fin.get(n);
		}
		fin.close();
		if(f == n){
			s += f - '0';
		}
		std::cout << s << "\n";
	}
	else{
		printf("One argument.\n Please...\n");
	}
	return 0;
}

