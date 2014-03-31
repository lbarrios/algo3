#include "Timer.h"
Timer::Timer(ostream &ptime) : _time(ptime)
{

}
Timer::~Timer()
{

}
void Timer::setInitialTime( string k )
{
  clock_gettime( CLOCK_REALTIME, &(this->_initialTimes[k]) );
}
void Timer::setFinalTime( string k )
{
  clock_gettime( CLOCK_REALTIME, &(this->_finalTimes[k]) );
}
uint64_t Timer::getTime( string k )
{
  if (this->_initialTimes.count(k) == 0){
    return 0;
  }
  if (this->_finalTimes.count(k) == 0){
    return 0;
  }
  uint64_t nseg = this->_finalTimes[k].tv_nsec - this->_initialTimes[k].tv_nsec;
  uint64_t seg = this->_finalTimes[k].tv_sec - this->_initialTimes[k].tv_sec;
  uint64_t total = nseg + (seg*(1e9));
  return total;
}
void Timer::saveAllTimes( void )
{
  for(time_dicc::iterator it = this->_initialTimes.begin(); 
  it != this->_initialTimes.end(); it++){
    _time << it->first << " " << this->getTime(it->first) << endl;
  }
}