#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
private:
    string value;
    int id;
    static int next_id;
public: 
    Message() {}
    Message(string text) 
    {
        value = text; 
        id = next_id; 
        next_id++; 
    }
    const string& get_text() 
    {
        return value;
    }
    bool operator < (const Message& msg)
    {
        return (this->id < msg.id);
    }
};
int Message::next_id = 0;

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) 
    {
        Message mess(text);
        return mess;
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    cout << "Please enter the message that you want shuffled and returned in the original order." << endl;
    cout << "The message will be shuffled by line. To end the message press contrl + D" << endl;
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}