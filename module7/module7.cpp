#include <iostream>
#include "assert.h"
#include "IntegerArray.h"
#include <stdexcept>
using namespace std;
using namespace module_7;

class IntegerArrayTests
{    
    public:
        void Test_Constructor()
        {
            IntegerArray array{};
            assert(array.GetLength() == 0 && "Неверня работа конструктора по умолчанию");
            IntegerArray array1{ 0 };
            assert(array1.GetLength() == 0 && "Неверня работа конструктора при значении 0");
            IntegerArray array2{ 5 };
            assert(array2.GetLength() == 5 && "Неверня работа конструктора при значении 5");

            IntegerArray array3{ 4 };
            for (int i = 0; i < array3.GetLength(); i++)
            {
                array3[i] = i;
            }            
            IntegerArray array4{ array3 };
            assert(array4.GetLength() == 4 && "Неверня работа конструктора копирования");
            for (int i = 0; i < array4.GetLength(); i++)
            {
                assert(array4[i] == i && "Неверня работа конструктора копирования");
            }
            cout << "Тестирование конструкторов выполнено без ошибок" << endl;
        }

        void Test_Resize()
        {
            IntegerArray array{};
            array.Resize(8);
            assert(array.GetLength() == 8 && "Невернаяработа метода Resize");
            array.Resize(7);
            assert(array.GetLength() == 7 && "Невернаяработа метода Resize");
            for (int i = 0; i < array.GetLength(); i++)
            {
                array[i] = i;
            }
            array.Resize(5);
            for (int i = 0; i < array.GetLength(); i++)
            {
                assert(array[i] == i && "Неверная работа метода Resize");
            }
            cout << "Тестирование Resize выполнено без ошибок" << endl;
        }

        void Test_InsertBefore()
        {
            IntegerArray array{10};                        
            array.InsertBefore(131, 4);
            assert(array.GetLength() == 11 && "Неверная работа InsertBefore");
            assert(array[4] == 131 && "Неверная работа InsertBefore");
            try
            {
                array.InsertBefore(432, 12);
                assert(false && "Неверная работа InsertBefore");
            }
            catch (const out_of_range&){}
            try
            {
                array.InsertBefore(423, -1);
                assert(false && "Неверная работа InsertBefore");
            }
            catch (const out_of_range&) {}
            cout << "Тестирование InsertBefore выполнено без ошибок" << endl;
        }

        void Test_InsertBegin()
        {
            IntegerArray array{ 10 };
            array.InsertBegin(122);
            assert(array[0] == 122 && "Неверная работа InsertBegin");
            assert(array.GetLength() == 11 && "Неверная работа InsertBegin");
            cout << "Тестирование InsertBegin выполнено без ошибок" << endl;
        }

        void Test_InsertEnd()
        {
            IntegerArray array{ 10 };
            array.InsertEnd(122);
            assert(array[10] == 122 && "Неверная работа InsertBegin");
            assert(array.GetLength() == 11 && "Неверная работа InsertBegin");
            cout << "Тестирование InsertEnd выполнено без ошибок" << endl;
        }

        void Test_IndexOf()
        {
            IntegerArray array{ 10 };
            for (int i = 0; i < array.GetLength(); i++)
            {
                array[i] = i;
            }
            int index = array.IndexOf(6);
            assert(index == 6 && "Неверная работа IndexOf");
            cout << "Тестирование IndexOf выполнено без ошибок" << endl;
        }

        void Test_Remove()
        {
            IntegerArray array{ 10 };
            for (int i = 0; i < array.GetLength(); i++)
            {
                array[i] = i;
            }
            array.Remove(5);
            assert(array.GetLength() == 9 && "Неверная работа Remove");
            assert(array.IndexOf(5) == -1 && "Неверная работа Remove");
            cout << "Тестирование Remove выполнено без ошибок" << endl;
        }

        void Test_Indexator()
        {
            IntegerArray array{ 10 };
            for (int i = 0; i < array.GetLength(); i++)
            {
                array[i] = i;
            }
            try
            {
                cout << array[11];
                assert(false && "Неверная работа Indexator");
            }
            catch (const out_of_range&){}
            try
            {
                cout << array[-1];
                assert(false && "Неверная работа Indexator");
            }
            catch (const out_of_range&){}

            int result = array[5];
            assert(result == 5 && "Неверная работа Indexator");

            cout << "Тестирование Indexator выполнено без ошибок" << endl;
        }


};


int main()
{
    setlocale(LC_ALL, "");    
    IntegerArrayTests tests;
    tests.Test_Constructor();
    tests.Test_Resize();
    tests.Test_InsertBefore();
    tests.Test_InsertBegin();
    tests.Test_InsertEnd();
    tests.Test_IndexOf();
    tests.Test_Remove();
    tests.Test_Indexator();
    return 0;
}

