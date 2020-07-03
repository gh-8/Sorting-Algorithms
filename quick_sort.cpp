/*quick sort algorithm */
#include <cstdlib>
#include <iostream>
#include<fstream>
using namespace std;

void print_array(int arr[], int low, int hi)
{
	cout<< "quick sort partition steps: ";
	for (int j=low; j<=hi;j++)
		cout <<" "<< arr[j];
	cout << endl;
	return;
}

void swap(int arr[], int i, int j)
{
    int temporary=arr[i];
	arr[i]=arr[j];
	arr[j] =temporary;
	return;
}

int partition(int arr[], int low, int hi)
{
	int pivot = arr[hi];
	int i = low;

	for (int j = low; j<hi; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(arr, i, j);
			i++;
		}
	}
	print_array(arr, low, hi);
	swap(arr, i, hi);
	return i;
}

void quick_sort(int arr[], int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot-1);
		quick_sort(arr, pivot+1, high);
	}
	return;
}

int main()
{
	int const max_length = 200;
	int arrayin[200]= {'\0'};
	int sizeall = 0;

    ifstream inFileStream;
    inFileStream.open("input.txt");
    for (int i=0;i < max_length; i++)
    {
        if (inFileStream.eof())
        {
            cout << "peace";
            break;
        }
        inFileStream >> arrayin[i];
        cout << arrayin[i] << "\n";
        sizeall++;
    }
    quick_sort(arrayin, 0,sizeall);
    print_array(arrayin, 0,sizeall);
    return 0;
}
