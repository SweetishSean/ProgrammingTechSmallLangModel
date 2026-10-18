
#include "trainmodel.h"

using namespace std;


Trainmodel::Trainmodel(int k_init,double alpha_init){
	k=k_init;
	alpha = alpha_init;
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
		if(next_char==NULL){
			cerr << "File is smaller then k" << endl;
			exit(1);
		}
		int new_letter=1;
		for(auto letter : alphabet){
			if(next_char==letter)
				new_letter=0;
		}
		if(new_letter){
			alphabet.push_back(next_char);
		}
		
		
		window=window+next_char;
	}
	while(file.get(next_char)) {
		distribution[window][next_char]+=1;
		window=window.substr(1,k)+next_char;
		
		int new_letter=1;
		for(auto letter : alphabet){
			if(next_char==letter)
				new_letter=0;
		}
		if(new_letter){
			alphabet.push_back(next_char);
		}
	}


	file.close();
}

map<string,map<char,double> > Trainmodel::dataout(){
	map<string,map<char,double> > frequency_map;
	
	for(const auto [word,counts] : distribution){
			int total=0;
			double freq;
			for(const auto [next_char,occ] : counts){
				total+=occ;	
			}
			for(const auto [next_char,occ] : counts){
				frequency_map[word][next_char]=static_cast<double>(distribution[word][next_char]) / total;
			}
	}



	return frequency_map;
}




