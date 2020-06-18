#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include <vector>
#include <string>
#include <set>
using namespace itertools;
using namespace std;


TEST_CASE("Test Range"){
    vector<int> result {1,2,3,4,5};
    int j=0;
    for(int i : range(1,6)){
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 5);


    vector<int> result1 = {0,1,2,3,4,5,6,7,8,9,10};
    j = 0;
    for(int i : range(0,11)){
        CHECK(i == result1.at(j));
        ++j;
    }
    CHECK(j == 11);
    CHECK(j != 10);
    CHECK(j != 20);
    CHECK(j != 0);

    vector<int> result2 = {5,5};
    for(int i : range(0,0)){
        CHECK(0==1); // empty
    }
        
}

TEST_CASE("Test Accumulate"){
    vector<int> result1 = {0,1,3,6,10,15};// 0, 0+1, 0+1+2, 0+1+2+3, 0+1+2+3+4, 0+1+2+3+4+5
    int j = 0;
    for (int i: accumulate(range(0,7))){
        CHECK(i == result1.at(j));
        ++j;
    }
    CHECK(j == 6);
    CHECK(j != 10);
    CHECK(j != 4);
    CHECK(j != 0);
    
    vector<int> result2 = {3,7,12,18,25,33};// 3,7,12,18,25,33
    j=0;
    for (int i: accumulate(range(3,9),[](int x, int y){return x+y;})){
        CHECK(i == result2.at(j));
        ++j;
    }
    CHECK(j == 6);
    CHECK(j != 10);
    CHECK(j != 4);
    CHECK(j != 0);

    vector<int> result3 = {2,6,24,120,720,5040};// 2,2*3,2*3*4,2*3*4*5,2*3*4*5*6,2*3*4*5*6*7
    j=0;
    for (int i: accumulate(range(2,8),[](int x, int y){return x*y;})){
        CHECK(i == result3.at(j));
        ++j;
    }
    CHECK(j == 6);
    CHECK(j != 10);
    CHECK(j != 4);
    CHECK(j != 0);

    vector<string> vecString {"Check", "If", "Work"};
    vector<string> result4 {"Check","CheckIf","CheckIfWork"};
    j=0;
    for(int i : accumulate(vecString)){
        CHECK(i == result4.at(j));
        ++j;
    }
    CHECK(j == 3);
    CHECK(j != 10);
    CHECK(j != 2);
    CHECK(j != 0);
}

TEST_CASE("Test Filterfalse"){
    vector<int> result = {3,5};
    int j = 0;
    for (int i: filterfalse([](int i){return i%2==0;}, range(2,6)) ){// without 2,4
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 2);
    CHECK(j != 3);
    CHECK(j != 1);
    CHECK(j != 0);

    vector<int> result2 = {2,4};
    j=0;
    for (int i: filterfalse([](int i){return i%2!=0;}, range(2,6)) ){ //without 3,6
        CHECK(i == result2.at(j));
        ++j;
    }
    CHECK(j == 2);
    CHECK(j != 3);
    CHECK(j != 1);
    CHECK(j != 0);

    vector<int> result3 {3,6,10,15,21,28,36,45,55};
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    j=0;
    for(int i : filterfalse([](int i){return i<2;},accumulate(vec))){
        CHECK(i == result3.at(j));
        ++j;
    }
    CHECK(j == 9);
    CHECK(j != 10);
    CHECK(j != 8);
    CHECK(j != 0);

    vector<int> result4 {3,4,5,7,8};
    vector<int> vec2 = {3,4,5,6,7,8};
    j=0;
    for (int i: filterfalse([](int i){return i=6;},accumulate(vec2))){
        CHECK(i == result4.at(j));
        ++j;
    }
    CHECK(j == 5);
    CHECK(j != 6);
    CHECK(j != 4);
    CHECK(j != 0);
}

TEST_CASE("Test Compress"){
    vector<int> result = {5,7};
    int j = 0;
    vector<bool> tftf {true,false,true,false};
    for (int i: compress(range(5,9), tftf) ){
        CHECK(i == result.at(j));
        ++j;
    }
    CHECK(j == 2);
    CHECK(j != 1);
    CHECK(j != 3);
    CHECK(j != -2);
    CHECK(j != 0);

    vector<bool> tftftft {true,false,true,false,true,false,true};
    vector<string> checkString = {"A","b", "c", "D", "e", "F", "g"};
    vector<string> resultString = {"A","c","e","g"};
    j = 0;
    for (int i: compress(checkString,tftftft) ){
        CHECK(resultString.at(j) == i);
        ++j;
    }
    CHECK(j == 4);
    CHECK(j != 1);
    CHECK(j != 5);
    CHECK(j != -2);
    CHECK(j != 0);


    vector<bool> ttft {true,true,false,true};
    string resultstring = "tet";
    string checkstring ="test";
    j = 0;
    for (int i: compress(checkstring,ttft)){
        CHECK(resultstring.at(j) == i);
        ++j;
    }
    CHECK(j == 3);
    CHECK(j != 1);
    CHECK(j != 5);
    CHECK(j != -2);
    CHECK(j != 0);

}