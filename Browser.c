#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *current = NULL;

/* Visit a new page */
void visitPage(char url[]) {
    struct Node *temp;
    struct Node *newNode;

    /* Delete forward history if branching to a new page */
    if (current != NULL && current->next != NULL) {
        temp = current->next;
        while (temp != NULL) {
            struct Node *deleteNode = temp;
            temp = temp->next;
            free(deleteNode);
        }
        current->next = NULL;
    }

    /* Create and initialize new node */
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newNode->url, url);
    newNode->prev = current;
    newNode->next = NULL;

    /* Link and advance current pointer */
    if (current != NULL) {
        current->next = newNode;
    }
    current = newNode;

    printf("Visited: %s\n", current->url);
}

/* Go back */
void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("Cannot go back.\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}

/* Go forward */
void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("Cannot go forward.\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}

/* Display current page */
void displayPage() {
    if (current == NULL) {
        printf("No page visited yet.\n");
    } else {
        printf("Current Page: %s\n", current->url);
    }
}

/* Free all nodes before exiting */
void freeAll() {
    if (current == NULL) return;

    /* Rewind to the very first node */
    while (current->prev != NULL) {
        current = current->prev;
    }

    /* Free all nodes sequentially */
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int choice;
    char url[100];

    do {
        printf("\n--- Browser Navigation ---\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%99s", url);
                visitPage(url);
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                displayPage();
                break;

            case 5:
                printf("Exiting Browser...\n");
                freeAll();
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
