////
////  interview_summary.cpp
////  C++ basic
////
////  Created by 熊飞 on 2018/3/23.
////  Copyright © 2018年 熊飞. All rights reserved.
////
//
////创业金融公司：
//#include <stdio.h>
//#include <iostream>
//#define MAX 26
//
//using namespace std;
//struct TriedNode{
//    int value;
//    bool isStr;
//    TriedNode* next[MAX];
//};
//
//void Insert(TriedNode* root,const char* s){
//    if(root==NULL || *s=='\0')
//        return;
//    TriedNode* cur=root;
//    while((*s) != '\0'){
//        if(cur->next[*s-'a'] == NULL){
//            TriedNode* temp = new TriedNode();
//            for(int i =0; i < MAX; i++){
//                temp->next[i] = NULL;
//            }
//            temp->isStr = false;
//            cur->next[*s-'a']=temp;
//            cur=cur->next[*s-'a'];
//        }else{
//            cur=cur->next[*s-'a'];
//        }
//        s++;
//    }
//    cur->isStr = true;
//}
//
//
//bool search(TriedNode* root, const char* s){
//    TriedNode* cur=root;
//    while(cur != NULL && (*s) != '0'){
//        cur = cur->next[*s-'a'];
//        s++;
//    }
//    return ((cur!=NULL) && (cur->isStr) == true);
//}
//
//void del(TriedNode* root){
//    for(int i=0 ; i < MAX; i++){
//        if(root->next[i] != NULL){
//            del(root->next[i]);
//        }
//    }
//    delete root;
//    root = NULL;
//}
//
//////返回TopN的结果，维护最小堆
////#include <set>
////#include <vector>
////#include <string>
////using namespace std;
////struct CMP{
////    bool operator()(const TriedNode* node1, const TriedNode* node2){
////        return node1->value < node2->value;
////    }
////};
////
////
////
////
////typedef set<TriedNode*, CMP> NodeSet;
////typedef set<TriedNode*, CMP>::iterator setIter;
////
////TriedNode* search_node(TriedNode* root, const char* s){
////    TriedNode* cur=root;
////    while(cur != NULL && (*s) != '0'){
////        cur = cur->next[*s-'a'];
////        s++;
////    }
////    return cur;
////}
////
////void helper(NodeSet &node_set, TriedNode* new_root, int k){
////    if(new_root == NULL){
////        return;
////    }
////    if(new_root->isStr == true){
////        if(node_set.size() < k)
////            node_set.insert(new_root);
////        else{
////            setIter iter = node_set.begin();
////            if(new_root->value > (*iter)->value){
////                node_set.erase(iter);
////                node_set.insert(new_root);
////            }
////        }
////    }
////    for(int i=0; i < MAX; i++){
////        if(new_root->next[i] != NULL)
////            helper(node_set, new_root->next[i], k);
////    }
////}
////
////vector<string> TopN(TriedNode* root, int k, const char *s){
////    vector<TriedNode*> res;
////    TriedNode* new_root = search_node(root, s);
////    if(new_root == NULL)
////        return res;
////    NodeSet node_set;
////    helper(node_set, new_root, k);
////}
//
//#include <map>
//#include <vector>
//#include <string>
//using namespace std;
//
//typedef pair<string, int> PAIR;
//
//struct CMP{
//    bool operator()(const PAIR &p1, const PAIR &p2){
//        return p1.second < p2.second;
//    }
//};
//
//typedef map<string, int, CMP> string_map;
//typedef map<string, int, CMP>::iterator mapIter;
//
//
//TriedNode* search_node(TriedNode* root, const char* s){
//    TriedNode* cur=root;
//    while(cur != NULL && (*s) != '0'){
//        cur = cur->next[*s-'a'];
//        s++;
//    }
//    return cur;
//}
//
//void helper(string_map &string_set, TriedNode* new_root, int k, string s){
//    if(new_root == NULL){
//        return;
//    }
//    if(new_root->isStr == true){
//        if(string_set.size() < k)
//            string_set.insert(make_pair(s, new_root->value));
//        else{
//            mapIter iter = string_set.begin(); //最小元素
//            if(new_root->value > (*iter).second){
//                string_set.erase(iter);
//                string_set.insert(make_pair(s, new_root->value));
//            }
//        }
//    }
//    for(int i=0; i < MAX; i++){
//        s += char('a'+i);
//        if(new_root->next[i] != NULL)
//            helper(string_set, new_root->next[i], k, s);
//    }
//}
//
//vector<string> TopN(TriedNode* root, int k, const char *s){
//    vector<string> res;
//    TriedNode* new_root = search_node(root, s);
//    if(new_root == NULL)
//        return res;
//    string_map string_set;
//    string temp_string;
//    helper(string_set, new_root, k, temp_string);
//    int i = 0;
//    for(auto x:string_set){
//        res[i] = x.first;
//    }
//    return res;
//}
//



