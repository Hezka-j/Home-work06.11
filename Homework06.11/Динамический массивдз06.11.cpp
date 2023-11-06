//#include <iostream>
//#include<ctime>
//using namespace std;
//void SetSize(unsigned int* ptr, int x, int y)
//{
//    if (*ptr < x)
//        *ptr = x;
//    if (*ptr > y)
//        *ptr = y;
//
//}
//void FreeMemory(int** a)
//{
//    delete[] *a;
//}
//void AllocateMemory(int** ar,int size)
//{
//    *ar = new int[size];
//}
//void FillArray(int** ar, int size, int x, int y)
//{
//    for (int i = 0; i < size; i++)
//    {
//        (*ar)[i] = x + rand() % y;
//    }
//}
//void ShowArray(int** ar,int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << (*ar)[i] << ", ";
//    }
//}
//int main()
//{
//    unsigned int size;
//    cout << "Enter size of array - ";
//    cin >> size;
//    SetSize(&size, 10, 100000);
//    int* ar;
//    AllocateMemory(&ar, size);
//    FillArray(&ar, size, 100, 2000);
//    ShowArray(&ar, size);
//    FreeMemory(&ar);
//    cout << "\n\n\n";
//      
//    
//   size++;
//    int* temp = new int[size];
//    for (int i = 0; i < size; i++)
//       {
//          temp[i] = ar[i];
//       }
//    FreeMemory(&ar);
//    int value;
//    cout << "/nInput number - ";
//    cin >> value;
//    temp[size - 1] = value;
//    ar = temp;
//    for (int i = 0; i < size; i++)
//        {
//                
//           cout << ar[i] << ", ";
//        }
//    FreeMemory(&ar);
//            
//        
//    
//            size--;
//            int* temp = new int[size];
//            for (int i = 0; i < size; i++)
//            {
//                temp[i] = ar[i];
//            }
//            FreeMemory(&ar);
//            int value;
//            cout << "Input number - ";
//            cin >> value;
//            ar = temp;
//            for (int i = 0; i < size; i++)
//            {
//                cout << ar[i] << ", ";
//            }
//            FreeMemory(&ar);
//            
//
//        
//    
//}
/////////////////////////////////////////////////////С добавлением и удалением в любые места
#include <iostream>
#include<ctime>
using namespace std;
void SetSize(unsigned int* ptr, int x, int y)
{
    if (*ptr < x)
        *ptr = x;
    if (*ptr > y)
        *ptr = y;

}
void FreeMemory(int** a)
{
    delete[] * a;
}
void AllocateMemory(int** ar, int size)
{
    *ar = new int[size];
}
void FillArray(int** ar, int size, int x, int y)
{
    for (int i = 0; i < size; i++)
    {
        (*ar)[i] = x + rand() % y;
    }
}
void ShowArray(int** ar, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << (*ar)[i] << ", ";
    }
}
int main()
{
    srand(time(0));
    unsigned int size;
    cout << "Enter size of array - ";
    cin >> size;
    SetSize(&size, 10, 100000);
    int* ar;
    AllocateMemory(&ar, size);
    FillArray(&ar, size, 100, 2000);
    ShowArray(&ar, size);
    //FreeMemory(&ar);
    
    int choice;
    do
    {

        cout << "\n1.Add\n2.Delete\n3.Exit\n";
        cin >> choice;


        switch (choice)
        {
        case 1:
        {

            int value;
            int index;
            cout << "Input number - ";
            cin >> value;
            cout << "Index - ";
            cin >> index;
            if (value > 1000)
            {
                value = 1000;
            }
            if (index > size)
                index = size - 1;
            size++;
            int* temp = new int[size];
            for (int i = 0; i < size; i++)
            {
                if (i == index)
                {

                    temp[i] = 0;
                    i++;
                    temp[i] = ar[i - 1];

                }
                if (temp[index] == 0)
                    temp[i + 1] = ar[i];
                else
                    temp[i] = ar[i];
                //cout << temp[i] << ", ";
            }
            FreeMemory(&ar);
            temp[index] = value;
            ar = temp;
            for (int i = 0; i < size; i++)
            {

                cout << ar[i] << ", ";
            }
            
            break;
        }
        case 2:
        {

            int index;
            bool r = false;
            cout << "Index - ";
            cin >> index;
            if (index > size)
                index = size;
            size--;
            int* temp = new int[size];
            for (int i = 0; i < size; i++)
            {
                if (i == index)
                {
                    r = true;
                    temp[i] = ar[i + 1];
                }
                if (r)
                {
                    temp[i] = ar[i + 1];
                }
                else
                    temp[i] = ar[i];
            }
            FreeMemory(&ar);
            
            ar = temp;
            for (int i = 0; i < size; i++)
            {
                cout << ar[i] << ", ";
            }
           
            break;

        }
        case 3:
        {
            FreeMemory(&ar);
            choice = 4;
            break;
        }
        }
    } while (choice != 4);
}