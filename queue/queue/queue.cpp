// queue.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
using std::endl;

struct MyStruct
{
    int data;
    MyStruct *next;
};
class Queue
{
private:
    MyStruct *head,*current;
public:
    Queue()
    {
        head = NULL;
        current = NULL;
    }
    ~Queue()
    {
        MyStruct *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete(temp);
        }
    }

    void push(int data);
    int pop();
};
void Queue::push(int data)
{
    if (head == NULL)
    {
        head = new MyStruct();
        head->data = data;
        head->next = NULL;
        current = head;
    }
    else
    {
        current->next = new MyStruct();
        current = current->next;
        current->data = data;
        current->next = NULL;
    }
}
int Queue::pop()
{
    int data = 0;
    MyStruct *temp = head;
    if (temp == NULL)
        return NULL;
    else
    {
        data = temp->data;
        head = temp->next;
        delete(temp);
    }
    return data;
}
int main()
{
    Queue queue = Queue();
        queue.push(3);
        queue.push(5);
        queue.push(7);
        queue.push(1);
        std::cout << queue.pop() << endl;
        std::cout << queue.pop() << endl;
        std::cout << queue.pop() << endl;
        std::cout << queue.pop() << endl;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
