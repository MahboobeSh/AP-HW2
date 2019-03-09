#ifndef DBNEW_H
#define DBNEW_H

#include <vector>

class DBnew{
 public:
  int year;
  int month;
  int day;
  int product_count;
  int customer_count;

  std::vector<int>  product;
  std::vector<int>  customer;
  


};

#endif
