
#ifndef TRAINMODEL_H
#define TRAINMODEL_H

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

class Trainmodel
{
	private:
		std::map<std::string, std::map<char,int> > distribution;
		int k;	
		int size_of_alphabet;
		std::vector<char> alphabet;
		double alpha;
	public:
		Trainmodel() {};
		Trainmodel(int k_init,double alpha_init);
		void readfile(std::string filename);
		std::map<std::string, std::map<char,double> >   dataout();
		
};





#endif