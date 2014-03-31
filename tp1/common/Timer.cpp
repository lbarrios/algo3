#include "Timer.h"

Timer::Timer(ostream &ptime) : _time(ptime)
{

}

Timer::~Timer()
{

}

void Timer::setInitialTime( string k )
{
  this->_initialTimes[k] = 0;
}
void Timer::setFinalTime( string k )
{
  this->_finalTimes[k] = 1;
}
uint64_t Timer::getTime( string k )
{
  if (this->_initialTimes.count(k) == 0){
    return 0;
  }
  if (this->_finalTimes.count(k) == 0){
    return 0;
  }
  return (this->_finalTimes[k] - this->_initialTimes[k]);
}
void Timer::saveAllTimes( void )
{
  for(map<string, uint64_t>::iterator it = this->_initialTimes.begin(); 
  it != this->_initialTimes.end(); it++){
    _time << it->first << " " << this->getTime(it->first) << endl;
  }
}