/* Barrier.h --- Barrier.h
 *
 * Filename: Barrier.h
 * Author: Kyle Hennessy
 * Created: 20/11/2020

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */
#pragma once
#include "Semaphore.h"
class Barrier{
    int numThreads = 0;
    int totalThreads;

    Semaphore turnstileOne{0};
    Semaphore turnstileTwo{1};
    Semaphore lock{1};

public:
    Barrier(int numThreads):totalThreads(numThreads){};
    virtual ~Barrier();
    void wait();
    void taskOne();
    void taskTwo();
};


/* Barrier.h ends here */
