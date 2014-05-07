#include "Timer.h"
Timer::Timer(ostream &ptime) : _timeOutput(ptime)
{

}
Timer::~Timer()
{

}
void Timer::setInitialTime( string k )
{
#ifdef TIME
  clock_gettime( CLOCK_REALTIME, &(this->_initialTimes[k]) );
#endif
}
void Timer::setFinalTime( string k )
{
#ifdef TIME
  clock_gettime( CLOCK_REALTIME, &(this->_finalTimes[k]) );
#endif
}
uint64_t Timer::getTime( string k )
{
#ifdef TIME
  if (this->_initialTimes.count(k) == 0){
    return 0;
  }
  if (this->_finalTimes.count(k) == 0){
    return 0;
  }
  uint64_t nseg = (int64_t)this->_finalTimes[k].tv_nsec - (int64_t)this->_initialTimes[k].tv_nsec;
  uint64_t seg = (int64_t)this->_finalTimes[k].tv_sec - (int64_t)this->_initialTimes[k].tv_sec;
  uint64_t total = nseg + (seg*(1e9));
  return total;
#endif
	return 0;
}
void Timer::saveAllTimes( void )
{
#ifdef TIME
  for(time_dicc::iterator it = this->_initialTimes.begin(); 
  it != this->_initialTimes.end(); it++){
    _timeOutput << it->first << " " << this->getTime(it->first) << endl;
  }
#endif
}
