#include <iostream>
using namespace std;

const int MAXN = 2001;
bool is_prime[MAXN + 1];
int arr_size;
int a_set[1000], b_set[1000];
int adj[1000][1000], adj_size[1000];
int a_match[1000], b_match[1000];
bool visited[1000];

int a_cnt = 0, b_cnt = 0;

void set_false(bool* arr, int n){
    for(int i=0;i<n;i++) arr[i]=false;
}

void set_int(int* arr, int n, int val){
    for(int i=0;i<n;i++) arr[i]=val;
}

int my_sqrt(int n){
    int r=0;
    while((r+1)*(r+1)<=n) r++;
    return r;
}

void my_sort(int* arr, int n){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(arr[i]>arr[j]){
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
}

void sieve(){
    for(int i=0;i<=MAXN;i++) is_prime[i]=true;
    is_prime[0]=false;
    is_prime[1]=false;
    int sq=my_sqrt(MAXN);
    for(int i=2;i<=sq;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=MAXN;j+=i)
                is_prime[j]=false;
        }
    }
}

bool DFS(int a_idx){
    if(a_idx==0 || visited[a_idx]) return false;
    visited[a_idx]=true;
    for(int i=0;i<adj_size[a_idx];i++){
        int b_idx=adj[a_idx][i];
        if(b_match[b_idx]==-1 || DFS(b_match[b_idx])){
            a_match[a_idx]=b_idx;
            b_match[b_idx]=a_idx;
            return true;
        }
    }
    return false;
}

int main(void)
{
    int first_num;
    cin>>arr_size;
    cin>>first_num;

    bool first_even = (first_num%2==0);
    a_set[a_cnt++]=first_num;

    for(int i=1;i<arr_size;i++){
        int x;
        cin>>x;
        if(first_even){
            if(x%2==0) a_set[a_cnt++]=x;
            else b_set[b_cnt++]=x;
        }else{
            if(x%2!=0) a_set[a_cnt++]=x;
            else b_set[b_cnt++]=x;
        }
    }

    if(a_cnt!=b_cnt){
        cout<<-1<<'\n';
        return 0;
    }

    sieve();

    for(int i=0;i<a_cnt;i++){
        adj_size[i]=0;
        for(int j=0;j<b_cnt;j++){
            if(is_prime[a_set[i]+b_set[j]]){
                adj[i][adj_size[i]++]=j;
            }
        }
    }

    int answers[1000], ans_cnt=0;

    for(int i=0;i<adj_size[0];i++){
        int pair_b_idx = adj[0][i];
        int paired_size = 1;

        for(int k=0;k<a_cnt;k++) a_match[k]=-1;
        for(int k=0;k<b_cnt;k++) b_match[k]=-1;

        a_match[0]=pair_b_idx;
        b_match[pair_b_idx]=0;

        for(int j=1;j<a_cnt;j++){
            set_false(visited,a_cnt);
            if(DFS(j)) paired_size++;
        }

        if(paired_size==b_cnt)
            answers[ans_cnt++]=b_set[pair_b_idx];
    }

    if(ans_cnt==0){
        cout<<-1<<'\n';
        return 0;
    }

    my_sort(answers, ans_cnt);

    for(int i=0;i<ans_cnt;i++){
        cout<<answers[i];
        if(i<ans_cnt-1) cout<<' ';
    }
    cout<<'\n';

    return 0;
}