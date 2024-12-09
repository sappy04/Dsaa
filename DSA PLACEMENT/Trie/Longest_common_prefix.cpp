#include <bits/stdc++.h>
using namespace std;

class trienode // trie node k saare essentials hai ismai
{
public:
    char data;              // charachter hota hai na wohi
    trienode *children[26]; // root k char children
    bool isterminal;        // last wala terminal node hai ki nahi uske liye
    int childcount;         // child count for the current node
    trienode(char ch)
    {
        data = ch; // data ko ch se inititalise kar diya
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL; // saare children ko null mark kar diya initially
        }
        childcount = 0;
        isterminal = false;
    }
};

class trie
{
public:
    trienode *root; // trie ka root
    trie()
    {
        root = new trienode('\0'); // root ko \0 se initialise kar diya
    }

    void insertutil(trienode *root, string word) // root pe word insert ho raha hai
    {
        if (word.length() == 0) // base case
        {
            root->isterminal = true; // lenght hi zero hogaya matlab to word khattam ho gaya na tab last ko terminal mark kar do
            return;
        }

        // assumption, word is in caps
        int index = word[0] - 'A'; // [A=0, ..., Z=25] index calculation
        trienode *child;

        // child present hai
        if (root->children[index] != NULL) // jo word k starting element ko mai khoj rha hoon root k children mai wohi word ka starting element present hai
        {
            child = root->children[index]; // hai to usse child declare kar diya
        }
        else                               // absent hai
        {                                  // new node creation
            child = new trienode(word[0]); // naya child banaya
            root->childcount++;
            root->children[index] = child; // usko link kar diya
        }

        // for rest of the word
        insertutil(child, word.substr(1)); // recursion
    }

    void insertword(string word) // word ayega call hoga aur insert ho jayega
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper); // lowercase to uppercase
        insertutil(root, word);
    }

    void lcp(trienode *root, string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];          // character nikal liya
            if (root->childcount == 1) // agar ek hi child hai root ka to ans mai daal do
            {
                ans.push_back(ch);            // ans mai daal diya aur aage badh gaya
                int index = ch - 'A';         // isi letter ka index nikala aur isse hi root mark diya abhi iska bhi child hai kya check karenge
                root = root->children[index]; // root bana diya bhai
            }
            else // count 1 nahi hai to bhaag jao
            {
                break;
            }

            if (root->isterminal) // agar root terminal hai tab bi bhag jao
            {
                break; // agar sirf 2 hi child ek k neeche ek ...tabh pehla wala to count hogaya phir uske neeche wala bhi count ho jayega phir wo to terinal detect ho gaya to break ho jayega
            }
        }
    }
};

string longestcp(vector<string> &ar, int n)
{
    trie t;

    // Insert all strings into the trie
    for (int i = 0; i < n; i++)
    {
        t.insertword(ar[i]);
    }

    string first = ar[0];      // pehla word root mai insert karne k liye
    string ans = "";           // empty string rakh diya ans store karne k liye
    t.lcp(t.root, first, ans); // Calculate LCP with root node and the first string
    return ans;                // ans jo bhi hai dedo
}

int main()
{
    vector<string> words = {"flower", "flow", "flight"};
    int n = words.size();
    string result = longestcp(words, n);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
