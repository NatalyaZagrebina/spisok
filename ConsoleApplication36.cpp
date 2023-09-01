// ConsoleApplication36.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <string.h>
using namespace std;

struct Delo // создаем структуру дело
{
    string name;
    int priority;
    string description;
    string date;
    string toString()
    {
        return "имя: " + name + ", приоритет: " + to_string(priority) + ", описание: " + description + ", дата: " + date;
    };
};

void deleteDelo(Delo* mas, int& count, int index) // функция удаления дела
{
    char confirm; //утверждать
    cout << "Вы действительно хотите удалить дело " << mas[index].name << "? (y/n): ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
    {
        for (int i = index; i < count - 1; i++)
        {
            mas[i] = mas[i + 1]; // сдвигаем элементы массива на один влево
        }
        mas[count - 1].name = ""; // заменяем последний элемент на пустую строку
        cout << "Дело " << mas[index].name << " успешно удалено." << endl;
        count--;
    }
    else
    {
        cout << "Отмена операции." << endl;
    }
}

void inputDelo(Delo& delo) // функция открыть дело
{
    cout << "Введите название дела: ";
    getline(cin, delo.name);
    cout << "Введите приоритет дела: ";
    cin >> delo.priority;
    cin.ignore(); // чтобы очистить символ новой строки из буфера потока
    cout << "Введите описание дела: ";
    getline(cin, delo.description);
    cout << "Введите дату дела в формате день/месяц/год: ";
    getline(cin, delo.date);
}

void editDelo(Delo* mas, int count, int index) // функция редактировать дело
{
    if (index >= count)
    {
        cout << "Такого дела не существует" << endl;
        return;
    }
    cout << "Введите новое имя дела: ";
    getline(cin, mas[index].name);
    cout << "Введите новый приоритет дела: ";
    cin >> mas[index].priority;
    cin.ignore();
    cout << "Введите новое описание дела: ";
    getline(cin, mas[index].description);
    cout << "Введите новую дату дела в формате день/месяц/год: ";
    getline(cin, mas[index].date);
}

void findDelo(Delo* mas, int count, int priority, string name = "", string description = "", string date = "") // находить дело
{
    for (int i = 0; i < count; i++)
    {
        if (mas[i].priority == priority && (name.empty() || mas[i].name == name) && (description.empty() || mas[i].description == description) && (date.empty() || mas[i].date == date))
        {
            cout << "Найдено дело с приоритетом " << priority << ":" << endl;
            cout << "Название: " << mas[i].name << endl;
            cout << "Описание: " << mas[i].description << endl;
            cout << "Дата: " << mas[i].date << endl;
            return;
        }
    }
    cout << "Дело с приоритетом " << priority << " не найдено." << endl;
}
void vivodDelo(Delo* mas, int count, int index = -1)
{
    if (index == -1)

        for (int i = 0; i < count; i++)
        {
            cout << mas[i].toString() << endl;
        }
    else 
    {
        if (index > -1 && index < count)
            cout << mas[index].toString() << endl;
        else
            cout << "индекс введен не верно " << endl;
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 10;
    Delo mas[size];
    int count = 0;
    int choice = 0; // выбор, инициализируем значением, отличным от 5
    int priority{};
    string name{};
    string description{};
    string date{};
    do
    {
        system("cls"); // очистить экран
        cout << "1. Добавить дело" << endl;
        cout << "2. Редактировать дело" << endl;
        cout << "3. Удалить дело" << endl;
        cout << "4. Найти дело" << endl;
        cout << " 5. Вывод на экран списка дел" << endl;
        cout << "6. Выйти из программы" << endl;



        cin >> choice; // выбор
        cin.ignore(); // очистить символ новой строки из буфера потока
    
    switch(choice) 
    {
    case 1:
        if (count < size)
        {
            inputDelo(mas[count]);
            count++;
        }
        else
        {
            cout << "Достигнуто максимальное количество дел." << endl;
        }
        break;
    case 2:
        int index;
        cout << "Введите индекс дела, которое хотите изменить: ";
        cin >> index;
        cin.ignore();
        editDelo(mas, count, index);
        break;
    case 3:
        int delIndex;
        cout << "Введите индекс дела, которое хотите удалить: ";
        cin >> delIndex;
        cin.ignore();
        deleteDelo(mas, count, delIndex);
        break;
    case 4:
        
        cout << "Введите приоритет дела: ";
        cin >> priority;
        cin.ignore(); // очистить символ новой строки из буфера потока
        cout << "Введите название дела (пусто, если не важно): ";
        getline(cin, name);
        cout << "Введите описание дела (пусто, если не важно): ";
        getline(cin, description);
        cout << "Введите дату дела в формате день/месяц/год (пусто, если не важно): ";
        getline(cin, date);
        findDelo(mas, count, priority, name, description, date);
        break;
    case 5:
        vivodDelo(mas,count);
        system("pause");
        break;
    case 6:
        break;
    
        
    default:
        cout << "Введите корректный номер операции." << endl;
    }
    } while (choice != 6);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
