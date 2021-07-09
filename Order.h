#pragma once
#include "Date.h"
#include "Time_.h"
class Order
{
    Date date;
    Time_ time;
    char* description;
    int duration;
    float price;
    int idOrder;
    static int count;

public:
    Order();
    Order(const char* description, int duration, float price);
    ~Order();
    Order(const Order& obj);
    Order& operator = (const Order& obj);
    
    Date getDate();
    Time_ getTime();
    const char* getDescription();
    int getDuration();
    Time_ getFinishTime();
    float getPrice();
    int getIdOrder();

    bool operator<(const Order& obj);
    friend ostream& operator << (ostream& out, Order& obj);
    friend istream& operator >> (istream& in, Order& obj);
};