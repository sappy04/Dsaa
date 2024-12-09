#include <bits/stdc++.h>
using namespace std;

class trienode // trie node k saare essentials hai ismai
{
public:
    char data;              // charachter hota hai na wohi
    trienode *children[26]; // root k char children
    bool isterminal;        // last wala terminal node hai ki nahi uske liye
    trienode(char ch)
    {
        data = ch; // data ko ch se initialise kar diya
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

    void printsuggestions(trienode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isterminal)
        {
            temp.push_back(prefix);
        }
        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            trienode *next = curr->children[ch - 'A'];
            if (next != NULL)//ja
            {
                prefix.push_back(ch);
                printsuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> get_suggestion(string str)
    {
        trienode *prev = root;             // root pe previous mark kar diya
        vector<vector<string>> output;    // output store karne k liye
        string prefix = "";               // mere input ka ek ek karke elements ismai dalte jayenge aur store hote rahenge

        for (int i = 0; i < str.length(); i++)
        {
            char lastchar = str[i];       // ismai sirf mera elements jo aate jaa rahe hai wohi rahenge,agar prefix aur last char donno mai same value hai tabhi sirf curretn pointer rahega waha pe
            prefix.push_back(lastchar);   // prefix update kar diya

            // check for lastchar
            trienode *curr = prev->children[lastchar - 'A'];

            // not found
            if (curr == NULL)
            {
                break;
            }

            // if found
            vector<string> temp;
            printsuggestions(curr, temp, prefix);//us word k related jitne saare suggestions hais ab aa jayenge

            output.push_back(temp);
            prev = curr; // aage traverse kar diya
        }
        return output;
    }
};

vector<vector<string>> phone_directory(vector<string> &contactlist, string &querystring)
{
    // creation of trie
    trie t;

    // insert all contacts in trie
    for (int i = 0; i < contactlist.size(); i++)
    {
        // trie mai sab contact list daala hai
        t.insertword(contactlist[i]);
    }
    return t.get_suggestion(querystring); // returns the ans
}

int main()
{
    vector<string> contacts = {"Alice", "Bob", "Alfred", "Ali", "Brian"};
    string query = "Al";

    vector<vector<string>> suggestions = phone_directory(contacts, query);

    cout << "Suggestions for \"" << query << "\":" << endl;
    for (int i = 0; i < suggestions.size(); i++)
    {
        cout << "After '" << query.substr(0, i + 1) << "': ";
        for (string suggestion : suggestions[i])
        {
            cout << suggestion << " ";
        }
        cout << endl;
    }
    return 0;
}
