#include<map>
#include<iostream>
#include<vector>


#include "trainmodel.h"
#include "generatemodel.h"


using namespace std;


int main(int argc, char* argv[]){

	int k,k_pos,text_pos,length_pos;
	double alpha;
	string input_text;
	int lengthgen;
	string starting_words;
	try{
		if(argc==4){
			k_pos = 1;
			alpha = 0;
			text_pos=2;
			length_pos=3;
		}else if(argc==6){
			k_pos = 3;
			text_pos=4;
			length_pos=5;
			size_t pos =0;
			string alpha_string = argv[2];
			alpha = stod(alpha_string,&pos);
			if(strcmp(argv[1],"-a")!= 0)
				throw invalid_argument("Invalid flag.");
			if(alpha <= 0)
				throw invalid_argument("Alpha must be greater then 0.");
			if(pos != alpha_string.size())
				throw invalid_argument("Alpha incorrect.");				
		}else {
			throw invalid_argument("Invalid Number of arguments.");

		}
		size_t pos = 0;
		string stringcheck = argv[k_pos];
		k = stoi(stringcheck,&pos);
		if(pos!=stringcheck.size())
			throw invalid_argument("K is not an integer.");
		
		stringcheck = argv[length_pos];
		lengthgen=stoi(stringcheck,&pos);
		if(pos!=stringcheck.size())
			throw invalid_argument("Length is not an integer.");
		
		input_text=argv[text_pos];

		if(k<0)
			throw invalid_argument("Input k is negative. Invalid.");
		if(lengthgen<0)
			throw invalid_argument("Output length is negative. Invalid.");
		if(k>lengthgen)
			throw invalid_argument("Input k is longer then the output length. Invalid.");
	} catch (const invalid_argument& e) {
		cerr << "slm error:"<< e.what() << endl;
		exit(1);
	}

	Trainmodel m1(k,alpha);

	try{
		m1.readfile(input_text);
	} catch (const runtime_error& e) {
		cerr << "slm error:" <<  e.what() << endl;
		exit(1);
	}

	map<string,map<char,double> > mapout = m1.dataout();
	starting_words = m1.highestfreqword();

	// Generate part below:
	vector<char> alphabet=m1.alphabet_out();
	Generatemodel gen1(k,mapout,alphabet,alphabet.size(),alpha);

	gen1.generatetext(starting_words,lengthgen);



	return 0;
}