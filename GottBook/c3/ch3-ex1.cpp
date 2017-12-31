
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <iterator>
#include <typeinfo>
#include <cmath>

//Generic string template function
template <typename T>
std::string to_string(const T& val){
  std::ostringstream os;
  os << std::setprecision(10) << val << std::endl;
  return os.str();
}

//veriadic template function
template < typename ...T>
std::string to_tuple_string(const T&... args){
  std::ostringstream s1;
  std::ostringstream s2;
  std::ostringstream s3;
  std::string str;

  std::vector<int> arg = {args...};
  for (int i = 0; i < arg.size(); i++){
    if (i%3 == 0){
      s1 << to_string(arg[i]);
    } else if (i%3==1){
      s2 << to_string(arg[i]);
    } else {
      s3 << to_string(arg[i]);
    }
  }

  str+= "(" + s1.str() + ", " + s2.str() + ", " + s3.str() + ")";
  str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

  return str;

}

//Generic Stack implementation
template <typename T, int defSize = 4096>
class stack {
  int si;
  std::vector<T> data ;

  public:
    stack(const T& first){
      this->si = defSize;
      data={first};
    }

    stack(int s, const T& first){
      this->si = s;
      data = {first};
    }

    std::string top(){
      int b = data.back();
      return to_string(b);
    }

    void push(const T& n){
      if (data.size() < si){
        data.push_back(n);
      } else {
        std::cout << "stack is too full"<< std::endl;
      }
    }

    void pop(){
      data.pop_back();
    }

    int size(){
      return si;
    }

    void clear(){
      data.clear();
    }

    void full(){
      if (data.size() == si){
        std::cout << "the stack is full" << std::endl;
      } else {
        std::cout << "fill me up, bitch!" << std::endl;
      }
    }

    void empty(){
      std::cout << ((data.size() == 0) ? ("the stack is empty") : ("I'm not empty!")) << std::endl;
    }

};

//vector class from book
template <typename T>
class vector1
{
public:
  explicit vector1(int size) : my_size(size), data(new T[my_size])
  {}

  vector1(const vector1& that)  : my_size(size), data(new T[my_size])
  {
    std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
  }

  int size() const { return my_size; }

  const T& operator[](int i) const
  {
    return data[i];
  }

  int get(){
    return my_size;
  }

  const T& begin(){
    return data[0];
  }

  const T& end(){
    return data[my_size];
  }

  const T& mydata(){
    return data;
  }

  void populate(){
    for (int i = 0; i <= my_size; i++){
      const T& r = T(rand()) / T(10);
      data[i] = r;
    }
  }

  void iterate(){
    std::string str;
    for (int i = 0 ; i <= my_size; i++){
      str+= to_string(i) + ": " + to_string(data[i])+ "   ";
    }
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    std::cout << str << std::endl;
  }

  T iterint(){
    T arr[my_size];
    for (int i = 0 ; i <= my_size; i++){
      arr[i]= data[i];
    }
    return arr;
  }

private:
  int   my_size;
  std::unique_ptr<T[]> data;

};

template<class T>
class odd_iterator
{
  int size;


public:
  std::vector<T> v;
  template<typename ...P>
  explicit odd_iterator(const P&... vec)
  {
    this->v = {vec...};
    this->size = v.size();
  }

  const T& get(){
    return size;
  }
  // prefix operator overload
  void operator++() {
    int i = v.back();
    int m = ((i % 2 == 1) ? i + 2 : i + 1);
    v.push_back(m);
    size= v.size();
  }
  //post-fix operator overload
  void operator++(int) {
    int i = v.back();
    int m = ((i % 2 == 1) ? i + 2 : i + 1);
    v.push_back(m);
    size= v.size();
  }
  //pointer/dereference operator overload
  const T& operator*(int i){
    T m = ((v[i] % 2 ==1) ? v[i] : (v[i+1]));
    return m;
  }



};

template<typename T>
class odd_range {

  std::vector<T> vec;
  T first, last;
  public:
    odd_range(const T& first, const T& last){
      this->first= first;
      this->last= last;
      vectorate();
    }

    void vectorate(){
      for(int i = first; i < last; i++){
        if (i % 2 == 1) {
          vec.push_back(i);
        }
      }
    }

    void iterateOdd(){
      for(int i : vec){
        std::cout << "odd_range val: "<< i << "\n" << std::endl;
      }
    }
};
//Deduce non-type template arguments
template<typename T>
void figure_array(T arr[]){
  std::cout << "Type: "<< typeid(arr).name()  <<" length: " << to_string(sizeof(arr)) <<std::endl;
}

//generate functor for Trapezoid rule
template<typename F, typename T>
T inline trapezoid(F f,const T& a,const T& b){
  T num = b - a;
  T n = num / num;
  T first = f(a)/2;
  T second = f(b)/2;
  T result = 0;

  for (int i = 1 ; i < num ; i++){
    T var = a + (n * i);
    result += f(var);
  }

  result = result + first + second;
  return result;

}

template<typename F, typename T>
T inline fin_diff(F f, const T& x, const T& h){
  return (f(x+h) - f(x))/h;
}

double dubCos( double x){
  return 2*std::cos(x)+std::pow(x, 2);
}

double exp3f(double x){
  return std::exp(3 * x);
}


int main(int argc, char* argv[]){
  //string converter ex1
  std::cout << "generic string function: 1. " <<to_string(10.09898)
  << "2. " << to_string('a') << std::endl;
  //tuple tester ex2
  std::cout << to_tuple_string(1, 2, 3, 4, 5, 6, 7, 7, 78, 99) << std::endl;
  //stack tester ex 3
  stack<int> c(100, 2);
  c.push(5);
  c.push(6);
  c.pop();
  std::cout << c.top() << c.size() << std::endl;
  c.clear();
  std::cout << c.top();
  c.empty();
  for (int i = 0 ; i < 102 ; i++){
    c.push(i);
  }
  c.clear();
  c.full();
  //vector class testing ex 4
  vector1<float> vect(10);
  vect.populate();
  std::cout << to_string(vect.get()) << "begin-value: " << to_string(vect.begin()) << "end value: " <<
            to_string(vect.end()) << std::endl;
  vect.iterate();

  //iterator class items 3.11.5
  odd_iterator<int> iter(1,2,3,4,5,6,7,8,9);
  std::cout << "  " << iter.get() << std::endl;
  ++iter;
  std::cout << " " << iter.get() << std::endl;
  iter++;
  std::cout << " " << iter.get() << std::endl;
  int num = iter*(10);
  std::cout << "number: " << num << std::endl;

  //3.11.6
  odd_range<int> stuff(7, 35);
  stuff.iterateOdd();

  //3.11.8
  stack<int> stack2(30);
  std::cout << stack2.top() << stack2.size() << std::endl;

  //3.11.9
  int array[300];
  figure_array(array);

  //3.11.10
  std::cout << "trapezoid function: " << trapezoid(exp3f, 1.0, 4.0) << std::endl;

  //3.11.11
  std::cout << "derivative 1: " <<fin_diff(dubCos, 1.0, .01) << " derivative 2: "
            << fin_diff(dubCos, 2.0, .01) << std::endl;

  //3.11.12
  std::cout << ":: lambda :: derivative 1: " <<fin_diff([](double x){return 2*std::cos(x)+std::pow(x, 2);}, 1.0, .01) << " derivative 2: "
            << fin_diff([](double x){return 2*std::cos(x)+std::pow(x, 2);}, 2.0, .01) << std::endl;
}
