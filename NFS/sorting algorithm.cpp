#include<iostream>
using namespace std;

int main()
{
	int arr[] = {6,2,1,3,5,4};
	int min_num;
	
	for (int i = 0; i < 6; i++)
	{
		for (int j = i; j < 6; j++)
		{
			if(arr[j] < arr[i])
			{	
				min_num = arr[j];
				arr[j] = arr[i];
				arr[i] = min_num;
			}
		}
	cout << arr[i] << " ";
	}
}