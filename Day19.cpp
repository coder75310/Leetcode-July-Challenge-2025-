/* 1233. Remove Sub-Folders from the Filesystem:
Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.

If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". 
For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".

The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.

For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not. */


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;

        for(const string& f : folder){
            if(res.empty() || f.find(res.back() + "/") != 0){
                res.push_back(f);
            }
        }
        return res;
    }
};





// 2nd method
/*  class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Step 1: Sort the folder paths lexicographically
        sort(folder.begin(), folder.end());

        vector<string> result;
        for (const string& path : folder) {
            // Step 2: If result is empty or current path is not a subfolder of last added
            if (result.empty() || path.find(result.back() + "/") != 0) {
                result.push_back(path);
            }
        }

        return result;
    }
}; */
