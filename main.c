#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tableSize = 0, totEle = 0;

struct node *hashTable = NULL;
struct node {
    int key;
    int number;
    int marker;
};

void display() {
    int i;
    if (totEle == 0) {
            printf("Hash Table is Empty!!\n");
            return;
    }
    printf("Number    Index \n");
    printf("-----------------------------------------\n");
    for (i = 0; i < tableSize; i++) {
        if (hashTable[i].marker == 1) {
            printf("%-10d", hashTable[i].number);
            printf("%d\n", i);
        }
    }
    printf("\n");
    return;
}


void insertInHash(int key, int number) {
    int hashIndex = number % tableSize;
    if (tableSize == totEle) {
            printf("Can't perform Insertion..Hash Table is full!!");
            return;
    }
    while (hashTable[hashIndex].marker == 1) {
            hashIndex = (hashIndex + 1) % tableSize;
    }
    hashTable[hashIndex].number= number;
    hashTable[hashIndex].marker = 1;
    totEle++;
    display();
    return;
}
 
 
int main() {
    int key=0, ch;
    long int x;
    int number;

    printf("-----------------------\n");
    printf("Enter Table Size:");
    scanf("%d", &tableSize);
    printf("-----------------------\n");

    // Hash table memory allocation.
    hashTable = (struct node *)calloc(tableSize, sizeof(struct node));

    while (1) {
        printf("1. Insertion\t");
        printf("2. Exit\n Enter option:");
        scanf("%d", &ch);
        switch (ch) {
                case 1:
                    printf("Enter The Number:");
                    scanf("%d", &number);
                    x=number;
                    key=0;
                        while(x!=0)
                        {
                            int r=x%10;
                            key+=r;
                            x/=10;
                        }
                        insertInHash(key, number);
                        printf("-----------------------\n");
                        break;
                        case 2:
                            exit(0);
                        default:
                            printf("You have entered wrong Option!\n");
                                break;
                }
        }
        return 0;
  }

