// #include <iostream>
// // using namespace std;

// int main(){
//     int age = 36;
//     double height = 1.67;
//     char grade = 'A';
//     bool isStudent = false;

//     std::cout << "Age: " << age << std::endl;
//     std::cout << "Height: " << height << std::endl;
//     std::cout << "Grade: " << height << std::endl;
//     std::cout << "IsStudent: " << isStudent << std::endl;
// }

#include <iostream>
using namespace std;

int main(){
// ⚠ Tham chiếu treo (dangling reference)
    int* p;
    {
        int x = 42;
        p = &x;
    }   // x bị hủy ở đây!
        *p = 10;   // hành vi không xác định — p trỏ vào vùng đã giải phóng
    // ⚠ Số học con trỏ (pointer arithmetic) — dễ vượt biên mảng
    int arr[5] = {1, 2, 3, 4, 5};
    int* q = arr;
    // q += 10;   // q trỏ ra ngoài mảng
    // *q = 99;   // hành vi không xác định — có thể ghi đè dữ liệu khác!
    cout << *(q+1) << endl;
}