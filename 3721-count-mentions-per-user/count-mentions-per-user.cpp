class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
         sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int tA = stoi(a[1]);
            int tB = stoi(b[1]);
            if (tA == tB) {
                return a[0] == "OFFLINE";
            }
            return tA < tB;
        });

        vector<bool> isOnline(numberOfUsers, true);

              priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> offlineQueue;
        vector<int> mentions(numberOfUsers, 0);

          for (const auto& event : events) {
            string type = event[0];
            int timestamp = stoi(event[1]);

           
            while (!offlineQueue.empty() && offlineQueue.top().first <= timestamp) {
                int userID = offlineQueue.top().second;
                isOnline[userID] = true; 
                offlineQueue.pop();
            }

            if (type == "OFFLINE") {
                int userID = stoi(event[2]);
                isOnline[userID] = false; 
                offlineQueue.push({timestamp + 60, userID}); 
            } else if (type == "MESSAGE") {
                string mentionsString = event[2];
                if (mentionsString == "ALL") {
                    
                    for (int i = 0; i < numberOfUsers; i++) {
                        mentions[i]++;
                    }
                } else if (mentionsString == "HERE") {
                    
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (isOnline[i]) {
                            mentions[i]++;
                        }
                    }
                } else {
                    
                    stringstream ss(mentionsString);
                    string token;
                    while (ss >> token) {
                        if (token.substr(0, 2) == "id") {
                            int userID = stoi(token.substr(2));
                            mentions[userID]++;
                        }
                    }
                }
            }
        }

        return mentions;

    }
};