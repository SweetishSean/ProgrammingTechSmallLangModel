
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
		//std::map<std::string, std::vector<std::string,int> > distribution;
		std::map<std::string,int> distribution;

		int k;	
	//		vector<std::vector<float> > ;
		int max_row;
		int max_col;
		
	public:
		Trainmodel() {};
		Trainmodel(int k_init);
		void readfile(std::string filename);
		
		
};





#endif