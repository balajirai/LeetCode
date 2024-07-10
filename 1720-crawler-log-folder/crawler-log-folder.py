class Solution(object):
    def minOperations(self, logs):
        dir = []
        for operation in logs:
            if operation == "../":
                if dir:
                    dir.pop()
            elif operation == "./":
                pass
            else:
                dir.append(operation)
        return len(dir)
        