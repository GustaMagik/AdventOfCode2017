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
		string elem;
		list<int> arr;
		int valid = 0;
		string::size_type sz;   
		while(!fin.eof()){
			getline(fin, elem);
			arr.push_back(stoi (elem,&sz));
		}
		int steps = 0;
		list<int>::iterator it = arr.begin();
		int tmp;
		while(it != arr.end()){
			tmp = *it;
			if(2 < tmp){
				*it = tmp-1;
			}else{
				*it = tmp +1;
			}
			advance(it, tmp);
			steps++;
		}
		cout << steps << "\n";
	}

	return 0;
}

