#include<map>
#include<iostream>
#include<vector>


#include "trainmodel.h"
#include "generatemodel.h"


using namespace std;


int main(int argc, char* argv[]){


	int k;
	double alpha;
	string input_text;
	int lengthgen;
	string starting_words;
	
	if(argc==4){
		k = stoi(argv[1]);
		alpha = 0;
		input_text=argv[2];
		lengthgen=stoi(argv[3]);
	}else if(argc==6){
		k = stoi(argv[3]);
		alpha = stod(argv[2]);
		input_text=argv[4];
		lengthgen=stoi(argv[5]);
	}else {
		cerr << "Invalid number of arguments. Exiting Now." << endl,
		exit(1);
	}

	Trainmodel m1(k,alpha);
	m1.readfile(input_text);
	map<string,map<char,double> > mapout = m1.dataout();
	starting_words = m1.highestfreqword();
	/*
	for(const auto &[key,value] : mapout){
		cout<<'[' << key << "] " << endl;
		for(const auto &[nex_char,occr] : value){
		cout<< nex_char << " " << occr << endl;
		}
	}
	*/


	// Generate part below:
	vector<char> alphabet=m1.alphabet_out();
	Generatemodel gen1(k,mapout,alphabet,alphabet.size(),alpha);

	gen1.generatetext(starting_words,lengthgen);



	return 0;
}