#include<iostream>
#include<vector>
#include<climits>

 using namespace std;//knapsack using greedy method
/*struct Item{
    int value,weight;
    Item(int value,int weight){
    this->value=value;
    this->weight=weight;
    }
};

bool cmp(struct Item a,struct Item b){
    double r1=(double)a.value/(double)a.weight;
    
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;

}
double Fractional(int W,struct Item arr[],int N){
    sort(arr,arr+N,cmp);
    double Finalvalue=0.00;
    for(int i=0;i<N;i++){
        if(arr[i].weight<=W){
            W-=arr[i].weight;
            Finalvalue+=arr[i].value;
        }
        else{
            Finalvalue+=arr[i].value* ((double)W/(double)arr[i].weight);
        }

    }
    return Finalvalue;
}
int main(){
    int W=20;
    Item arr[]={{10,5},{20,4},{25,10},{10,2}};// 
    int N=sizeof(arr)/sizeof(arr[0]);
    cout<<"Max"<<Fractional(W,arr,N);
    return 0;
} */

void floyd(vector<vector<int>> &a) {//
    int n=a.size();

    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;j++){
                if(a[i][k]!=INT_MAX && a[k][j]!=INT_MAX){
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }   
            }
        }
    }


    cout<<"Shortest Path :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == INT_MAX){
                cout<<"INF"<<" ";
            }else{
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> a = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0}
    };

    floyd(a);
    return 0;
}


