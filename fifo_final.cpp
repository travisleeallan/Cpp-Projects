/*
Project 2
simulate FIFO scheduling for a set of 64 processes with memory management addition
runs on the CSE machines with g++ and no special lib requirements

Christopher Roche
Matt Pitsenbarger
Travis Allan

Due: May 3, 2016
*/


#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define NUMPROC 65

using namespace std;

// function prototypes
void generatorOne(int, int); 							// for part one of the project
void fifoOne();											// for part one of the project
void fifoTwo();											// for part two of the project
void fifoThree(int);									// for part three of the project 	(int is for percent mem avail)
void fifoThreeNew(int);
void avgWait();
void output();
int my_malloc(int, int);										// used for part 2 and part 3
int my_free(int, int);										// used for part 2 and part 3

// variables
int availableMemory;
int total_time;
int *memoryPoolTwo;										// used for part 2 	
int *memoryPoolThree;									// used for part 3
int *memoryPoolFour;									// used for part 3
int startMem[NUMPROC + 1]; 								// the location each process starts in mem
double sleepAmount;                                     // variable for determining how long the system should sleep
// process data structure
struct process {
  int pid;
  int cycles; 											// number of cycles process takes to complete
  int mem;												// memory requirement for this process
  int arrival_time; 									// time (in cycles) the process arrives
  int start_time; 										// time the process begins
  int wait_time; 										// start_time - arrival_time
  int finish_time; 										// time the process ended execution
  void *memorySpace;									// used for malloc in part 1
    int status;                                            // used to determine whether a process can run or not
} p[NUMPROC + 1];




