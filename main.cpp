#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

#define NUM_PHILOSOPHERS 5
#define CHOPSTICKS true

pthread_mutex_t mutex[NUM_PHILOSOPHERS];
sem_t sem[NUM_PHILOSOPHERS];

// Dining Philosophers Problem
void philosopher (void *arg) {
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;
    bool state;

    do {
        std::cout << "Philosopher " << id << " is hungry." << std::endl;
        sleep(rand() % 3 + 1); // Simulate time taken for feeling hungry

        std::cout << "Philosopher " << id << " is trying to pick up the left chopsticks." << std::endl;
        sem_wait(&sem[left]);
        pthread_mutex_lock(&mutex[left]);
        std::cout << "Philosopher " << id << " picks up the left chopsticks." << std::endl;

        std::cout << "Philosopher " << id << " is trying to pick up the right chopsticks." << std::endl;
        sem_wait(&sem[right]);
        pthread_mutex_lock(&mutex[right]);
        std::cout << "Philosopher " << id << " picks up the right chopsticks." << std::endl;

        std::cout << "Philosopher " << id << " is eating." << std::endl;
        sleep(rand() % 3 + 1); // Simulate time taken for eating

        std::cout << "Philosopher " << id << " puts down the right chopsticks." << std::endl;
        pthread_mutex_unlock(&mutex[right]);
        sem_post(&sem[right]);

        std::cout << "Philosopher " << id << " puts down the left chopsticks." << std::endl;
        pthread_mutex_unlock(&mutex[left]);
        sem_post(&sem[left]);
    } while (true);
}
int main() {
    srand(time(nullptr));
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&mutex[i], nullptr);
        sem_open("/sem", O_CREAT | O_EXCL, 0644, CHOPSTICKS);
        ids[i] = i;
        pthread_create(&philosophers[i], nullptr, (void *(*)(void *))philosopher, &ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], nullptr);
    }

    return 0;
}
