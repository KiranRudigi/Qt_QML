#ifndef LINKEDL_H
#define LINKEDL_H
#include <iostream>
#include <QRegion>
#include <QString>
#include <QDebug>

template<class T>
class linkedL
{
public:linkedL(){
        count = 0;
        head = NULL;
    }

    T getValueAt(int index)
    {
        Node* temp;
        temp = head;
        int n = 0;
        if(temp->link == NULL)
            return temp->data;
        while(temp!=NULL)
        {
//            std::cout<<"Inside while"<<std::endl;
            if(n == index)
            {
//                std::cout<<temp->data<<std::endl;
                return temp->data;
            }
            temp = temp->link;
            n++;
        }
        return 0;
    }

    class Node{
    public:
        T data;
        Node* link;
    };

    Node* getAdOf(int index)
    {
        Node* temp;
        temp = head;
        int n = 0;
        while(temp!=NULL)
        {
//            std::cout<<"Inside while"<<std::endl;
            if(n == index)
            {
//                std::cout << "Address " << temp<<std::endl;
                void **p = (void**)&temp;
                int x = (int)*p;
                QString str = QString::number(x);
//                qDebug() << "Str" << str;
                return (temp);
            }
            temp = temp->link;
            n++;
        }
        return NULL;
    }
    int count;
    Node* head;

    Node* insert(T item)
    {
        Node *node = new Node;
        node->data = item;
        node->link = NULL;
        count++;
        std::cout<<"Inserted "<<item<<std::endl;
        if(head == NULL)
        {
            return node;
        }
        else
        {
            Node* temp;
            temp = head;
            while(temp->link!=NULL)
            {
                temp = temp->link;
            }
            temp->link = node;
        }
        return head;
    }
    Node* del(int key)
    {
        Node* temp;
        Node* prev;
        temp = head;
        prev = NULL;
        if(head == NULL)
        {
            std::cout<<"List is empty"<<std::endl;
            return NULL;
        }
        count--;
        if(temp->data == key)
        {
            std::cout<<"Deleted "<<temp->data<<std::endl;
            prev = temp->link;
            delete(temp);
            return prev;
        }
        while(temp->data != key)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = temp->link;
        std::cout<<"Deleted "<<temp->data<<std::endl;
        delete(temp);
        return head;
    }
    void display()
    {
        Node* temp;
        if(head == NULL)
        {
            std::cout<<"List is empty"<<std::endl;
            return;
        }
        std::cout<<"CONTENTS"<<std::endl;
        temp = head;
        while(temp!=NULL)
        {
            std::cout<<temp->data<<" ";
            temp = temp->link;
        }
        std::cout<<std::endl;
    }
};

#endif // LINKEDL_H
