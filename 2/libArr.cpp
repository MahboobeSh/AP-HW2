#include <iostream>
#include "libArr.h"


int libArr::counter(int n)
{
  arr = new int[n];
  int sum{0};
  for(int i{0} ; i<n ;i++)
    {
        arr[i]=i;
	sum += i;
    }
  delete []arr;
  
  return sum;


}