int main()
{
	int 	input = -1;
	struct 	timeval tvalBefore, tvalAfter;				// used to calculate execution time
    struct  timespec sleepTime;                         // used to put the system asleep for the required sleep time

	while (input != 0){ 								// ask the user which part of the project they want to run
		cout << "Project 2.  Which part would you like to run? [1] [2] or [3]  Or enter [0] to quit  ";
		cin >> input;
		
	if (input == 1)
	{
		cout << endl << "Part 1:" << endl;
		gettimeofday (&tvalBefore, NULL);				// time it starts executing
		generatorOne(input,100); 						// generate the processes stored in array p
		fifoOne();										// uses malloc and free
		output();										// output info
		avgWait();
        //cout << "Sleep " << sleepAmount << endl;
        sleepTime.tv_sec = 0;
        sleepTime.tv_nsec = sleepAmount;
        nanosleep(&sleepTime, NULL);                    // puts the system asleep for the amount of cycles it would take the processes to complete
		gettimeofday (&tvalAfter, NULL);				// time it is done executing
		printf("Execution time: %ld microseconds\n", ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L + tvalAfter.tv_usec) - tvalBefore.tv_usec);
		cout << "********************************************" << endl << endl;
	}
	
	else if (input == 2)
	{
		cout << endl << "Part 2:" << endl;
		gettimeofday (&tvalBefore, NULL);				// time it starts executing
		generatorOne(input,100);	// generates the processes the same as part one
		fifoTwo();					// uses my_malloc and my_free
		output();					// output
		avgWait();
        //cout << "Sleep " << sleepAmount << endl;
        sleepTime.tv_sec = 0;
        sleepTime.tv_nsec = sleepAmount;
        nanosleep(&sleepTime, NULL);                    // puts the system asleep for the amount of cycles it would take the processes to complete
        gettimeofday (&tvalAfter, NULL);				// time it is done executing
        free(memoryPoolTwo);					// cleanup
		printf("Execution time: %ld microseconds\n", ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L + tvalAfter.tv_usec) - tvalBefore.tv_usec);
		cout << "********************************************" << endl << endl;
	}
	
	else if (input == 3)
	{
        int input2;
		cout << endl << "Part 3: ";
        while (input2 != 1 || input2 != 2 || input2 != 3 || input2 != 4) {
            cout << "select an option\n1. 50% available memory using my_malloc & my_free\n2. 10% available memory using my_malloc & my_free\n3. 50% available memory using malloc & free\n4. 10% available memory using malloc & free\nInput: ";
            cin >> input2;
            if (input2 == 1) {
                
                // 50% total memory available
                
                /**** my_malloc & my_free ****/
                gettimeofday (&tvalBefore, NULL);				// time it starts executing
                generatorOne(input, 50);	// generates the processes the same as part one
                fifoThree(50);
                output();
                avgWait();
                cout << "Sleep " << sleepAmount << endl;
                sleepTime.tv_sec = 0;
                sleepTime.tv_nsec = sleepAmount;
                nanosleep(&sleepTime, NULL);                    // puts the system asleep for the amount of cycles it would take the processes to complete
                gettimeofday (&tvalAfter, NULL);				// time it is done executing
                free(memoryPoolThree);					// cleanup
                printf("Execution time: %ld microseconds\n", ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L + tvalAfter.tv_usec) - tvalBefore.tv_usec);
                cout << "********************************************" << endl << endl;

                break;
            }
            else if (input2 == 2) {
                // 10% total memory available
                
                /**** my_malloc & my_free ****/
                gettimeofday (&tvalBefore, NULL);				// time it starts executing
                generatorOne(input, 10);
                fifoThree(10);
                output();
                avgWait();
                cout << "Sleep " << sleepAmount << endl;
                sleepTime.tv_sec = 0;
                sleepTime.tv_nsec = sleepAmount;
                nanosleep(&sleepTime, NULL);                    // puts the system asleep for the amount of cycles it would take the processes to complete
                gettimeofday (&tvalAfter, NULL);				// time it is done executing
                free(memoryPoolThree);					// cleanup
                printf("Execution time: %ld microseconds\n", ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L + tvalAfter.tv_usec) - tvalBefore.tv_usec);
                cout << "********************************************" << endl << endl;
                
                break;
            }
            else if (input2 == 3) {
                /**** malloc & free ****/
                gettimeofday (&tvalBefore, NULL);				// time it starts executing
                generatorOne(4, 50);	// generates the processes the same as part one
                fifoThreeNew(50);
                output();
                avgWait();
                cout << "Sleep " << sleepAmount << endl;
                sleepTime.tv_sec = 0;
                sleepTime.tv_nsec = sleepAmount;
                nanosleep(&sleepTime, NULL);                    // puts the system asleep for the amount of cycles it would take the processes to complete
                gettimeofday (&tvalAfter, NULL);				// time it is done executing
                //free(memoryPoolThree);					// cleanup
                printf("Execution time: %ld microseconds\n", ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L + tvalAfter.tv_usec) - tvalBefore.tv_usec);
                cout << "********************************************" << endl << endl;
                
                break;
            }
            else if (input2 == 4) {
                /**** malloc & free ****/
                gettimeofday (&tvalBefore, NULL);				// time it starts executing
                generatorOne(4, 10);	// generates the processes the same as part one
                fifoThreeNew(10);
                output();
                avgWait();
                cout << "Sleep " << sleepAmount << endl;
                sleepTime.tv_sec = 0;
                sleepTime.tv_nsec = sleepAmount;
                nanosleep(&sleepTime, NULL);                    // puts the system asleep for the amount of cycles it would take the processes to complete
                gettimeofday (&tvalAfter, NULL);				// time it is done executing
                //free(memoryPoolThree);					// cleanup
                printf("Execution time: %ld microseconds\n", ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L + tvalAfter.tv_usec) - tvalBefore.tv_usec);
                cout << "********************************************" << endl << endl;
                
                break;
                
            }
            else cout << "Invalid input" << endl;
        }
	}
	
	else if (input == 0)
		cout << "goodbye" << endl;
	else
		cout << "Invalid entry" << endl;
	}
} 	// end main




