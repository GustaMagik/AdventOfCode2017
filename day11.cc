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
		string coord;
		int n = 0, s = 0, nw = 0, ne = 0, sw = 0, se = 0, maxSize = 0;
		int on = 0, os = 0, onw = 0, one = 0, osw = 0, ose = 0;
		while(getline(fin,coord,',')){
			if(coord == "n"){on++;}
			if(coord == "ne"){one++;}
			if(coord == "nw"){onw++;}
			if(coord == "s"){os++;}
			if(coord == "se"){ose++;}
			if(coord == "sw"){osw++;}
			n = on;
			s = os;
			ne = one;
			nw = onw;
			se = ose;
			sw = osw;
			bool change = true;
			int size;
			while(change){
				size = n+s+ne+nw+se+sw;
				//cancel
				if(n != 0 && s !=0){n--;s--;}
				if(nw != 0 && se != 0){nw--;se--;}
				if(ne != 0 && sw != 0){ne--;sw--;}
				//combinations
				if(ne != 0 && s != 0){ne--;s--;se++;}
				if(nw != 0 && s != 0){nw--;s--;sw++;}
				if(se != 0 && n != 0){se--;n--;ne++;}
				if(sw != 0 && n != 0){sw--;n--;nw++;}
				if(sw != 0 && se != 0){sw--;se--;s++;}
				if(nw != 0 && ne != 0){nw--;ne--;n++;}
				if(size == n+s+ne+nw+se+sw){change = false;}
			}
			if(size > maxSize){maxSize = size;}

		}
		cout << "Task1: " << n + s + ne + nw + se + sw << "\n" << "Task2: " << maxSize << "\n";
	}
}