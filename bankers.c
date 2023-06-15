#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int work[MAX_RESOURCES];
int finish[MAX_PROCESSES];

int num_processes;
int num_resources;

void initialize() {
    int i, j;
    for (i = 0; i < num_processes; i++) {
        finish[i] = 0;
        for (j = 0; j < num_resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

int safety_check() {
    int i, j, k;
    int sequence[MAX_PROCESSES];
    
    for (i = 0; i < num_resources; i++) {
        work[i] = available[i];
    }
    
    int count = 0;
    while (count < num_processes) {
        int found = 0;
        for (i = 0; i < num_processes; i++) {
            if (!finish[i]) {
                int can_execute = 1;
                for (j = 0; j < num_resources; j++) {
                    if (need[i][j] > work[j]) {
                        can_execute = 0;
                        break;
                    }
                }
                
                if (can_execute) {
                    sequence[count] = i;
                    count++;
                    finish[i] = 1;
                    for (k = 0; k < num_resources; k++) {
                        work[k] += allocation[i][k];
                    }
                    found = 1;
                }
            }
        }
        
        if (!found) {
            return 0; // Unsafe state
        }
    }
    
    printf("\nSafe sequence: ");
    for (i = 0; i < num_processes - 1; i++) {
        printf("P%d -> ", sequence[i]);
    }
    printf("P%d\n", sequence[num_processes - 1]);
    
    return 1; // Safe state
}

int request_resources(int process_id, int request[]) {
    int i;
    
    for (i = 0; i < num_resources; i++) {
        if (request[i] > need[process_id][i] || request[i] > available[i]) {
            return 0; // Requested resources exceed need or available resources
        }
    }
    
    for (i = 0; i < num_resources; i++) {
        available[i] -= request[i];
        allocation[process_id][i] += request[i];
        need[process_id][i] -= request[i];
    }
    
    if (safety_check()) {
        return 1; // Request granted
    } else {
        // Rollback changes
        for (i = 0; i < num_resources; i++) {
            available[i] += request[i];
            allocation[process_id][i] -= request[i];
            need[process_id][i] += request[i];
        }
        
        return 0; // Request denied
    }
}

int main() {
    int i, j;
    
    // Input the total number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);
    
    // Input the available resources
    printf("Enter the available resources: ");
    for (i = 0; i < num_resources; i++) {
        scanf("%d", &available[i]);
    }
    
    // Input the maximum resource requirement for each process
    printf("Enter the maximum resource requirement for each process:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < num_resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }
    
    // Input the resource allocation for each process
    printf("Enter the resource allocation for each process:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    
    // Initialize the data structures
    initialize();
    
    // Perform the safety check
    if (safety_check()) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is in an unsafe state.\n");
        return 0;
    }
	
	printf("\n");
    
    // Request additional resources
    int process_id;
    int request[MAX_RESOURCES];
    
    printf("Enter the process ID requesting resources: ");
    scanf("%d", &process_id);
    
    printf("Enter the resource request: ");
    for (i = 0; i < num_resources; i++) {
        scanf("%d", &request[i]);
    }
    
    if (request_resources(process_id, request)) {
        printf("Request granted. The system is still in a safe state.\n");
    } else {
        printf("Request denied. The system would enter an unsafe state.\n");
    }
    
    return 0;
}
