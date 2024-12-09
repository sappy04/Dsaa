#include <bits/stdc++.h>
using namespace std;

class trienode // trie node k saare essentials hai ismai
{
public:
    char data;          // charachter hota hai na wohi
    trienode *children[26]; // root k char children
    bool isterminal;    // last wala terminal node hai ki nahi uske liye
    trienode(char ch)
    {
        data = ch; // data ko ch se inititalise kar diya
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL; // saare children ko null mark kar diya initially
        }
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

        // assumption,word is in caps
        int index = word[0] - 'A'; //[a=0 and z=25]in index to abhi A ka aschi hai 65 and A ka bhi 65 to - karne se 0 agaya jo ki mera alloted slot hai for index for a..like wise all
        trienode *child;

        // child present hai
        if (root->children[index] != NULL) // jo word k starting element ko mai khoj rha hoon root k children mai wohi word ka starting element present hai
        {
            child = root->children[index]; // hai to usse child declare kar diya
        }
        else                               // absent hai
        {                                  // new node creation
            child = new trienode(word[0]); // naya child banaya
            root->children[index] = child; // usko link kar diya
        }

        // for rest of the word
        insertutil(child, word.substr(1)); // reccursion
    }

    void insertword(string word) // word ayega call hoga aur insert ho jayega
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper); // lowercase to uppercase
        insertutil(root, word);
    }

    bool searchword(trienode *root, string word)
    {
        if (word.length() == 0) // word ka length hi khattam hogaya hai to usse root ka terminal mark kar do
        {
            return root->isterminal;
        }

        int index = word[0] - 'A'; // jis word ko khojna hai uska index to nikal le
        trienode *child;

        if (root->children[index] != NULL) //main root pe search ho raha
        {//mil gaya hai to
            child = root->children[index];//child ko us letter pe target karde jo ki baad mai root hoke pass hoga and uske under checking hoga usi word ka further letters
        }
        else // absent hai
        {
            return false;//nahi mila bc
        }
        return searchword(child, word.substr(1));//current searching word k pehla word, root k hisab se, send ho gaya abhi uske neeche wala searching hoga
    }

    bool removeutil(trienode *root, string word)
    {
        
        if (word.length() == 0)//word ka length hi khattam hogaya
        {
            if (root->isterminal)//to terminal hoga na usko terminal se unmark kar de rahe
            { // If terminal node, unmark it
                root->isterminal = false;
                // Check if node has any children
                return isEmpty(root); // Delete node only if it's empty
            }
            return false; // Word not present as terminal
        }

        // Get index of current character
        int index = word[0] - 'A';

        if (root->children[index] != NULL)
        { // Check if child exists
            bool shouldDeleteChild = removeutil(root->children[index], word.substr(1));

            if (shouldDeleteChild)
            { // If child is deletable
                delete root->children[index];
                root->children[index] = NULL;

                // Check if current node is now empty
                return !root->isterminal && isEmpty(root);
            }
        }
        return false; // Child does not exist, nothing to delete
    }

    // Helper function to check if a node has any children
    bool isEmpty(trienode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
                return false; // Node is not empty
        }
        return true; // Node is empty
    }

    void removeword(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper); // lowercase to uppercase
        removeutil(root, word);
    }

    bool prefixutil(trienode *root, string word)
    {
        if (word.length() == 0) // word ka length hi khattam hogaya hai to usse root ka terminal mark kar do
        {
            return true;
        }

        int index = word[0] - 'A'; // jis word ko khojna hai uska index to nikal le
        trienode *child;

        if (root->children[index] != NULL) // agar mere root mai yahi letter present hai to
        {
            child = root->children[index];//mil gaya child keh diya usko
        }
        else // absent hai
        {
            return false;//nahi mila bc
        }
        return prefixutil(child, word.substr(1));//recurssive call
    }

    bool startwithprefix(string prefix)
    {
        return prefixutil(root,prefix);
    }
};

int main()
{
    trie t;

    t.insertword("CAT");
    t.insertword("CAR");
    t.insertword("DOG");

    cout << (t.searchword(t.root, "CAT") ? "CAT Found" : "CAT Not Found") << endl;

    t.removeword("CAT");
    cout << (t.searchword(t.root, "CAT") ? "CAT Found" : "CAT Not Found") << endl;

    cout << (t.startwithprefix("CA") ? "Prefix CA Found" : "Prefix CA Not Found") << endl;
    cout << (t.startwithprefix("DO") ? "Prefix DO Found" : "Prefix DO Not Found") << endl;
    cout << (t.startwithprefix("DA") ? "Prefix DA Found" : "Prefix DA Not Found") << endl;

    return 0;
}
