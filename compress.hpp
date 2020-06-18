#pragma once

namespace itertools{
    class compress{
        int start,end;
        public:
            template <typename T1, typename T2> compress(T1,T2): start(0), end(0){}
        int* begin(){
            return nullptr;
        }
        int* end(){
            return nullptr;
        }
    };
}