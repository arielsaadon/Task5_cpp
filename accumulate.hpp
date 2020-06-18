#pragma once

namespace itertools{
    class accumulate{
        int start,end;
        public:
            template <typename T> accumulate(T): start(0), end(0){}
            template <typename T1, typename T2> accumulate(T1,T2): start(0), end(0){}
        int* begin(){
            return nullptr;
        }
        int* end(){
            return nullptr;
        }
    };
}