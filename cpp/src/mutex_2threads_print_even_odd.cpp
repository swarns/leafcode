/*
* Copyright 2020 @LeafCode
* 
* This code is for printing even and odd numbers using two threads,
* one thread printing all the even numbers and other thread printing all the
* odd numbers.
*
*/

#include <iostream>
#include <string>

using namespace std;

pthread_mutex_t mlock;
int shared_data;

/* Function to print even numbers */
void* print_shared_data_even(void *args) {

	pthread_mutex_lock(&mlock);
	do {

		if (shared_data % 2 == 0) {

			cout<<"Even Thread ("<<pthread_self()<<"): \t"<<shared_data<<endl;
			shared_data++;
		} else {
			
			pthread_mutex_unlock(&mlock);	
		}

	} while (shared_data <= 10);

return NULL;
}

/* Function to print odd numbers */
void* print_shared_data_odd(void *args) {

	pthread_mutex_lock(&mlock);
	do {

		if (shared_data % 2 != 0) {

			cout<<"Odd Thread ("<<pthread_self()<<"): \t"<<shared_data<<endl;
			shared_data++;
		} else {
			
			pthread_mutex_unlock(&mlock);	
		}

	} while (shared_data <= 10);

return NULL;
}

int main() {

	pthread_t tid[2];

	if (pthread_mutex_init(&mlock, NULL) != 0) {

		cout<<"mutex init failed"<<endl;
	}
	
	if (pthread_create(&tid[0], NULL, print_shared_data_even, NULL) != 0) {

		cout<<"thread creation failed"<<endl;
	}
	
	if (pthread_create(&tid[1], NULL, print_shared_data_odd, NULL) != 0) {

		cout<<"thread creation failed"<<endl;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	pthread_mutex_destroy(&mlock);

return 0;
}
