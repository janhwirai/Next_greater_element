#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>st;
        vector<long long>ans(n);
        int k=n-1;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                    st.pop();   //Remove the smaller elements from the stack
            }
            if(st.empty()){     //No greater element hence the stack is empty
                ans[k]=-1;
                k--;
            }
            else if(st.top()>arr[i] && !st.empty()){
                ans[k]=st.top();    //Return the greater element present in the stack
                k--;
            }
            st.push(arr[i]);    //Push the element into the stack
        }
        return ans;
    }
};

int main()
{
    int t;
    cout<<"\nEnter testcases";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"\nEnter the size of array";
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cout<<"\nEnter the elements:";
            cin>>arr[i];
        }
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}