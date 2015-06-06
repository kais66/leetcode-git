class Solution:
    # @param {integer[][]} buildings
    # @return {integer[][]}
    # each 'building' is represented by a triplet
    def getSkyline(self, buildings):
        events = self.decompose(buildings)
        prioQ = []

        ret = []
        for event in eventList:
            eventType = event[2]
            if eventType == -1: # if left corner
                heappush(prioQ, [event[1], event])

            if not ret:
                ret.append([event[0], event[1]])
            else:
                topEvent = None
                while True:
                    topEvent = prioQ[0][1]
                    if topEvent[0] < event[0]:
                        heappop(prioQ)
                    else:
                        break
                if topEvent[0] == ret[-1][0] and topEvent[1] > ret[-1][1]:
                    ret[-1][1] = topEvent[1]


    def decompose(self, buildings):
        eventList = []
        for thisBuild in buildings:
            # last field is event type
            eventList.append([thisBuild[0], thisBuild[2], -1])
            eventList.append([thisBuild[1], thisBuild[2], 1])
        eventList.sort(key=lambda a: a[0])
        return eventList
