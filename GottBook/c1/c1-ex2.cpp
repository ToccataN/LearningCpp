#include <iostream>
#include <memory>
#include <string>


int main(){

  // part 1
  const char * ch = "a";

  int array[]= {1,2,3,4,5,6,7,8,9,0};

  int * arr= new int[10];

  char* charArr[] = {"a", "b", "c"};

  const char * myChar = "c";
  const char **m = &myChar;

  int const mouth= 30;

  const int face = 20;

  for(int i = 0; i < 10; ++i){
    std::cout << "\n array num :  " << array[i] << "\n" << std::endl;
    arr[i] = array[i] * 10;
  }

  for (int i = 0; i < 10; ++i){
    std::cout << "\n new array num: "<< arr[i] << "\n" << std::endl;
  }

  for (char * i : charArr){
     std::cout << "\n "<< i << std::endl;
  }

  std::cout << "\n letter of the day: " << **m << " is for " << mouth << " mouths."<<std::endl;


  std::cout << "your face is "<< face << " feet wide!!!" << std::endl;

  //part 2

  int array1[100];

  int * array2 = new int[100];


  return 0;

}
