/*����� �������� ����� (��) ����������� ����. ��������� ������ � �����: ���� ����������� (��������, 090304),
�������� �����������, ���� ������� (��������,090304_1), �������� ������� (��������, ��������� ����������), ��� ������ �������� ��.
��������
1)	��������� ������ �� ������ �������� ����� � ����������.
2)	�������� ������ � ������� ������ � ������ ���������, � ����� � ��� �� ������ �����������.
3)	������� �������� �������� � ��� ������ �������� �������� ����� ��������� �����������.
4)	������� ����� ���� �������� ������� ����� ��� ���������� 4-� ���.
*/
#include "dinam struct.h"
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
void Input(Table& T, Plan& P) //���� �������� ���������
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
void Output(Table& T) //����� ���� ������ ���������
{
    cout << "Cipher of direction  " << " Name of direction  " << " Cipher of profile  " << " Name of profile  " << setw(10) << " Year\n";
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
//������� �������� �������� � ��� ������ �������� �������� ����� ��������� �����������.
void print_profiles(Table& T)
{
    cout << " Name of profile  " << " Year of start \n";
    for (int i = 0; i < T.cur_size; i++)
    {
        cout << setw(15) << T.strings[i].name_profile;
        cout << setw(15) << T.strings[i].start_year;
        cout << endl;
    }
}
void Insert(Table& T, Plan& P) //������� �������� � ���������
{
    int shifr;
    cout << "Enter cipher of direction to insert new plan\n";
    cin >> shifr;
    bool flag = false;
    int i = 0;
    int nomer = -1;
    while (!flag && i < T.max_size)
    {
        if (shifr == T.strings[i].shifr_direct)
        {
            flag = true;
            nomer = i; //���������� �����
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
        for (int i = T.cur_size - 1; i >= nomer; i--)
        {
            swap(T.strings[i + 1], T.strings[i]); //���������� ������ �� ������ �������
        }
    }
    cout << "Inserted \n";
}
//������� �����, ���� �������� ������� ����� ��� ���������� 4-� ���
void Delete(Table& T)
{
    int now = 2022;
    for (int i = 0; i < T.cur_size; i++)
    {
        if (now - T.strings[i].start_year > 4)
        {
            for (int j = i; j < T.cur_size; j++)
                swap(T.strings[i], T.strings[i + 1]);
            T.cur_size -= 1;
        }
    }

}
int main()
{
    Table Titul;
    Plan P;
    Input(Titul, P);
    print_profiles(Titul); //����� ������� � ����
    Insert(Titul, P);
    print_profiles(Titul);
    //Output(Titul); //����� ���� ������ ���������
    Delete(Titul);
    cout << "After deleting\n";
    print_profiles(Titul);
    int b;
    cin >> b;
}

