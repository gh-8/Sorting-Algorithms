/*bubble sort algorithm */
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std; 

void print_array(int array[], int size) //Display the array after each step of the bubble sort
{										//Pre-condition: the array it is reading in has values
	cout<< "bubble sort steps: ";
	int j; 
	for (j=0; j<size;j++)
    {
        cout <<" "<< array[j];
    }
	cout << endl;
}

void bubble_sort(int arr[], int size) //Bubble sort
{									  //Pre-condition: the array has values it can read
	bool not_sorted = true;
    int j=1;
    int tmp;
	while(not_sorted)
	{ 
		not_sorted = false; 
		j++; 
		for(int i = 0; i < size - 1; i++)
		{ 
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1]; 
				arr[i + 1] = tmp; 
				not_sorted = true;     
			}
			print_array(arr,size);  
		}
	}
}
	
int main()
{
    const int max_length = 200;
    int a[max_length];
    int count = 0;
    ifstream infile;
    infile.open("input.txt");
    if (infile.is_open())
		{
			for(int i = 0; i < max_length; i++)
			{
				if (infile.eof())
				{
					break;
				}
				count++;
				infile >> a[i];
			}
		}
    print_array(a,count - 1);
    bubble_sort(a,count - 1);
    return 0;
}
