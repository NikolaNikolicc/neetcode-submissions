class Twitter:

    def __init__(self):
        self.followList = defaultdict(set)
        self.userTweets = defaultdict(list)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.userTweets[userId].append(tweetId)

    def getNewsFeed(self, userId: int) -> List[int]:

        heap = []
        for followee in self.followList[userId]:
            if followee in self.userTweets:
                lastIndex = len(self.userTweets[followee]) - 1
                heap.append((-self.userTweets[followee][lastIndex], lastIndex, followee))

        if userId in self.userTweets:
            lastIndex = len(self.userTweets[userId]) - 1
            heap.append((-self.userTweets[userId][lastIndex], lastIndex, userId))

        heapq.heapify(heap)

        res = []
        for _ in range(10):
            if heap == []:
                return res
            
            tweet, index, followee = heapq.heappop(heap)

            res.append(-tweet)

            if index > 0:
                heapq.heappush(heap, (-self.userTweets[followee][index - 1], index - 1, followee))
            
        return res





    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId == followeeId:
            return

        self.followList[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followList[followerId]:
            self.followList[followerId].remove(followeeId)
