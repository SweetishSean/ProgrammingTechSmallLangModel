
#include "generatemodel.h"

using namespace std;


Generatemodel::Generatemodel(int k_init, map<std::string, map<char,double> > init_freq,vector<char> init_alphabet,int size_alpha)
	: gen(random_device{}()),
      distr(0.0, 1.0),
      dis_int(0,size_alpha)
{
	k=k_init;
	freq_map = init_freq;
	alphabet = init_alphabet;
	size_of_alphabet= size_alpha;

}

char Generatemodel::generatenext(std::string word){
	/*
		Need to get random number then go through each of the letters in the alphabet subtracting each one till I get to around zero.
	*/
		double rand = distr(gen);
		for(const auto [next_char,freq] : freq_map[word]){
			rand=rand - freq;			
			if(rand<=0){
				return next_char;
			}
		}
		// If the k-gram never occured in the training text then pick a letter from the alphabet at random
		int  index_ran= dis_int(gen);
		return alphabet[index_ran];
	
}


void Generatemodel::generatetext(string initial_word,int length){
	string window= initial_word;
	cout << "Generating Text: " << endl;
	char next_char;
	for(int i=0;i<length;i++){
		next_char = generatenext(window);
		cout << next_char;
		window = window.substr(1,k)+next_char;
	}
	
	//cout<<"Generating text: " <<initial_word << generatenext(initial_word) << endl;


}

   