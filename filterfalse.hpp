#pragma once

namespace itertools{
    class filterfalse{
        int Start,End;
        public:
            template <typename T1, typename T2> filterfalse(T1,T2): Start(0), End(0){}
        int* begin(){
            return nullptr;
        }
        int* end(){
            return nullptr;
        }
    };
}