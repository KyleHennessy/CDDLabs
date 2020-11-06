/*! \mainpage Lab02 Semaphores
    \author Kyle Hennessy
    \date 02/11/2020
    \copyright This project is covered by the GNU General Public License v3.0
    \name Semaphores
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>
/*! \class Signal
    \brief An Implementation of Threads Using Semaphores

   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions

*/
/*! displays a message first*/
/*! \fn void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay )
    \brief This function task one will first sleep and then print out the string before signaling other threads
    \param theSemaphore The semaphore used to handle synchronization
    \param delay the amount of time the thread has to wait to sleep

    Semaphore is initially set to 0.
    the function should print "I must print first" on one line.
*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}
/*! displays a message second*/
/*! \fn void taskTwo(std::shared_ptr<Semaphore> theSemaphore)
    \brief This function will first wait until it is signalled to run by another thread.
    \param theSemaphore the semaphore used to handle synchronization

    Semaphore is initially set to 0.
    The function prints out "This will appear second".
*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

/*! Main function*/
/*! \fn void main(void)
    \brief driver of main.cpp. It creates 2 threads and a semaphore that is
    shared between them.
*/
/*! \var int taskOneDelay
    \brief used to say the amount of time the thread is to be delayed
*/
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  int taskOneDelay=5;
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem,taskOneDelay);
  std::cout << "Launched from the main\n";
   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();
  return 0;
}
