class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInMap;
    unordered_map<string, pair<int, int>> routeMap; 
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkInMap[id];
        checkInMap.erase(id);
            
        string routeName = checkIn.first + "_" + stationName;
        routeMap[routeName].first += t - checkIn.second;
        routeMap[routeName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        auto& route = routeMap[routeName];
        return (double) route.first / route.second;
    }
};