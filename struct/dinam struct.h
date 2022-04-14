#pragma once
#ifndef __DINAM_STRUCT_H__
#define __DINAM_STRUCT_H__
#include <iostream>
#include <malloc.h>
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
    Plan* strings = (Plan*)malloc(1 * sizeof(int));
    int max_size;
    int cur_size;
};
#endif