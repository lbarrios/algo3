#ifndef TIMER_H
#define TIMER_H

#include "headers.h"
#ifdef __clang__
#include <sys/timeb.h>
#else
#include "time.h"
#endif

class Timer {
public:
  Timer(ostream &);
  ~Timer();
  void setInitialTime( string );
  void setFinalTime( string );
  uint64_t getTime( string );
  void saveAllTimes( void );

private:
  typedef map<string, timespec> time_dicc;
  time_dicc _initialTimes;
  time_dicc _finalTimes;
  ostream &_timeOutput;
};

#endif
