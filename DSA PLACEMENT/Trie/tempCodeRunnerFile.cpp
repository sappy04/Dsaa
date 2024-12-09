bool removeutil(trienode *root, string word)
    // {
    //     // Base Case: Word traversal complete
    //     if (word.length() == 0)
    //     {
    //         if (root->isterminal)
    //         { // If terminal node, unmark it
    //             root->isterminal = false;
    //             // Check if node has any children
    //             return isEmpty(root); // Delete node only if it's empty
    //         }
    //         return false; // Word not present as terminal
    //     }

    //     // Get index of current character
    //     int index = word[0] - 'A';

    //     if (root->children[index] != NULL)
    //     { // Check if child exists
    //         bool shouldDeleteChild = removeutil(root->children[index], word.substr(1));

    //         if (shouldDeleteChild)
    //         { // If child is deletable
    //             delete root->children[index];
    //             root->children[index] = NULL;

    //             // Check if current node is now empty
    //             return !root->isterminal && isEmpty(root);
    //         }
    //     }
    //     return false; // Child does not exist, nothing to delete
    // }

    // // Helper function to check if a node has any children
    // bool isEmpty(trienode *root)
    // {
    //     for (int i = 0; i < 26; i++)
    //     {
    //         if (root->children[i] != NULL)
    //             return false; // Node is not empty
    //     }
    //     return true; // Node is empty
    // }

    // void removeword(string word)
    // {
    //     transform(word.begin(), word.end(), word.begin(), ::toupper); // lowercase to uppercase
    //     removeutil(root, word);
    // }