#pragma once

#include <vector>
#include <iostream>

int root(std::vector<int>& root, int i);
void MakeSet(std::vector<int>& parent, std::vector<int>& size, int N);
bool find_set(std::vector<int>& parent, int a, int b);
void Union_set(std::vector<int>& parent, std::vector<int>& size, int a, int b);
