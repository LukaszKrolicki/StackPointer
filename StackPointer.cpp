#include <iostream>
using namespace std;


class Element{
private:
    int v;
    Element* next;
public:
    Element(int x, Element* next);
    int getValue();
    Element* getNext();
    void setNext(Element *p);
};

Element::Element(int x, Element* next){
    next=next;
    v=x;
}
void Element::setNext(Element *p){
    next=p;
}
int Element::getValue(){
    return v;
}
Element* Element::getNext(){
    return next;
}

class LinkedStack{
private:
    Element *top;
public:
    LinkedStack();
    bool empty();
    void push(int x);
    int peek();
    void pop();
    void clear();
    friend ostream& operator<<(ostream& out, LinkedStack* l);
    ~LinkedStack();
};

LinkedStack::LinkedStack(){
    top=nullptr;
}

LinkedStack::~LinkedStack(){
    clear();
}

bool LinkedStack::empty(){
    if(top==nullptr){
        return true;
    }
    else{
        return false;
    }
}

void LinkedStack::push(int x){
    Element* e = new Element(x, top);
    e->setNext(top);
    top=e;
}

int LinkedStack::peek(){
    if(empty()){
        cout<<"Stack empty error:";
        return 420;
    }
    else{
        return top->getValue();
    }
}

void LinkedStack::pop(){
    if(empty()){
        cout<<"Stos empty";
    }
    else{
        Element* x= top->getNext();
        delete top;
        top=x;
    }
}

void LinkedStack::clear(){
    while(empty()==false){
        pop();
    }
}

ostream& operator<<(ostream& out, LinkedStack* l){
    if(l->empty()){
        cout<<"stos empty"<<endl;
    }
    else{
        while(l->top->getNext()!=nullptr){
            out<<l->peek()<<endl;
            l->top = l->top->getNext();
        }
        out<<l->peek()<<endl;
    }
}

int main()
{
    //Example

    LinkedStack* l = new LinkedStack();


    cout<<"Peek: ";
    cout<<l->peek()<<endl;
    l->push(1);
    cout<<"Peek: ";
    cout<<l->peek()<<endl;
    l->push(2);
    cout<<"Peek: ";
    cout<<l->peek()<<endl;
    l->push(3);
    cout<<"Peek: ";
    cout<<l->peek()<<endl;


    l->pop();
    cout<<"Peek: ";
    cout<<l->peek()<<endl;

    l->pop();
    cout<<"Peek: ";
    cout<<l->peek()<<endl;

    l->pop();
    l->pop();

    cout<<endl;


    l->push(1);
    cout<<"Peek: ";
    cout<<l->peek()<<endl;
    l->push(2);
    cout<<"Peek: ";
    cout<<l->peek()<<endl;
    l->push(3);
    cout<<"Peek: ";
    cout<<l->peek()<<endl;
    cout<<l;
    l->clear();
    cout<<"Peek: ";
    cout<<l->peek()<<endl;
    cout<<l;

}
