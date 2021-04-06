//Gregor Wagner
//WaG-dyn2.c

//includes
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//struct
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;

//node functions
node *createTree(int start){
    //create Root of tree
    node *tempNode;
    tempNode = malloc(sizeof(node));
    tempNode->data = start;
    tempNode->left = NULL;
    tempNode->right = NULL;
    return tempNode;
}

node *insertData(node *child, int data){
    if(child == NULL){
        return createTree(data);
    } else{
        if(data < child->data){
            child->left = insertData(child->left, data);
        }
        else if(data > child->data){
            child->right = insertData(child->right, data);
        }
        else if(data == child->data){
            printf("Data already exists, so it is a loop!");
        }
        return child;
    }
}

void displayTree(node *child){
    if(child==NULL){
        return;
    }
    displayTree(child->left);
    printf("| %d", child->data);
    displayTree(child->right);
}

int franziskus(int num){
    int sum = 0;

    while (num > 0){
        sum += ((num % 10)*(num % 10));
        num /= 10;
    }
    return sum;
}   

bool is_num_in_tree(node *child, int num){
    if ((child->left == NULL && child->right == NULL ) || child->data == num){
        return (child->data == num) ? true : false;
    } else {
        if(child->data < num){
            return is_num_in_tree(child->right, num);
        } else if(child->data > num){
            return is_num_in_tree(child->left, num);
        }
    }
    return (child->data == num) ? true : false;
}

//main
int main (void){
    //variables    
    node *tree;
    int start = 0;

    //input
    printf("Bitte Zahl eingeben: ");
    scanf("%d", &start);

    //create Root
    tree = createTree(start);

    int num = franziskus(start);

    while (!is_num_in_tree(tree, num)){
        if(num == 1){
            printf("this is a happy number");
            displayTree(tree);
            return 1;
        }
        tree = insertData(tree, num); 
        num = franziskus(num);
    }

    printf("unhappy number, loop was found");
    
    displayTree(tree);

    return 1;
}
