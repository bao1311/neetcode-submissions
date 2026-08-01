class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        mp = {}
        st = set()
        for word in strs: 
            temp = [0]*26
            for c in word:
                temp[ord(c)-ord('a')] += 1
            key = tuple(temp)
            if key in mp:
                mp[key].append(word)
            else:
                mp[key] = [word]
        for value in mp.values():
            ans.append(value)
        return ans
