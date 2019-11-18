#ifndef TEMPLATEQUEUE_H
#define TEMPLATEQUEUE_H

#endif // TEMPLATEQUEUE_H

#include <mutex>

template <typename T> struct Node
{
    Node<T> *next, *previous;
    T data;

    Node<T>(T _data)
    {
        this->next = this->previous = nullptr;
        this->data = _data;
    }
};

template <typename T> struct Queue
{
    Node<T> *first, *last;
    std::mutex mutex;

    Queue<T>()
    {
        this->first = this->last = nullptr;
    }

    bool isEmpty(){
        bool empty = this->first == nullptr;
        return empty;
    }

    void queue(T data)
    {
        if (this->isEmpty()){
            this->last = this->first = new Node<T>(data);
        }
        else{
            this->last->next = new Node<T>(data);
            this->last = this->last->next;
        }
    }

    void push(T data)
    {
        if (this->isEmpty()){
            this->last = this->first = new Node<T>(data);
        }
        else{
            Node<T>* nuevo = new Node<T>(data);
            nuevo->next= this->first;
            this->first=nuevo;
        }
    }

    T dequeue(){
        Node<T> * borrado = first;
        if(!isEmpty()){
            first = first->next;
            borrado->next = nullptr;
            return borrado->data;
        }
        else{
            return nullptr;
        }

    }



    int getSize(){
        Node<T> * tmp = first;
        int size = 0;
        while (tmp != nullptr){
            size++;
            tmp = tmp->next;
        }
        return size;
    }

};
