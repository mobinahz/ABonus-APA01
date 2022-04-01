#include <iostream>

#include <vector>

using namespace std;

struct Input
{
   int row;
   int column;
   vector<vector<int>> land;
};

struct Data
{
   long int max;
   int current;
};


Input get_input()
{
   int product;
   Input input;
   
   cin >> input.row >> input.column;

   vector<vector<int>> farm_land(input.row, vector<int>(input.column));

   for(int i = 0; i < input.row; i++)
   {
      for(int j = 0; j < input.column; j++)
      {
         cin >> product;
         farm_land[i][j] = product;
      }
   }
   input.land = farm_land;

   return input; 
}


long int calculate_sum(vector<int> each_line)
{
    long int sum = 0;

    for (int i = 0; i < each_line.size(); i++)
    {
       sum += each_line[i];
    }

    return sum;
}


vector<long int> calculate_sum_of_the_rows(int row, vector<vector<int>> farm_land)
{

   long int sum = 0;
   vector<long int> row_sum;

   for(int i = 0; i < row; i++)
   {
      sum = calculate_sum(farm_land[i]);
      row_sum.push_back(sum);
      sum = 0;
   }

   return row_sum;
}


vector<long int> calculate_sum_of_the_columns(int row, int column, vector<vector<int>> farm_land)
{
   long int sum = 0;
   vector<long int> column_sum;
   
   for(int j = 0; j < column; j++)
   { 
      for(int i = 0; i < row; i++)
      {
         sum += farm_land[i][j];
      }
      column_sum.push_back(sum);
      sum = 0;
   }

   return column_sum;
}


long int calculate_best_ways(vector<vector<int>> farm_land, int column, int row)
{
    int max_row = 0;
    int max_column = 0;
    long int harvest = 0;
    long int chosen = 0;
    vector<long int> row_sums;
    vector<long int> column_sums;
    Data row_data;
    Data column_data;

    for(int move = 0; move < 4; move++) 
    {
        row_sums = calculate_sum_of_the_rows(row, farm_land);
        
        column_sums = calculate_sum_of_the_columns(row, column, farm_land);

        if(maxColumn > max_row){
            harvest += maxColumn;
            for(int i = 0; i < m; i++){
                farm[i][column] = 0;
            }
        }
        else{
            harvest += max_row;
            for(int j = 0; j < n; j++){
                farm[row][j] = 0;
            }
        }
        row = 0;
        column = 0;
        maxColumn = 0;
        max_row = 0;
    }
}
/*----------------*/
int main() 
{
    Input input;
    long int harvest = 0;
    
    input = get_input();
    // solve
    solve(m, n, harvest);
    cout<<harvest;
    return 0;
    cout << "Hello there! I'm unreachable!" << endl;
} // main

// no reason for this comment
