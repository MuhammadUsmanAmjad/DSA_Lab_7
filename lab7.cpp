#include <iostream>
using namespace std;
template <typename T>
struct node
{
    T data;
    node<T> *next;
    node<T>()
    {
        next = NULL;
    }
    node<T>(T val)
    {
        this->data = val;
        next = NULL;
    }
};
template <typename T>
class stack
{
    node<T> *top;
    int size;

public:
    stack()
    {
        this->top = NULL;
        this->size = 0;
    }
    int get_size()
    {
        return size;
    }
    void push(T val)
    {
        node<T> *n = new node<T>(val);
        if (isEmpty())
        {
            ++size;
            this->top = n;
            return;
        }
        ++size;
        n->next = top;
        top = n;
    }
    void pop()
    {
        // if (isEmpty())
        //     return;
        --size;
        node<T> *t = this->top;
        this->top = this->top->next;
        delete t;
    }
    bool isEmpty()
    {
        return (this->top == NULL);
    }
    T get_top_element()
    {
        return this->top->data;
    }
    stack<T> *sort(stack<T> *stack_s)
    {
        stack<T> *temp_s = new stack<T>;
        while (!stack_s->isEmpty())
        {
            T val = stack_s->get_top_element();
            stack_s->pop();
            while (!temp_s->isEmpty() && temp_s->get_top_element() > val)
            {
                stack_s->push(temp_s->get_top_element());
                temp_s->pop();
            }
            temp_s->push(val);
        }
        return temp_s;
    }
    void display()
    {
        for (node<T> *temp = top; temp != NULL; temp = temp->next)
            cout << temp->data << "->";
        cout << "NULL\n";
    }
    void delete_middle()
    {
        if (top == NULL || size == 1)
            return;
        node<T> *temp = top;
        for (int i = 0; i < size / 2 - 1; i++)
            temp = temp->next;
        node<T> *t = temp->next;
        temp->next = t->next;
        delete t;
        --size;
    }
    bool check_pallindrome()
    {
        node<T> *temp = top;
        node<T> *temp2 = NULL;
        for (int i = 0; i < size / 2; i++)
        {
            temp2 = top;
            for (int j = 0; j < size - i - 1; j++)
                temp2 = temp2->next;
            if (temp->data != temp2->data)
                return false;
            temp = temp->next;
        }
        return true;
    }
    void get_k_sum_elements(T k)
    {
        node<T> *temp = top;
        node<T> *temp1 = top;
        bool flag = false;
        for (; temp != NULL; temp = temp->next)
        {
            for (temp1 = temp; temp1 != NULL; temp1 = temp1->next)
            {
                if (temp->data + temp1->data == k)
                {
                    cout << temp->data << "  " << temp1->data << endl;
                    // return;
                    flag = true;
                }
            }
        }
        if (!flag)
            cout << "Not Found a pair Equal to K\n";
    }

    void insert(stack<T> *&s, T d)
    {
        if (s->isEmpty())
        {
            s->push(d);
            return;
        }
        T data = s->get_top_element();
        s->pop();
        insert(s, d);
        s->push(data);
    }
    void reverse_stack(stack<T> *s)
    {
        if (s->isEmpty())
            return;
        T data = s->get_top_element();
        s->pop();
        reverse_stack(s);
        s->insert(s, data);
    }
    void insert_sort(stack<T> *s, T d)
    {
        if (s->isEmpty() || s->get_top_element() < d)
        {
            s->push(d);
            return;
        }
        T data = s->get_top_element();
        s->pop();
        insert_sort(s, d);
        s->push(data);
    }
    void sort_recurr(stack<T> *s)
    {
        if (s->isEmpty())
            return;
        T data = s->get_top_element();
        s->pop();
        sort_recurr(s);
        insert_sort(s, data);
    }
};
// TASK-2
bool pallin(string str)
{
    static int i = 0;
    if (i > str.length() / 2 + 1)
        return true;
    if (str[i] != str[str.length() - i - 1])
        return false;
    i++;
    bool flag = pallin(str);
    return flag;
}
// Task-5
int factorial(int i)
{
    if (i == 0)
        return 1;
    return i * factorial(i - 1);
}
int get_combination(int n, int r)
{
    if (n == 0 || r == n)
        return 1;
    int a = factorial(n);
    int b = factorial(n - r);
    int c = factorial(r);
    int d = a / (c * b);
    return d;
}
int k = 0;
char str[100];
// TASK-3...
void get_commas(int num)
{
    if (num == 0)
        return;
    static int i = 0;
    if (i == 3)
    {
        str[k++] = ',';
        i = 0;
    }
    i++;
    int s = num % 10;
    char ch = char(s + 48);
    str[k++] = ch;
    num = num / 10;
    get_commas(num);
}
// Task-4
int *create_array(int k)
{
    int *arr = new int[k];
    for (int i = 0; i < k; i++)
    {
        if (i < k / 2)
            arr[i] = 0;
        else
            arr[i] = 1;
    }
    return arr;
}
void print(int *arr,char*str, int i,int j, int size)
{
    if(i==size)
    {
        str[j]=0;
        cout<<str<<"  ";
        return;
    }
    for(int k=0;k<size;k++){
    str[j]=char(arr[k]+48);
    print(arr,str,i+1,j+1,size);
    }
}
int main()
{
    stack<int> *s = new stack<int>;
    s->push(1);
    s->push(1);
    s->push(9);
    s->push(1);
    s->push(2);
    s->push(3);
    s->display();
    s->reverse_stack(s);
    s->display();
    s->sort_recurr(s);
    s->display();
    string str1 = "madam";
    cout << pallin(str1) << endl;
    cout << get_combination(5, 3) << endl;
    get_commas(1234567890);
    for (int i = k; i >= 0; i--)
        cout << str[i];
    cout << endl;
    int size;
    cout<<"Enter K value:-\n";
    cin>>size;
    int*arr=create_array(size);
    char ch[1000];
    print(arr,ch,0,0,size);
    
}
