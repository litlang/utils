#pragma once

#include <vector>

class ranges {
public:
	ranges(std::initializer_list<std::pair<int, int>> init_list);

    bool include(int element);
private:
	std::vector<std::pair<int, int>> Ranges;
};