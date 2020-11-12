/*! \mainpage Lab03 Rendezvous
    \author Kyle Hennessy
    \date 12/11/2020
    \copyright This project is covered by the GNU General Public Licence v3.0
    \name Rendezvous
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>

/*! \class Signal
    \brief An Implementation of a Rendezvous using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads

*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
/*! \fn void taskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore> secondSem, int delay)
    \brief This function task one will sleep for 5 seconds before displaying
    the message"Task One has arrived!". It will then signal the other thread
    that it is finished and wait for that to finish. When that finishes,
    the message "Task one has left!" will be printed and the task will be
    finished
    \param int delay How long the thread will be delayed for
    \param firstSem Semaphore for the first thread that runs
    \param secondSem Semaphore for the second thread that runs

*/
void taskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore>  secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task One has arrived! "<< std::endl;
  //THIS IS THE RENDEZVOUS POINT!
  firstSem->Signal();
  secondSem->Wait();
  std::cout << "Task One has left!"<<std::endl;
}
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
/*! \fn void taskTwo(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore> secondSem, int delay)
  \brief This function task two  will sleep for 1 seconds before displaying
  the message"Task Two has arrived". It will then signal the other thread
  that it is finished and wait for that to finish. When that finishes,
  the message "Task Two has left" will be printed and the task will be
  finished
  \param int delay How long the thread will be delayed for
  \param firstSem Semaphore for the first thread that runs
  \param secondSem Semaphore for the second thread that runs

*/
void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task Two has arrived "<<std::endl;
  //THIS IS THE RENDEZVOUS POINT!
  secondSem->Signal();
  firstSem->Wait();
  std::cout << "Task Two has left "<<std::endl;
}

/*! Main function*/
/*! \fn void main(void)
    \brief driver of main.cpp. Creates two threads and two semaphores
*/
/*! \var int taskOneDelay
    \brief time in seconds task one will be delayed by. Will run after thread two
*/
/*! \var int taskTwoDelay
    \brief time in seconds task two will be dealyed by. Will run before thread one
*/
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  int taskOneDelay=5;
  int taskTwoDelay=1;
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2,taskTwoDelay);
  threadTwo=std::thread(taskOne,sem1,sem2,taskOneDelay);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