void fifoOne() 	//****************************************************************************************pt1
{
	/*
Assuming that the combined memory requirement of all 64 processes is less than 20 MB, use the system
calls malloc() and free() to dynamically allocate and de-allocate memory to your processes. Measure the
total system time that is required to simulate the execution of your 64 processes.
	*/
	
    
	for(int i = 1; i < NUMPROC; i++)
	{
       int cycle = 10; 	// cycle counter starts at 10 for first context switch penalty
	   if(p[i].arrival_time > cycle) 			// wait for next process to arrive
	   {
		cycle = p[i].arrival_time + 10;
	   }

	   p[i].start_time = cycle;
	   p[i].wait_time = p[i].start_time - p[i].arrival_time;
	   cycle = cycle + p[i].cycles;
	   p[i].finish_time = cycle;
	   
	   free(p[i].memorySpace);					// this process is finished so free the dynamic memory   
	   cycle += 10; 							// plus 10 for context switch penalty
       total_time = cycle;
	}
    sleepAmount = .35714298469392 * total_time; //average clock speed of the UNT cse machines in nanoseconds multiplied times the total cycles
    //cout << "Sleep " << sleepAmount << endl;
    //sleep(sleepAmount);
}



void fifoTwo() 	//*****************************************************************************************pt2
{
	/*
Develop your own memory management system with corresponding function calls my_malloc() and
my_free() to manage a pre-defined block of memory of size 20MB. The function my_malloc() will try to
find the required chunk of memory within the pre-defined 20MB block and allocate it to an arriving
process. Upon completion, the memory partition is returned to the memory pool via the function
my_free(), to be used by other processes. Compare the performance of your memory manager to the
performance of malloc() and free(). Note that you memory manager does only call the system’s
malloc() once to request the initial 20MB block, hence you are reducing the number of context switches.
	*/
	int cycle = 10; 					// cycle counter starts at 10 for first context switch penalty
	for(int i = 1; i < NUMPROC; i++)
	{
       int cycle = 10; 					// cycle counter starts at 10 for first context switch penalty
	   if(p[i].arrival_time > cycle) 				// wait for next process to arrive
	   {
		cycle = p[i].arrival_time + 10;
	   }

	   p[i].start_time = cycle;
	   p[i].wait_time = p[i].start_time - p[i].arrival_time;
	   cycle = cycle + p[i].cycles;
	   p[i].finish_time = cycle;
	   my_free(i, 2); 									//free the mem when the process completes
	   cycle += 10; 								// plus 10 for context switch penalty
       total_time = cycle;

	}
    sleepAmount = .35714298469392 * total_time; //average clock speed of the UNT cse machines in nanoseconds multiplied times the total cycles
    //cout << "Sleep " << sleepAmount << endl;
    ///sleep(sleepAmount);
}



