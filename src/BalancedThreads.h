
#ifndef BT_BALANCEDTHREADS_H
#define BT_BALANCEDTHREADS_H

#include <string.h>

struct SContextInit{
    size_t numThreads;
    enum {
        BT_METHOD_MINIMIZE_ERROR, // Order the jobs so it minimizes the execution time difference between threads
        BT_METHOD_DONT_CARE // I don't care about the execution time difference
    } methodType;

    union{
        struct minimizeErrorMethod{
            enum {
                // Also known as "work stealing". Randomly assing jobs to threads, and when a thread is done, that thread will get a job that hasn't been run yet
                BT_ALGORITHM_UNORDERED, 
                // In the main thread, assign jobs to the threads so that roughly everyone gets the same amount of time of execution
                // Note that in the first x iterations, this does not happen as the algorithm needs to know the average time of the jobs
                BT_ALGORITHM_ORDERED,
            } threadAlgorithmType;

        };
        struct dontCareMethod{
            enum {
                // Assign jobs in the order that they came in
                BT_SHUFFLING_LINEAR, 
                // Shuffle the job ordering and then assign them in that order
                BT_SHUFFLING_RANDOM, 
            } shufflingType;
        };
    };
};

#ifndef BT_INTERNAL
struct SContext{
    void* unused;
};
#endif 

#endif