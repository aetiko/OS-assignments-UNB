#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct memProcesses{
    int id;
    int base;
    int limit;
    int address;
}memProcesses;

// first fit algorithm
void firstFit(int size);
// best fit algorithm
void bestFit(int size);
// worst fit algorithm
void worstFit(int size);
//stop the program 
int terminateProcess(int idIn);
//initialise the values in struct
memProcesses * intalizeMemory(int idIn, int baseIn, int limitIn);

int location = 0;
int totalMemoryUsed = 0;
int totalProcesses = 0;
int totalSum = 0;
int totalFreed = 0;
int totalMemoryAvailable = 0;
int totalTermnated = 0;
int fragment = 0;
memProcesses * tempProcess;

int main (int argc, char* argv[]){
   location=0;
   int size = atoi(argv[2]);
   if(strcmp(argv[1], "-f") == 0){
       printf("--------Welcome First fit memory allocation---------\n");
       firstFit(size);
   }else if(strcmp(argv[1], "-b") == 0){
       printf("--------Welcome Best fit memory allocation---------\n");
       bestFit(size);
   }else if(strcmp(argv[1], "-w") == 0){
       printf("--------Welcome Worst fit memory allocation---------\n");
       worstFit(size);
   }else{
       printf("wrong tag input, can only us -f, -b and -w");
   }
        return 0;
}

memProcesses * intalizeMemory(int idIn, int baseIn, int limitIn){
    memProcesses * temporaryMem;
    if((temporaryMem = malloc(sizeof(memProcesses))) == NULL){
        exit(-1);
    }
    temporaryMem->id = idIn;
    temporaryMem->base = baseIn;
    temporaryMem->limit = limitIn;
    temporaryMem->address = location;

    return temporaryMem;
}

void firstFit(int size) {
    //using this to mark where the base starts
    int line  = 0;
    //there has been no assignment
    memProcesses * garbage = intalizeMemory(-1, 0, 0);
    if((tempProcess = malloc(100*sizeof(memProcesses))) == NULL){
        exit(-1);
    }
    int x;
    for(x = 0; x<100; x++){
        tempProcess[x] = *garbage;
    }
    while(1){
        char operationType = 'a';
        int inputNumber = 0;
        int inputMemory = 0;

        scanf("%c%d",&operationType, &inputNumber);
        char operations[2];
        operations[0] = operationType;
        operations[1] = '\0';

        if(strcmp(operations, "S") == 0){
            //stop and print the memory allocation information
            break;
        } if (strcmp(operations, "T") == 0){
            //we want to terminate a certain process
            terminateProcess(inputNumber);
        } if(strcmp(operations, "N") == 0){
            scanf(" %d", &inputMemory);
            if(totalMemoryUsed+inputMemory > size){
                printf("Proces %d failed to allocate %d\n", inputNumber, inputMemory);
            }else{
                    memProcesses * currentProcess = intalizeMemory(inputNumber, line, line+inputMemory);
                    line =  line + inputMemory;
                    int i;
                    for(i=0; i<100; i++){
                        if(tempProcess[i].id == -1){
                            tempProcess[i] = *currentProcess;
                            totalSum+=inputMemory;
                            totalMemoryUsed+=inputMemory;
                            location+=1;
                            totalProcesses+=1;
                            break;
                        }
                    }
                    totalMemoryAvailable = size - totalSum;
                }
            }
        }
    printf("Total Processes created -> %d,\nTotal allocated Memomry allocated -> %d,\nFinal memory available -> %d,\nTotal Memory freed -> %d,\nTotal processes terminated -> %d,\nTotal fragmented space -> %d\n", totalProcesses, totalSum, totalMemoryAvailable, totalFreed, totalTermnated, fragment); 
    }

    void bestFit(int size){

        //using this to mark where the base starts
        int line  = 0;
        //there has been no assignment
        memProcesses * garbage = intalizeMemory(-1, 0, 0);
        if((tempProcess = malloc(100*sizeof(memProcesses))) == NULL){
            exit(-1);
        }
        int x;
        for(x = 0; x<100; x++){
            tempProcess[x] = *garbage;
        }
        while (1){

            char operationType = 'a';
            int inputNumber = 0;
            int inputMemory = 0;

            scanf("%c%d",&operationType, &inputNumber);
            char operations[2];
            operations[0] = operationType;
            operations[1] = '\0';

            if(strcmp(operations, "S") == 0){
                //stop and print the memory allocation information
                break;
            } if (strcmp(operations, "T") == 0){
                //we want to terminate a certain process
                terminateProcess(inputNumber);
            } if(strcmp(operations, "N") == 0){
                scanf(" %d", &inputMemory);
                if(totalMemoryUsed+inputMemory > size){
                    printf("Proces %d failed to allocate %d\n", inputNumber, inputMemory);
                }else{
                    memProcesses * currentProcess = intalizeMemory(inputNumber, line, line + inputNumber);
                    int gap = 0;
                    int bestGap = 100;
                    int bestSlotForProcess = 0;
                    int loc = 0; //used for the location of the last process
                    int c;
                    for(c=0;c<100;c++){
                        if(tempProcess[c].id != -1){
                            loc = c;
                            gap = 0;
                        }else{
                            gap = c - loc;
                            if(gap<bestGap && gap>0){
                                bestGap = gap;
                                bestSlotForProcess = loc + 1;
                            } 
                        }
                    }
                    tempProcess[bestSlotForProcess] = *currentProcess;
                    totalProcesses +=1;
                    location +=1;
                    totalSum += inputMemory;
                    totalMemoryUsed += inputMemory;
                    totalMemoryAvailable = size - totalSum;
                }
            }
        }
        printf("Total Processes created -> %d,\nTotal allocated Memomry allocated -> %d,\nFinal memory available -> %d,\nTotal Memory freed -> %d,\nTotal processes terminated -> %d,\nTotal fragmented space -> %d\n", totalProcesses, totalSum, totalMemoryAvailable, totalFreed, totalTermnated, fragment); 
    }

