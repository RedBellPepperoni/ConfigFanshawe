//#include "Counter.h"
//
//void Counter::Init(int start)
//{
//    startValue = start > 0 ? start : 0;
//    currentValue = startValue;
//}
//
//Counter::Counter() : startValue(0)
//                   ,currentValue(0)
//{
//    Init(100);
//}
//
//Counter::Counter(int start)
//{
//    Init(start);
//}
//
//Counter::~Counter()
//{
//}
//
//int Counter::GetStart() const
//{
//    return startValue;
//}
//
//int Counter::GetCurrent() const
//{
//    return currentValue;
//}
//
//bool Counter::IsDone() const
//{
//    return currentValue == 0;
//}
//
//void Counter::CountDown()
//{
//    currentValue -= 1;
//    
//    if (currentValue < 0)
//    {
//        currentValue = 0;
//    }
//
//}
