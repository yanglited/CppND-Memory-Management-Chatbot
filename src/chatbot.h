#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <string>
#include <wx/bitmap.h>

class GraphNode;  // forward declaration
class ChatLogic;  // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap* _image;  // avatar image

    // data handles (not owned)
    GraphNode* _currentNode;
    GraphNode* _rootNode;
    ChatLogic* _chatLogic;

    // proprietary functions
    static int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                                      // constructor WITHOUT memory allocation
    explicit ChatBot(const std::string& filename);  // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(ChatBot const& source);                 // copy constructor
    ChatBot& operator=(ChatBot const& source);      // copy assignment operator
    ChatBot(ChatBot&& source) noexcept;             // move constructor
    ChatBot& operator=(ChatBot&& source) noexcept;  // move assignment operator

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode* node);
    void SetRootNode(GraphNode* rootNode)
    {
        _rootNode = rootNode;
    }
    void SetChatLogicHandle(ChatLogic* chatLogic)
    {
        _chatLogic = chatLogic;
    }
    wxBitmap* GetImageHandle()
    {
        return _image;
    }

    // communication
    void ReceiveMessageFromUser(const std::string& message);
};

#endif /* CHATBOT_H_ */