#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include <mutex>
#include <condition_variable>
#include <chrono>
/*! \class Semaphore
  \brief A Semaphore Implementation

  Uses C++11 features such as mutex and condition variables to implement Semaphore

*/


class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex;     /*! Mutex lock for semaphore */
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount=0)
        : m_uiCount(uiCount) { };
    /*! /fn void Wait()
      /brief This function decrements the S value of the semaphore and places
      the current thread on to the queue if the s value becomes a negative int
    */
    void Wait();
    template< typename R,typename P >
    bool Wait(const std::chrono::duration<R,P>& crRelTime);
    /*! /fn void Signal()
      /brief This function increments the s value of the semaphore
    */
    void Signal();

};

#endif
