#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct File {
    char fname[20];   
};

struct Directory {
    char dname[20];   
    struct File files[10];  
    int fileCount;    
} dir[10];            

int dirCount = 0;


void createDirectory() {
    char name[20];
    printf("Enter the directory (user) name: ");
    scanf("%s", name);

    
    for (int i = 0; i < dirCount; i++) {
        if (strcmp(dir[i].dname, name) == 0) {
            printf("Directory '%s' already exists!\n", name);
            return;
        }
    }

    strcpy(dir[dirCount].dname, name);
    dir[dirCount].fileCount = 0;
    dirCount++;
    printf("Directory '%s' created successfully.\n", name);
}


void createFile() {
    char dname[20], fname[20];
    printf("Enter the directory (user) name: ");
    scanf("%s", dname);

    for (int i = 0; i < dirCount; i++) {
        if (strcmp(dir[i].dname, dname) == 0) {
            printf("Enter the file name to create: ");
            scanf("%s", fname);

            
            for (int j = 0; j < dir[i].fileCount; j++) {
                if (strcmp(dir[i].files[j].fname, fname) == 0) {
                    printf("File '%s' already exists in directory '%s'!\n", fname, dname);
                    return;
                }
            }

            strcpy(dir[i].files[dir[i].fileCount].fname, fname);
            dir[i].fileCount++;
            printf("File '%s' created in directory '%s'.\n", fname, dname);
            return;
        }
    }
    printf("Directory '%s' not found!\n", dname);
}


void deleteFile() {
    char dname[20], fname[20];
    printf("Enter the directory (user) name: ");
    scanf("%s", dname);

    for (int i = 0; i < dirCount; i++) {
        if (strcmp(dir[i].dname, dname) == 0) {
            printf("Enter the file name to delete: ");
            scanf("%s", fname);

            for (int j = 0; j < dir[i].fileCount; j++) {
                if (strcmp(dir[i].files[j].fname, fname) == 0) {
                    for (int k = j; k < dir[i].fileCount - 1; k++) {
                        strcpy(dir[i].files[k].fname, dir[i].files[k + 1].fname);
                    }
                    dir[i].fileCount--;
                    printf("File '%s' deleted from directory '%s'.\n", fname, dname);
                    return;
                }
            }
            printf("File '%s' not found in directory '%s'.\n", fname, dname);
            return;
        }
    }
    printf("Directory '%s' not found!\n", dname);
}


void searchFile() {
    char dname[20], fname[20];
    printf("Enter the directory (user) name: ");
    scanf("%s", dname);

    for (int i = 0; i < dirCount; i++) {
        if (strcmp(dir[i].dname, dname) == 0) {
            printf("Enter the file name to search: ");
            scanf("%s", fname);

            for (int j = 0; j < dir[i].fileCount; j++) {
                if (strcmp(dir[i].files[j].fname, fname) == 0) {
                    printf("File '%s' found in directory '%s'.\n", fname, dname);
                    return;
                }
            }
            printf("File '%s' not found in directory '%s'.\n", fname, dname);
            return;
        }
    }
    printf("Directory '%s' not found!\n", dname);
}


void display() {
    if (dirCount == 0) {
        printf("No directories available.\n");
        return;
    }

    printf("\nTwo-Level Directory Structure:\n");
    for (int i = 0; i < dirCount; i++) {
        printf("\nDirectory: %s\n", dir[i].dname);
        if (dir[i].fileCount == 0) {
            printf("  No files.\n");
        } else {
            for (int j = 0; j < dir[i].fileCount; j++) {
                printf("  %d. %s\n", j + 1, dir[i].files[j].fname);
            }
        }
    }
}

int main() {
    int choice;

    printf("----- Two Level Directory Simulation -----\n");

    while (1) {
        printf("\n1. Create Directory\n2. Create File\n3. Delete File\n4. Search File\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createDirectory(); break;
            case 2: createFile(); break;
            case 3: deleteFile(); break;
            case 4: searchFile(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

