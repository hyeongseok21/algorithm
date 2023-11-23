vector<vector<double>> solution(vector<vector<double>> buildings) {
    vector<vector<double>> ans;
    multiset<double> pq{0};
    
    // (points, height)
    vector<pair<double, double>> points;
    for(int i = 0; i < buildings.size(); ++i) {
        double l = buildings[i][0];
        double r = l + buildings[i][1]; 
        double h = buildings[i][2];
        points.push_back({l, -h}), points.push_back({r, h});
    }
    
    sort(points.begin(), points.end());
    
    double ongoingheight = 0;
    for(int i = 0; i < points.size(); ++i) {
        double currentpoint = points[i].first;
        double currentheight = points[i].second;
        
        if (currentheight < 0) {
            pq.insert(-currentheight);
        }
        else {
            pq.erase(pq.find(currentheight));
        }
        
        auto pqTop = *pq.rbegin();
        if (ongoingheight != pqTop) {
            ongoingheight = pqTop;
            ans.push_back({currentpoint, ongoingheight});
        }
    }
    
    return ans;
}