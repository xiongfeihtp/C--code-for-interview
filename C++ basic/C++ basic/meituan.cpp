//青蛙跳问题，数的整数次方

//#include <stdio.h>
//#include <iostream>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//int main(){
//    int N,res;
//    cin >> N;
//    cout<<PowerWithUnsignedExponent(2,N);
//    return 0;
//}
//int PowerWithUnsignedExponent(int base, unsigned int exp){
//    if(exp == 0)
//        return 1;
//    if(exp == 1)
//        return base;
//    int result = PowerWithUnsignedExponent(base, exp>>1);
//    result *= result;
//    if(exp & 0x1 == 1)
//        result *= base;
//    return result;
//}



//斐波那契数列递推写法
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//using namespace std;
//int main(){
//    int N,res;
//    cin >> N;
//    vector<int> table(6,0);
//    table[0]=1;
//    for(int i=1;i<6;i++){
//        for(int j=0;j<i;j++){
//            table[i]+=table[j];
//        }
//        table[i]+=1;
//    }
//    if(N<=6){
//        cout<<table[N-1];
//        return 0;
//    }
//    for(int i=7;i<=N;i++){
//        for(auto x:table){
//            res+=x;
//        }
//        for(int j=0;j<5;j++){
//            table[j]=table[j++];
//        }
//        table[5]=res;
//    }
//    cout<<res;
//    return 0;
//}


