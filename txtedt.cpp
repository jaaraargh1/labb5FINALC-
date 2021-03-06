

#include "txtedt.h"

using namespace std;

txtedt::txtedt(){};
txtedt::~txtedt(){};

/*

We are using a map since this will give us a faster time to find 
arleady inserted values. However, if every word would be different then it would make no
difference :)

*/

//Comment: The syntax map[string] += 1 works so that if the key
//already exists in the map it returns a reference to the value of
//that key, otherwise it creates the key value pair. As such you do
//not need to count or check the number of occurances, just doing the
//operation solves your problem.


vector<string>& txtedt::getText(){
return text;
}

void txtedt::insert(map<string, int> &f) {

  for_each(text.begin(), text.end(), [&f](string s){
				       if (f.count(s) > 0) {
					 f[s] = f[s]+1;
				       } else {
					 f.insert({s, 1});
				       }
				     });
}

/*

Using find max with lamba since we need to compare every single words
to find the length to print.

*/

//Comment: Good that you found the max element function.

//TODO: Distance calculates at which index the word occurs, not the
//length of the word. To get the lenght of the word you have to look
//at the word that your iterator points to.



// fixed
int txtedt::find_max() {
  
  vector<string>::iterator max;
  max = max_element(text.begin(), text.end(), []
		    (const string& a, const string& b) {
						return a.size() < b.size();
					       });

   string tmp{*max};
   
   return tmp.size();
 
}


/*
For_each since it does not matter how we iterate through the list.
*/


void txtedt::print() const {

  copy(text.begin(), text.end(), ostream_iterator<string>{cout, " "});

}



/*
Using pairs to convert our maps values so we cna print them
and sort its values with our custom operator to sort the words 
else we'd need to make a custom copy function.
*/

//TODO: Only capture variables that are needed in your lambdas. You do
//not use f in your lambda and should therefore not capture it. Only
//capture by reference if you actually need to change the value,
//otherwise capture it without a reference as that makes it a constant
//reference.
//Fixed



void txtedt::frequency() {
  std::map<std::string, int> f{};
  insert(f);
   int tmp = find_max();
  vector <pair<string, int>> sortw {};
  copy(f.begin(), f.end(), back_inserter(sortw));
  sort(sortw.begin(), sortw.end(), sortword());
    
  using pair = pair<string, int>;

  for_each(sortw.begin(), sortw.end(), [tmp](const pair& p) {
					 cout << setw(tmp) << p.first
					      << " " << p.second
					      << right << endl;    
				       });
  cout << endl;
}


void txtedt::table()  {
  map<string, int> f{};
  insert(f);
  int tmp = find_max();
  vector <pair<string, int>> sortl {};
  copy(f.begin(), f.end(), back_inserter(sortl));
  
  using pair = pair<string, int>;
 
  for_each(sortl.begin(), sortl.end(), [tmp](const pair& p) {
					 cout << left <<  setw(tmp)
					      << p.first << " " << p.second
					      << right << endl;    
				       });
  cout << endl;
}

/*

we have no other way to know where the word is located
so might as well use something that iterates through
the entire list =)

*/



void txtedt::removeword(string &parameter) {

  text.erase(remove(text.begin(), text.end(), parameter), text.end()); 
}

/*

This logical is literallly the same as above. We must in the worst 
case iterate through the entire list.

*/

void txtedt::substitute(string &parameter) {

  string delimiter{"+"};
  size_t sub = parameter.find(delimiter);
  string oldS = parameter.substr(0, sub);
  string newS = parameter.substr(sub+1, parameter.length());
  replace(text.begin(), text.end(), oldS, newS);
  
}
  


