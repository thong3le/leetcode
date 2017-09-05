class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        vector<string> result; 
        for(int i = list1.size()-1; i >= 0; i--)
            map[list1[i]] = i;
        int min = list1.size() + list2.size();
        for(int i = 0; i < list2.size(); i++){
            if (map.find(list2[i]) != map.end()){
                if (map[list2[i]]+i < min){
                    min = map[list2[i]] + i;
                    result.clear();
                    result.push_back(list2[i]);
                }
                else if (map[list2[i]]+i == min)
                    result.push_back(list2[i]);
            }
        }
        return result;
    }
};