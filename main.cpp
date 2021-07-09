#include "KFC.h"

int Order::count = 0;//инициализация статического поля до создания объектов

int main() {
    int menu = 0;
    char tmp[100] = "";
    float b;
    float a;
    KFC kfc;
    //KFC kfc;
    //kfc.addOrder(new Order("ice", 45, 200));
    //kfc.addOrder(new Order("pizza", 15, 200));
    //kfc.addOrder(new Order("burg", 30, 200));
    //kfc.showTable();
  //  Order order1 ;
  //  Order order2( "pizza", 15, 200);
  //  Order order3;
  ////  cin >> (order3);
  //
  //  cout << (order1) << endl;
  //  cout << (order2) << endl;
  //  cout << (order3) << endl;
    do
    {
        cout << "======================MENU======================\n";
        cout << "\t1 - Add order\n";
        cout << "\t2 - Show table of ready orders\n";
        cout << "\t3 - Show all orders\n";
        cout << "\t4 - Take order\n";
        cout << "================================================\n";
        cin >> menu;
        system("cls");
        switch (menu)
        {
        case 1: cout << "Input description of order: \n"; cin.get(); cin.getline(tmp, 100);
            cout << "Input price: \n"; cin >> b;
            cout << "Input time: \n"; cin >> a;
            kfc.addOrder(new Order(tmp, a, b));
            break;
        case 2:kfc.showTable(); break;
        case 4:kfc.takeOrder(); break;
        case 0: cout << "Goodbye !=)\n";
            break;
        default: cout << "Switch error: menu\n";
            break;
        }
    } while (menu);
    system("pause");
    return 0;
}