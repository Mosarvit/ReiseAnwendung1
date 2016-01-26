#include "Graph.h"
#include <list>
#include <fstream>
#include <algorithm>


//---------------------------------------------------------------------------------------------------------------------

Graph::~Graph()
{

	for (std::list<Node*>::iterator it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
		delete (*it);
	}

	for (std::list<Edge*>::iterator it = m_edges.begin(); it != m_edges.end(); it++)
	{
		delete (*it);
	}

}


//---------------------------------------------------------------------------------------------------------------------

Node& Graph::addNode(Node* pNode)
{
	m_nodes.push_back(pNode);
    return *pNode;
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::addEdge(Edge* pEdge)
{
	m_edges.push_back(pEdge);
	pEdge->getSrcNode().getOutgoingEdges().push_back(pEdge);
	pEdge->getDstNode().getIncomingEdges().push_back(pEdge);
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::deleteNode(Node* pNode)
{
	typedef std::list<Edge*>::iterator tEdgeListIter;

	std::list<Edge*>& rIncoming = pNode->getIncomingEdges();
	std::list<Edge*>& rOutgoing = pNode->getOutgoingEdges();

	for (tEdgeListIter it = rIncoming.begin(); it != rIncoming.end(); it++)
	{
		/*
		std::list<Edge*>::iterator itEdge = std::find(m_edges.begin(), m_edges.end(), (*it) );
		if (itEdge != m_edges.end())
		{
			m_edges.erase(itEdge);
		}
		*/
		m_edges.remove((*it));
		delete *it;
	}

	for (tEdgeListIter it = rOutgoing.begin(); it != rOutgoing.end(); it++)
	{
		m_edges.remove((*it));
		delete *it;
	}

	m_nodes.remove(pNode);
	delete pNode;
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::deleteEdge(Edge* pEdge)
{
	pEdge->getSrcNode().getOutgoingEdges().remove(pEdge);
	pEdge->getDstNode().getIncomingEdges().remove(pEdge);
	m_edges.remove(pEdge);
	delete pEdge;
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::saveAsDot(const std::string& rFilename)
{
	std::fstream f;
	f.open(rFilename, std::fstream::out);

	f << "digraph {" << std::endl;

	for (int i = 0; i < 10; i++) { 
	
	}

	typedef std::list<Node*>::iterator tNodeListIter;
	typedef std::list<Edge*>::iterator tEdgeListIter;

	for (tNodeListIter it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
		Node* pCurrentNode = (*it);
		f << pCurrentNode->getID() << ";" << std::endl;
	}

	for (tEdgeListIter it = m_edges.begin(); it != m_edges.end(); it++)
	{
		f << (*it)->toString() << ";" << std::endl;
	}

	f << "}" << std::endl;

	f.close();
}


//---------------------------------------------------------------------------------------------------------------------

/*
 * Dijkstra-Algorithmus (vgl. https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
 */
bool Graph::findShortestPathDijkstra(std::deque<Edge*>& rPath, Node* pSrcNode, Node* pDstNode)
{
	tNodeList Q;				// Liste der noch zu betrachtenden Knoten
	tDijkstraMap nodeEntry;		// Datenstruktur für prevNode, prevEdge, dist (für jeden Node)

	//Initialisierung
	for (tNodeList::iterator it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
		Node* pCurrNode = *it;
		Q.push_back(pCurrNode);

		tDijkstraEntry entry;
		entry.dist = 10000000;
		entry.prevNode = NULL;
		entry.prevEdge = NULL;

		nodeEntry[pCurrNode] = entry;
	}

	nodeEntry[pSrcNode].dist = 0;

	// Start des Algorithmus
	while (!Q.empty())
	{
		// Finde Node mit der kleinsten gespeicherten Distanz
		Node* pCurrentNode = Q.front();
		for (tNodeList::iterator it = Q.begin(); it != Q.end(); it++)
		{
			if (nodeEntry[pCurrentNode].dist > nodeEntry[*it].dist)
			{
				pCurrentNode = *it;
			}
		}
		tDijkstraEntry& rCurrNodeEntry = nodeEntry[pCurrentNode];
		// Aktuellen Knoten aus der Liste der zu betrachtenden Knoten entfernen
		Q.remove(pCurrentNode);

		// Falls der aktuelle Knoten mit der kleinsten Distanz der Zielknoten ist -> abbrechen (fertig)
		if (pCurrentNode == pDstNode)
		{
			break;
		}

		std::list<Edge*>& rOutEdges = pCurrentNode->getOutgoingEdges();

		// Alle ausgehenden Kanten des aktuellen Knotens durchsuchen
		for (std::list<Edge*>::iterator it = rOutEdges.begin(); it != rOutEdges.end(); it++)
		{
			Node* pNeighbour = &((*it)->getDstNode());
			tDijkstraEntry& rNeighbourEntry = nodeEntry[pNeighbour];

			double newDistance = rCurrNodeEntry.dist + (*it)->getWeight();
			if (newDistance < rNeighbourEntry.dist)
			{
				rNeighbourEntry.dist = newDistance;
				rNeighbourEntry.prevNode = pCurrentNode;
				rNeighbourEntry.prevEdge = *it;
			}
		}
	}

	// Den Weg in 'rPath' speichern.
	for (Node* n = pDstNode; n != NULL; n = nodeEntry[n].prevNode)
	{
		if (nodeEntry[n].prevEdge != NULL)
		{
			rPath.push_front(nodeEntry[n].prevEdge);
		}
	}

	return !rPath.empty();
}


//---------------------------------------------------------------------------------------------------------------------
