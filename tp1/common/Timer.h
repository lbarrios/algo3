#include "headers.h"
#include <map>
#include <string>

class Timer {
public:
  Timer(ostream &);
  ~Timer();
  void setInitialTime( string );
  void setFinalTime( string );
  uint64_t getTime( string );
  void saveAllTimes( void );

private:
  map<string, uint64_t> _initialTimes;
  map<string, uint64_t> _finalTimes;
  ostream &_time;
};