void fifoThree(int percentAvail) 	//**************************************************************************pt3
{
	/*
Assume that the available memory is less than the sum of requirements of all 64 processes. Modify your
system such that a process can only execute if the required memory can be allocated, otherwise, the
process will have to wait in a special queue for memory to become available. For a given set of 64
processes, analyze the overall completion of your simulation under the assumption that:
• The system only has 50% of the memory required by the set of 64 processes.
• The system only has 10% of the memory required by the set of 64 processes.
• Of course, the required memory per process is always guaranteed to be less than system memory.
	*/
	int cycle = 10; 				// cycle counter starts at 10 for first context switch penalty
    int completed = 0;              // number of completed processes
    int run = 0;                    // counter that keeps track of the amount of times the for loop has ran
    int waitque[NUMPROC];           // wait queue for processes that can't access the memory
    int waitcount = 1;              // number of spots taken in the wait queue.
    int i;
    total_time = 0;
    cout << percentAvail << "% available memory" << endl << endl;
    
    //set the initial memory status
    for (i=1; i<NUMPROC; i++) {
        waitque[i] = 0;             //I put this in the loop just to make sure all of the initial values = 0
        if (availableMemory >= p[i].mem) { //my_malloc(i, 3) > 0) { //
            p[i].status = 1;
            availableMemory = availableMemory - p[i].mem;
            //cout << "mem" << availableMemory << endl;
        }
        else p[i].status = 0;
    }
    
    while (completed < NUMPROC-1) {
        
        int candidate;                  // placeholder for process with the earliest time
        int checker;                    // placeholder for candidate from wait que
        run++;
        /*for (i=1; i<NUMPROC; i++) {
            if (p[i].status == 2) {
                my_free(i, 3);
                p[i].status = 3;
            }
        }*/
        for (i=1; i<NUMPROC; i++) {
            if (run==1 && p[i].status==1) {
                if(p[i].arrival_time > cycle) 					// wait for next process to arrive
                {
                    cycle = p[i].arrival_time;
                }
                p[i].start_time = cycle;
                p[i].wait_time = p[i].start_time - p[i].arrival_time;
                cycle = cycle + p[i].cycles;
                p[i].finish_time = cycle;
                p[i].status = 2;                                //signifying completion
                completed++;
                my_free(i, 3);
                //cout << availableMemory << endl;
                //availableMemory = availableMemory + p[i].mem;
                cycle += 10; 									// plus 10 for context switch penalty
            }
            else if (run==1 && p[i].status==0) {
                waitque[waitcount] = i;
                waitcount++;
            }
            else if (run > 1) {
                int earliestTime = 999999;      // used to determine when the next process executes
                for (int j=1; j<NUMPROC; j++) {                //determines when the next process will start
                    if (p[j].finish_time <= earliestTime && p[j].status == 2) {
                        earliestTime = p[j].finish_time;
                        candidate = j;
                    }
                }
                if (earliestTime == 999999) {
                    earliestTime = 0;
                    candidate = 1;
                }
                else p[candidate].status = 3;
                for (int j=1; j<=waitcount; j++) {
                    checker = waitque[j];
                    if (p[checker].status == 0 && p[checker].mem <= availableMemory) { //my_malloc(checker, 3) > 0) { //
                        //cout << "test" << endl;
                        cycle = earliestTime + 10;
                        p[checker].start_time = cycle;
                        p[checker].wait_time = p[checker].start_time - p[checker].arrival_time;
                        cycle += p[checker].cycles;
                        p[checker].finish_time = cycle;
                        p[checker].status = 2;                                //signifying completion
                        my_free(i, 3);
                        //availableMemory = availableMemory + p[checker].mem;
                        total_time = cycle + 10;
                        //cout << availableMemory << endl;
                        completed++;
                    }
                }
            }
            else {
                cout << "Error" << endl;
            }
        }
    }
    for (i=1; i<NUMPROC; i++) {
        if (p[i].finish_time > total_time) total_time = p[i].finish_time; //ensures that the last completed process gives the total execution time
    }
    sleepAmount = .35714298469392 * total_time; //average clock speed of the UNT cse machines in nanoseconds multiplied times the total cycles
    
}

