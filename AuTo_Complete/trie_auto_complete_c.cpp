#include <bits/stdc++.h>
using namespace std;


struct node{
    node* trie[26];
    bool flag = false;
    
    
    bool containsChar(char c){          // Checks whether the Node exists in Trie
        return trie[c-'a'] != NULL;
    }
    
    void addNewChar(char c, node* ref){ // Adds a new child Trie Node; 
        trie[c-'a'] = ref;
    }
    node* getToNode(char c){    // returns the address of the child Trie Node for the char c
        return trie[c-'a'];
    }
    
    void setEnd(){              // this sets the flag marking the end of the string 
        flag = true;
    }
    bool isEnd(){               // returns whether any string ends at the current Node.
        return flag;
    }
};

class Trie {
public:
    node* root; 
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node *head = root;
        int n = word.length();
        for(int i = 0; i < n; i++){
            if(!head->containsChar(word[i]))
                head->addNewChar(word[i], new node());
            head = head->getToNode(word[i]);
        }
        head->setEnd();
    }
    
    bool search(string word) {
        node* head = root;
        int n = word.length();
        for(int i = 0; i < n; i++)
        {
            if(!head->containsChar(word[i])) return false;
            head = head->getToNode(word[i]);
        }
        return (head->isEnd());
    }
    
};


bool isLastNode(node* root) 
{ 
	for (int i = 0; i < 26; i++) 
		{if (root->containsChar((char)i)) 
					return 0; 
		}
	return 1; 
}

void suggest(node* root , string &s , vector<string>& ans)
{
	if(root->isEnd())
	{
		ans.push_back(s);
	}

	if(isLastNode(root))
	{
		s.pop_back();
		return;
	}

	

	for( int i = 0 ; i<26 ; i++)
	{
		if(root->containsChar('a' + (char)i))
		{
			s.push_back('a' + (char)i);
			suggest(root->getToNode('a' + (char)i) , s , ans);
			
		}
	}
	s.pop_back();
	

}

vector<string> print( node* root , string s)
{
	node* temp = root;
	vector<string> ans;

	 for( int i =0 ; i< s.length() ; i++)
	 {
	 	if( !temp->containsChar(s[i]))
	 	{
	 		return ans;
	 	}
	 	temp = temp->getToNode(s[i]);
	 }

	 bool current = temp->isEnd();

	 bool lastnode = isLastNode(temp);

	 if( lastnode == true and current == true)
	 {
	 	ans.push_back(s);
	 	return ans;
	 }
	 if( lastnode == false)
	 {

	 	string newstring = s;
	 	suggest(temp , newstring , ans);
	 	return ans;
	 }

	 return ans;

}

int main()
{

Trie obj;


obj.insert("hell");
obj.insert("dog");
obj.insert("heli");
obj.insert("help");
obj.insert("helps");
obj.insert("helping");
obj.insert("hello");
obj.insert("helis");
obj.insert("cat");
vector<string> ans = print(obj.root , "hel");

if( ans.size() == 0)
	cout<<"No suggestion found!"<<endl;

for( auto it : ans)
{
	cout<<it<<endl;
}

return 0;

}