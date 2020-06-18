#pragma once

namespace itertools{
    class accumulate{
        int Start,End;
        public:
            template <typename T> accumulate(T): Start(0), End(0){}
            template <typename T1, typename T2> accumulate(T1,T2): Start(0), End(0){}
        int* begin(){
            return nullptr;
        }
        int* end(){
            return nullptr;
        }
    };
}