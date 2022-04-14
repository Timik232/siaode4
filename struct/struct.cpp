/*Титул учебного плана (УП) направления ВУЗа. Структура записи о плане: шифр направления (например, 090304), 
название направления, шифр профиля (например,090304_1), название профиля (например, Мобильные приложения), год начала действия УП.
Операции
1)	Заполнить запись по одному учебному плану с клавиатуры.
2)	Вставить запись в таблицу планов в начало подсписка, с одним и тем же шифром направления.
3)	Вывести названия профилей и год начала действия учебного плана заданного направления.
4)	Удалить планы срок действия которых истек при прошествии 4-х лет.
*/
#include "Header.h"
#include <iomanip>

void Input_struct(Plan& P)
{
    cout << "Enter cipher of direction\n";
    cin >> P.shifr_direct;
    cout << "Enter name of direction\n";
    cin >> P.name_direct;
    cout << "Enter cipher of profile\n";
    cin >> P.shifr_profile;
    cout << "Enter name of profile\n";
    cin >> P.name_profile;
    cout << "Enter year of start\n";
    cin >> P.start_year;
}
void Input(Table &T, Plan &P) //ввод значений структуры
{   
    bool flag = true;
    cout << "Enter max size (>0 & <100)\n";
    while (flag)
    {
        cin >> T.max_size;
        if (T.max_size <= 0 || T.max_size > 100)
            cout << "Invalid input\n";
        else flag = false;
    }
    T.cur_size = 0;
    for (int i = 0; i < T.max_size; i++)
    {
        Input_struct(P);
        T.strings[i] = P;
        T.cur_size += 1;
    }    
}
void Output(Table &T) //вывод всех данных структуры
{
    cout <<  "Cipher of direction  " << " Name of direction  " << " Cipher of profile  " << " Name of profile  " << setw(10) << " Year\n";
    for (int i = 0; i < T.cur_size; i++)
    {
        cout << setw(19) << T.strings[i].shifr_direct;
        cout << setw(20) << T.strings[i].name_direct;
        cout << setw(19) << T.strings[i].shifr_profile;
        cout << setw(18) << T.strings[i].name_profile;
        cout << setw(12) << T.strings[i].start_year;
        cout << endl;
    }
}
//Вывести названия профилей и год начала действия учебного плана заданного направления.
void print_profiles(Table &T)
{
    cout << " Name of profile  " << " Year of start \n";
    for (int i = 0; i < T.cur_size; i++)
    {
        cout << setw(15) << T.strings[i].name_profile;
        cout << setw(15) << T.strings[i].start_year;
        cout << endl;
    }
}
void Insert(Table& T, Plan &P) //вставка элемента в структуру
{
    int shifr;
    cout << "Enter cipher of direction to insert new plan\n";
    cin >> shifr;
    bool flag = false;
    int i = 0;
    int nomer = -1;
    while (!flag && i<T.max_size)
    {
        if (shifr == T.strings[i].shifr_direct)
        {
            flag = true;
            nomer = i; //запоминаем номер
        }
        i++;
    }
    if (!flag)
        cout << "There is no element with this cipher\n";
    else
    {
        cout << "Enter Plan\n";
        Input_struct(P);
        T.cur_size += 1;
        T.strings[T.cur_size] = P;
        for (int i = T.cur_size-1; i >= nomer; i--)
        { 
            swap(T.strings[i+1],T.strings[i]); //посмотреть почему не меняет местами
        }
    }
    cout << "Inserted \n";
}
//Удалить планы, срок действия которых истек при прошествии 4-х лет
void Delete(Table& T)
{
    int now = 2022;
    for (int i = 0; i < T.cur_size; i++)
    {
        if (now - T.strings[i].start_year > 4)
        {
            for (int j = i; j < T.cur_size; j++)
                swap(T.strings[i], T.strings[i+1]);
            T.cur_size -= 1;
        }       
    }
    
}
int main()
{
    Table Titul;
    Plan P;
    Input(Titul, P);
    print_profiles(Titul); //вывод профиля и года
    Insert(Titul,P);
    print_profiles(Titul);
    //Output(Titul); //вывод всех данных структуры
    Delete(Titul);
    cout << "After deleting\n";
    print_profiles(Titul);
    int b;
    cin >> b;
}

