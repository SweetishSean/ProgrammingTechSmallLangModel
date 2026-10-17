#include<map>
#include<iostream>
#include<vector>


#include "trainmodel.h"
#include "trainmodel.cpp"

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
	
	string input_text= "story.txt";
	int k = 5;

	Trainmodel m1(k);
	m1.readfile(input_text);
	
	test_map["abab"]=15;
	
	
	for(const auto [key,value] : test_map)
		cout<<'[' << key << "] " << value<< endl;
	
	
	//map<string, vector<string,int> > distribution;

	return 0;
}