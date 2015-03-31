//Memory-Management-Simulator---Best-Fit-Algorithm
//Simulator for the memory management portion of an operating system with fixed partition scheme using best-fit algorithm


/*
Memory: 32 KB
Scheme: Fixed
Algorithm: Best-Fit 
No. of Partitions: 
                    Partition 1: 4 KB
                    Partition 1: 4 KB
                    Partition 1: 8 KB
                    Partition 1: 16 KB
/*

#include <stdio.h>

int main(void){
	int SIZE = 100;
	int total_time_m3p2b = 0;
	int m3p2b_exe = 0;
	int m3p2b_not_exe = 0;
	
	int jobs[SIZE][2];
	int i, j;
	for(i = 0; i < SIZE; i++){
		jobs[i][0] = rand()%15+2;
		jobs[i][1] = rand()%20+1;
	}
	
	
	int m3p2b[2][2];
	m3p2b[0][0] = 0;
	m3p2b[0][1] = 4;
	m3p2b[1][0] = 0;
	m3p2b[1][1] = 4;
	m3p2b[2][0] = 0;
	m3p2b[2][1] = 8;
	m3p2b[3][0] = 0;
	m3p2b[3][1] = 16;
	int k;
	int stm3p2b[3];
	stm3p2b[0] = 0;
	stm3p2b[1] = 0;
	stm3p2b[2] = 0;
	
	for(i = 0; i < SIZE; i++){
		if(jobs[i][1] > 16){
			m3p2b_not_exe++;
		}
		else{
			k = ind_small(jobs[i][1], m3p2b[0][1], m3p2b[1][1], m3p2b[2][1], m3p2b[3][1]);
			m3p2b_exe++;
			total_time_m3p2b += stm3p2b[k];
			stm3p2b[k] = jobs[i][0];
		}
	}
	
	printf("Number of jobs executed: %d\n", m3p2b_exe);
	printf("Number of jobs not executed: %d\n", m3p2b_not_exe);
	printf("Total time of execution: %d\n", total_time_m3p2b);
	return 0;
}

int ind_small(int a, int b, int c, int d, int e){
	int arr[4];
	arr[0] = a-b;
	if(arr[0] < 0)
		arr[0] = -100;
	arr[1] = a-c;
	if(arr[1] < 0)
		arr[1] = -100;
	arr[2] = a-d;
	if(arr[2] < 0)
		arr[2] = -100;
	arr[3] = a-e;
	if(arr[3] < 0)
		arr[3] = -100;
		
	int i, j, temp = 0;
	for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){
              if(arr[j] > arr[j+1]){
                   temp = arr[j];
                   arr[j] = arr[j+1];
                   arr[j+1] = temp;
               }
           }
       }
       int t = 0;
       for(i = 0; i < 4; i++){
       	if(arr[i] >= 0){
       		if(arr[i] + b == a){
       			t = 0;
       			break;
       		}
       		else if(arr[i] + c == a){
       			t = 1;
       			break;
       		}
       		else if(arr[i] + d == a){
       			t = 2;
       			break;
       		}
       		else if(arr[i] + e == a){
       			t = 3;
       			break;
       		}
       		}
       }
       
       return t;
}

