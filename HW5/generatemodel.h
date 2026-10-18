
#ifndef GENERATEMODEL_H
#define GENERATEMODEL_H

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <random>

class Generatemodel
{
	private:
		std::map<std::string, std::map<char,double> > freq_map;

	//	std::mt19937 gen;
//		std::uniform_real_distribution<double> distr;
		
		int k;	
		int size_of_alphabet;
		std::vector<char> alphabet;
	public:
		Generatemodel() {};
		Generatemodel(int k_init,std::map<std::string, std::map<char,double> > init_freq);
		void Generatetext(std::string word);
		
};





#endif