 #include <conio.h>//refreshes screen
 #include <iostream>
 #include <cmath> 
 #include <algorithm>
 #include <queue>
 #include <string>
using namespace std;
#include <time.h>

int distance(int array[][3]);
void printboard(int array[][3]);
int rightmove(int array[][3],int zerox,int zeroy);
int leftmove(int array[][3],int zerox,int zeroy);
int downmove(int array[][3],int zerox,int zeroy);
int upmove(int array[][3],int zerox,int zeroy);
  int main()
  {
   
     srand(time(NULL));
     int randomTie;
     int right;
     int left;
     int up;
     int down;
     int lastcall = 0;
     int zerox = 0;
     int zeroy = 0;
     int count = 0;
     int X = 0;
     int goal [3][3] = { {1,2,3},{4,5,6},{7,8,0}};
     const int N = 3;
     int intial[N][N]= { {9,9,9},{9,9,9},{9,9,9}};;
     cout << "Enter in values(1-8,0 for blank space): \n";
     for(int i=0; i<3; i++)    //This loops on the rows.
	{
		for(int j=0; j<3; j++) //This loops on the columns
		{
			cin >> intial[i][j];
			system("cls");
			cout << "----- \n";
			printboard(intial);
			cout << "----- \n";
			cout << "Enter in values(1-8,0 for blank space):";
            if(intial[i][j] == 0)
            {
               zerox = i;
               zeroy = j;                
            }
            if(intial[i][j] > 8 || intial[i][j] < 0 )
            {
             cout << "Error! Enter only 0-8!!\n";
             system("PAUSE");
             exit(0);
            }
            
		}
	}
    
    
    
     int z = distance(intial);
    
     printboard(intial);
   
   while(z > 0)
   {
    
      right = 100;
      left = 100;
      up = 100;
      down = 100; 
            
     
     if(zeroy != 2 && lastcall != 2)
     {                     
           right = rightmove(intial,zerox,zeroy);
           
     }
     if(zeroy !=0 && lastcall != 1)
     {
           left = leftmove(intial,zerox,zeroy);
           
     }
     if(zerox != 0 && lastcall !=3)
     {
           up = upmove(intial,zerox,zeroy);
           
     }
     if(zerox != 2 && lastcall != 4)
     {
           down = downmove(intial,zerox,zeroy);
           
     }
         if(right ==left || right == up || right == down )
         {
                randomTie = rand()%2;
                if(randomTie == 0)
                {
                      right = 100;       
                }       
                       
                       
         }  
         else if(left ==right || left == up || left == down )
         {
                randomTie = rand()%2;
                if(randomTie == 0)
                {
                      left = 100;       
                }       
                       
                       
         } 
         else if(up ==right || up == left || up == down )
         {
                randomTie = rand()%2;
                if(randomTie == 0)
                {
                      up = 100;       
                }       
                       
                       
         } 
         else if(down ==right || down == left || down == left )
         {
                randomTie = rand()%2;
                if(randomTie == 0)
                {
                      up = 100;       
                }       
                       
                       
         } 
            
           
          
          
          
          //right
          if(right <= left && right <= up && right <= down)
           {
             
              
              int temp = intial[zerox][zeroy + 1];
              intial[zerox][zeroy + 1] = intial[zerox][zeroy];
              intial[zerox][zeroy] = temp;
              zeroy = zeroy + 1;
              lastcall = 1;
              
                    
            }
           //down
           else if(down <= left && down <= up && down <= right)
           {
              int temp = intial[zerox+1][zeroy];
              intial[zerox +1][zeroy] = intial[zerox][zeroy];
              intial[zerox][zeroy] = temp;
              zerox = zerox + 1;
              lastcall = 3;
           }
           //left
           else if(left <= right && left <= up && left <= down)
           {
              
              int temp = intial[zerox][zeroy - 1];
              intial[zerox][zeroy - 1] = intial[zerox][zeroy];
              intial[zerox][zeroy] = temp;
              zeroy = zeroy - 1;
              lastcall = 2; 
                     
           }
           
           //up
           else if(up <= left && up <= right && up <= down)
           {
              int temp = intial[zerox-1][zeroy];
              intial[zerox - 1][zeroy] = intial[zerox][zeroy];
              intial[zerox][zeroy] = temp;
              zerox = zerox - 1;
              lastcall =4;
           }
           
           printboard(intial);  
           z = distance(intial);
           count++;
           if(count == 10000)
           {
             z = -1;  
           }
           
    }
     
    if(z == 0)
    {
     cout << "Goal State reached!!!!! \n";
     cout << "Took " << count << " moves!!!\n";
     }
     else if(z < 0)
     {
         cout << "Did 10000 moves still no solution\n";
     }
     //printboard(intial);
     system("PAUSE");
     return 0;
}
int distance(int array[][3])
{
      
      int MSum = 0;
      int x,y,value,targetX,targetY,dy,dx;
      for (x = 0; x < 3; x++){ //Transversing rows(i)
          for (y = 0; y < 3; y++) { //traversing colums (j)
            value = array[x][y]; // sets int to the value of space on board
                if (value != 0) { // Don't compute MD for element 0
                   targetX = (value - 1) / 3; // expected x-coordinate (row)
                   targetY = (value - 1) % 3; // expected y-coordinate (col)
                   dx = x - targetX; // x-distance to expected coordinate
                   dy = y - targetY; // y-distance to expected coordinate
                   MSum += abs(dx) +abs(dy);   
                }
            }
      
      }
      int m = MSum;
      return m;
    
}
int rightmove(int array[][3],int zerox,int zeroy)
{
   int arraycopy[3][3];
   copy(&array[0][0], &array[0][0] + 3*3, &arraycopy[0][0]);
   int temp = arraycopy[zerox][zeroy+1];
   arraycopy[zerox][zeroy+1] = arraycopy[zerox][zeroy];
   arraycopy[zerox][zeroy] = temp;
  // zeroy = zeroy + 1;
   int z = distance(arraycopy);

   return z;  
}

