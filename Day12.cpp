/* 1900. The Earliest and Latest Rounds Where Players Compete :
There is a tournament where n players are participating. The players are standing in a single row and are numbered from 1 to n
based on their initial standing position (player 1 is the first player in the row, player 2 is the second player in the row, etc.).

The tournament consists of multiple rounds (starting from round number 1). In each round, the ith player from the front of the row
competes against the ith player from the end of the row, and the winner advances to the next round. When the number of players is 
odd for the current round, the player in the middle automatically advances to the next round.

For example, if the row consists of players 1, 2, 4, 6, 7
Player 1 competes against player 7.
Player 2 competes against player 6.
Player 4 automatically advances to the next round.
After each round is over, the winners are lined back up in the row based on the original ordering assigned to them initially (ascending order).

The players numbered firstPlayer and secondPlayer are the best in the tournament. They can win against any other player before they compete
against each other. If any two other players compete against each other, either of them might win, and thus you may choose the outcome of 
this round.

Given the integers n, firstPlayer, and secondPlayer, return an integer array containing two values, the earliest possible round number and
the latest possible round number in which these two players will compete against each other, respectively. */


class Solution {
public:
        map<tuple<int, int, int>, pair<int, int>> memo;

    pair<int, int> dfs(int n, int a, int b) {
        if (a > b) swap(a, b);
        auto key = make_tuple(n, a, b);
        if (memo.count(key)) return memo[key];

        int l = a, r = b;
        if (l + r == n + 1) return {1, 1}; // They face each other this round

        int minRound = INT_MAX, maxRound = INT_MIN;
        vector<pair<int, int>> pairs;
        for (int i = 1; i <= n / 2; ++i)
            pairs.push_back({i, n - i + 1});
        if (n % 2 == 1) pairs.push_back({(n + 1) / 2, (n + 1) / 2});

        vector<int> current;
        for (int mask = 0; mask < (1 << pairs.size()); ++mask) {
            current.clear();
            bool valid = true;
            for (int i = 0; i < pairs.size(); ++i) {
                int x = pairs[i].first, y = pairs[i].second;
                if (x == y) {
                    current.push_back(x);
                    continue;
                }

                bool containsA = (x == a || y == a);
                bool containsB = (x == b || y == b);

                if (containsA && containsB) {
                    valid = false;
                    break;
                }
                if (containsA) {
                    current.push_back(a);
                } else if (containsB) {
                    current.push_back(b);
                } else {
                    current.push_back((mask >> i) & 1 ? x : y);
                }
            }

            if (!valid) continue;
            sort(current.begin(), current.end());

            // new positions of a and b
            int posA = find(current.begin(), current.end(), a) - current.begin() + 1;
            int posB = find(current.begin(), current.end(), b) - current.begin() + 1;

            auto [nextMin, nextMax] = dfs(current.size(), posA, posB);
            minRound = min(minRound, nextMin + 1);
            maxRound = max(maxRound, nextMax + 1);
        }

        return memo[key] = {minRound, maxRound};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        auto [minR, maxR] = dfs(n, firstPlayer, secondPlayer);
        return {minR, maxR};
    }
};
