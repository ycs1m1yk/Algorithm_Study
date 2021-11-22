#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
typedef pair<int, string> pic;

bool compare (const pic &v1, const pic &v2){
    if(v1.first==v2.first) return v1.second<v2.second;
    return v1.first>v2.first;   
}

bool compare2 (const pic &v1, const pic &v2){
    return v1.first<v2.first;   
}

int main(){
    int arr[5] = {4,6,5,3,1};
    vector<int> vec = {34, 27, 25, 15, 3};

    // 오름차순
    sort(arr, arr+5);
    sort(vec.begin(), vec.end());

    for(int i = 0; i <5; i++) cout << arr[i] << " ";
    cout<<"\n";
    for(int i = 0; i <5; i++) cout << vec[i] << " ";
    cout<<"\n";

    // 내림차순
    sort(arr, arr+5, greater<int>());
    sort(vec.begin(), vec.end(), greater<int>());

    for(int i = 0; i <5; i++) cout << arr[i] << " ";
    cout<<"\n";
    for(int i = 0; i <5; i++) cout << vec[i] << " ";
    cout<<"\n";

    vector<pic> picVec1;
    picVec1.push_back({17, "Tea"});
    picVec1.push_back({31, "Baskin Robbins"});
    picVec1.push_back({17, "Ballantine's"});
    picVec1.push_back({17, "Seventeen"});
    picVec1.push_back({10, "Sunny"});

    vector<pic> picVec2(picVec1);
    vector<pic> picVec3(picVec1);
    vector<pic> picVec4(picVec1);
    vector<pic> picVec5(picVec1);

    cout << "picVec1: ";
    for(int i = 0; i <5; i++) cout << "{" << picVec1[i].first << ", " << picVec1[i].second << "} ";
    cout<<"\n";
    cout << "picVec2: ";
    for(int i = 0; i <5; i++) cout << "{" << picVec2[i].first << ", " << picVec2[i].second << "} ";
    cout<<"\n";
    cout << "picVec3: ";
    for(int i = 0; i <5; i++) cout << "{" << picVec3[i].first << ", " << picVec3[i].second << "} ";
    cout<<"\n";
    cout << "picVec4: ";
    for(int i = 0; i <5; i++) cout << "{" << picVec4[i].first << ", " << picVec4[i].second << "} ";
    cout<<"\n";
    cout << "picVec5: ";
    for(int i = 0; i <5; i++) cout << "{" << picVec5[i].first << ", " << picVec5[i].second << "} ";
    cout<<"\n";

    // 그냥 정렬
    sort(picVec1.begin(), picVec1.end());
    // stable_sort
    stable_sort(picVec2.begin(), picVec2.end());
    // 사용자 정의 compare 함수
    sort(picVec3.begin(), picVec3.end(), compare);
    // 사용자 정의 compare2 함수 (first만 오름차순 정렬)
    sort(picVec4.begin(), picVec4.end(), compare2);
    // compare2 함수 stable_sort
    stable_sort(picVec5.begin(), picVec5.end(), compare2);

    cout << "picVec1: ";
    for(int i = 0; i <5; i++) cout << "{" << picVec1[i].first << ", " << picVec1[i].second << "} ";
    cout<<"\n";
    cout << "picVec2: ";
    for(int i = 0; i <5; i++) cout << "{" << picVec2[i].first << ", " << picVec2[i].second << "} ";
    cout<<"\n";
    cout << "picVec3: ";
    for(int i = 0; i <5; i++) cout << "{" << picVec3[i].first << ", " << picVec3[i].second << "} ";
    cout<<"\n";
    cout << "picVec4: ";
    for(int i = 0; i <5; i++) cout << "{" << picVec4[i].first << ", " << picVec4[i].second << "} ";
    cout<<"\n";
    cout << "picVec5: ";
    for(int i = 0; i <5; i++) cout << "{" << picVec5[i].first << ", " << picVec5[i].second << "} ";
    cout<<"\n";
}