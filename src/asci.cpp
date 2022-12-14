#include "asci.hpp"
#include <initializer_list>

llcd::symbol::symbol(std::initializer_list<bool> array,int16_t s_w,int16_t s_h){
    w = s_w;
    h = s_h;
    arr = new bool[w*h];
    auto b = array.begin();
    for (int i = 0; i < array.size(); i++)
    {
        arr[i] = *b;
        b++;
    }
}
llcd::symbol::symbol(std::initializer_list<std::initializer_list<bool>> array){
    h = array.size();
    w = array.begin()->size();
    arr = new bool[h*w];
    auto b = array.begin();
    for (int i = 0; i < array.size(); i++)
    {
        auto b2 = b->begin();
        for (int j = 0; j < b->size(); j++)
        {
            arr[w*i+j] = *b2;
            b2++;
        }
        b++;
    }
}
llcd::symbol::symbol(const symbol& b){
    w = b.w;
    h = b.h;
    arr = new bool[w*h];
    for(int i = 0;i<w*h;i++){
        arr[i] = b.arr[i];
    }
}
llcd::symbol::~symbol()
{
    delete[] arr;
}

bool llcd::symbol::operator[](int index)
{
    return arr[index];
}
//letters
//to-do
llcd::symbol default_s({true},1,1);

#include <iostream>

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int llcd::getChar(char c){
    c = toLowerCase(c);
    switch (c){
        case 'a':
    return 0;
    case 'b':
    return 1;
    case 'c':
    return 2;
    case 'd':
    return 3;
    case 'e':
    return 4;
    case 'f':
    return 5;
    case 'g':
    return 6;
    case 'h':
    return 7;
    case 'i':
    return 8;
    case 'j':
    return 9;
    case 'k':
    return 10;
    case 'l':
    return 11;
    case 'm':
    return 12;
    case 'n':
    return 13;
    case 'o':
    return 14;
    case 'p':
    return 15;
    case 'r':
    return 16;
    case 's':
    return 17;
    case 't':
    return 18;
    case 'u':
    return 19;
    case 'w':
    return 20;
    case 'y':
    return 21;
    case 'z':
    return 22;
    case 'x':
    return 23;
    case '.':
    return 24;
    case ',':
    return 25;
    case ':':
    return 26;
    case '-':
    return 27;
    case '_':
    return 28;
    case '/':
    return 29;
    case '(':
    return 30;
    case ')':
    return 31;
    case '1':
    return 32;
    case '2':
    return 33;
    case '3':
    return 34;
    case '4':
    return 35;
    case '5':
    return 36;
    case '6':
    return 37;
    case '7':
    return 38;
    case '8':
    return 39;
    case '9':
    return 40;
    case '0':
    return 41;
    case '?':
    return 42;
    case ' ':
    return 43;
    }
    return 42;
};

