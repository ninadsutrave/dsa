template <typename T>
class List {

    private: 
    struct ListNode {
        T data;
        ListNode* next;
        ListNode (const T& data) {
            this->data = data;
            next = nullptr;
        }
    };
    ListNode* headNode;
    ListNode* tailNode;

    public:
    List() {
        headNode = tailNode = nullptr;
    }

    ~List() {
        while(size()) {
            remove
        }
    }

};