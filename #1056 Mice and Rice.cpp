#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t totalPlayerNum, playerNumEachGroup;
    
    if(scanf("%zu%zu", &totalPlayerNum, &playerNumEachGroup) != 2) return 0;
    vector<unsigned> weight(totalPlayerNum), rank(totalPlayerNum);
    vector<size_t> order(totalPlayerNum);
    for(unsigned &w : weight) if(!scanf("%u", &w)) return 0;
    for(size_t &s : order) if(!scanf("%zu", &s)) return 0;

    for(size_t playerNum = totalPlayerNum, groupNum, ranking; playerNum != 1; playerNum = groupNum) {
        ranking = (groupNum = (playerNum + playerNumEachGroup - 1) / playerNumEachGroup) + 1;
        for(size_t i = 0, idxOfMax; i < playerNum; i += playerNumEachGroup) {
            idxOfMax = order[i];
            for(size_t j = 0, idxOfNow; i + j < playerNum && j < playerNumEachGroup; ++j) {
                idxOfNow = order[i + j];
                rank[idxOfNow] = ranking;
                if(weight[idxOfNow] > weight[idxOfMax]) idxOfMax = idxOfNow;
            }
            order[i / playerNumEachGroup] = idxOfMax;
        }
    }
    rank[order[0]] = 1;
    for(size_t i = 0; i < totalPlayerNum; ++i) 
        printf("%u%c", rank[i], " \n"[i == totalPlayerNum - 1]);
    return 0;
}