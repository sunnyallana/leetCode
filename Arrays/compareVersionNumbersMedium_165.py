class Solution:
    def compareVersion(self, version1, version2):
        parts1, parts2 = version1.split("."), version2.split(".")
        i, j = len(parts1) - 1, len(parts2) - 1
        
        while parts1 and int(parts1[i]) == 0:
            parts1.pop()
            i -= 1
        while parts2 and int(parts2[j]) == 0:
            parts2.pop()
            j -= 1
        
        for i in range(min(len(parts1), len(parts2))):
            int1, int2 = int(parts1[i]), int(parts2[i])
            if int1 > int2:
                return 1
            elif int1 < int2:
                return -1
        
        if len(parts1) > len(parts2):
            return 1
        elif len(parts2) > len(parts1):
            return -1
        return 0
