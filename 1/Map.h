#ifndef MAP_H
#define MAP_H

class Map{

 public:

  Map(int n);
  void showMap();
  void showRoute();
  void showRoute_B();
  void showbest();
  ~Map();

 private:
  void findRoute();
  void findRoute_B();
  void findbest();


  int N;
  int** map_arr{};
  int** route_arr_A{};
  int** route_arr_B{};
  int** best_route{};
 
};
	  

#endif
