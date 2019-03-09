#include <iostream>
#include <sstream>     
#include <string>
#include <cmath>
#include <fstream>
#include "DB.h"
#include "DBnew.h"


int main(){
  int number{};
  std::ifstream myfile ("db.txt");
  std::string input;


  std::getline(myfile,input);
  std::stringstream ss(input);
  ss >> number;

  DB dbarr[number];

  char temp{};
      for( int i{0} ; i < number ; i++ )
      {
         std::getline(myfile, input);
	 std::stringstream s(input);

         s >> temp >> dbarr[i].year >> temp >> dbarr[i].month
         >> temp >> dbarr[i].day >> dbarr[i].hour >> temp >> dbarr[i].minute
         >> temp  >> dbarr[i].product_id >> dbarr[i].customer_id ;

       
      }
  myfile.close();

   std::ofstream file ("dbnew.txt");
     DBnew test;
     test.year = dbarr[0].year;
     test.month = dbarr[0].month;
     test.day = dbarr[0].day;

     int t1{};
     int t2{};

     
     
     for( int i{0} ; i < number ; i++)
       {
	  t1=0;
	  t2=0;

	 
	 if( ( test.year == dbarr[i].year) & ( test.month == dbarr[i].month) & (test.day == dbarr[i].day))
	   {
	     for(size_t j{0} ; j < test.product.size() ; j++ )
	       {
		 if( dbarr[i].product_id == test.product[j] )
		     t1=1;
	       }
             for(size_t j{0} ; j < test.customer.size() ; j++ )
	       {
		 if( dbarr[i].customer_id == test.customer[j] )
		     t2=1;
	       }

	     if( t1 ==0 )
	          test.product.push_back( dbarr[i].product_id);
	     
	     if(t2 == 0)
	          test.customer.push_back( dbarr[i].customer_id);
	     
	   }
	 else
	   {
	     test.product_count = test.product.size();
	     test.customer_count = test.customer.size();
	    

	     file << "[" << test.year  << "-" << test. month
	          << "-" << test.day 
	          << "]" << " " << test.product_count
	           << " "  << test.customer_count <<std::endl;

	     test.product.clear();
	     test.customer.clear();

	     
	     test.year = dbarr[i].year;
             test.month = dbarr[i].month;
             test.day = dbarr[i].day;
             test.product.push_back( dbarr[i].product_id);
	     test.customer.push_back( dbarr[i].customer_id);



	   }
	 


       }
             test.product_count = test.product.size();
	     test.customer_count = test.customer.size();

	     
	     file << "[" << test.year  << "-" << test.month
	          << "-" << test.day 
	          << "]" << " " << test.product_count
	           << " "  << test.customer_count <<std::endl;

	     file.close();
    
       


       
       
   
    
   


  return 0;
}