void fifoThreeNew(int percentAvail) 	//**************************************************************************pt3
{
    /*
     Assume that the available memory is less than the sum of requirements of all 64 processes. Modify your
     system such that a process can only execute if the required memory can be allocated, otherwise, the
     process will have to wait in a special queue for memory to become available. For a given set of 64
     processes, analyze the overall completion of your simulation under the assumption that:
     • The system only has 50% of the memory required by the set of 64 processes.
     • The system only has 10% of the memory required by the set of 64 processes.
     • Of course, the required memory per process is always guaranteed to be less than system memory.
     */
    int cycle = 10; 				// cycle counter starts at 10 for first context switch penalty
    int completed = 0;              // number of completed processes
    int run = 0;                    // counter that keeps track of the amount of times the for loop has ran
    int waitque[NUMPROC + 1];           // wait queue for processes that can't access the memory
    int waitcount = 1;              // number of spots taken in the wait queue.
    int i;
    total_time = 0;
    availableMemory = 0;
    cout << percentAvail << "% available memory" << endl << endl;
    
    //set the initial memory status
    for (i=1; i<NUMPROC; i++) {
        waitque[i] = 0;             //I put this in the loop just to make sure all of the initial values = 0
        p[i].status = 0;
    }
    
    while (completed < NUMPROC-1) {
        
        int candidate;                  // placeholder for process with the earliest time
        int checker;                    // placeholder for candidate from wait que
        run++;
        
        for (i=0; i<NUMPROC; i++) {
            if (run == 1 && percentAvail == 50) {
                availableMemory += p[i].mem / 2;
                if (p[i].mem >= availableMemory) {
                    p[i].memorySpace = (void *)malloc(availableMemory+1);
                    availableMemory -= p[i].mem;
                    p[i].status = 1;
                    cycle = p[i].arrival_time + 10;
                    p[i].start_time = cycle;
                    p[i].wait_time = p[i].start_time - p[i].arrival_time;
                    cycle = cycle + p[i].cycles;
                    p[i].finish_time = cycle;
                    p[i].status = 2;                                //signifying completion
                    completed++;
                    free(p[i].memorySpace);
                    cycle += 10; 									// plus 10 for context switch penalty

                }
                else {
                    waitque[waitcount] = i;
                    waitcount++;
                }
            }
            else if (run == 1 && percentAvail == 10) {
                availableMemory += p[i].mem / 10;
                if (p[i].mem >= availableMemory) {
                    p[i].memorySpace = (void *)malloc(availableMemory+1);
                    availableMemory -= p[i].mem;
                    p[i].status = 1;
                    cycle = p[i].arrival_time + 10;
                    p[i].start_time = cycle;
                    p[i].wait_time = p[i].start_time - p[i].arrival_time;
                    cycle = cycle + p[i].cycles;
                    p[i].finish_time = cycle;
                    p[i].status = 2;                                //signifying completion
                    completed++;
                    free(p[i].memorySpace);
                    cycle += 10; 									// plus 10 for context switch penalty
                    
                }
                else {
                    waitque[waitcount] = i;
                    waitcount++;
                }
            }
            else if (run > 1 && percentAvail == 50) {
                int earliestTime = 999999;      // used to determine when the next process executes
                for (int j=1; j<NUMPROC; j++) {                //determines when the next process will start
                    if (p[j].finish_time <= earliestTime && p[j].status == 2) {
                        earliestTime = p[j].finish_time;
                        candidate = j;
                    }
                }
                
                if (earliestTime == 999999) {
                    earliestTime = 0;
                    candidate = 1;
                }
                else {
                    p[candidate].status = 3;                        //ensures time(p[candidate]) is not used again
                    availableMemory += p[i].mem / 2;
                }
                for (int j=1; j<=waitcount; j++) {
                    checker = waitque[j];
                    if (p[checker].status == 0 && p[checker].mem <= availableMemory) { //my_malloc(checker, 3) > 0) { //
                        //cout << "test" << endl;
                        p[checker].memorySpace = (void *)malloc(availableMemory+1);
                        availableMemory -= p[i].mem;
                        cycle = earliestTime + 10;
                        p[checker].start_time = cycle;
                        p[checker].wait_time = p[checker].start_time - p[checker].arrival_time;
                        cycle += p[checker].cycles;
                        p[checker].finish_time = cycle;
                        p[checker].status = 2;                                //signifying completion
                        free(p[checker].memorySpace);
                        total_time = cycle + 10;
                        cout << availableMemory << endl;
                        completed++;
                    }
                }
            }
            else if (run > 1 && percentAvail == 10) {
                int earliestTime = 999999;      // used to determine when the next process executes
                for (int j=1; j<NUMPROC; j++) {                //determines when the next process will start
                    if (p[j].finish_time <= earliestTime && p[j].status == 2) {
                        earliestTime = p[j].finish_time;
                        candidate = j;
                    }
                }
                if (earliestTime == 999999) {
                    earliestTime = 0;
                    candidate = 1;
                }
                else {
                    p[candidate].status = 3;                        //ensures time(p[candidate]) is not used again
                    availableMemory += p[i].mem / 2;
                }
                for (int j=1; j<=waitcount; j++) {
                    checker = waitque[j];
                    if (p[checker].status == 0 && p[checker].mem <= availableMemory) { //my_malloc(checker, 3) > 0) { //
                        //cout << "test" << endl;
                        p[i].memorySpace = (void *)malloc(availableMemory+1);
                        availableMemory -= p[i].mem;
                        cycle = earliestTime + 10;
                        p[checker].start_time = cycle;
                        p[checker].wait_time = p[checker].start_time - p[checker].arrival_time;
                        cycle += p[checker].cycles;
                        p[checker].finish_time = cycle;
                        p[checker].status = 2;                                //signifying completion
                        free(p[i].memorySpace);
                        total_time = cycle + 10;
                        cout << availableMemory << endl;
                        completed++;
                    }
                }
            }
        }
    }
    for (i=1; i<NUMPROC; i++) {
        if (p[i].finish_time > total_time) total_time = p[i].finish_time; //ensures that the last completed process gives the total execution time
    }
    sleepAmount = .35714298469392 * total_time; //average clock speed of the UNT cse machines in nanoseconds multiplied times the total cycles
    
}


