#include <iostream>
#include <sstream>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    size_t n;
    string key;
    unordered_map<string, set<size_t>> lib[5]; // title, author, keywords, publisher, published year;
    if(scanf("%zu", &n) == EOF) return 0;
    for(size_t i = 0, id; i < n && scanf("%zu%*c", &id); ++i) {
        for(size_t j = 0; j < 5; ++j) {
            getline(cin, key);
            if(j != 2) lib[j][key].insert(id);
            else for(istringstream keys(key); keys >> key; lib[j][key].insert(id));
        }
    }
    if(scanf("%zu", &n) == EOF) return 0;
    for(size_t i = 0, type; i < n && scanf("%zu: ", &type); ++i) {
        getline(cin, key);
        printf("%zu: %s\n", type, key.c_str());
        if(!lib[type-1].count(key)) printf("Not Found\n");
        else for(const size_t id : lib[type-1][key]) printf("%07zu\n", id);
    }
    return 0;
}

/*

Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].


1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year


3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla


1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found
*/