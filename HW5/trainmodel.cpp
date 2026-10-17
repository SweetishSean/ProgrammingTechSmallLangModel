
#include "trainmodel.h"

using namespace std;


Trainmodel::Trainmodel(int k_init){
	k=k_init;

}



void Trainmodel::readfile(string filename){
	ifstream file(filename);
	string window="";
	char next_char;
	if(!file) {
		cout << "File did not open";
		exit(1);
	}
	for(int i;i<k;i++){
		file.get(next_char);
		window=window+next_char;
	}
	//while(


	file.close();
}






