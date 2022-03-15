//TODO: You get warnings when compiling that indicates that your const
//placement on the functions does not actually make the function
//const. Place the const after the naming to actually make it const.
//fixed 

//TODO: When using classes it is important to actually use
//encapsulation. That means that the data members should be declared
//as private since it is the class responsibility to change them.
// Fixed 
#ifndef TXTEDT_H
#define TXTEDT_H

#include <iostream>
#include <istream>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cstring>

class txtedt {
  
public:
  txtedt();
  ~txtedt();

  void insert(std::map<std::string, int> &f);
  int find_max();
  void print() const;
  void frequency();
  void table();
  void removeword(std::string &parameter);
  void substitute(std::string &parameter);
  std::vector<std::string>& getText();
private:
    std::vector<std::string> text{};

  struct sortword{
    bool operator()(const std::pair<std::string, int> &a,
		    const std::pair<std::string, int> &b){
      return a.second > b.second;}
  };
};

#endif
