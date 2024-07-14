#ifndef SEARCH_H
#define SEARCH_H
#include <vector>
#include <list>
using namespace std;
class Search
{
public:
    static std::vector<int> search_aStar(int start, int goal, int vertices, vector<list<pair<int, int>>> adj);
};
#endif //SEARCH_H