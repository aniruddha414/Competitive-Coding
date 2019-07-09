/*
    Given string break into X blocks and sort to find K th number in such that only one element
    from each block is taken in given order
    eg : '123456789'
    [123],[456],[789]  : blocks formed
    9 th number will be - 169
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    
    string s;   // input string
    int k;  // find K th  number
    int x;  // divide into x blocks

    cout << " Enter input : " << endl;
    cin >> s >> k >> x;

    cout << s << "\t" << k << "\t" << x << "\t" <<endl;
    cout << endl;
    
    vector <string> blocks;

    for (int i = 0; i < s.length(); i+=x) {
        int start = i;
        int end = std :: min( ((int)s.length()) , (i+x) );

        // cout << "start " << start << " end " << end <<endl;

        string sub = s.substr(start, end - start);
        sort(sub.begin(),sub.end());
        blocks.push_back(sub);
    }

    int totalPerms = 1;
    int noOfBlocks = blocks.size();
    //cout << "no. blocks "<< noOfBlocks << endl;

    for (auto i = blocks.begin(); i < blocks.end(); i++) {
            string temp = *i;
            totalPerms *= (int) temp.length();
    }
    // cout << "Total Permutation : "<< totalPerms << endl;

    int ck = k;
    string number = "";
    for (int i = 0; i < noOfBlocks; i++) {
        int bl = (int)blocks[i].length();
        int div = totalPerms / bl;

        int index = 1;
        bool flag = true;
        // cout << " K " << ck << " div " << div << endl ;

        while (ck > div) {
            flag = false;
            ck -=  div;
            // cout << "ck -- "<<ck <<endl; 
            index++;
        }
        if (ck == 0) 
            ck += div;
        
        if (flag) {
            index = 1;
            // cout << "not went in loop " << endl;
            if ( i == (blocks.size()-1) ) {
                index = ck;
            }
        }
        // cout << "Index : " << (index-1) << " K after loop : " << ck << endl;
        // cout << " -- -- -- -- " <<endl;
        number += blocks[i][index-1];
        totalPerms = div;
    }

    cout << "number is : " << number << endl;

    cout << "end" << endl;
    return 0;
}