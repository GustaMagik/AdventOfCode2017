#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
using namespace std;

int main(int argc, char *argv[]){
	if (argc == 2){
		int i = 1;
		string input = argv[1];
		string::size_type sz;
		int target = stoi (input,&sz);
		while (i*i < target){
			i+=2;
		}
		int inRingMax = (i-2)*(i-2);
		int outerRing = i*i - inRingMax;
		//outerRing starts at inRingMax+1 and is 
		//next to the bottom right corner element.
		//there are 4 corner elements and 4 lines.
		//each line contain (outerRing-4)/4 elems.
		//the first elem in each ring is the first
		//elem in the rightmost line.
		//target - inRingMax = relativeIndex in outer ring
		// index 0->(outerRing-4)/4 => in first line
		//index outerring-4/4+1 => upper right corner 
		int steps= (i-1)/2;		
		int index = target - inRingMax;
		int line = (outerRing-4)/4;
		int line2 = line+1;
		if(index < (line2)){
			steps += abs(index-line/2-1);	
		}else if(index % line2 == 0){
			steps += line/2+1;
		}else if(index < 2*line2){
			index -= line2;
			steps += abs(index-line/2-1);
		}else if(index < 3*line2){
			index -= 2*line2;
			steps += abs(index-line/2-1);
		}else if(index < 4*line2){
			index -= 3*line2;
			steps += abs(index-line/2-1);
		}
		cout << steps << "\n";
	}
}