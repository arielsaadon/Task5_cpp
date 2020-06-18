#pragma once

namespace itertools{
    class range{
        int start,end;
        public:
            range(int a, int b): start(a), end(b){}
        int* begin(){
            return nullptr;
        }
        int* end(){
            return nullptr;
        }
    };
}
