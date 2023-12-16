#include <bits/stdc++.h>

using namespace std;

    string longestCommonPrefix(vector < string > & strs) {

    if(strs.size() == 1){
        return strs[0];
    }
    set < char > check;
    int n = strs.size();
    int Min = 300;
    int Index = 0;
    for (int i = 0; i < n; i++) {
        if (strs[i].size() < Min) {
            Min = strs[i].size();
            Index = i;
        }
    }

	
    bool kiemtra = true;
    int dem = 0;
    int cat =0;

    check.insert(strs[Index][0]);
    for (int i = 0; i < Min; i++) {

        for (int j = 0; j < n; j++) {
            if (check.count(strs[j][i]) == 1) {
                dem ++;                
            } else {
                kiemtra = false;
                break;
            }
        }

        if (dem == n){
            cat = i+1;
            dem =0;
        }

        check.insert(strs[Index][i + 1]);
        if (kiemtra == false) {
            break;
        }
    }
	cout<<"cat  "<<cat<<endl;
    string result = strs[Index].substr(0, cat);
    return result;
}

int main() {
    vector < string > strs = {
		"aac","ab"
    };
    string result = longestCommonPrefix(strs);

    cout << result << endl;

    return 0;
}
