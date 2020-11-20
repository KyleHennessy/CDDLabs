// Barrier.cpp ---
//
// Filename: Barrier.cpp
// Description:
// Author: Kyle Hennessy
// Created: 20/11/2020

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
//
//

// Code:
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>

Barrier::~Barrier()
{
}
void Barrier::taskOne()
{
    lock.Wait();
    ++numThreads;
    if (numThreads == totalThreads)
    {
        std::cout << std::endl;
        turnstileTwo.Wait();
        turnstileOne.Signal();
    }
    lock.Signal();
    turnstileOne.Wait();
    turnstileOne.Signal();
}

void Barrier::taskTwo()
{
    lock.Wait();
    --numThreads;
    if (numThreads == 0)
    {
        std::cout << std::endl;
        turnstileOne.Wait();
        turnstileTwo.Signal();
    }
    lock.Signal();
    turnstileTwo.Wait();
    turnstileTwo.Signal();
}
//
// Barrier.cpp ends here
