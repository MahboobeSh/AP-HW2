#include<iostream>
#include "Map.h"
#include <ctime>

int main(){

  int n{};
  std::cout << "inter number : " ;
  std::cin >> n ;
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  
  Map map1{n};

  map1.showMap();
  map1.showRoute();
  map1.showRoute_B();
  map1.showbest();

  return 0;
}

