#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include "Node.h"
#include "Edge.h"

class Graph
{

public:

	struct tDijkstraEntry
	{
		double dist;
		Node* prevNode;
		Edge* prevEdge;
	};

	typedef std::list<Node*> tNodeList;
	typedef std::map<Node*, tDijkstraEntry> tDijkstraMap;
    typedef std::deque<Edge*> tPath;


	~Graph();

	Node& addNode(Node* pNode);
	void addEdge(Edge* pEdge);

	void deleteNode(Node* pNode);
	void deleteEdge(Edge* pEdge);

	void saveAsDot(const std::string& rFilename);

	bool findShortestPathDijkstra(tPath& rPath, Node* pSrcNode, Node* pDstNode);


protected:

	std::list<Node*> m_nodes;
	std::list<Edge*> m_edges;
};

#endif