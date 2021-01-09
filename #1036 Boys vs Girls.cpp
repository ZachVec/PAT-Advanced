#include <iostream>
#include <tuple>
typedef std::tuple<std::string, std::string, int> Record;

int main() {
    size_t n;
    int score;
    char gender;
    std::string name, courseId;
    Record male("", "", 101), female("", "", -1);
    if(scanf("%zu", &n) != 1) return 0;
    for(size_t i = 0; i < n && std::cin >> name >> gender >> courseId >> score; ++i) {
        if(gender == 'F' && score > std::get<2>(female)) 
            female = {name, courseId, score};
        else if(gender == 'M' && score < std::get<2>(male))
            male   = {name, courseId, score};
    }
    auto printRec = [](const Record &r, int absent){
        if(std::get<2>(r) == absent) printf("Absent\n");
        else printf("%s %s\n", std::get<0>(r).c_str(), std::get<1>(r).c_str());
    };
    printRec(female, -1); printRec(male, 101);
    if(std::get<2>(female) == -1 || std::get<2>(male) == 101) printf("NA\n");
    else printf("%d\n", std::get<2>(female) - std::get<2>(male));
    return 0;
}