#include "main.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <iterator>
#include <string>
#define LOG(X) std::cout << std::endl << X << std::endl;
using namespace std;

int main(){
    sList<int> l1;
    assert(l1.size()==0);
    l1.push_back(1);
    l1.push_back(2);
    assert(l1.size()==2);
    l1.pop_front();
    assert(l1.size()==1);
    l1.pop_front();
    assert(l1.size()==0);

    sList<int> l2;
    for(int i = 0; i < 100; i=i+2){
        l2.push_back(i);
    }
    //l2.print();
    assert(l2.size() == 50);
    l2.pop_front();
    assert(l2.size() == 49);

    LOG(l2[0]);
    l2[0] = 100;
    assert(l2.front() == 100);

    //l2.print();
    l2.clear();
    //l2.print();
    assert(l2.size() == 0);


    sList<sList<string>> large_list;
    
    string name;
    LOG("What is your Name?: ")
    cin >> name;
    cin.clear();

    string opinion;
    if((name.length() - 1) > 6){
        opinion = "shit";
    }
    else{opinion = "good";}
    
    vector<string> g_data = {"Hi","my", "name","is","Randy"};
    vector<string> b_data = {"See","you", "soon"};
    vector<string> secret_message = {name, "is", "a", opinion, "name"};

    sList<string> greeting(g_data);
    sList<string> bye(b_data);
    sList<string> message(secret_message);


    large_list.push_back(greeting);
    large_list.push_back(bye);
    large_list.push_back(message);

    large_list[2].print();

}
