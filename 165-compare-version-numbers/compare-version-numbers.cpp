class Solution {
private:
    vector<int> split(string version) {
        vector<int> parts;
        stringstream ss(version);
        string part;
        while (getline(ss, part, '.')) {
            parts.push_back(stoi(part));
        }
        return parts;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1Parts = split(version1);
        vector<int> v2Parts = split(version2);

        // Padding the vectors with zeros to make them of equal length
        int maxLength = max(v1Parts.size(), v2Parts.size());
        v1Parts.resize(maxLength, 0);
        v2Parts.resize(maxLength, 0);

        for (int i = 0; i < maxLength; ++i) {
            if (v1Parts[i] < v2Parts[i]) {
                return -1;
            } else if (v1Parts[i] > v2Parts[i]) {
                return 1;
            }
        }

        return 0;
    }
};