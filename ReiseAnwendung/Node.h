#ifndef NODE_H
#define NODE_H
#include <string>

#include <list>
class Edge;

class Node
{
public:

	typedef std::list<Edge*> tEdgeList;

	Node();

	Node(std::string id);

	std::string getID() const { return m_id; }

	tEdgeList& getOutgoingEdges() { return m_outgoingEdges; }
	tEdgeList& getIncomingEdges() { return m_incomingEdges; }

private:
	std::string m_id;

	tEdgeList m_outgoingEdges;
	tEdgeList m_incomingEdges;

	static int s_numInstances;
};

#endif