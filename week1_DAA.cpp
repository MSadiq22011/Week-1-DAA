#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<int> insert_element(){
    vector<int> v;
    int x,i=1;
    cout<<endl<<" **-1 to Exit** "<<endl;
    while(x!=-1){
        cout<<"Enter Element "<<i<<" : ";
        cin>>x;
        v.push_back(x);
        i++;

    }

    return v;

}

//time complexity O(n)
void linear_search(vector<int> v,int key){
    int i;
    bool flag;
    for(i=0;i<v.size();i++){
        if(v[i]==key){
            cout<<endl<<"Present"<<endl;
            flag=true;
            break;
        }
        else{
            flag=false;
        }

    }
    if(!flag){
        cout<<"Not Present"<<endl;
    }
    cout<<"Comparison : "<<i+1<<endl;

}


//works with unsorted vector too,time complexity O(nlogn);
int comp=0;
void binary_search(vector<int> v,int key,int min,int max){
    sort(v.begin(),v.end());
    int mid=1;
    if(min>=max){
        cout<<"Not Present"<<endl;
        cout<<"Comparison : "<<comp<<endl;
        return;
    }
    else{
        mid=(min+max)/2;
        if(v[mid]==key){
            comp++;
            cout<<"Present"<<endl;
            cout<<"Comparison : "<<comp+1<<endl;
            exit(0);
        }
        else if(v[mid]>key){
            comp++;
            binary_search(v,key,mid+1,max);

        }
        else{
            comp++;
            binary_search(v,key,min,mid-1);
        }
    }
}


void jump_search(vector<int> v,int key,int size){
    sort(v.begin(),v.end());
    int start=0;
    int end=sqrt(size);
    while(v[end]<=key &&  end<size){
        start=end;
        end+=sqrt(size);
        if(end>size-1){
            end=size;
        }
    }

    int i,comp=0;
    bool flag;
    for(i=start;i<end;i++){
        comp++;
        if(v[i]==key){
            flag=true;
            cout<<"Present"<<endl;
            break;
        }
    }
    cout<<"Comparison : "<<comp<<endl;
    if(!flag){
        cout<<"Not Present\n";
    }
}



int main(){
    vector<int> v;
    v=insert_element();
    jump_search(v,34,v.size());
}