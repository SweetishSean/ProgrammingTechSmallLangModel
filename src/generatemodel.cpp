
#include "generatemodel.h"

using namespace std;


Generatemodel::Generatemodel(int k_init, map<std::string, map<char,double> > init_freq,vector<char> init_alphabet,int size_alpha,double alpha)
	: gen(random_device{}()),
      distr(0.0, 1.0),
      dis_int(0,size_alpha)
{
	k=k_init;
	freq_map = init_freq;
	alphabet = init_alphabet;
	size_of_alphabet= size_alpha;

	// Once the model is trained the alpha does not matter, unless it is zero since the model is supposed to stop if there are no alternatives.
	if(alpha){
		is_alpha_zero = false;
	}else{
		is_alpha_zero = true;
	}
}

char Generatemodel::generatenext(std::string word){
	/*
		Need to get random number then go through each of the letters in the alphabet subtracting each freq till I get to around zero.
	*/
		double rand = distr(gen);
		for(const auto [next_char,freq] : freq_map[word]){
			rand=rand - freq;			
			if(rand<=0){
				return next_char;
			}
		}
		// if the k-gram never occured in the training and alpha is 0 stop generating text.
		if(is_alpha_zero){
			exit(0);
		}
		// If the k-gram never occured in the training text then pick a letter from the alphabet at random
		int  index_ran= dis_int(gen);
		return alphabet[index_ran];
	
}


void Generatemodel::generatetext(string initial_word,int length){
	string window= initial_word;

	char next_char;
	for(int i=0;i<length;i++){
		next_char = generatenext(window);
		cout << next_char;
		window = window.substr(1,k)+next_char;
	}



}

   