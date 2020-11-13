#include"graph.h"
#include<vector>
#include<list>
#include<iterator>
#include <algorithm>


vector<int> LPATH (Graph G, bool flag)
{
  	vector<int> longestPath;

  	int far1, far2;

  	vector<int> v;

  	v = BFS_SPATH(G,0,flag);
	far1 = max_element(v.begin(), v.end()) - v.begin(); // farthest element from 0

  	v = BFS_SPATH(G,far1,flag);
  	far2 = max_element(v.begin(), v.end()) - v.begin(); // farthest element from far1

  	longestPath.push_back(far1);
  	longestPath.push_back(far2);

  	return longestPath;
}
