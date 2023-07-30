#ifndef TIMER_H
#define TIMER_H
#include <functional>
#include <list>

class Timer
{
public:
    //одиночка
    static Timer& createTimer()
    {
        static Timer t;
        return t;
    }

    ~Timer();
    ///подписчик
    void subscribe(int time, const std::function<void()>& itemUse);
    void timer();


private:
    Timer();
    int quality  = 0;
    std::list<std::pair<int,std::function<void()>>> m_timers;
    
};







#endif