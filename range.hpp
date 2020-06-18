#pragma once

namespace itertools{
    class range{
        int Start,End;
        public:
            range(int a, int b): Start(a), End(b){}
        int* begin(){
            return nullptr;
        }
        int* end(){
            return nullptr;
        }
    };
}