const bool letters[44][5][5] = {
// "a":
{{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1}},
// "b":
{{1,1,1,0,0},{1,0,0,1,0},{1,1,1,0,0},{1,0,0,1,0},{1,1,1,0,0}},
// "c":
{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,0},{1,0,0,0,1},{0,1,1,1,0}},
// "d":
{{1,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,1,1,0,0}},
// "e":
{{1,1,1,1,0},{1,0,0,0,0},{1,1,1,0,0},{1,0,0,0,0},{1,1,1,1,0}},
// "f":
{{1,1,1,1,0},{1,0,0,0,0},{1,1,1,0,0},{1,0,0,0,0},{1,0,0,0,0}},
// "g":
{{0,1,1,1,0},{1,0,0,0,0},{1,0,0,1,1},{1,0,0,0,1},{0,1,1,1,0}},
// "h":
{{1,0,0,0,1},{1,0,0,0,1},{1,1,1,1,1},{1,0,0,0,1},{1,0,0,0,1}},
// "i":
{{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}},
// "j":
{{0,0,0,1,0},{0,0,0,1,0},{0,0,0,1,0},{0,1,0,1,0},{0,0,1,0,0}},
// "k":
{{0,1,0,0,1},{0,1,0,1,0},{0,1,1,0,0},{0,1,0,1,0},{0,1,0,0,1}},
// "l":
{{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,1,1,1,0}},
// "m":
{{1,0,0,0,1},{1,1,0,1,1},{1,0,1,0,1},{1,0,0,0,1},{1,0,0,0,1}},
// "n":
{{1,0,0,0,1},{1,1,0,0,1},{1,0,1,0,1},{1,0,0,1,1},{1,0,0,0,1}},
// "o":
{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}},
// "p":
{{1,1,1,0,0},{1,0,0,1,0},{1,1,1,0,0},{1,0,0,0,0},{1,0,0,0,0}},
// "r":
{{1,1,1,0,0},{1,0,0,1,0},{1,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0}},
// "s":
{{0,1,1,1,0},{1,0,0,0,0},{0,1,1,1,0},{0,0,0,0,1},{0,1,1,1,0}},
// "t":
{{1,1,1,1,1},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}},
// "u":
{{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}},
// "w":
{{1,0,0,0,1},{1,0,0,0,1},{0,1,0,1,0},{0,1,1,1,0},{0,1,0,1,0}},
// "y":
{{1,0,0,0,1},{0,1,0,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}},
// "z":
{{1,1,1,1,1},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{1,1,1,1,1}},
// "x":
{{1,0,0,0,1},{0,1,0,1,0},{0,0,1,0,0},{0,1,0,1,0},{1,0,0,0,1}},
// ".":
{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,1,0,0}},
// ",":
{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,1,0,0},{0,0,1,0,0}},
// ":":
{{0,0,0,0,0},{0,0,0,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,1,0,0}},
// "-":
{{0,0,0,0,0},{0,0,0,0,0},{0,1,1,1,0},{0,0,0,0,0},{0,0,0,0,0}},
// "_":
{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{1,1,1,1,1}},
// "/":
{{0,0,0,1,0},{0,0,0,1,0},{0,0,1,0,0},{0,1,0,0,0},{0,1,0,0,0}},
// "(":
{{0,0,0,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,1,0}},
// ")":
{{0,1,0,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,1,0,0,0}},
// "1":
{{0,0,1,0,0},{0,1,1,0,0},{1,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0}},
// "2":
{{0,1,1,1,0},{1,0,0,0,1},{0,0,0,1,0},{0,0,1,0,0},{1,1,1,1,1}},
// "3":
{{0,1,1,1,0},{1,0,0,0,1},{0,0,0,1,0},{1,0,0,0,1},{0,1,1,1,0}},
// "4":
{{0,0,0,1,0},{0,0,1,1,0},{0,1,0,1,0},{1,1,1,1,1},{0,0,0,1,0}},
// "5":
{{1,1,1,1,1},{1,0,0,0,0},{1,1,1,1,0},{0,0,0,0,1},{1,1,1,1,0}},
// "6":
{{0,1,1,1,1},{1,0,0,0,0},{1,1,1,1,0},{1,0,0,0,1},{0,1,1,1,0}},
// "7":
{{1,1,1,1,1},{0,0,0,1,0},{0,0,0,1,0},{0,0,1,0,0},{0,0,1,0,0}},
// "8":
{{0,1,1,1,0},{1,0,0,0,1},{0,1,1,1,0},{1,0,0,0,1},{0,1,1,1,0}},
// "9":
{{0,1,1,1,0},{1,0,0,0,1},{0,1,1,1,1},{0,0,0,0,1},{0,1,1,1,0}},
// "0":
{{0,1,1,1,0},{1,0,0,0,1},{1,0,0,0,1},{1,0,0,0,1},{0,1,1,1,0}},
// "?":
{{0,1,1,1,0},{0,0,0,1,0},{0,0,1,1,0},{0,0,0,0,0},{0,0,1,0,0}},
// " ":
{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,1},{0,0,0,0,0}}
};
