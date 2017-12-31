#include <iostream>

int main () {
  std::cout << "What is your age?" << std::endl;
  int age;
  std::cin >> age;
  std::cout << "You are "<< age << " years old!!! \n"<<std::endl;
  std::cout << ((age < 50) ? ("Youre not too old") : ("ACK!!!")) << std::endl;
            return 0;
}
