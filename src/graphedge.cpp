#include "graphedge.h"
#include "graphnode.h"

GraphEdge::GraphEdge(int id)
    : _childNode {nullptr}
    , _parentNode {nullptr}
{
    _id = id;
}

void GraphEdge::SetChildNode(GraphNode* childNode)
{
    _childNode = childNode;
}

void GraphEdge::SetParentNode(GraphNode* parentNode)
{
    _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string const& token)
{
    _keywords.push_back(token);
}