//网易第一题
//将中缀表达式改写成后缀表达式


//网易第二题
//字典序问题
//排列组合问题
//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//#include <vector>
//using namespace std;
//
////组合数计算
//int f(int m, int n){
//
//}
//
//int main(){
//    int N;
//    cin >> N;
//    string str;
//    while(N--){
//        getline(cin,str);
//        size_t len = str.size();
//        vector<int> char_table(len);
//        int sum = 0;
//        //长度小于len的所有情况
//        for(int i = 1; i<len; i++){
//            sum += f(26, i);
//        }
//        //长度等于len的所有情况
//        for(int i = 0; i < len; i++){
//            char_table[i] = str.at(i) - 'a';
//        }
//        int temp = 1;
//        for(int i = len; i > 0; i--){
//            for(int j = temp; j < char_table[len - i]; j++){
//                sum += f(26 - j, i-1);
//            }
//            temp += char_table[len - i] + 1;
//        }
//    }
//}
//
//网易游戏 第三题




////美团第一题
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//    string S,T;
//    cin>>S>>T;
//    int ret=0;           //结果
//    int nt=T.length();
//    int na,nb;          //保存字符a、b的个数
//    na=nb=0;
//    int f,r;            //子串的首尾下标
//    for(r=0; S[r+nt-1]!='\0'; r++)
//    {
//        if(S[r]=='a')   na++;
//        else    nb++;
//    }
//    //此时r指向了子串之外的一个字符，也就是该字符不在当前子串中
//    f=0;
//    int i=0;    //这里i其实和f是相等的
//    while(T[i]!='\0')
//    {
//        //与T串匹配
//        if(T[i]=='a')       ret+=nb;
//        else                ret+=na;
//        //下一个子串与上一个子串相比，
//        //第一位少了一个字符，最后多了一个字符，我们要把他计算下来
//        if(S[f++]=='a')     na--;
//        else                nb--;
//
//        if(S[r++]=='a')     na++;
//        else                nb++;
//        i++;
//    }
//    cout<<ret;
//    return 0;
//}
//
////美团第二题
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
//
//
////今日头条第一题
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//#include <stdlib.h>
//using namespace std;
//int main()
//{
//    int N, k;
//    cin >> N >> k;
//    vector<int> nums(N,0);
//    for(int i = 0; i < N; i++){
//        cin >> nums[i];
//    }
//    //排序和去重
//    sort(nums.begin(), nums.end());
//    vector<int>::iterator unique_end = unique(nums.begin(), nums.end());
//    //nums.erase(unique_end,nums.end());
//    int unique_len = unique_end-nums.begin();
//    int cur = 0;
//    int res = 0;
//    for(int i = 0; i < unique_len; i++){
//        while(cur < unique_len && nums[cur] - nums[i] < k) cur++;
//        if(cur == unique_len)
//            break;
//        if(nums[cur] - nums[i] == k) res++;
//    }
//    cout << res << endl;
//    return 0;
//}

////今日头条第二题
////从（1，1）开始进行深搜，通过队列保存每一层的状态，通过map保存状态对应步数
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//#include <stdlib.h>
//#include <map>
//#include <queue>
//using namespace std;
//typedef pair<int, int> pii;
//int main()
//{
//    int n;
//    cin >> n;
//    queue<pii> q;
//    q.push(make_pair(1, 1));
//    map<pii, int> map_pair;
//    map_pair[make_pair(1, 1)] = 0;
//    while(!q.empty()){
//        //取出最近的一个pair
//        pii p = q.front();
//        q.pop();
//        //验证
//        if(p.first == n){
//            cout << map_pair[p] << endl;
//            exit(0);
//        }
//        //分别将第一个操作和第二个操作的pair放入map和queue中
//        pii t = p;
//        t.second = t.first; t.first *=2;
//        if(!map_pair.count(t)){
//            q.push(t);
//            map_pair[t]=map_pair[p]+1;
//        }
//        t = p;
//        t.first += t.second;
//        if(!map_pair.count(t)){
//            q.push(t);
//            map_pair[t]=map_pair[p]+1;
//        }
//    }
//    return 0;
//}

