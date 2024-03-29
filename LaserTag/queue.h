/*
 * queue.h
 *
 *  Created on: Mar 25, 2014
 *      Author: hutch
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdint.h>
#include <stdbool.h>

#define QUEUE_MAX_NAME_SIZE 50  // Limit the size of the statically-allocated queue name.

// Big enough to address everything in the queue.
typedef uint32_t queue_index_t;

// Just make everything double for this project.
typedef double queue_data_t;

// Not sure we need something different from the index type.
typedef uint32_t queue_size_t;

// The queue struct with elementCount to speed up computations to determine element count.
// Queue will use the empty location and pointer arithmetic to determine full and empty.
typedef struct {
  queue_index_t indexIn;			// Always points to the next open slot.
  queue_index_t indexOut;			// Always points to the next element to be removed from the queue (or "oldest" element).
  queue_size_t size;					// This is the capacity of the queue.
  queue_size_t elementCount;	// Number of things currently in the queue.
  queue_data_t * data;				// Points to a dynamically-allocated array.
  bool underflowFlag;         // True if queue_pop() is called on an empty queue. Reset to false after queue_push() is called.
  bool overflowFlag;          // True if queue_push() is called on a full queue. Reset to false once queue_pop() is called.
  char name[QUEUE_MAX_NAME_SIZE];	// Name for debugging purposes.
} queue_t;

// Allocates the memory to you queue (the data* pointer) and initializes all parts of the data structure.
// Prints out an error message if malloc() fails and calls assert(false) to
// print-out line-number information and die.
void queue_init(queue_t* q, queue_size_t size, const char* name);

// Get the user-assigned name for the queue.
const char* queue_name(queue_t* q);

// Returns the number of elements that the queue can hold when completely full. This number will be 1 less than the size of the array that holds the elements.
queue_size_t queue_size(queue_t* q);

// Returns true if the queue is full.
bool queue_full(queue_t* q);

// Returns true if the queue is empty.
bool queue_empty(queue_t* q);

// If the queue is not full, pushes a new element into the queue and clears the underflowFlag.
// IF the queue is full, set the overflowFlag, print an error message and DO NOT change the queue.
void queue_push(queue_t* q, queue_data_t value);

// If the queue is not empty, remove and return the oldest element in the queue, set overflow flag to false.
// If the queue is empty, set the underflowFlag, print an error message, and DO NOT change the queue.
queue_data_t queue_pop(queue_t* q);

// If the queue is full, call queue_pop() and then call queue_push().
// If the queue is not full, just call queue_push().
void queue_overwritePush(queue_t* q, queue_data_t value);

// Provides random-access read capability to the queue.
// Low-valued indexes access older queue elements while higher-value indexes access newer elements
// (according to the order that they were added).
// Print a meaningful error message if an error condition is detected.
queue_data_t queue_readElementAt(queue_t* q, queue_index_t index);

// Returns a count of the elements currently contained in the queue.
queue_size_t queue_elementCount(queue_t* q);

// Returns true if an underflow has occurred (queue_pop() called on an empty queue).
bool queue_underflow(queue_t* q);

// Returns true if an overflow has occurred (queue_push() called on a full queue).
bool queue_overflow(queue_t* q);

// Frees the storage that you malloc'd before.
void queue_garbageCollect(queue_t* q);

// Prints the current contents of the queue. Handy for debugging.
// This must print out the contents of the queue in the order of oldest element first to newest element last.
// HINT: Just use queue_readElementAt() in a for-loop. Trivial to implement this way.
void queue_print(queue_t* q);

// Performs a comprehensive test of all queue functions. Returns false if the test fails, true otherwise.
// Prints out a series of informational messages during the test.
bool queue_runTest();

#endif /* QUEUE_H_ */
