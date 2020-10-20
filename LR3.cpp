#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
void ResultArr(int* Array,int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << Array[i] << "\t";
    }
    cout << "\n";
}
void ResultVec(vector<int> vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << "\t";
    }
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n, a, k1, k2, l1, l2, sum = 0, arr1[10];
    double kolvo = 0;
    bool isFirst = true;
    string stroka, zamena;
    vector<int> vec1;


    //Начало первого задания
    for (int i = 0; i < 10; i++)
    {
     arr1[i] = rand() % 21 - 10;           
     cout << arr1[i] << "\t";           
    }
    cout << "\n" << pow(arr1[0], 3) + pow(arr1[1], 3) + pow(arr1[6], 3) << "\n\n";
    

    //Начало второго задания
    cout << "Задайте размер массива(от 10 эл-ов): ";
    cin >> n;
    int* arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr2[i] = a;
    }
    cout << "\n";
    ResultArr(arr2, n);
    for (int i = 0; i < n; i++)
    {
        if (arr2[i] < 0)
        {
            arr2[i] *= 3;
        }
    }
    ResultArr(arr2, n);
    cin >> k1; cin >> k2;
    for (; k1 <= k2; k1++)
    {
        sum += arr2[k1];
    }
    cout << sum << "\n";
    delete[] arr2;
    

    //Начало третьего задания
    cout << "Задайте размер вектора(от 5 эл-ов): ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec1.push_back(a);
    }
    cout << "\n";
    ResultVec(vec1, n);
    vec1.push_back(5);
    ResultVec(vec1, n + 1);
    for (int i = 0; i < (n+1); i++) sum += vec1[i];
    cout << sum << "\n";
    for (int i = 0; i < n; i++)
    {
        if (vec1[i] < 0 && isFirst )
        {
            vec1.erase(vec1.begin() + i);
            isFirst = false;
        }
    }
    ResultVec(vec1, n);


    //Начало четвертого задания
    cout << "Введите строку: "; getline(cin, stroka);
    cout << stroka << "\n" << stroka.length() << "\n";
    for (int i = 0; i < stroka.length(); i++)
    {
        if (stroka[i] == 'q') kolvo++;
    }
    cout << kolvo/stroka.length() << "\n";
    cout << "Выберите l1: "; cin >> l1; 
    cout << "Выберите l2: "; cin >> l2;
    cout << stroka.substr(l1, l2) << "\n";
    cin.ignore();
    cout << "Введите замену: "; getline(cin, zamena);
    string dano = "Can you can a can as a canner can can a can?";
    cout << dano << "\n";
    for (int i = 0; i < dano.length(); i++)
    {
        if (dano.substr(i, 3) == "can" or dano.substr(i, 3) == "Can")
        {
            if (dano[i+3] == ' ' or dano[i + 3] == '?')
            {
                dano.replace(i, 3, zamena);
            }
        }
    }
    cout << dano;
    return 0;
}