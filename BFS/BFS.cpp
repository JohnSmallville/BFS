// BFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stack>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef int Vertex;

typedef std::vector < std::list < int > > Graph;

Graph graph;

void BFS(Graph *graph) {

}

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream ifstr("input.txt");
	int v_num, e_num;
	ifstr >> v_num >> e_num; // количество вершин, количество ребер с весом (откуда, куда)
	graph.resize(v_num);
	for (int i = 0; i < e_num; ++i) {
		int from_vertex, to_vertex;
		ifstr >> from_vertex >> to_vertex;
		graph[from_vertex].push_back(to_vertex);
	}
	getchar();
	return 0;
}

