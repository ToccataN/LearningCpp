/*
 * Chad Denaux: chapter 4 exercises
 * Skip exercise 3, will instead engage in a tutorial learning
 * SDL2 specifically.
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

//Ex. 1. Sort vector values using functor passed with lambda function.
template<typename F, typename T>
vector<T> compMag(F f, vector<T> vec){
  for (int i = 0 ; i < vec.size() ; i++){
    for(int j = 0; j < vec.size(); j++){
      if(f(vec[i], vec[j])){
        iter_swap(vec.begin() + i, vec.begin() + j);
      }
    }
  }
  return vec;
}


int main(){

  //Exercise 1
  vector<double> myVec= {-9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2};

  myVec= compMag([](double x, double y){ return (x>y); }, myVec);

  for (double i : myVec){
    cout << "list-item: "<< i << endl;
  }

  //exercise 2 finding numbers
  map<string, unsigned long> phones= {{"chad", 5555555},
                            {"shannon", 1234567},
                            {"hamster", 6666666},
                            {"theface", 9999999}};

  cout << "Chads #: " << phones.at("chad") << "\n"<<
          "Shiro's number: " << phones["Shiro"]<<endl;
          auto it = phones.begin();
        	while(it != phones.end())
        	{
        		if(it->second == 1234567)
        		{
        			cout << it->first << "'s number"<<endl;
        		}
        		it++;
        	}

  return 0;


}
