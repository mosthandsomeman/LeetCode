#include "common.h"

int main(){
    createTree A;
    vector<int> a = {1,2,4,5,3,6},  b = {4,2,5,1,3,6};
    auto root = A.createTreeByPreAndIn(a, b);
    vector<int> vec;
    A.postOrder(vec, root);
    system("pause");
    return 0;
}