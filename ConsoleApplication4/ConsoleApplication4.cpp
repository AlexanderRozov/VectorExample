// Self implementation of
// the Vector Class in C++


#include <iostream>
using namespace std;
template <typename T> class vectorClass
{

    // arr is the integer pointer
    // У казатель на вектор
    T* arr;

    // 
    // 
    int capacity;

    // текущее значение
    int current;

public:
    // Конструктор по умолчанию для инициализации
      // начальная емкость в 1 элемент и
      // распределение памяти с использованием динамического распределения 
    vectorClass()
    {
        arr = new T[1];
        capacity = 1;
        current = 0;
    }

    // Функция для добавления элемента в конец
    void push(T data)
    {

            /*если количество элементов равно емкости, это означает, что у нас нет места для размещения дополнительных элементов.
            Нам нужно удвоить емкость*/
        if (current == capacity) {
            T* temp = new T[2 * capacity];

          
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

      
        arr[current] = data;
        current++;
    }
   


    // функция для добавления элемента по любому индексу 
    void push(int data, int index)
    {

        // если индекс равен емкости, то это
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }

    // функция для извлечения элемента по любому индексу 
    T get(int index)
    {

        // если привысили
        if (index < current)
            return arr[index];
    }

    // удалить послений элемент
    void pop() { current--; }

    // размер
    int size() { return current; }

    // кол-во
    int getcapacity() { return capacity; }

    // печать
    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Driver code
int main()
{
    vectorClass<int> v;
    vectorClass<char> v1;
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    v.push(50);
    v1.push(71);
    v1.push(72);
    v1.push(73);
    v1.push(74);

    cout << "Vector size : " << v.size() << endl;
    cout << "Vector capacity : " << v.getcapacity() << endl;

    cout << "Vector elements : ";
    v.print();

    v.push(100, 1);
    // добавили элементы
    cout << "\nAfter updating 1st index" << endl;

    cout << "erase element : " << endl;


    v.pop(); //
 
    // пример с типом char
    v.print();
    cout << "Vector with elements of type char : " << endl;
    v1.print();
    cout << "Element at 1st index of type int: " << v.get(1)
        << endl;
    cout << "Element at 1st index of type char: "
        << v1.get(1) << endl;

   
    
    v1.pop();

    cout << "\nAfter deleting last element" << endl;

    cout << "Vector size of type int: " << v.size() << endl;
    cout << "Vector size of type char: " << v1.size()
        << endl;
    cout << "Vector capacity of type int : "
        << v.getcapacity() << endl;
    cout << "Vector capacity of type char : "
        << v1.getcapacity() << endl;

    cout << "Vector elements of type int: ";
    v.print();
    cout << "Vector elements of type char: ";
    v1.print();

    return 0;
}