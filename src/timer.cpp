#include "timer.h"


Timer::Timer(){}
Timer::~Timer(){}

void Timer::timer(){
    
    for(auto it = m_timers.begin();it != m_timers.end();){
        it->first--;
        if(it->first == 0){
          it->second();
          it = m_timers.erase(it);
        }
        else
        {
            ++it;
        }
    }
    
}

void Timer::subscribe(int time, const std::function<void()>& itemUse){
    m_timers.push_back({time , itemUse});      
}