void generatorOne(int input, int percent) 	// ***************************************************************************Pt1
{
	int k = NUMPROC; 										// number of processes (64)
	int id = 1;
	int cycTotal = 0;
	int cycAvg = 0;
	int memTotal = 0;
	int memAvg = 0;
	int arrive_counter = 0;
    int memcount = 0;

	srand(time(NULL));
	// generates the processes
	for(int i = 1; i <= k; i++)
	{		
	   p[i].pid = id;										// basic processor info unchanged from proj1
	   id++;
	   p[i].arrival_time = arrive_counter; 					// set arrival time
	   arrive_counter += 50;
	   cycAvg = cycTotal / i; 								// compute average cycles of processes
	   
	   if(cycAvg <= 6000)									// set the number of cycles for each process
	   {
	      p[i].cycles = (rand() % 6001) + 5000;
	      cycTotal += p[i].cycles;
	   }
	   else
	   {
	      p[i].cycles = (rand() % 4001) + 1000;
	      cycTotal += p[i].cycles;
	   }
	
		// the project 2 instructions say the total mem needed must be under 20 MB
		// setting all processes to ( 290 KB <= p.mem <= 310 KB ) gives an average of 300 KB per
		// process for a total of between 18560 and 19840 KB, avg of 19200 KB total.
		
		p[i].mem = ((rand() % (310 + 1 - 290)) + 290) * 1024;
		memTotal += p[i].mem;
		memAvg = memTotal/NUMPROC;
        
        
        // allocate initial memory pools with malloc.  only called once for parts two and three
        if(input == 2){										// if this is part two, you need one memory pool of 20 MB to start
            availableMemory = (20*1024*1024);
            memoryPoolTwo = (int *)malloc(20*1024*1024+1);
        }
        
        else if (input == 3 && percent == 50) {			// if this is part three you either want 50% or 10%
            memcount = 0;
            for (int i=1; i<NUMPROC; i++) {
                memcount = memcount + p[i].mem;
            }
            availableMemory = memcount / 2; //;
            //cout << availableMemory << endl;
            memoryPoolThree = (int *)malloc(availableMemory+1);
        }
        
        else if (input == 3 && percent == 10) {			// 10%
            memcount = 0;
            for (int i=1; i<NUMPROC; i++) {
                memcount = memcount + p[i].mem;
            }
            availableMemory = memcount / 10; //((20*1024*1024)/10);
            //cout << availableMemory << endl;
            memoryPoolThree = (int *)malloc(availableMemory+1);
        }
        /*
        else if (input == 4 && percent == 50) {			// if this is part three you either want 50% or 10%
            memcount = 0;
            for (int i=1; i<NUMPROC; i++) {
                memcount = memcount + p[i].mem;
            }
            availableMemory = memcount / 2; //;
            //cout << availableMemory << endl;
            memoryPoolThree = (int *)malloc(availableMemory+1);
        }
        
        else if (input == 4 && percent == 10) {			// 10%
            memcount = 0;
            for (int i=1; i<NUMPROC; i++) {
                memcount = memcount + p[i].mem;
            }
            availableMemory = memcount / 10; //((20*1024*1024)/10);
            //cout << availableMemory << endl;
            memoryPoolThree = (int *)malloc(availableMemory+1);
        }
        */
        else;
        

		// if this is part one, you malloc the amount of memory needed for each process as it is created
		if(input == 1)
			p[i].memorySpace = (void *)malloc(p[i].mem * 1024);
		
		// if this is part two, you call my_malloc to allocate from the base pool of 20 MB
		// you pass the process number to my_malloc, so it can get the mem requirements from the struct
		else if(input == 2)
			my_malloc(i, input);
        
        //
        else if(input == 3) {
            my_malloc(i, input);
        }
	}

	
	// print the process info after all processes are created
	cout << "********************";
	cout << endl << "Process information:" << endl;
	cout << "Cycles      Memory" << endl; 
	
	for(int g = 1; g <= k; g++)
	{
	   cout << p[g].cycles << "        " << p[g].mem << endl;
	}
	
	cout << "********************" << endl;
	cout << "cycAvg = " << cycAvg << " cycles" << endl << "memAvg = " << memAvg 
						<< " B" << endl << "memTotal = " << memTotal << " B" << endl;
	cout <<                 "********************" << endl << endl;

}



