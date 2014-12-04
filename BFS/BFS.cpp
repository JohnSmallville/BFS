// BFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef int Vertex;

typedef std::vector < std::list < int > > Graph;

Graph graph;

#define inf 0x7FFFFFFF //~бесконечность для int

void BFS(Vertex vertex) {
	std::vector <Vertex> color;// 0 == white; 1 == gray; 2 == black;
	std::vector <int> pred;
	std::vector <int> d;

	std::queue <Vertex> Q;

	color.resize(graph.size());
	pred.resize(graph.size());
	d.resize(graph.size());

	for (int i = 0; i < graph.size(); ++i) {
		color[i] = 0; //white
		d[i] = inf;
		pred[i] = 0;
	}

	color[vertex] = 1;
	d[vertex] = 0;
	pred[vertex] = 0;

	Q.push(vertex);

	while (Q.size() != 0) {
		vertex = Q.front();
		Q.pop();
		for (std::list<int>::iterator it = graph[vertex].begin(); it != graph[vertex].end(); it++) {
			if (!color[*it]) {
				color[*it] = 1;
				d[*it]++;
				pred[*it] = vertex;
				Q.push(*it);
				std::cout << *it << ' ';
			}
			std::cout << '(' << *it << ')';
		}
		std::cout << std::endl;
		color[vertex] = 2;
	}
	getchar();
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

	BFS(0);

	getchar();
	return 0;
}

