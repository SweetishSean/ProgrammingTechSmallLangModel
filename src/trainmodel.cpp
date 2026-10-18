
#include "trainmodel.h"

using namespace std;


Trainmodel::Trainmodel(int k_init,double alpha_init){
	k=k_init;
	alpha = alpha_init;
	most_common = "";
	highest_count=0;
}


// I specifically made this program so I could train it on mutiple files if I want to.
void Trainmodel::readfile(string filename){
	ifstream file(filename);
	string window="";
	char next_char;
	if(!file) {
		throw runtime_error("File did not open.");
	}
	// get the first k gram and make sure the file is larger then k
	for(int i=0;i<k;i++){
		
		if(!file.get(next_char)){
			throw runtime_error("File is smaller then k characters.");
		}
		//check if its a new char, if it is add it to the alphabet
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

	if(file.peek() == char_traits<char>::eof() ){
			throw runtime_error("File has only k characters.");
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
	
	for(const auto &[word,counts] : distribution){
			int total_occ=0;
			double num, dem;
			for(const auto &[next_char,occ] : counts){
				total_occ+=occ;	
			}
			for(const auto next_char : alphabet){
				num=static_cast<double>(distribution[word][next_char])+alpha;
				dem=static_cast<double>(total_occ)+alpha*alphabet.size();
				frequency_map[word][next_char]=num / dem;
			}
			if(total_occ>highest_count)
				most_common = word;
	}


	return frequency_map;
}

std::vector<char> Trainmodel::alphabet_out(){
	return alphabet;
}
// Needs to be called after dataout()
std::string Trainmodel::highestfreqword(){
	return most_common;
}

