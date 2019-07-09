/*
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
nums = [2, 7, 11, 15], target = 9,
nums[0] + nums[1] = 2 + 7 = 9,
[0, 1]
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main () {
    map <int,int> hashSum;
    int target,n;
    vector <int> arr;
    cout << "enter target and no. of elements " << endl;
    cin >> target >> n;
    cout << "enter array " << endl;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];

        if (hashSum.find(arr[i]) != hashSum.end()) {
            cout << "found" << endl;
            cout << arr[i] << " , " << complement << endl;
            break;
        }

        hashSum[complement] = arr[i];
    }
    // cout << "hasmap" << endl;
    // for (auto& i : hashSum){
    //     cout << i.first << " , " << i.second << endl;
    // }
    // map <int,int> :: iterator it ;
    // it = hashSum.find(7);

    // cout << it->second<< endl;

    return 0;
}
