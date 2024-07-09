class Solution(object):
    def averageWaitingTime(self, customers):
        start = customers[0][0]
        end = start + customers[0][1]
        total_waiting_time = float(end-start)
        for i in range(1, len(customers)):
            if(customers[i][0] <= end):
                start = end
                end = start + customers[i][1]
            else:
                start = customers[i][0]
                end = start + customers[i][1]
            total_waiting_time += (end - customers[i][0])

        avg_waiting_time = total_waiting_time/(len(customers))
        return avg_waiting_time
        