#include "../../header.h"

int* selection_sort_lowToup(int *arr, int n)
{
	int *ans = (int*)calloc(n, sizeof(int));
	ptr_err(ans);
	memcpy(ans, arr, n * sizeof(int));
	for(int i = 0; i < n; i++)
	{
		int max_index = i;
		for(int j = i + 1; j < n - 1; j++)
		{
			if(ans[max_index] > ans[j])
			{
				max_index = j;
			}
		}
		int tmp = ans[i];
		ans[i] = ans[max_index];
		ans[max_index] = tmp;
	}
	return ans;
}

int *bubble_sort_lowToup(int *arr, int n)
{
	int *ans = (int*)calloc(n, sizeof(int));
	ptr_err(ans);
	memcpy(ans, arr, n * sizeof(int));
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > ans[j+1])
			{
//				printf("\n\tChange %d[%d] to %d[%d]", arr[j], j, arr[j+1], j+1);
				int tmp = ans[j];
				ans[j] = ans[j+1];
				ans[j+1] = tmp;
			}
		}
	}
	return ans;
}

int* insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++) 
	{
        int key = arr[i];
        int j = i - 1;
 
        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}

double* selection_sort_lowToup_modData(double *arr, int n)
{
	double *ans = (double*)calloc(n, sizeof(double));
	ptr_err(ans);
	memcpy(ans, arr, n * sizeof(double));
	for(int i = 0; i < n; i++)
	{
		int max_index = i;
		for(int j = i + 1; j < n - 1; j++)
		{
			if(ans[max_index] < ans[j])
			{
				max_index = j;
			}
		}
		struct MyStudents temp_data;
		memcpy(&temp_data, &data[i], sizeof(struct MyStudents));
		memcpy(&data[i], &data[max_index], sizeof(struct MyStudents));
		memcpy(&data[max_index], &temp_data, sizeof(struct MyStudents));
		
		double tmp = ans[i];
		ans[i] = ans[max_index];
		ans[max_index] = tmp;
	}
	return ans;
}

int* insertion_sort_lowToup_modData(int *arr, int n)
{
	int *ans = (int*)malloc(n * sizeof(int));
	ptr_err(ans);
	memcpy(ans, arr, n * sizeof(int));
	
    for (int i = 1; i < n; i++) 
	{
		struct MyStudents templarary;
		memcpy(&templarary, &data[i], sizeof(struct MyStudents));
        int tmp = ans[i]; // tmp = 1
        int j = i - 1; // j = 0
 
        while (j >= 0 && ans[j] > tmp) 
		{
            ans[j + 1] = ans[j];
            memcpy(&data[j + 1], &data[j], sizeof(struct MyStudents));
            j--;
        }
        ans[j + 1] = tmp;
        memcpy(&data[j + 1], &templarary, sizeof(struct MyStudents));
    }
    return ans;
}

void insertion_sort_lowToup_modData_sname(int n)
{
    for (int i = 1; i < n; i++) 
	{
		struct MyStudents templarary;
		memcpy(&templarary, &data[i], sizeof(struct MyStudents));
        int j = i - 1; // j = 0
 
        while (j >= 0 && strcmp(data[j].s_name, templarary.s_name) > 0 && data[j].group == data[i].group) 
		{
            memcpy(&data[j + 1], &data[j], sizeof(struct MyStudents));
            j--;
        }
        memcpy(&data[j + 1], &templarary, sizeof(struct MyStudents));
    }
}

int* count_sort(int *arr, int n)
{
	int max = find_max_arr(arr, n);
	max++;
	int *counting_arr = (int*)calloc(max, sizeof(int));
	ptr_err_adv(counting_arr, "count_sort");
	
	for(int i = 0; i < n; i++)
	{
		counting_arr[arr[i]]++;
	}
	print_array(counting_arr, max - 1, "Taken counting arr:");
	
	int *ans = (int*)calloc(0, sizeof(int));
	ptr_err_adv(ans, "count_sort_ans");
	
	int new_counter = 0;
	for(int i = 0; i < max; i++)
	{
		while(counting_arr[i] != 0)
		{
			new_counter++;
			counting_arr[i]--;
			ans = (int*)realloc(ans, new_counter * sizeof(int));
			ptr_err_adv(ans, "count_sort_ans");
			ans[new_counter - 1] = i;
		}
	}
	print_array(ans, new_counter, "Srt arr:");
	free(counting_arr);
	return ans;
}

int *shell_sort(int *arr, int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int tmp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
            {
            	arr[j] = arr[j - gap];
			}
            arr[j] = tmp;
        }
    }
    return arr;
}

int partition(int *arr, int left, int right)
{
//  int pivot = find_mediana(arr, right - left);
	int pivot = arr[right];
//	printf("\npivot[%d]", pivot);
  	int i = left - 1;

  	for (int j = left; j < right; j++) 
	  {
	    if (arr[j] <= pivot)
		{
	      i++;
	      swap(&arr[i], &arr[j]);
	    }
  }
  swap(&arr[i + 1], &arr[right]);

  return i + 1;
}

void quick_sort(int *arr, int left, int right) 
{
  if (left < right) 
  {
	int pi = partition(arr, left, right);
	quick_sort(arr, left, pi - 1);
	quick_sort(arr, pi + 1, right);
  }
}