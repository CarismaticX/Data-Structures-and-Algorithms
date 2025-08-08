class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() >s2.length()){
            return false;
        }

        vector <int> freq1(26, 0) ,freq2(26,0);

// Step 1: Count frequency of characters in s1
        for(int i =0; i<s1.length();i++){
            int index = s1[i] - 'a';
            freq1[index]++;
        }

// Step 2: Count frequency of first window in s2
        for(int i= 0; i<s1.length();i++){
            int index = s2[i] -'a';
            freq2[index]++;
        }

 // Step 3: Compare first window
        if (freq1 == freq2) return true;



        for(int i = s1.length(); i<s2.length();i++){
            freq2[s2[i] - 'a']++;
            freq2[s2[i - s1.length()] - 'a']--;


            if(freq1 == freq2) return true;
        }

return false;
        
    }
};