//二阶动态规划+模型压缩，数组输入
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void){
//    int N;
//    vector<int> coins={1,5,10,20,50,100};
//    cin >> N;
//    //有时候长度太大会超过
//    vector<long> table(N+1,0);
//    for(int i=0;coins[0]*i<=N;i++){
//        table[coins[0]*i]=1;
//    }
//    for(int i=1;i<coins.size();i++){
//        for(int j=1;j<=N;j++){
//            if(j-coins[i]>=0){
//                table[j]=table[j]+table[j-coins[i]];
//            }
//        }
//    }
//    cout<<table[N];
//    return 0;
//}


//矩形输入
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int main(void){
//    int N;
//    cin >> N;
//    vector<int> nums(N,0);
//    for(int i=0;i<N;i++){
//        cin>>nums[i];
//    }
//    int sum_max=0;
//    for(int i=0;i<N;i++){
//        int h=nums[i],med_sum=0,temp=0;
//        //连续子数组
//        for(int j=0;j<N;j++){
//            //千万不要标号混乱，错误十分难查
//            if(nums[j]>=h)
//                temp+=h;
//            else{
//                temp=0;
//            }
//            med_sum=max(med_sum,temp);
//        }
//        sum_max=max(sum_max,med_sum);
//    }
//    cout<<sum_max;
//    return 0;
//}

//字符串输入
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//using namespace std;
//
//int main(){
//    string str1,str2;
//    getline(cin,str1);
//    getline(cin,str2);
//    int res=0;
//    vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),0));
//    for(int i=0;i<str1.size();i++){
//        for(int j=0;j<str2.size();j++){
//            if(str1[i]==str2[j]){
//                if(i==0||j==0){
//                    dp[i][j]=1;
//                }else{
//                    dp[i][j]=dp[i-1][j-1]+1;
//                }
//            }
//            res=max(res,dp[i][j]);
//        }
//    }
//    cout<<res;
//}

//考虑大数问题
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//using namespace std;
//
//bool Increment(string &number){
//    bool isOverflow = false;
//    int nTakeOver=0;
//    size_t nLength = number.size();
//    for(size_t i = nLength - 1; i >= 0; i--){
//        int nSum = number[i]-'0'+ nTakeOver;
//        if(i == nLength - 1)
//            nSum++;
//        if(nSum >= 10){
//            if(i == 0)
//                isOverflow = true;
//            else{
//                nSum -= 10;
//                nTakeOver = 1;
//                number[i] = nSum + '0';
//            }
//        }else{
//            number[i] = '0' + nSum;
//            break;
//        }
//    }
//    return isOverflow;
//}
//
//void Print(string &number){
//    bool IsBegin = true;
//    size_t nLength = number.size();
//    for(int i=0;i<nLength;i++){
//        if(IsBegin && number[i] != '0'){
//            IsBegin = false;
//        }
//        if(!IsBegin)
//            cout<<number[i];
//    }
//}
//
//void PrintMaxN(int n){
//    if(n <= 0)
//        return;
//    string str(n,'0');
//    cout<<str;
//    while(!Increment(str)){
//        Print(str);
//        cout<<endl;
//    }
//}
//
//int main(){
//    int N;
//    cin >> N;
//    PrintMaxN(N);
//    return 0;
//}


////字符串输入
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//using namespace std;
//int cal_dist(string str1, string str2){
//    int count=0;
//    for(int i=0;i<str1.size();i++){
//        if(str1[i]!=str2[i])
//            count++;
//    }
//    return count;
//}
//
//
//int main(){
//    string str1,str2;
//    getline(cin,str1);
//    getline(cin,str2);
//    int len1 = str1.size();
//    int len2 = str2.size();
//    vector<int> table(len1-len2+1,0);
//    int res = 0;
//    int temp = 0;
//    for(int j=0;j<len2;j++){
//        if(str1[j]!=str2[j])
//            temp++;
//    }
//    table[0]=temp;
//    for(int i=1;i<len1-len2+1;i++){
//        int temp=0;
//        if(str1[i-1] == str2[0])
//            temp--;
//        if(str1[i+len2-1]!=str1[len2-1])
//            temp++;
//        table[i]=table[i-1]+temp;
//    }
//    for(auto item: table){
//        cout<<item<<endl;
//        res+=item;
//    }
//    cout<<res;
//}
//字符串输入
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//using namespace std;
//int cal_dist(string str1,string str2){
//    int count=0;
//    for(int i=0;i<str1.size();i++){
//        if(str1[i]!=str2[i])
//            count++;
//    }
//    return count;
//}
//int main(){
//    string str1,str2;
//    getline(cin,str1);
//    getline(cin,str2);
//    int len1 = str1.size();
//    int len2 = str2.size();
//    int res = 0;
//    for(int i=0;i<len1-len2+1;i++){
//        res+=cal_dist(str1.substr(i,len2),str2);
//    }
//    cout<<res;
//}

//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//#include <stdlib.h>
//
//using namespace std;
//int main(){
//    string str;
//    getline(cin,str);
//    int len = str.size();
//    vector<int> table(10, 0);
//    table[0] = 1;
//    for(int i; i < len; i++){
//        table[str[i] - '0']++;
//    }
//    int miss = 9999999;
//    int num = 0;
//
//    for(int i = 0; i < 10; i++){
//        if(table[i] < miss){
//            num = i;
//            miss = table[i];
//        }
//    }
//    if(num == 0){
//        string ans;
//        for(int i = 0; i < miss; i++){
//            ans += to_string(num);
//            cout << ans << endl;
//        }
//        cout << to_string(1) + ans ;
//    }else{
//        string ans;
//        for(int i=0;i<miss+1;i++){
//            ans += to_string(num);
//        }
//        cout << ans;
//
//    }
//}

//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//using namespace std;
//typedef long long ll;
//ll cal(ll num){
//    int temp = 0;
//    while(num){
//        temp += num % 10;
//        num/=10;
//    }
//    return temp;
//}
//
//int main(){
//    ll l, r;
//    cin >> l >> r;
//    int res = 0;
//    ll l_sum = 0;
//    for(ll i=1;i <= l_sum; i++){
//        l_sum +=cal(i);
//    }
//    if(l_sum % 3 == 0)
//        res++;
//    for(ll i = l+1; i <= r; i++){
//        l_sum += cal(i);
//        if(l_sum % 3 == 0)
//            res++;
//    }
//    cout<<res;
//}


//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//
//int my_cmp(pair<int, int> p1, pair<int, int> p2){
//    return p1.first < p2.first;
//}
//int main(){
//    int people_num, task_num;
//    cin >> people_num >> task_num;
//    vector<pair<int, int>> input;
//    vector<int> ability;
//    for(int i =0; i < task_num; i++){
//        int abli, reward;
//        cin >> abli >> reward;
//        input.push_back(make_pair(abli, reward));
//    }
//    for(int i = 0; i < people_num; i++){
//        int temp;
//        cin >> temp;
//        ability.push_back(temp);
//    }
//    sort(input.begin(),input.end(),my_cmp);
//    unordered_map<int, int> index;
//    index[input[0].first] =input[0].second;
//    int max_reward = input[0].second;
//    for(int i = 1; i < task_num; i++){
//        if(input[i].second > max_reward){
//            index[input[i].first] = input[i].second;
//            max_reward = input[i].second;
//        }else{
//            index[input[i].first] = max_reward;
//        }
//    }
//    vector<int> ret;
//    for(int item: ability){
//        while(index.count(item)==0){
//            item--;
//        }
//        ret.push_back(index[item]);
//    }
//    for(int k:ret) cout << k << " ";
//}


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void GetNext(string P, vector<int> &next){
    int p_len = P.size();
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(i < p_len){
        if(j == -1 || P[i] == P[j]){
            i++;
            j++;
            next[i] = j;
        }else
            j = next[j];
    }
}
int KMP(string S, string P){
    vector<int> next(P.size(),0);
    int i = 0;
    int j = 0;
    GetNext(P, next);
    for(int x : next)
        cout<<x<<endl;
    //对长度进行比较的时候，需要用int，不然会报错
    int len_S = S.size();
    int len_P = P.size();
    while(i < len_S && j < len_P){
        if(j == -1 || S[i] == P[j]){
            i++;
            j++;
        }else
            j = next[j];
    }
    
    if(j == len_P){
        return i - j;
    }
    return -1;
}

#include <map>

string minWindow(string s, string t) {
    int len_s = s.size();
    int len_t = t.size();
    map<char, int> char_count;
    for(char x : t){
        char_count[x]++;
    }
    int begin = 0;
    int end = 0;
    int count = 0;
    int min_len = INT_MAX;
    string res = "";
    map<char, int> temp_count;
    for(end = 0; end < len_s; end++){
        if(char_count.find(s.at(end)) == char_count.end()) continue;
        temp_count[s.at(end)]++;
        if(temp_count[s.at(end)] <= char_count[s.at(end)])
            count++;
        //如果存在满足条件的窗口，收缩begin
        //这里有一个bug，map在索引的时候会默认添加value为0的key
        if(count == len_t){
            while(1){
                if(char_count.find(s.at(begin)) == char_count.end()){
                    begin++;
                }else if(temp_count[s.at(begin)] > char_count[s.at(begin)]){
                    //bug这里会自动添加元素
                    temp_count[s.at(begin)]--;
                    begin++;
                }else
                    break;
            }
            int cur_len = end - begin + 1;
            if(cur_len < min_len){
                min_len = cur_len;
                res = s.substr(begin, min_len);
            }
        }
    }
    return res;
}



int main()
{
    cout << minWindow("ADOBECODEBANC", "ABC") << endl; //15
    return 0;
}





