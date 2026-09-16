#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coeff;
    int exp;
    struct poly *link;
};

struct poly *createNode(int coeff, int exp) {
    struct poly *newNode = (struct poly *)malloc(sizeof(struct poly));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->link = NULL;
    return newNode;
}

void appendNode(struct poly **head, struct poly **tail, int coeff, int exp) {
    struct poly *newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        (*tail)->link = newNode;
    }
    *tail = newNode;
}

struct poly *addPoly(struct poly *p1, struct poly *p2) {
    struct poly *resultHead = NULL;
    struct poly *resultTail = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) {
                appendNode(&resultHead, &resultTail, sum, p1->exp);
            }
            p1 = p1->link;
            p2 = p2->link;
        } else if (p1->exp > p2->exp) {
            appendNode(&resultHead, &resultTail, p1->coeff, p1->exp);
            p1 = p1->link;
        } else {
            appendNode(&resultHead, &resultTail, p2->coeff, p2->exp);
            p2 = p2->link;
        }
    }

    while (p1 != NULL) {
        appendNode(&resultHead, &resultTail, p1->coeff, p1->exp);
        p1 = p1->link;
    }

    while (p2 != NULL) {
        appendNode(&resultHead, &resultTail, p2->coeff, p2->exp);
        p2 = p2->link;
    }

    return resultHead;
}

void display(struct poly *head) {
    if (!head) {
        printf("0\n");
        return;
    }
    struct poly *temp = head;
    while (temp != NULL) {
        printf("%d(x^%d)", temp->coeff, temp->exp);
        if (temp->link != NULL)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}

void freePoly(struct poly *head) {
    struct poly *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

int main() {
    struct poly *poly1 = NULL, *tail1 = NULL;
    struct poly *poly2 = NULL, *tail2 = NULL;
    struct poly *poly3 = NULL;
    int n1, n2, coeff, exp;

    printf("Enter number of terms for polynomial 1 (descending exponents): ");
    if (scanf("%d", &n1) != 1) return 1;
    for (int i = 0; i < n1; i++) {
        printf("Term %d (coeff exp): ", i + 1);
        scanf("%d %d", &coeff, &exp);
        appendNode(&poly1, &tail1, coeff, exp);
    }

    printf("Enter number of terms for polynomial 2 (descending exponents): ");
    if (scanf("%d", &n2) != 1) return 1;
    for (int i = 0; i < n2; i++) {
        printf("Term %d (coeff exp): ", i + 1);
        scanf("%d %d", &coeff, &exp);
        appendNode(&poly2, &tail2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    poly3 = addPoly(poly1, poly2);

    printf("Sum:  ");
    display(poly3);

    freePoly(poly1);
    freePoly(poly2);
    freePoly(poly3);

    return 0;
}
