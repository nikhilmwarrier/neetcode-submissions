class Solution {
public:

    string encode(vector<string>& strs) {
        string f;

        for (const string& s : strs) {
            f += std::to_string(s.size());
            f += '#';
            f += s;
        }

        std::cout << f << '\n';
        return f;
    }

    vector<string> decode(string s) {
        vector<string> fa;
        string slice;

        int i = 0;
        int j = 0;

        int len = 0;

        while (i < s.size()) {
            j = i;
            while (s[j] != '#')
                j++;
            // j is now on the '#'

            len = std::stoi(s.substr(i, j - i));
            
            i = j+1; // i is right after '#'
            slice = s.substr(i, len);
            fa.push_back(slice);
            i += len;
            len = 0;
        }


        return fa;
    }
};