////今日头条第三题
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//#include <stdlib.h>
//#include <map>
//#include <queue>
//#include <unordered_map>
//using namespace std;
//
//typedef long long ll;
////输出这种东西的技巧
//char G[5][10][8] = {
//    {"66666", "....6", "66666", "66666", "6...6", "66666", "66666", "66666", "66666", "66666"},
//    {"6...6", "....6", "....6", "....6", "6...6", "6....", "6....", "....6", "6...6", "6...6"},
//    {"6...6", "....6", "66666", "66666", "66666", "66666", "66666", "....6", "66666", "66666"},
//    {"6...6", "....6", "6....", "....6", "....6", "....6", "6...6", "....6", "6...6", "....6"},
//    {"66666", "....6", "66666", "66666", "....6", "66666", "66666", "....6", "66666", "66666"}
//};
//
//ll cal(string s)
//{
//    int n = s.size();
//    ll sum=0, cur=0, prd=1;
//    for(int i=0; i<n; ++i)
//    {
//        //cur当前数  sum 和 prd *的左边
//        if(isdigit(s[i])) cur=s[i]-'0';
//        else if(s[i] == '-')
//        {
//            sum+=prd*cur;
//            cur=0;
//            prd=-1;
//        }
//        else if(s[i] == '+')
//        {
//            sum+=prd*cur;
//            cur=0;
//            prd=1;
//        }
//        else
//        {
//            prd*=cur;
//            cur=0;
//        }
//    }
//    return sum+prd*cur;
//}
//
//int main()
//{
//    int T;
//    cin >> T;
//    string str;
//    while(T--)
//    {
//        cin >> str;
//        ll ans = cal(str);  //字符串表示的整数，需要考虑大数问题
//        //一行一行输出
//        vector<int> v;
//        ll tmp = ans;
//        while(tmp){
//            v.push_back(tmp%10);
//            tmp/=10;
//        }
//        //v保存了每一位，进行反序
//        reverse(v.begin(), v.end());
//        //如果为空，则输出0
//        if(v.empty()) v.push_back(0);
//        //输出
//        for(int i=0; i<5; ++i)
//        {
//            for(int j=0; j<v.size(); ++j)
//            {
//                string end_str = (j+1 == v.size())? "\n":"..";
//                cout << G[i][v[j]] << end_str;
//            }
//        }
//    }
//    return 0;
//}
////今日头条第五题
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//#include <stdlib.h>
//#include <map>
//#include <queue>
//using namespace std;
//const int N = 1e5+1000;
//bool vis[N]; //可视范围
//int a[N];  //存所有板的高度
//
//typedef pair<int, int> pii;  //first height，second step
//int main()
//{
//    int n, k, h;
//    cin >> n >> k >> h;
//    vector<int> board(n, 0);
//    for(int i = 0; i < n; i++){
//        cin >> board[i];
//    }
//
//    for(auto x: board){
//        a[x] = 1;
//    }
//
//    queue<pii> q;
//    q.push(make_pair(0, 0));
//    int ans = 0;
//    while(!q.empty()){
//        //取出一种情况，并验证
//        pii t = q.front();
//        q.pop();
//        if(t.second > k) break;
//        ans = max(ans, t.first);
//        //将当前步往后的满足条件的所有情况加入到队列中
//        for(int i = 1; i <= h; i++){
//            //向上跳，存在对应的板并且没有达到过
//            if(a[t.first + i] && !vis[t.first + 2 * i]){
//                vis[t.first + 2 * i] = true;
//                q.push(make_pair(t.first + 2 * i, t.second + 1));
//            }
//            //向下跳，满足距离大于0，并且存在对应的板，并且没有到达过
//            if(t.first - 2 * i > 0 && a[t.first - i] && !vis[t.first - 2 * i]){
//                vis[t.first - 2 * i] = true;
//                q.push(make_pair(t.first - 2 * i, t.second + 1));
//            }
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}

//腾讯第一题
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//#include <stdlib.h>
//#include <map>
//#include <queue>
//using namespace std;
//
//
////考虑大数问题
//int main()
//{
//    long m, n;
//    cin >> m >> n;
//    long res = 0;
//    long nums = n / (2*m);
//    res = nums * m * m;
//    cout << res << endl;
//    return 0;
//}


//腾讯第一题
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//#include <stdlib.h>
//#include <map>
//#include <queue>
//using namespace std;

/*
 排列组合，内存会爆
 */
