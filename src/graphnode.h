#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <memory>
#include <string>
#include <vector>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    std::vector<GraphEdge*> _parentEdges;  // edges to preceding nodes
    ChatBot                 _chatBot;      // The chat bot instance handle(?), not owned

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int                      _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    explicit GraphNode(int id);
    ~GraphNode();

    // getter / setter
    [[nodiscard]] int GetID() const
    {
        return _id;
    }
    int GetNumberOfChildEdges()
    {
        return static_cast<int>(_childEdges.size());
    }
    GraphEdge*               GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers()
    {
        return _answers;
    }
    int GetNumberOfParents()
    {
        return static_cast<int>(_parentEdges.size());
    }

    // proprietary functions
    void AddToken(std::string const& token);  // add answers to list
    void AddEdgeToParentNode(GraphEdge* edge);
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);

    //// STUDENT CODE
    ////

    void MoveChatbotHere(ChatBot chatBot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode* newNode);
};

#endif /* GRAPHNODE_H_ */