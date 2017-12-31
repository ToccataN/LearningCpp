/* Chad Denaux - Chapter 2 exercises 1 - 3 from Gottschling book.
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <initializer_list>

class polynomial {
  int degree;
  std::vector<float> *coef = new std::vector<float>();
  std::string str;

  public:
    //constructor method
    polynomial(int d,const std::vector<float>& v){
      degree = d;
      *coef = v;
    }

    //move assignment
    polynomial(polynomial&& cp) : degree(cp.degree), coef(cp.coef){

      cp.coef=0;
      cp.degree=0;

    }

    //initializer_list
    polynomial(std::vector<float> values)
      : degree(values.size()), coef( new std::vector<float>() )
      {
        this->coef->assign(values.begin(), values.end());
      }

    //print out specifications
    void get(){
      iterate(*coef);
      std::cout << degree <<" degree polynomial with coefficients of: " << str << std::endl;
    }
    //iterate through the vector
    void iterate(const std::vector<float> v){
      for ( int i = 0 ; i < v.size() ; i++){
         //had to round out format for to_string argument
         str += " " + std::to_string((v[i] * 100)/100).substr(0, 4) + ", ";
      }
    }

    polynomial f(float a, float b, float c){
      std::vector<float> v = {a, b, c};
      std::cout << "Here we go!!!";
      polynomial n(3, v);
      return n;
    }

    ~polynomial() {
      for (int i = 0 ; i < coef->size() ; i++){
        delete coef;
        std::cout << " coefficients vector deleted."<<std::endl;
      }
    }


};

int main(){
   std::vector<float> c = {1.0, 2.2, 3.0};
   polynomial p(3, c);
   p.get();
   polynomial v(p.f(30.2, 50.1, 2.7));
   v.get();

   polynomial mouth({5.5,6.6,7.7, 8.8, 9.9});
   mouth.get();

}
