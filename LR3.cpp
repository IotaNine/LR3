#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void ResultArr(int* Array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << Array[i] << "\t";
    }
    cout << "\n";
}
void ResultVec(vector<int> vec)
{
    for (int i : vec)
    {
        cout << i << "\t";
    }
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int arr1[10];

    int a, n, k1, k2;
    int sum = 0;

    vector<int> vec1;
    bool isFirst = true;

    string str, zamena;
    double k = 0;
    int l1, l2;


    //Начало первого задания
    for (int i = 0; i < 10; i++)
    {
        arr1[i] = rand() % 21 - 10;
        cout << arr1[i] << "\t";
    }
    cout << "\n" << pow(arr1[0], 3) + pow(arr1[1], 3) + pow(arr1[6], 3) << "\n";
    delete[] arr1;


    //Начало второго задания
    cout << "Задайте размер массива(от 10 эл-ов): ";
    cin >> n;
    int* arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Элемент " << i << " = ";
        cin >> a;
        arr2[i] = a;
    }
    ResultArr(arr2, n);
    for (int i = 0; i < n; i++)
    {
        if (arr2[i] < 0)
        {
            arr2[i] *= 3;
        }
    }
    ResultArr(arr2, n);
    std::cout << "Введите номер первого элемента: ";
    cin >> k1;
    std::cout << "Введите номер второго элемента: ";
    cin >> k2;
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
        cout << "Элемент " << i << " = ";
        cin >> a;
        vec1.push_back(a);
    }
    ResultVec(vec1);
    vec1.push_back(5);
    ResultVec(vec1);
    for (int i : vec1) sum += i;
    cout << sum << "\n";
    n = 0;
    do 
    {
        if (vec1[n] >= 0)
        {
            n++;
        }
        else
        {
            vec1.erase(vec1.begin() + n);
            isFirst = false;
        }
    } while (isFirst && (n <= vec1.size() - 1));
    ResultVec(vec1);


    //Начало четвертого задания
    cin.ignore();
    cout << "Введите строку: ";
    getline(cin, str);
    cout << str << "\n" << str.length() << "\n";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'q') k++;
    }
    cout << k / str.length() << "\n";
    cout << "Выберите l1: "; cin >> l1;
    cout << "Выберите l2: "; cin >> l2;
    cout << str.substr(l1 - 1 , l2 - l1 + 1) << "\n";
    cin.ignore();
    cout << "Введите замену: ";
    getline(cin, zamena);
    string dano = "Can you can a can as a canner can can a can?";
    cout << dano << "\n";
    for (int i = 0; i < dano.length(); i++)
    {
        if (dano.substr(i, 3) == "can" or dano.substr(i, 3) == "Can")
        {
            if (dano[i + 3] == ' ' or dano[i + 3] == '?')
            {
                dano.replace(i, 3, zamena);
            }
        }
    }
    cout << dano;
    return 0;
}
