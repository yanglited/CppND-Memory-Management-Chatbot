#include "graphnode.h"
#include "graphedge.h"

GraphNode::GraphNode(int id)
    : _chatBot {nullptr}
    , _id {id}

{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // Bug fix, removed delete of _chatBot. The GraphNode class does not own the resource.

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string const& token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge* edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot* chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode* newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr;  // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge* GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}