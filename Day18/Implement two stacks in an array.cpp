//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks {
  public:
    int n1 = -1,n2 = 100;
    int v1[202];
    twoStacks(){
        memset(v1,0,sizeof(v1));
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        v1[++n1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        v1[++n2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        int ans = -1;
        if(n1 >= 0)
        {
            ans = v1[n1--];
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        int ans = -1;
        if(n2 >= 101)
        {
            ans = v1[n2--];
        }
        else return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends