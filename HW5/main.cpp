#include<map>
#include<iostream>
#include<vector>


#include "trainmodel.h"
#include "trainmodel.cpp"

#include "generatemodel.h"
#include "generatemodel.cpp"


using namespace std;
/*
map<string,int>readdata(map<string,int> distro , string data_source,int k){
//	fstream data_source;
	string window;
	for(int i,i<k,i++){
		data_source
		
		
	}

	//window=window.substr(0,k-1);


	return distro;
}
*/


int main(int argc, char* argv[]){
	string output= "Hello Word";
	string output_2=output.substr(0,5)+'t';
	cout <<output_2<<endl;
	map<string,int> test_map;
	
	test_map["abab"]=15;
	test_map["abaa"]=20;
	test_map["ssab"]=15;
	
	
	
	string input_text= "story.txt";
	int k = 5;
	double alpha = .1;
	Trainmodel m1(k,alpha);
	m1.readfile(input_text);
	map<string,map<char,double> > mapout = m1.dataout();
	/*
	for(const auto [key,value] : test_map)
		cout<<'[' << key << "] " << value<< endl;
	
	cout << test_map["abb"]<<endl;
	
	for(const auto [key,value] : test_map)
		cout<<'[' << key << "] " << value<< endl;
	*/
	
	for(const auto [key,value] : mapout){
		cout<<'[' << key << "] " << endl;
		for(const auto [nex_char,occr] : value){
		cout<< nex_char << " " << occr << endl;
		}
	}
	


	// Generate part below:
	Generatemodel gen1(k,mapout);




	return 0;
}