#include <iostream>
#include <deque>
#include <stdbool.h>

using namespace std;
deque<int> bookshelf;
int books[200000] = {0};

bool findBook(int bookNum) {
    return (books[bookNum-1] == 1);
}

void insertBook(int K, int bookNum) {
    if (findBook(bookNum)) {
        return;
    } else {
        if (bookshelf.size() == K) {
            //bookshelf at max capacity
            int bookOut = bookshelf.front();
            books[bookOut-1] = 0;
            bookshelf.pop_front();
        }
        bookshelf.insert(bookshelf.end(), bookNum);
        books[bookNum-1] = 1;
    }
}

void queryBook(int bookNum) {
    if (findBook(bookNum)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}


int main() {
    int N, K, Q, commandType, bookNum;
    
    cin >> N >> K >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> commandType >> bookNum;
        if (commandType == 1) {
            insertBook(K, bookNum);
        } else if (commandType == 2) {
            queryBook(bookNum);
        }
    }

}