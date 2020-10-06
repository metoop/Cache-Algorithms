class Solution:
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        maxFreq = 0
        max_count = 0
        dic = {}
        for task in tasks:
            if task in dic:
                dic[task] += 1
            else:
                dic[task] = 1
            if dic[task] > maxFreq:
                maxFreq = dic[task]
                max_count = 1
            elif dic[task] == maxFreq:
                max_count += 1
        
        if len(dic) <= n+1:
            return (maxFreq-1) * (n+1) + max_count
        else:
            return max((maxFreq-1) * (n+1) + max_count, len(tasks))

