#include "Edge.h"


std::string Edge::toString() const
{
	std::string result;
	result = m_rSrc.getID() + " -> " + m_rDst.getID();
	return result;

	// return m_Src.getID() + " -> " + m_Dst.getID();
}