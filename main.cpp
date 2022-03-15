//TODO: Connected to the previous todo, define your variables as
//locally as possible. If a variable is only used in a lambda function
//and it is not necessary that it exists outside of the lambda then
//the variable should be declared in the lambda.  Not fixed: You are
//passing arguments through many lambdas altough it is not needed.


// Fixed in main file
//TODO: You do not use the return value of the findeq
//function. Declare it as void instead.

// fixed
#include <iostream>
#include <istream>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "txtedt.h"

using namespace std;
/*
  we have to find substring element of the = and only way to do 
  this is to iterate through every single character.
*/
void findeq(string s, const vector <string> &arguments, string &flag,
	      string &parameter) {

  string tmp{};
  string delimiter{"="};

  flag=s.substr(0, s.find(delimiter));
  parameter=s.substr(s.find(delimiter)+1, s.length());

}

int main(int argc, char** argv) {
  
  vector <string> arguments {argv, argv + argc};
  txtedt txt{};
  
  if (argc > 2) {
    string inputfile{arguments[1]};
    ifstream readingInput(inputfile);
    vector <string> tmp {
      istream_iterator<string>{readingInput},
      istream_iterator<string>{}
    };
    readingInput.close();
    txt.getText() = tmp;
	
    arguments.erase(arguments.begin());
    arguments.erase(arguments.begin());

    for_each(arguments.begin(), arguments.end(), [&txt, &arguments](string s)
						 {
						   if (s == "--print") {
						     txt.print();
						     cout << endl;
						   } else if (s == "--frequency") {
						     txt.frequency();
						     cout << endl;
						   } else if (s == "--table") {
						     txt.table();
						     cout << endl;
						   }
						   //TODO: Define your
						   //variables as
						   //locally as
						   //possible. The
						   //flag and
						   //parameter does
						   //not need to be
						   //defined outside
						   //of the lambda.
						   //FIXED

						   
						   if (s.find('=')){
						     
						     for_each(arguments.begin(), arguments.end(),
							      [&arguments, &txt](string s){
								string flag;
								string parameter;
								  if(s.find('=') != string::npos) {
								    findeq(s, arguments, flag, parameter);
								    if (flag == "--remove") {
								      txt.removeword(parameter);								    
								    } else if (flag == "--substitute") {
								      txt.substitute(parameter);
								    }
								  }});
						   }
	
						 });

						    
  } else {
    cout << "no commands given" << endl;
  }

}
