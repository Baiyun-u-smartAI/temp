#include <bits/stdc++.h>

int fun(int){
    return 1;
}

int fun(float){
    return 2;
}

template <typename T>
int activate(T* funIn,int input){
    return funIn(input);
}




int main() {
    std::cout << activate(static_cast<int(*)(float)>(&fun),3) << std::endl;
    return 0;
}
