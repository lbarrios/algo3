#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

#include <algorithm>

#include <list>
#include <vector>
#include <queue>
#include <set>

#include <ctime>
#include <time.h>
#include <unistd.h>
using namespace std;

#define uint unsigned int


template < class T, class Container = vector<T>,
  class Compare = less<typename Container::value_type> >
class r_priority_queue: public std::priority_queue<T, Container, Compare>{
public:
    typedef typename std::priority_queue<T>::size_type size_type;
    r_priority_queue(size_type capacity = 0) { reserve(capacity); };
    void reserve(size_type capacity) { this->c.reserve(capacity); }
        void clear(void) { this->c.clear(); }
    size_type capacity() const { return this->c.capacity(); }
};

#ifdef DEBUG
        #define DEBUGC(x) cout << x
        #define IFDEBUG(x,y) if(x){ y }
#else
        #define DEBUGC(x)
        #define IFDEBUG(x,y)
#endif

#ifdef TIME
        //#include <sys/timeb.h>
        #define IFTIME(x) x
#else
        #define IFTIME(x)
#endif

#endif
