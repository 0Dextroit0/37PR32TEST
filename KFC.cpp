#include "KFC.h"

KFC::KFC()
{
	amountOfOrders = 0;
	arr = NULL;
}

KFC::~KFC()
{
	if (amountOfOrders > 0) delete[] arr;
}

void KFC::addOrder(Order* obj)
{
	Order** tmp = new Order*[++amountOfOrders];
	for (int i = 0; i < amountOfOrders - 1; i++)
	{
		tmp[i] = arr[i];
	}
	if (arr != NULL) delete[] arr;
	tmp[amountOfOrders - 1] = obj;
	arr = tmp;
}//

void KFC::sortByTime()
{
	for (int i = 0; i < amountOfOrders; i++)
	{
		for (int j = 0; j < amountOfOrders - 1 - i; j++)
		{
			if (arr[j + 1]->getFinishTime() < arr[j]->getFinishTime()) {
				swap(arr[j + 1], arr[j]);
			}
		}
	}
}

void KFC::showTable()
{
	sortByTime();
	for (int i = 0; i < amountOfOrders; i++)
	{
		Time_ t = arr[i]->getFinishTime();
		cout << t << " " << arr[i]->getIdOrder() << endl;
	}
}

void KFC::takeOrder()
{
	sortByTime();
	if (amountOfOrders > 0)
	{
		cout << "Ready order: \n";
		cout << *arr[0] << endl;
		delete arr[0];

		--amountOfOrders;
		for (int i = 0; i < amountOfOrders; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
}

ostream & operator<<(ostream & out, KFC & obj)
{
	// TODO: insert return statement here
	return out;
}
