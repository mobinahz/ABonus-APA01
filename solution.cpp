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


Data calculate_the_max(long int max, vector<long int> sums)
{
   Data data;

   for(int i = 0; i < sums.size(); i++)
   {
      if(sums[i] >= max)
      {
         data.max = sums[i];
         data.current = i;
         max = data.max;
      }
   }

   return data;
}


long int choose_the_way(long int harvest, long int max_row, long int max_column)
{
   if(max_column > max_row)
   {
      harvest += max_column;
   }
   else
   { 
      harvest += max_row;
   }

   return harvest;
}


void delete_the_column(int row, int current_column, vector<vector<int>> & farm_land)
{
   for(int i = 0; i < row; i++)
   {
      farm_land[i][current_column] = 0;
   }
}


void delete_the_row(int column, int current_row, vector<vector<int>> & farm_land)
{
   for(int j = 0; j < column; j++)
   {
      farm_land[current_row][j] = 0;
   }
}


long int calculate_best_ways(vector<vector<int>> farm_land, int column, int row)
{
    long int max_row = 0;
    long int max_column = 0;
    long int harvest = 0;
    long int chosen = 0;
    vector<long int> row_sums;
    vector<long int> column_sums;
    Data row_data;
    Data column_data;

    for(int move = 0; move < 4; move++) 
    {
        row_sums = calculate_sum_of_the_rows(row, farm_land);
        row_data = calculate_the_max(max_row, row_sums);       
        column_sums = calculate_sum_of_the_columns(row, column, farm_land);
        column_data = calculate_the_max(max_column, column_sums);
        chosen = harvest;
        harvest = choose_the_way(chosen, row_data.max, column_data.max);

        if(column_data.max > row_data.max)
        {
           delete_the_column(row, column_data.current, farm_land);   
        } 
        else
        {
           delete_the_row(column, row_data.current, farm_land);
        }

        row_data.max = 0;
        column_data.max = 0;
        row_data.current = 0;
        column_data.current = 0;
    }

    return harvest;
}


void print_the_output(long int harvest)
{
   cout << harvest << endl;
}


int main() 
{
   Input input;
   long int harvest = 0;
    
   input = get_input();
   harvest = calculate_best_ways(input.land, input.column, input.row);
   print_the_output(harvest);

   return 0;
} 