//unsigned long long combine_cal(int n, int m){
//    //组合数计算，范围问题
//    if(m == 0){
//        return 1;
//    }
//    long long temp1 = 1;
//    for(int i = n; i >= n - m + 1; i--){
//        temp1 *= i;
//    }
//    long long temp2 = 1;
//    for(int i = m; i >= 1; i--){
//        temp2 *= i;
//    }
//    return temp1/temp2;
//}
//
//int main()
//{
//    int K, A, X, B, Y;
//    cin >> K;
//    cin >> A >> X >> B >> Y;
//    int NB = 0;
//    int sub_sum = 0;
//    unsigned long long res = 0;
//    NB = K/B;
//    for(int i = 0; i <= min(NB, Y); i++){
//        sub_sum = K - B * i;
//        if(sub_sum % A == 0 && sub_sum/A <= X){
//            cout << X << " " << sub_sum/A <<" " << Y << " " << i << endl;
//            res += (combine_cal(X, sub_sum/A) * combine_cal(Y, i));
//        }
//    }
//    cout << res << endl;
//    return 0;
//}

//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//#include <stdlib.h>
//#include <map>
//#include <queue>
//using namespace std;
///*
// 动态规划
// */
//int main()
//{
//    int K, A, X, B, Y;
//    cin >> K;
//    cin >> A >> X >> B >> Y;
//    //建表，注意范围设置一般为最大范围+1
//    vector<vector<int>> dp(X+Y+1,vector<int> (K+1));
//    //初始化，特殊情况
//    for(int i = 0; i < X + Y+ 1; i++){
//        dp[i][0] = 1;
//    }
//    //开始规划，注意起始位置
//    for(int i = 1; i < X + Y + 1; i++){
//        for(int j = 1; j < K + 1; j++){
//            //长度为A的歌
//            if(i <= X){
//                if(j >= A) dp[i][j] = (dp[i-1][j] + dp[i-1][j-A]) % 1000000007;
//                else
//                    dp[i][j] = dp[i-1][j] % 1000000007;
//            }else if(i <= X+Y){
//                if(j >= B) dp[i][j] = (dp[i-1][j] + dp[i-1][j-B]) % 1000000007;
//                else
//                    dp[i][j] = dp[i-1][j] % 1000000007;
//            }
//        }
//    }
//    cout << dp[X+Y][K] << endl;
//    return 0;
//}

//腾讯第三题
//排序搜索，贪婪算法
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <string>
//#include <stdlib.h>
//#include <map>
//#include <queue>
//using namespace std;
//
//typedef pair<int, int> pii;
//
//
//int my_cmp(pair<int, int> const p1, pair<int, int> const p2){
//    if(p1.first == p2.first)
//        return p1.second < p2.second;
//    else
//        return p1.first < p2.first;
//}
//int main()
//{
//    int m, n;
//    cin >> m >> n;
//    int time, level;
//    vector<pii> machine(m);
//    vector<pii> task(n);
//    for(int i = 0; i < m; i++){
//        cin >> time >> level;
//        machine.push_back(make_pair(time, level));
//    }
//    for(int i = 0; i < n; i++){
//        cin >> time >> level;
//        task.push_back(make_pair(time, level));
//    }
//    //按照时间进行贪心
//    sort(machine.begin(), machine.end(), my_cmp);
//    sort(task.begin(), task.end(), my_cmp);
//    vector<int> cnt(105);
//    long sum = 0;  //总收益
//    int j = 0, cnt1 = 0;  //以完成的任务数量，优先级比较高，按时间进行排序
//    //所有机器level情况进行统计
//    while(j < m){
//        cnt[machine[j].second]++;
//        j++;
//    }
//    for(int i = 0; i < n; i++){
//        //针对每一个任务，能够完成任务的机器的使用情况进行统计，因为通过排序，所以贪心的保证完成的任务数量最大
////        while(j < m && machine[j].first >= task[i].first){
////            cnt[machine[j].second]++;
////            j++;
////        }
//        //按照当前任务的等级，选择满足条件并等级最小的机器，选择后，计算收益和完成任务数量，并退出，对下一个任务进行统计
//        for(int k = task[i].second; k < 105; k++){
//            if(cnt[k] != 0){
//                cnt[k]--;
//                sum += 200 * task[i].first + 3 * task[i].first;
//                cnt1++;
////              cnt.clear(); //清零统计结果
//                break;
//            }
//        }
//    }
//    cout << cnt1 << " " << sum <<endl;
//}
