#include <iostream>
#include <fstream>

int main (){
  std::ifstream fileMTX;
  fileMTX.open("young1c.mtx");

  int M, N, S;

  while (fileMTX.peek() == '%') fileMTX.ignore(2048, '\n');

  fileMTX >> M >> N >> S;

  std::cout <<"Rows: "<<  M << " Columns: "<< N << " Non-zeros: " << S << std::endl;

  fileMTX.close();

  return 0;
}
