class Solution(object):
    def passThePillow(self, n, time):
        if time < n:
            return time+1
        else:
            k = time / (n-1)
            time = time % (n-1)
            if k % 2 == 0:
                return time+1
            return n - time