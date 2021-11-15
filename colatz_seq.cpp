#include <iostream>
#include <list>
using namespace std;

int next_collatz(int n){
    return n % 2 == 0 ? n/2 : n * 3 + 1;
}

list<int> collatz_seq(int n){
    if(n == 4)
       return list<int>{4, 2, 1};
    else{
        list<int> seq = collatz_seq(next_collatz(n));
        seq.push_front(n);
        return seq;
    }
}

int main(int argc,char* argv[]){
    int start = stoi(argv[1]);
    for(int n: collatz_seq(start)){
        cout << n << " ";
    }
    cout<<endl;
}