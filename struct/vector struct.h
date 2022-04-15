#pragma once
#ifndef __VECTOR_STRUCT_H__
#define __VECTOR_STRUCT_H__
#include <iostream>
#include <vector>
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
    //Plan strings[100];
    vector <Plan> strings;
    int max_size;
};
#endif