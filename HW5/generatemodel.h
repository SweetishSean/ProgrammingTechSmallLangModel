
#ifndef GENERATEMODEL_H
#define GENERATEMODEL_H

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <random>
#include <stdexcept>

class Generatemodel
{
	private:
		std::map<std::string, std::map<char,double> > freq_map;

		std::mt19937 gen;
		std::uniform_real_distribution<double> distr;
		std::uniform_int_distribution<> dis_int; 
		
		bool is_alpha_zero;
		int k;	
		int size_of_alphabet;
		std::vector<char> alphabet;
	public:
		Generatemodel() {};
		Generatemodel(int k_init,std::map<std::string, std::map<char,double> > init_freq,std::vector<char> init_alphabet,int size_alpha,double alpha);
		char generatenext(std::string word);
		void generatetext(std::string initial_word,int length);
		
};





#endif