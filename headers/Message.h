//
// Created by Administrator on 2016/3/28.
//

#ifndef LEARNCPP_MESSAGE_H
#define LEARNCPP_MESSAGE_H

#include <set>
#include <string>

#include "Folder.h"

using namespace std;

class Message {
    friend class Folder;

    friend void swap(Message &lhs, Message &rhs);

public:

    Message(const string &content = "") : content(new string(content)) {
    };

    Message(const Message &msg) : content(new string(msg.content)), parent_folders(msg.parent_folders) {
        addSelf(msg);
    };

    Message &operator=(Message &rhs);

    ~Message() {
        delete content;
        removeSelf();
    }

    void save(Folder &folder);

    void remove(Folder &folder);

private:
    string *content;
    set<Folder *> parent_folders;

    void removeSelf() {
        for (auto pf : parent_folders) {
            pf->remMsg(*this);
        }
    };

    void addSelf(const Message &msg) {
        for (auto pf : msg.parent_folders) {
            pf->addMsg(*this);
        }
    }
};


void Message::save(Folder &folder) {
    parent_folders.insert(&folder);
    folder.addMsg(*this);
}

void Message::remove(Folder &folder) {
    parent_folders.erase(&folder);
    folder.remMsg(*this);
}

Message &Message::operator=(Message &rhs) {
    auto new_content = new string(*rhs.content);
    removeSelf();
    delete content;
    parent_folders = rhs.parent_folders;
    content = new_content;
    addSelf(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    lhs.removeSelf();
    rhs.removeSelf();
    swap(lhs.content, rhs.content);
    swscanf(lhs.parent_folders, rhs.parent_folders);
    lhs.addSelf(lhs);
    rhs.addSelf(rhs);
}

#endif //LEARNCPP_MESSAGE_H