int my_malloc(int num, int funcNum){
        // memoryPoolTwo or memoryPoolThree is the initial malloc needed for par$
        if(availableMemory - p[num].mem < 0)
        {
			// this can't occur for part two
            //cout << "OUT OF MEMORY" << endl;
            p[num].status = 0;
        }
        else
        {
           availableMemory -= p[num].mem;
            //cout << "mem" << availableMemory << endl;
            p[num].status = 1;
           if(num == 1)
           {
                startMem[num] = 0;
                for(int q = 0; q < p[num].mem; q++)
                {
                   if (funcNum == 2) memoryPoolTwo[q] = 1;
                   else if (funcNum == 3) memoryPoolThree[q] = 1;
                }
           }
           else
           {	//startMem[NUMPROC + 1]
                startMem[num] = startMem[num-1] + p[num - 1].mem;
                for(int i = startMem[num]; i < p[num].mem; i++)
                {
                   if (funcNum == 2) memoryPoolTwo[i] = 1;
                   else if (funcNum == 3) memoryPoolThree[i] = 1;
                }
           }
        }
        return availableMemory;
}



int my_free(int num, int funcNum){
	// called when a process finishes.
	availableMemory += p[num].mem;
	
    for(int i = startMem[num]; i < p[num].mem; i++)
        {
           if (funcNum == 2) memoryPoolTwo[i] = 0;
           else if (funcNum == 3) memoryPoolThree[i] = 0;
        }

	return availableMemory;						// returns the availableMemory + the memory free'd in this function call
}



void avgWait()
{
	int wait_time = 0; 							// wait time of the process
	int avgWait; 								// the average wait time of all processes
	
	for(int i = 1; i < NUMPROC; i++)
	{
		wait_time += p[i].wait_time; 			// calculate the wait time for the process
	}
	
	avgWait = wait_time / (NUMPROC-1); 				// calculate the average wait time for 50 processes
	cout << "average wait time is  " << avgWait << " cycles" << endl;	
}



void output()									// just prints out the info
{
	for(int i = 1; i < NUMPROC; i++)
	{
	   cout << "process " << i << endl;
	   cout << "arrival time: " << p[i].arrival_time << endl;
	   cout << "start time: " << p[i].start_time << endl;
	   cout << "finish time: " << p[i].finish_time << endl;
	   cout << "wait time: " << p[i].wait_time << endl << endl;
	}
	
	cout << "********************************************" << endl;
	cout << "total processor time: " << total_time << " cycles" << endl;
}

// **********************************************************************************************end