int leftmove(int array[][3],int zerox,int zeroy)
{
   int arraycopy[3][3];
   copy(&array[0][0], &array[0][0] + 3*3, &arraycopy[0][0]);
   int temp = arraycopy[zerox][zeroy - 1];
   arraycopy[zerox][zeroy - 1] = arraycopy[zerox][zeroy];
   arraycopy[zerox][zeroy] = temp;
   int z = distance(arraycopy);
   return z; 
 
}
int upmove(int array[][3],int zerox,int zeroy)
{
   int arraycopy[3][3];
   copy(&array[0][0], &array[0][0] + 3*3, &arraycopy[0][0]);
   int temp = arraycopy[zerox-1][zeroy];
   arraycopy[zerox-1][zeroy] = arraycopy[zerox][zeroy];
   arraycopy[zerox][zeroy] = temp;
   int z = distance(arraycopy);
   return z; 
 
}
int downmove(int array[][3],int zerox,int zeroy)
{
   int arraycopy[3][3];
   copy(&array[0][0], &array[0][0] + 3*3, &arraycopy[0][0]);
   int temp = arraycopy[zerox+1][zeroy];
   arraycopy[zerox+1][zeroy] = arraycopy[zerox][zeroy];
   arraycopy[zerox][zeroy] = temp;
   int z = distance(arraycopy);
   
   return z; 
}
 
void printboard(int array[][3])
{
  cout << "\n";
  for(int i =0; i <3;i++)
  {
       for(int j = 0; j <3;j++)
       {
              if(array[i][j] !=0)
               {
                  cout << array[i][j] << " ";
              }
              else
                 cout << "  ";
       }   
       cout << "\n";
  }   
  cout << "\n";   
     
}
