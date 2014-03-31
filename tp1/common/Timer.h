#ifndef TIMER_H
#define TIMER_H

#include "headers.h"
#include <sys/timeb.h>

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
  ostream &_time;
};

#endif