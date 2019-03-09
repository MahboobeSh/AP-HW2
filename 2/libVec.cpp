#include <iostream>
#include "libVec.h"
#include <vector>



int libVec::counter(int n)
{
  std:: vector <int> vec;
  int sum{0};
  for(int i{0} ; i<n ;i++)
    {
      vec.push_back(i) ;
      sum += i;
    }
  return sum;
}
