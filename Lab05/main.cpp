/*! \mainpage Lab05 Reusable Barrier function
    \author Kyle Hennessy
    \date 20/11/2020
    \copyright This project is covered by the GNU General Public Licence v3.0
    \name Reusable Barrier
*/

#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 10;
int sharedVariable=0;


/*! \fn barrierTask
    \brief An example of using a reusable barrier
    Task one tells task two wait by forming a "barrier" and prints A and
    the current number we are at in the loop 10 times. After that is complete
    We can then move on to prining task two which creates a barrier so that task
    one will not go until it has completed. Task two will be the same output as
    Task one except it will print B instead of A. After it has done so, the process
    repeats until we have gone past the number of loops
*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void barrierTask(std::shared_ptr<Barrier> theBarrier, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Do first bit of task
    std::cout << "A"<< i;
    //Barrier
    theBarrier->taskOne();
    //Do second half of task
    std::cout<< "B" << i;
    theBarrier->taskTwo();
  }


}

/*! \fn main
    \brief The main driver for the program. This program uses barrier.cpp and barrier.h
    to incorporate the barrier function. The number of loops is 10 as it is the parameter
    for the thread vt on line 57


*/

int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Barrier> aBarrier( new Barrier(num_threads));
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(barrierTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
