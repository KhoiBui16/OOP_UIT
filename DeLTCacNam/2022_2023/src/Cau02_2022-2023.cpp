#include <iostream>
using namespace std;

class IntArr {
private:
    int count; //*tổng số lượng phần tử có trong values 
    int * values; //*mảng các số nguyên đang có trong đối tượng hiện tại
public:
    //*Sinh viên bổ sung đầy đủ các thành phần cần thiết để hàm main hoạt động như mong đợi 
    IntArr() 
    { 
        count = 0;
        values = NULL;
    }

    IntArr(int n, int data)
    {
        count = n;
        values = new int[count];
        for (int i = 0; i < count; i++) 
            values[i] = data;
    }

    IntArr(int n) 
    {
        count = n;
        values = new int[n];
        for (int i = 0; i < n; i++) 
            values[i] = 0;
    }

    ~IntArr() 
    {
        delete[] values;
        values = NULL;
        count = 0;
    }

    IntArr concat(const IntArr& arr) 
    {
        IntArr temp(count + arr.count);
        for (int i = 0; i < count; i++) 
            temp.values[i] = values[i];
        for (int i = 0; i < arr.count; i++) 
            temp.values[count + i] = arr.values[i];
        return temp;
    }
    
    IntArr& operator = (const IntArr& arr) 
    {
        count = arr.count;
        values = new int[count];
        for (int i = 0; i < count; i++) 
            values[i] = arr.values[i];
        return *this;
    }

    IntArr& push(int data) 
    {
        int* temp = new int[count + 1];
        for (int i = 0; i < count; i++) 
            temp[i] = values[i];
        temp[count] = data;
        delete[] values;
        values = temp;
        count++;
        return *this;
    }

    friend istream& operator >> (istream& is, IntArr& arr)
    {
        delete[] arr.values;
        is >> arr.count;
        arr.values = new int[arr.count];
        for (int i = 0; i < arr.count; i++) 
            is >> arr.values[i];
        return is;
    }

    friend ostream& operator << (ostream& os, const IntArr& arr) 
    {
        for (int i = 0; i < arr.count; i++) 
            os << arr.values[i] << " ";
        cout << endl;
        return os;
    }
};

int main() {

    IntArr l1;//*tạo mảng không chứa bất kì phần tử nào 
    IntArr l2(3,2);//* tạo một mảng với 3 phần tử, tất cả phần tử đều có giá trị là 2 
    IntArr l3(2);//*tạo một mảng với 2 phần tử, tất cả phần tử đều có giá trị là 0 
    IntArr l4 = l2.concat(l3);//*tạo ra một IntArr mới có nội dung là kết quả của việc nối các phần tử l3 vào cuối các phần tử của l2 theo thứ tự 
    l2.push(3);//*thêm số 3 vào cuối danh sách trong đối tượng l2 
    cin >> l2;//*Xoá các giá trị hiện có trong l2 và cho phép người dùng nhập số lượng phần tử mới và giá trị các phần tử mới vào l2 (cần xoá các vùng nhớ không sử dụng nếu có) 
    cout << l2;//*in ra các số nguyên có trong danh sách 
    //*Khi vượt quá phạm vi sử dụng cần huỷ tất cả các vùng nhớ được cấp phát cho các values của IntArr 

    return 0;
}