#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include <iterator>
#define LOG(X) std::cout << std::endl << X << std::endl;

template <typename T>
class sList {
    public:
        sList() : first(nullptr), last(nullptr){}

        sList( std::vector<T> data){
            first = nullptr;
            last = nullptr;
            for( typename std::vector<T>::iterator it = data.begin(); it != data.end(); it++){
                push_back(*it);
            }
            
        }

        T& operator[](int index){
            if(index < 0 || index > (size())){
                LOG("USER ERROR");
                assert(false);
            }
            node* Iteratornode = first;
            for(int i = 0; i < index; i++){
                Iteratornode = Iteratornode->next;
            }
            return Iteratornode->data;
        }

        void push_back(T val){
            node* newnode = new node; //new operator returns a pointer
            newnode->data = val;
            if(size() == 0){
                first = newnode;
                last = newnode;
                first->next = nullptr;
                last->next = nullptr;
                newnode->next = nullptr;
                return;
            }
            else{
                node* oldlast = last;
                oldlast->next = newnode;
                newnode->next = nullptr;
                last = newnode;
            }
        }
        void pop_front(){ //singly linked only pop front
            if(size()==0){
                LOG("USER ERROR");
                assert(false);
                return;
            }
            if(size() == 1){
                node* oldfirst = first;
                first = nullptr;
                last = nullptr;
                delete oldfirst;
                return;
            }
            node* oldfirst = first;
            node* newfirst = first->next;
            first = newfirst;
            delete oldfirst;
        }

        int size(){
            if(first == nullptr || last == nullptr){
                return 0;
            }

            int n = 1;
            
            node* iteratornode = first;
            while(iteratornode->next != nullptr){
                iteratornode = iteratornode->next;
                n++;
            }
            return n;
        }
        void print(){
            LOG("List Items: ")
            node* iteratornode = first;
            while(iteratornode != nullptr){
                LOG(iteratornode->data);
                iteratornode = iteratornode->next;
            }
            LOG("END OF LIST")
        }

        T front(){
            return first->data;
        }

        void clear(){
            while(size() != 0){
                pop_front();
            }
            return;
        }

    private:
        struct node{
            T data;
            node* next;
        };
        node* first;
        node* last;
};
