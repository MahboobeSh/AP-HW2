#include <iostream>
#include "libArr.h"
#include "libVec.h"
#include <iomanip>
#include <chrono>

using namespace std::chrono;

template<class T>
double runTime(int (T::*)(int) ,int);

int main(){


  int (libArr::*farr)(int){&libArr::counter};  //creating pointer to member function;
  int (libVec::*fvec)(int){&libVec::counter};
  

  //show result
  std::cout << std::setw(10)<< "n" << std::setw(15) <<"array time" <<std::setw(15)<< " vector time" << std::endl;
  
  for(long int i{1}; i < 10000000; i = 10 * i )
    {
      std::cout << "  " << std::setw(10) << i
                << std::setw(10)<< runTime(farr,i) << "    "  
                << std::setw(10)<< runTime(fvec,i) << "    " << std::endl;
  
    }



  return 0;
}

template<class T>       //define runTime function

double runTime( int (T::*f)(int) ,int n){

    T a;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();  //start time
    (a.*f)(n);
    high_resolution_clock::time_point t2 = high_resolution_clock::now(); //stop time
 
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();    //calculate runtime

 
    return duration;
 
}

