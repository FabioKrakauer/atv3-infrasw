#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define QTD_THREADS 3

int maxValue, minValue = 0;
float avr = 0;
int total = 0;
int numbers[0];

void *max(void *amount) {

        int *internAmount = (int *)amount;
        maxValue = numbers[0];
        for (int i = 0; i < *internAmount; i++) {
            if (numbers[i] > maxValue) {
                maxValue = numbers[i];    
            }
        }

        return NULL;
}

void *min(void *amount) {

        int *internAmount = (int *)amount;

        minValue = numbers[0];
        for (int i = 0; i < *internAmount; i++) {
            if (numbers[i] < minValue) {
                minValue = numbers[i];
            }    
        }

        return NULL;
}

void *average(void *qnt) {
    int *quantity = (int *)qnt;
    avr = total/(float)*quantity;
    return NULL;
}

int main(void) {

        pthread_t thread_one;
        pthread_t thread_two;
        pthread_t thread_three;

        int retCreation[QTD_THREADS];
        int amountValues;
        
        printf("Numbers amount: ");
        scanf("%d", &amountValues);

        for (int i = 0; i < amountValues; i++)
        {
            printf("\nNumber %d: ",i+1);
            scanf("%d", &numbers[i]);
            total += numbers[i];
        }

        pthread_create(&thread_one, NULL, max, (void *)(&(amountValues)));
        pthread_join(thread_one, NULL);

        pthread_create(&thread_two, NULL, min, (void *)(&(amountValues)));
        pthread_join(thread_two, NULL);

        pthread_create(&thread_three, NULL, average, (void *)(&(amountValues)));
        pthread_join(thread_three, NULL);

        printf("\nThe average values is %0.2f", avr);
        printf("\nThe maximum values is %d", maxValue);
        printf("\nThe minimum values is %d\n", minValue);

        return 0;
}
