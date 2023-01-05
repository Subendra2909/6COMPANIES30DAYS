class Solution {
public:
    void calculate_dist(int v, vector<int>& dist, vector<int>& parent, vector<int> adj[], int d, int p){
        dist[v] = d;
        parent[v] = p;
        for(auto it : adj[v]){
            if(it == p) continue;
            calculate_dist(it, dist, parent, adj, d+1, v);
        }
    }

    int max_income(int v, vector<int> adj[], vector<int>& amount, int p){
        int curr_income = amount[v];
        int maxi = INT_MIN;
        for(auto it : adj[v]){
            if( it != p){
                maxi = max(maxi, max_income(it, adj, amount, v));
            }
        }
        if(maxi == INT_MIN) return curr_income;
        else return curr_income + maxi;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> adj[n];
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dist(n,0);
        vector<int> parent(n,0);

        calculate_dist(0,dist, parent, adj,0,0);

        int curr = bob;
        int bob_dist = 0;
        while(curr != 0){
            if(dist[curr] > bob_dist){
                amount[curr] = 0;
            }
            else if(dist[curr] == bob_dist){
                amount[curr] /= 2;
            }
            curr = parent[curr];
            bob_dist++;
  
        }

        return max_income(0, adj, amount,0);
    }
};