#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

1.postTweet(userId, tweetId): Compose a new tweet.
2.getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
3.follow(followerId, followeeId): Follower follows a followee.
4.unfollow(followerId, followeeId): Follower unfollows a followee.

Example:
Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        id = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_front(make_pair(id++, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        vector < deque<pair<int, int>>> heapvec;
        if (!tweet[userId].empty())
            heapvec.push_back(tweet[userId]);
        for(auto i:map[userId])
            if(!tweet[i].empty())
                heapvec.push_back(tweet[i]);
        auto cmp = [](deque<pair<int, int>> &pa, deque<pair<int, int>> &pb) {
            return pa.front().first < pb.front().first;
        };
        make_heap(heapvec.begin(), heapvec.end(), cmp);
        while (result.size() != 10 && !heapvec.empty()) {
            result.push_back(heapvec.front().front().second);
            pop_heap(heapvec.begin(), heapvec.end(), cmp);
            heapvec.back().pop_front();
            if (heapvec.back().empty())
                heapvec.pop_back();
            else
                push_heap(heapvec.begin(), heapvec.end(), cmp);
        }
        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        map[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        map[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> map;
    unordered_map<int, deque<pair<int, int>>> tweet;
    unsigned int id;
};

int main() {
     
    return 0;
}