#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
	if(argc==2){
		fstream fin;
		fin.open(argv[1], ifstream::in);
		string line, word;
		list<string> lline;
		int valid = 0;
		while(!fin.eof()){
			getline(fin, line);
			stringstream elems(line);
			while(elems.good()){
				elems >> word;
				lline.push_back(word);
			}
			int whole = lline.size();
			lline.sort();
			lline.unique();
			int noDup = lline.size();
			if(whole == noDup){
				valid++;
			}
			lline.clear();
		}
		cout << valid << "\n";
	}
	return 0;
}

