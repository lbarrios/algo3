#ifndef HEADERS_H
#define HEADERS_H

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>

#include <list>
#include <vector>
#include <queue>
#include <set>

#include <stdint.h>

//#include <ctime>
//#include <time.h>
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

#else

#endif



  #ifdef DEBUG
    #define DEBUG_ENTER fprintf (stderr, "\n")
    #define DEBUG_INT(x) fprintf(stderr, "DEBUG: %s=%d in %s (%s:%d)\n",#x,(void*)(x),__func__,__FILE__,__LINE__)
    #define DEBUG_UINT(x) fprintf(stderr, "DEBUG: %s=%u in %s (%s:%d)\n",#x,(void*)(x),__func__,__FILE__,__LINE__)
    #define DEBUG_POINTER(x) fprintf (stderr, "DEBUG: %s=%p in %s (%s:%d)\n",#x,(void*)(x),__func__,__FILE__,__LINE__)
    #define DEBUG_CHAR(x) fprintf (stderr, "DEBUG: %s=%c in %s (%s:%d)\n",#x,x,__func__,__FILE__,__LINE__)
    #define DEBUG_STRING(x) fprintf (stderr, "DEBUG: %s=%s in %s (%s:%d)\n",#x,x,__func__,__FILE__,__LINE__)
    #define DEBUG_BOOL(x) fprintf (stderr, "DEBUG: %s=%s in %s (%s:%d)\n",#x,(x?"true":"false"),__func__,__FILE__,__LINE__)
    #define DEBUGC(x) cerr << "DEBUG: " << x << endl
    #define _C(x) DEBUGC(x)
    #define IFDEBUG(x,y) if(x){ y }
  #else
    #define DEBUG_ENTER do{}while(false)
    #define DEBUG_INT(x) do{}while(false)
    #define DEBUG_UINT(x) do{}while(false)
    #define DEBUG_POINTER(x) do{}while(false)
    #define DEBUG_CHAR(x) do{}while(false)
    #define DEBUG_STRING(x) do{}while(false)
    #define DEBUG_BOOL(x) do{}while(false)
    #define DEBUGC(x) do{}while(false)
    #define _C(x) DEBUGC(x)
    #define IFDEBUG(x,y)
  #endif

  #ifdef TIME
    #define tomarTiempoInicial() do{}while(0)
    #define imprimirTiempoFinal() do{}while(0)
  #else
    #define tomarTiempoInicial() do{}while(0)
    #define imprimirTiempoFinal() do{}while(0)
  #endif

#endif