void worstFit(int size){
    //using this to mark where the base starts
        int line  = 0;
        //there has been no assignment
        memProcesses * garbage = intalizeMemory(-1, 0, 0);
        if((tempProcess = malloc(100*sizeof(memProcesses))) == NULL){
            exit(-1);
        }
        int x;
        for(x = 0; x<100; x++){
            tempProcess[x] = *garbage;
        }
        while (1){

            char operationType = 'a';
            int inputNumber = 0;
            int inputMemory = 0;

            scanf("%c%d",&operationType, &inputNumber);
            char operations[2];
            operations[0] = operationType;
            operations[1] = '\0';

            if(strcmp(operations, "S") == 0){
                //stop and print the memory allocation information
                break;
            } if (strcmp(operations, "T") == 0){
                //we want to terminate a certain process
                terminateProcess(inputNumber);
            } if(strcmp(operations, "N") == 0){
                scanf(" %d", &inputMemory);
                if(inputMemory + totalMemoryUsed > size){
                    printf("Proces %d failed to allocate %d\n", inputNumber, inputMemory);
                }else{
                    memProcesses * currentProcess = intalizeMemory(inputNumber, line, line + inputMemory);
                    int bestGap = 0;
                    int gap = 0;
                    int loc = 0; //location of last instance
                    int bestSlotForProcess = 0;
                    int x = 0;

                    for(x=0; x<100;x++){
                        if(tempProcess[x].id != -1){
                            loc = x;
                            gap = 0;
                        }else{
                            gap = x - loc;
                            if(gap > bestGap){
                                bestGap = gap;
                                bestSlotForProcess = loc + 1;
                            }
                        }
                    }
                    tempProcess[bestSlotForProcess] = *currentProcess;
                    totalMemoryUsed += inputMemory;
                    totalSum += inputMemory;
                    totalProcesses +=1;
                    location +=1;
                    totalMemoryAvailable = size - totalMemoryUsed;
                }
            }
        }
        printf("Total Processes created -> %d,\nTotal allocated Memomry allocated -> %d,\nFinal memory available -> %d,\nTotal Memory freed -> %d,\nTotal processes terminated -> %d,\nTotal fragmented space -> %d\n", totalProcesses, totalSum, totalMemoryAvailable, totalFreed, totalTermnated, fragment); 
    }

    int terminateProcess(int idIn){
        int i = 0;
        for(i=0; i<100;i++){
            if(tempProcess[i].id == idIn){
                memProcesses * garbageCollector = intalizeMemory(-1, 0, 0);
                totalMemoryUsed -= (tempProcess[i].limit) - (tempProcess[i].base);
                totalFreed += (tempProcess[i].limit) - (tempProcess[i].base);
                fragment += (tempProcess[i].limit) - (tempProcess[i].base);
                totalTermnated +=1;
                tempProcess[i] = *garbageCollector;
                location--;
                return 1;
            }
        }
        printf("Process %d failed to free memory\n", idIn);
        return 2;
    }