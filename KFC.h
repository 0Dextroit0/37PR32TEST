#pragma once
#include "Order.h"
class KFC
{
	Order** arr;
	int amountOfOrders;

public:
	KFC();
	~KFC();
	void addOrder(Order* obj);
	void sortByTime();
	void showTable();
	void takeOrder();

	friend ostream& operator << (ostream& out, KFC& obj);
};

