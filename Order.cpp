#include "Order.h"

Order::Order()
{
    date = Date();
    time = Time_();
    description = new char[6];
    strcpy_s(description, 6, "empty");
    duration = 0;
    price = 0;
    idOrder = ++count;

}

Order::Order(const char* description, int duration, float price)
    
{
    date = Date();
    time = Time_();
    
    this->description = new char[strlen(description)] + 1;
    strcpy_s(this-> description, strlen(description) + 1, description);
    this->duration = duration;
    this -> price = price;
    this->idOrder = ++count;
}

Order::~Order()
{
    if (description != NULL) delete[] description;
}

Order::Order(const Order& obj)
{
    this->description = new char[strlen(obj.description) + 1];
    strcpy_s(this->description, strlen(obj.description) + 1, obj.description);
    this->date = obj.date;
    this->time = obj.time;
    this->duration = obj.duration;
    this->price = obj.price;
    this->idOrder = obj.idOrder;
}

Order& Order::operator=(const Order& obj)
{
    this->description = new char[strlen(obj.description) + 1];
    strcpy_s(this->description, strlen(obj.description) + 1, obj.description);
    this->date = obj.date;
    this->time = obj.time;
    this->duration = obj.duration;
    this->price = obj.price;
    this->idOrder = obj.idOrder;
    return *this;
}

Date Order::getDate()
{
    return date;
}

Time_ Order::getTime()
{
    return time;
}

const char* Order::getDescription()
{
    return description;
}

int Order::getDuration()
{
    return duration;
}

Time_ Order::getFinishTime()
{
    return time + duration * 60;
}

float Order::getPrice()
{
    return price;
}

int Order::getIdOrder()
{
    return idOrder;
}

bool Order::operator<(const Order& obj)
{
    if (this->date < obj.date)return true;
    else if (this->date == obj.date && this->time < obj.time)return true;
    else return false;
}

ostream& operator<<(ostream& out, Order& obj)
{
    out << "==============================================\n";
    out << "\t Order# " << obj.idOrder << endl;
    out << "==============================================\n";
    out << "Date: " << obj.date << endl;
    out << "Time: " << obj.time << endl;
    out << "Description: " << obj.description << endl;
    out << "==============================================\n";
    out << "Price: " << obj.price << endl;
    Time_ t = obj.getFinishTime();
    out << "Finish time: " << t << endl;
    out << "==============================================\n";
    return out;
}

istream& operator>>(istream& in, Order& obj)
{
    char tmp[100] = "";
    cout << "Input description: "; in >> tmp;
    if (obj.description != NULL) delete[] obj.description;
    obj.description = new char[strlen(tmp) + 1];
    strcpy_s(obj.description, strlen(tmp) + 1, tmp);
    cout << "Input date and time: ";
    do { in >> obj.date; } while (obj.date < Date());
    do { in >> obj.time; } while (obj.date < Date() || obj.time < Time_());
    cout << "Input duration: "; in >> obj.duration;
    cout << "Input price: "; in >> obj.price;
    return in;
}