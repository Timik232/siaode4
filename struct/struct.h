#pragma once
#ifndef __STRUCT_H__
#define __STRUCT_H__
#include <iostream>
using namespace std;
struct Plan
{
    int shifr_direct;
    string name_direct;
    int shifr_profile;
    string name_profile;
    int start_year;
};
struct Table
{
    Plan strings[100];
    int max_size;
    int cur_size;
};
#endif