#include <iostream>
using namespace std;

int* dangling_example() {
    int local_val = 42; 
    return &local_val; 
} // 'local_val' bị hủy khi thoát hàm, nhưng địa chỉ của nó vẫn được trả về 
 
int main() {
    int* ptr = dangling_example(); 
    
    // 'ptr' hiện là một Dangling Pointer (một dạng của dangling reference) 
    // Đối tượng tại địa chỉ này không còn tồn tại hợp lệ nữa.
    
    // std::cout << *ptr; // NGUY HIỂM: Truy cập vào vùng nhớ đã bị thu hồi 
    return 0;
}