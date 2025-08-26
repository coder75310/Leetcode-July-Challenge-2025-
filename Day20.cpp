/* 1948. Delete Duplicate Folders in System :
Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder in the file system.

For example, ["one", "two", "three"] represents the path "/one/two/three".
Two folders (not necessarily on the same level) are identical if they contain the same non-empty set of identical subfolders and underlying subfolder structure. 
The folders do not need to be at the root level to be identical. If two or more folders are identical, then mark the folders as well as all their subfolders.

For example, folders "/a" and "/b" in the file structure below are identical. They (as well as their subfolders) should all be marked:
/a
/a/x
/a/x/y
/a/z
/b
/b/x
/b/x/y
/b/z
However, if the file structure also included the path "/b/w", then the folders "/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" 
would still be considered identical even with the added folder.
Once all the identical folders and their subfolders have been marked, the file system will delete all of them. The file system only runs the deletion once, 
so any folders that become identical after the initial deletion are not deleted.
Return the 2D array ans containing the paths of the remaining folders after deleting all the marked folders. The paths may be returned in any order.
*/


class TrieNode {
public:
    unordered_map<string, TrieNode*> children;
    bool deleted = false;
};

class Solution {
    unordered_map<string, int> serialCount;

    // Build the Trie
    void insert(TrieNode* root, vector<string>& path) {
        TrieNode* node = root;
        for (string& folder : path) {
            if (!node->children.count(folder)) {
                node->children[folder] = new TrieNode();
            }
            node = node->children[folder];
        }
    }

    // Serialize subtree
    string serialize(TrieNode* node) {
        if (node->children.empty()) return "";

        vector<pair<string, string>> serials;
        for (auto& [name, child] : node->children) {
            serials.emplace_back(name, serialize(child));
        }

        sort(serials.begin(), serials.end());
        string s;
        for (auto& [name, sub] : serials) {
            s += "(" + name + sub + ")";
        }

        serialCount[s]++;
        return s;
    }

    // Mark duplicates
    string mark(TrieNode* node) {
        if (node->children.empty()) return "";

        vector<pair<string, string>> serials;
        for (auto& [name, child] : node->children) {
            serials.emplace_back(name, mark(child));
        }

        sort(serials.begin(), serials.end());
        string s;
        for (auto& [name, sub] : serials) {
            s += "(" + name + sub + ")";
        }

        if (serialCount[s] > 1) {
            node->deleted = true;
        }

        return s;
    }

    // Collect all remaining paths
    void collect(TrieNode* node, vector<string>& path, vector<vector<string>>& res) {
        for (auto& [name, child] : node->children) {
            if (!child->deleted) {
                path.push_back(name);
                res.push_back(path);
                collect(child, path, res);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();

        // Step 1: Build Trie
        for (auto& path : paths) {
            insert(root, path);
        }

        // Step 2: Serialize to find duplicates
        serialize(root);

        // Step 3: Mark duplicates
        mark(root);

        // Step 4: DFS to collect results
        vector<vector<string>> result;
        vector<string> current;
        collect(root, current, result);

        return result;
    }
};
