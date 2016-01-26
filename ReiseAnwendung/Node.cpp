#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>

#include "Node.h"
using namespace std;

// static initialization
int Node::s_numInstances = 0;

Node::Node()
{
	s_numInstances++;

	stringstream s;
	s << "Node_" << setw(4) << setfill('0') << s_numInstances;
	m_id = s.str();
}


Node::Node(std::string id) : m_id(id)
{ 
	s_numInstances++; 

	for (unsigned int i = 0; i < id.length(); i++)
	{
		if ( !isalnum(id[i]) )
		{
			throw "Falsche Node-ID angegeben!";
		}
	}
}