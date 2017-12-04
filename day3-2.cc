#include <map>
#include <string>
#include <iostream>
using namespace std;

		

int main(int argc, char *argv[]){
	if(argc==2){
		string::size_type sz;
		int inp = stoi (argv[1],&sz);
		typedef pair<int, int> Key;
		typedef map<Key, int> MyMap;
		int maxVal = 0;
		int x = 0;
		int y = 0;
		int ringBase = 3;
		int index = 0;
		int ofSet = 0;
		MyMap map;
		Key k (x,y);
		map.insert(make_pair(k,1));
		MyMap::iterator it;
		while(maxVal <= inp){
			if (index == 0){
				x++;
			}else if(index < ringBase-1){
				y++;
			}else if(index < 2*(ringBase-1)){
				x--;
			}else if(index < 3*(ringBase-1)){
				y--;
			}else if(index < 4*(ringBase-1)){
				x++;
			}
			index++;
			if(index == 4*(ringBase-1)){
				index = 0;
				ringBase += 2;
			}
			int val = 0;
			int x1 = x;
			int y1 = y;
			for(int i = 0; i<8;i++){
				if(i==0){
					x1++;
				}else if(i<2){
					y1++;
				}else if(i<4){
					x1--;
				}else if(i<6){
					y1--;
				}else if(i<8){
					x1++;
				}
				Key k(x1,y1);
				it = map.find(k);
				if(it != map.end()){
					val += (*it).second;
				}
			}
			Key k(x,y);
			map.insert(make_pair(k, val));
			maxVal = val;
			int c;
		}
		cout << maxVal << "\n";
	}
	return 0;
}

