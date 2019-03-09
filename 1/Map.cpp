#include <iostream>
#include "Map.h"
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>

Map::Map(int n){
  
  N = n;
  map_arr = new int*[N];
  
  for(int i{0} ; i < N ; i++)
    map_arr[i] = new int[N];

  for(int i{0} ; i < N ; i++)
    for( int j{0} ; j < N ; j++)
      map_arr[i][j]= rand()%101;


  route_arr_A = new int*[N];

  for(int i{0} ; i < N ;i++)
    route_arr_A[i] = new int[N];

  route_arr_B = new int*[N];

  for(int i{0} ; i < N ;i++)
    route_arr_B[i] = new int[N];
  
  best_route = new int*[N];

  for(int i{0} ; i < N ;i++)
    best_route[i] = new int[N];

}

Map :: ~Map(){

  for(int i{0} ; i < N ; i++ )
    delete [] map_arr[i];
  delete [] map_arr;


  for(int i{0} ; i < N ; i++ )
    delete [] route_arr_A[i];
  delete [] route_arr_A;
  
   for(int i{0} ; i < N ; i++ )
    delete [] route_arr_B[i];
   delete [] route_arr_B;

     
   for(int i{0} ; i < N ; i++ )
    delete [] best_route[i];
   delete [] best_route;
}




void Map::showMap(void){
  
  std::cout << "MAP : "  << std::endl;
  
  for(int i{0} ; i < N ; i++)
  {
    for(int j{0} ; j < N ;j++)
      std::cout << std::setw(3) << map_arr[i][j] << "  "  ;

    std::cout << std::endl;
  }

  return ;
  
}

void Map::findRoute(){
  
  int x{0};
  int y{0};
  int sum{0};


  
   while( (x != N-1) || (y != N-1))
    {
      route_arr_A[x][y] = 1;
  
         if( x == N-1)
	   {    sum += std::abs(map_arr[x][y] - map_arr[x][y+1]);
         	y++;
	   }
         else if( y == N-1)
	   {    sum += std::abs(map_arr[x][y] - map_arr[x+1][y]);
        	x++;
	   }
         else if(std::abs( map_arr[x+1][y]-map_arr[x][y]) <std::abs( map_arr[x][y+1]-map_arr[x][y]) )
	   {
	        sum += std::abs(map_arr[x][y] - map_arr[x+1][y]);
        	x++;
	   }
         else
	   {
	     sum += std::abs(map_arr[x][y] - map_arr[x][y+1]);
	     y++;
	   }
	      
    
    }
   
  route_arr_A[x][y] = 1;
  std::cout << " SUM : " << sum << std::endl;

  return;
  }


void Map::showRoute(){
  
  std::cout << "part A: " << std::endl;
    findRoute();
    std::cout <<" ROUTE "  << " : " << std::endl;
  
  for(int i{0} ; i < N ; i++)
  {
    for(int j{0} ; j < N ;j++)
      std::cout << std::setw(3) << route_arr_A[i][j] << "  "  ;

    std::cout << std::endl;
  }
  

  return ;
  
}


void Map::findRoute_B(){
  
  int x{0};
  int y{0};
  int sum{0};

  
   while( (x != N-1) || (y != N-1))
    {
    
      route_arr_B[x][y] = 1;
      
         if( x == N-1)
	   {    sum += std::abs(map_arr[x][y] - map_arr[x][y+1]);
         	y++;
	   }
         else if( y == N-1)
	   {
	        sum += std::abs(map_arr[x][y] - map_arr[x+1][y]);
        	x++;
	   }
          else if( ( std::abs(map_arr[x+1][y]-map_arr[x][y])<=std::abs( map_arr[x][y+1]- map_arr[x][y])) &
		   (std::abs(map_arr[x+1][y]- map_arr[x][y])<= std::abs(map_arr[x+1][y+1]- map_arr[x][y])))
	   {
		 sum += std::abs(map_arr[x][y] - map_arr[x+1][y]);
		 x++;
	   }
	   else if( (std::abs(map_arr[x][y+1]- map_arr[x][y])<= std::abs(map_arr[x+1][y]-map_arr[x][y])) &
		    (std::abs( map_arr[x][y+1]-map_arr[x][y])<= std::abs(map_arr[x+1][y+1]-map_arr[x][y])))
	    {
	        sum += std::abs(map_arr[x][y] - map_arr[x][y+1]);
                y++;
	    }
	   else
        	{ sum += std::abs(map_arr[x][y] - map_arr[x+1][y+1]);
		  x++;
 		  y++;
	       	}    
    
    }

 
  route_arr_B[x][y] = 1;

  std::cout << " SUM : " << sum << std::endl;

  return;
  }


void Map::showRoute_B(){

  std::cout << "part B :" << std::endl;
  findRoute_B();
  std::cout <<" ROUTE "  << " : " << std::endl;
  
  for(int i{0} ; i < N ; i++)
  {
    for(int j{0} ; j < N ;j++)
      std::cout << std::setw(3) << route_arr_B[i][j] << "  "  ;

    std::cout << std::endl;
  }
  return;

}

void Map::findbest(void){

  int sum{0};
  int sum_min{100000};
  int x{};
  int y{};

  std::vector<int> v ;
  std::vector<int> v1;
  for(int i{0} ; i< N-1 ; i++)
    {
      v.push_back(2);
      v.push_back(3);
    }
  
    do {
          x=0;
          y=0;
         sum=0;
          best_route[x][y]=1;
        for(int i{0} ; i< 2*(N-1) ;i++)
	{
	  if(v[i] == 2)
	    {
	      sum += std::abs(map_arr[x][y]-map_arr[x+1][y]);
	       x++;
	    }
	  else
	    {
	      sum += std::abs(map_arr[x][y]-map_arr[x][y+1]);
	      y++;

	    }
	  
	}

        if( sum  < sum_min )
	{
	  sum_min = sum;
	  v1.clear();
	    for(int i{0} ; i< 2*(N-1) ;i++)
	      v1.push_back( v[i]);
	 }
  
    } while (std::next_permutation(v.begin(), v.end()));
    
    x=0;
    y=0;
    
      for(int i{0} ; i< 2*(N-1) ;i++)
	{
	  if(v1[i] == 2)
	       x++;
	  else
	      y++;
	  best_route[x][y]=1;
	}
      
      best_route[x][y]=1;
      std::cout << std::endl;
      std::cout << "sum : " << sum_min << std::endl;

  return;
}


void Map::showbest(void){

   std::cout << "part C :" << std::endl;
   findbest();
   std::cout <<" BEST ROUTE "  << " : " << std::endl;
  
  for(int i{0} ; i < N ; i++)
  {
    for(int j{0} ; j < N ;j++)
      std::cout << std::setw(3) << best_route[i][j] << "  "  ;

    std::cout << std::endl;
  }

  return;
}
