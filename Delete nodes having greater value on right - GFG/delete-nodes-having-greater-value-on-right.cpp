//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // Node* p=head;
        // vector<int> v;
        // Node *r=head;
        // while(r)
        // {
        //     v.push_back(r->data);
        //     r=r->next;
        // }
        // int n=v.size();
        // int maxi=v[n-1];
        // for(int i=n-2;i>=0;i--)
        // {
        //     maxi=max(maxi,v[i]);
        //     v[i]=maxi;
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(v[i] > p->data)
        //     {
        //         if(p==head)
        //         {
        //             head=head->next;
        //             delete(p);
        //             p=head;
        //         }
        //         else
        //         {
        //             p->data=p->next->data;
        //             Node* temp= p->next;
        //             p->next=temp->next;
        //             delete(temp);
        //         }
        //     }
        //     else
        //     {
        //         p=p->next;
        //     }
        // }
        // return head;
        
        Node* r=head;
        vector<int> v;
        while(r)
        {
            v.push_back(r->data);
            r=r->next;
        }
        int n=v.size();
        vector<int> temp;
        temp.push_back(v[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(v[i] >= temp.back())
                temp.push_back(v[i]);
        }
        
        Node* root = new Node(temp[temp.size()-1]);
        Node *p = root;
        for(int i = temp.size()-2; i>=0;i--)
        {
            Node *t = new Node(temp[i]);
            p->next = t;
            p = p->next;
        }
        return root;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends