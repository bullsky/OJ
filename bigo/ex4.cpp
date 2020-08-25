#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <random>

using namespace std;

int ads_num;
vector<int> weights;

vector<int> temp;

void genAdvertiseltem(int& frist,int& second) {
    int max1 = 0,max2 = 0;
    for(int i=0;i<ads_num;i++) {
        temp[i] = weights[i]*(rand()%ads_num);
        if(temp[i] >= max1) {
            max2 = max1;
            max1 = temp[i];
        } else if(temp[i] > max2) {
            max2 = temp[i];
        }
    }
    frist = max1;
    second = max2;
}
int main() {
    int frist,second;
    int * counter = new int[ads_num];
    temp.assign(ads_num,0);
    for(int i=0;i<10000000;i++) {
        genAdvertiseltem(frist,second);
        counter[frist]++;
        counter[second]++;
    }
    for(int i=0;i<ads_num;i++) {
        cout << "ads no"<<i<<".appears:"<<counter[i]<<endl;
    }
}