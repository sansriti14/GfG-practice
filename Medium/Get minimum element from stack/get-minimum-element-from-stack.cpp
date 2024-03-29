//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minElement;
    stack<int> st;
    public:
        
       /*returns min element from stack*/
       int getMin(){
           return (st.empty()) ? -1 : minElement;
       }
       
       /*returns poped element from stack*/
       int pop(){
            if (st.empty()) return -1;
           
            if(st.top() >= minElement){
                int temp = st.top();
                st.pop();
                return temp;
                
            } else if(st.top() < minElement) {
                int temp = minElement;
                minElement = 2 * minElement - st.top();
                st.pop();
                return temp;
            }
       }
       
       /*push element x into the stack*/
       void push(int x){
           if (st.empty()) {
               st.push(x);
               minElement = x;
           }
           
           else {
               if (x >= minElement) {
                   st.push(x);
               }
               
               else if (x < minElement) {
                   st.push(2 * x - minElement);
                   minElement = x;
               }
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends