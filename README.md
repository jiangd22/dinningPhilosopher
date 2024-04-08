# Dining Philosophers Problem

This repository contains a C++ implementation of the Dining Philosophers Problem using pthreads and semaphores.

## Description
The Dining Philosophers Problem is a classic concurrency problem in computer science. It illustrates synchronization issues and the need for mutual exclusion when multiple processes (philosophers) compete for shared resources (chopsticks) to avoid deadlock and starvation.

In this implementation, each philosopher is represented as a thread. The philosophers alternate between thinking and eating. To simulate the problem, each philosopher requires two chopsticks to eat. The chopsticks are represented by semaphores, ensuring that only one philosopher can pick up each chopstick at a time. Because this is only a simulation of the problem, there are sleep() with random duration sneaked into the program to simmulate the passage of time with the intention of arbitrarily.(i.e., time taken for feeling hungry, time taken for eating).


## Configuration
- `NUM_PHILOSOPHERS`: The number of philosophers in the simulation. Default is set to 5.
- `CHOPSTICKS`: Boolean value indicating whether the chopsticks are available initially. Default is set to `true`.

## Implementation Details
- Each philosopher is represented by a thread.
- Mutual exclusion is achieved using pthread mutexes for critical sections.
- Semaphores are used to represent the chopsticks, allowing only one philosopher to pick up each chopstick at a time.
- The philosophers alternate between hungry, picking up chopsticks, eating, and putting down chopsticks.

## Future Improvements
- Error handling: Implement robust error handling for thread creation, semaphore initialization, etc.
- Refactor code: Improve code readability and modularity.
- Parameterization: Allow users to specify the number of philosophers and other parameters at runtime.(I got lazy ╮(￣▽￣"")╭. The question didn't specify any runtime input, please have mercy)
