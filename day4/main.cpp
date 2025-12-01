#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int main() {
    std::unordered_set<int> winners;
    std::vector<int> points;
    
    std::string line; 
    while (std::getline(std::cin, line)) {
        if (line.empty()) break;
        
        winners.clear();
        
        int index = line.find(':');
        int splitPos = line.find('|', index);
        int cur_val = 0;
        for(; index < splitPos; ++index) {
            if(std::isdigit(line[index])) {
                cur_val = cur_val * 10 + (line[index] - '0');
            }
            else if(cur_val != 0) {
                winners.insert(cur_val);
                cur_val = 0;
            }
        }
        
        int cur_points = 0;
        index = splitPos + 1;
        cur_val = 0;
        for(; index < line.size() + 1; ++index) {
            if(index < line.size() && std::isdigit(line[index])) {
                cur_val = cur_val * 10 + (line[index] - '0');
            }
            else if(cur_val != 0) {
                if(winners.find(cur_val) != winners.end()) {
                    ++cur_points;
                }
                cur_val = 0;
            }   
        }
        points.push_back(cur_points);
    }
    
    std::vector<int> counts(points.size(), 1);
    int sum = 0;
    
    for(size_t i = 0; i < points.size(); ++i) {
        sum += counts[i];
        for(size_t j  = i + 1; j < points[i] + i + 1 && j < points.size(); ++j) {
            counts[j] += counts[i];
        }
    }
    
    std::cout << sum << std::endl;
    return 0;
}